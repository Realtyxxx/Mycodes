#include "Listf.h" 
#include "Llist.h"
#include <bits/stdc++.h>

using namespace std;

void test(Llist<int> &llist) {
  int act;
  int pos, value;
  do {
    //读取指令  指令说明：1  插入  2  删除  3  获取值  4  查找
    cin >> act;
    switch (act) {
      case 1:  //在pos位置插入值value
        cin >> pos >> value;
        llist.moveToPos(pos);
        llist.insert(value);
        llist.print();
        break;
      case 2:  //删除pos位置的元素
        cin >> pos;
        llist.moveToPos(pos);
        llist.remove();
        llist.print();
        break;
      case 3:  //获取指定位置的值
        cin >> pos;
        llist.moveToPos(pos);
        cout << llist.getValue() << endl;
        break;
      case 4:  //查询特定值所在位置，如果存在输出位置，否则不输出
        cin >> value;
        for (llist.moveToStart(); llist.currPos() < llist.length();
             llist.next()) {
          if (llist.getValue() == value) {
            cout << llist.currPos() << endl;
            break;
          }
        }
        break;
      case 0:
        return;
    }
  } while (true);
}

int main() {
  Llist<int> llist;
  test(llist);  //测试
  return 0;
}
