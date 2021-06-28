#include <semaphore.h>

semaphore offer1;  //提供音乐磁带和电池
semaphore offer2;  //提供随身听和电池
semaphore offer3;  //提供随声听和音乐磁带
semaphore finish；  //是否交易结束，如果没有结束不让下一次交易开始
    semaphore goods;    //交货
semaphore     payment;  //是否交钱
int           random = 0;

void boss() {
  while (true) {
    random = rand() % 3 + 1;
    if (random == 1) V(offer1);
    if (random == 2) V(offer2);
    if (random == 3) V(offer3);
    拿出一个组合出来卖
    P(payment);  //等对方交钱再给货
    V(goods);    //拿到钱之后交货
    P(finish);   //对方用完之后才可以下一阵子开始
  }
}

void musician1() {
  while (true) {
    P(offer1);
    V(payment);
    P(goods);
    V(finish);
  }
}
void musician2() {
  while (true) {
    P(offer2);
    V(payment);
    P(goods);
    V(finish);
  }
}
void musician3() {
  while (true) {
    P(offer3);
    V(payment);
    P(goods);
    V(finish);
  }
}