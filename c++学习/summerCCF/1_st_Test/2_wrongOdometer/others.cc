#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {  //主要思想是给出的数字其实就是一个八进制数字,每位范围12 4567 9,
                                 //如果是4-7则减去1, 9减去2, 即得原来的数字
    string s;
    cin >> s;
    int len = s.length();
    int a;
    for (int i = 0; i < len; i++) {  //转化为真正的八进制数据
      if (s[i] >= '4') {
        if (s[i] == '9')
          s[i] -= 2;
        else
          s[i] -= 1;
      }
    }
    //下面是两种八进制转化到十进制的方法

    // stringstream ss;
    // ss << oct << s;
    // ss >> a;
    // cout << a << endl; //理解不能

    int result = strtol(s.c_str(), NULL, 8);  // strtol()和c_str()可上网查
    cout << result << endl;
  }
  return 0;
}
// ————————————————
// 版权声明：本文为CSDN博主「yogdzewa」的原创文章，遵循CC 4.0
// BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/weixin_51307568/article/details/118418142