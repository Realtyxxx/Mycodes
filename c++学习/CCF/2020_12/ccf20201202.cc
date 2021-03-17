#include <iostream>
#include <algorithm>

typedef struct {
  int y;
  int result;
} student;
bool comp(const student& a, const student& b) { return a.y < b.y; }

int main() {
  int m;
  std::cin >> m;

  student* stu = new student[m];

  int cnt[2];
  int now[2];
  
  for (int i = 0; i < m; i++) {
    std::cin >> stu[i].y >> stu[i].result;
    cnt[stu[i].result]++;
  }

  std::sort(stu, stu + m, comp);

  int maxOK = 0, maxtheta = 0;
  for (int i = 0; i < m; ++i) {
    if (i > 1 && stu[i].y == stu[i - 1].y) {
      now[stu[i].result]++;
      continue;
    }
    int OK = cnt[1] + now[0] - now[1];
    if (OK >= maxOK) {
      maxOK = OK;
      maxtheta = stu[i].y;
    }
    now[stu[i].result]++;
  }
  std::cout << maxtheta << std::endl;
  return 0;
}