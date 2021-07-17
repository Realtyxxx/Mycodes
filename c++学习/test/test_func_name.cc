#include <stdio.h>
#include <stdlib.h>

// 在宏定义中，使用 # 将参数转为字符串，使用 ## 来连接两个参数作为一个整体标识符。
#define STRING(x) #x
#define COMBINE(x, y) x##y

int main(int argc, char **argv)
{
    int x1 = 3;
    int x2 = 4;
    // STRING(x1) 将变成 "x1"
    // COMBINE(x, 1) 将变成 x1
    printf(STRING(x1) " = %d\n", COMBINE(x, 1));
    printf(STRING(x2) " = %d\n", COMBINE(x, 2));
    return 0;
}