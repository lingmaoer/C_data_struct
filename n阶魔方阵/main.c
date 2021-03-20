/*
给定一奇数n，构造一个n阶魔方阵。
n阶魔方阵是一个n阶方阵，其元素由自然数1,2,3，……，n组成。
魔方阵的每行元素之和，每列元素之和以及主、副对角线之和均相等。编写程序，输出魔方阵。


（1）自然数 1 出现在第一行的正中间；
（2）若填入的数字在第一行（不在第 n 列），则下一个数字在第 n 行（最后一行）且列数加 1（列数右移一列）；
（3）若填入的数字在该行的最右侧，则下一个数字就填在上一行的最左侧；
（4）一般地，下一个数字在前一个数字的右上方（行数少 1，列数加 1）；
（5）若应填的地方已经有数字或在 方阵之外，则下一个数字就填在前一个数字的下方。（一般地，n 的倍数的下一个数字是在该数的下方。）
*/
// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 20

void f(int x);

int main()
{
    int x;
    scanf("%d", &x);
    f(x);
    return 0;
}

void f(int x)
{
    int num[size][size] = {0};
    int i = 0, j = x / 2, k = 1;

    while (k <= x * x)
    {
        num[i][j] = k;
        k++;
        i--;
        j++;
        if (i < 0 && j < x) //横轴出边界，竖轴还在边界内
        {
            i = x - 1;
            continue;
        }

        if (j > x - 1 && i > -1) //竖轴出边界，横轴还在边界内
        {
            j = 0;
            continue;
        }

        if (i < 0 && j > x - 1) //横轴和竖轴都出边界
        {
            i += 2;
            j--;
            continue;
        }

        if (i > -1 && j < x && num[i][j] != 0) //横轴和竖轴都在边界，但是有数据。
        {
            i += 2;
            j--;
            continue;
        }
    }
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            printf("%5d", num[i][j]);
        }
        printf("\n");
    }
}