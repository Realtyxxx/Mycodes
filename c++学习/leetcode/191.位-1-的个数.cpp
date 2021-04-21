/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 *
 * https://leetcode-cn.com/problems/number-of-1-bits/description/
 *
 * algorithms
 * Easy (73.88%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    158.2K
 * Total Submissions: 214.1K
 * Testcase Example:  '00000000000000000000000000001011'
 *
 * 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为
 * '1' 的个数（也被称为汉明重量）。
 *
 *
 *
 * 提示：
 *
 *
 * 请注意，在某些语言（如
 * Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
 * 在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在上面的 示例
 * 3 中，输入表示有符号整数 -3。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：00000000000000000000000000001011
 * 输出：3
 * 解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：00000000000000000000000010000000
 * 输出：1
 * 解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
 *
 *
 * 示例 3：
 *
 *
 * 输入：11111111111111111111111111111101
 * 输出：31
 * 解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
 *
 *
 *
 * 提示：
 *
 *
 * 输入必须是长度为 32 的 二进制串 。
 *
 *
 *
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如果多次调用这个函数，你将如何优化你的算法？
 *
 *
 */

// @lc code=start
#include <iostream>
using namespace std;
/*
class Solution {
 public:
  int hammingWeight(uint32_t x) {
    int count;

    int tmpMask1 = (0x55) | (0x55 << 8);
    int mask1 = (tmpMask1) | (tmpMask1 << 16);  //得到掩码： 01010101……01010101

    int tmpMask2 = (0x33) | (0x33 << 8);
    int mask2 = (tmpMask2) | (tmpMask2 << 16);  //得到掩码： 00110011……00110011

    int tmpMask3 = (0x0f) | (0x0f << 8);
    int mask3 = (tmpMask3) | (tmpMask3 << 16);  //得到掩码： 00001111……00001111

    int mask4 = (0xff) | (0xff << 16);
    //得到掩码： 0000 0000 1111 1111 0000 0000 1111 1111

    int mask5 = (0xff) | (0xff << 8);
    //得到掩码： 0000 0000 0000 0000 1111 1111 1111 1111

    count = (x & mask1) + ((x >> 1) & mask1);
    //分别计算每组2位中，低位的1的个数；再移位求每组2位中，高位的1的个数；求和
    count = (count & mask2) + ((count >> 2) & mask2);  //两两相加
    count = (count + (count >> 4)) & mask3;            //同理，两两相加
    count = (count + (count >> 8)) & mask4;            //同理，两两相加
    count = (count + (count >> 16)) & mask5;           //同理，两两相加
    return count;
  }
};
 */
#include <bits/stdc++.h>
class Solution {
 public:
  int hammingWeight(uint32_t x) {
    int count;
    int mask1 = 0x55555555;
    int mask2 = 0x33333333;
    int mask3 = 0x0f0f0f0f;
    int mask4 = 0x00ff00ff;
    int mask5 = 0x0000ffff;

    count = (x & mask1) + (mask1 & (x >> 1));
    // std::cout << "bin:count=" << bitset<sizeof(unsigned int) * 8>(count)
    // << endl;

    // count = (count + (count >> 2)) & mask2;
    count = (count & mask2) + ((count >> 2) & mask2);  //两两相加
    // std::cout << "bin:count=" << bitset<sizeof(unsigned int) * 8>(count)
    // << endl;

    count = (count + (count >> 4) & mask3);
    // std::cout << "bin:count=" << bitset<sizeof(unsigned int) * 8>(count)
    // << endl;

    count = (count + (count >> 8) & mask4);
    // std::cout << "bin:count=" << bitset<sizeof(unsigned int) * 8>(count)
    // << endl;

    count = (count + (count >> 16)) & mask5;
    // std::cout << "bin:count=" << bitset<sizeof(unsigned int) * 8>(count)
    // << endl;

    return count;
  }
};
// @lc code=end

// cout<<"bin:i="<<bitset<sizeof(unsigned int)*8>(i)<<endl;
// bitset类输出二进制形式： bitset<sizeof(unsigned int) * 8>(count)