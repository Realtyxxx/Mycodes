#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct people {
  char id[19];   /* 身份证号码 */
  int  social;   /* 社保缴纳月数 */
  int  area;     /* 现有住房面积 */
  char date[11]; /* 申报日期 */
};

people *getMess(int &n);

int main() {
  people *person; /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */
  int     n;      /* n为报名人数，通过调用函数getMess获取 */
  person = getMess(n); // n=13
  cout << n << endl;
  // ...
  int m, T;
  cin >> m >> T;
  vector<string> query;
  for (int i = 0; i < T; i++) {
    string tmp_id;
    cin >> tmp_id;
    query.push_back(tmp_id);
  }

  return 0;
}

people *getMess(int &n) /* 将文件数据读入内存 */
{
  FILE *fp;
  fp = fopen("house.bin", "rb");
  fseek(fp, -1 * (long)sizeof(int), 2);
  fread(&n, sizeof(int), 1, fp);
  rewind(fp);
  people *tmp = new people[n];
  fread(tmp, sizeof(people), n, fp);
  fclose(fp);
  return tmp;
}