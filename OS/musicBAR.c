#include "bits/stdc++.h"

semaphore offer1 = 0;   //随身听+电池组合
semaphore offer2 = 0;   //随身听+磁带组合
semaphore offer3 = 0;   //电池+磁带组合
semaphore finish = 0;   //老板提供的组合被买走
semaphore payment = 0;  //交钱
semephore goods = 0;    //交货
int random = 0;

void boss() {
  while (true) {
    random = random() % 3;
    if (random == 0) v(offer1);
    if (random == 1) v(offer2);
    if (random == 2) v(offer3);
    拿出一个组合放出来卖
    p(payment);  //等待对方交钱
    v(goods);    //拿到钱之后交货
    p(finish);   //在这个要暂停，不能继续生产，除非上述生产的东西被买走
  }
}

void listener1() {
  while (true) {
    p(offer1);
    v(payment);  //一手付钱
    v(goods);    //一手拿货
    买走自己需要的组合
    v(finish);  //听完一整首歌之后，被卡住的老板进程可以继续再生产
  }
}

void listener2() {
  while (true) {
    p(offer2);
    v(payment);  //一手付钱
    v(goods);    //一手拿货
    买走自己需要的组合
    v(finish);
  }
}

void listener3() {
  while (true) {
    p(offer3);
    v(payment);  //一手付钱
    v(goods);    //一手拿货
    买走自己需要的组合
    v(finish);
  }
}