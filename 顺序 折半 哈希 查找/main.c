//设计一个小软件，实现所有查找技术的演示过程。
#include <stdio.h>
#define max 50
#define haximax 100
#define offset 2
int haxi_num;
int haxi_array[haximax];
void show();
void paixu(int data[], int num);
int shunxu(int data[], int num, int x);
int zhishu(int num);
int haxi(int x);
void creat_haxi(int data[], int num);

int main()
{
    int data[max];
    int num, i;
    printf("输入数据的个数");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &data[i]);
    }
    paixu(data, num);
    show();
    int chioce, x;
    while (1)
    {
        printf("\t\t输入你的选择:");
        scanf("%d", &chioce);
        switch (chioce)
        {
            case 1:
            {
                printf("请输入要查的数:");
                scanf("%d", &x);
                if (shunxu(data, num, x) == 1)
                    printf("找到此数\n");
                else
                    printf("不存在此数\n");
                break;
            }
            case 2:
            {
                printf("请输入要查的数:");
                scanf("%d", &x);
                if (zheban(data, num, x) == 1)
                    printf("找到此数\n");
                else
                    printf("不存在此数\n");
                break;
            }
            case 3:
            {
                printf("请输入要查的数:");
                scanf("%d", &x);
                creat_haxi(data, num);
                if (haxi(x) == 1)
                    printf("找到此数\n");
                else
                    printf("不存在此数\n");
                break;
            }
            case 4:
                printf("感谢你的再次使用\n");
                return 0;
            default:
            {
                printf("输入失败，请重新输入:\n");
                continue;
            }
        }
    }
}

void show()
{
    printf("\t\t1.顺序查找\n");
    printf("\t\t2.折半查找\n");
    printf("\t\t3.哈希查找\n");
    printf("\t\t4.退出\n");
}

void paixu(int data[], int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                int t;
                t = data[j];
                data[j] = data[j + 1];
                data[j + 1] = t;
            }
        }
    }
    for (i = 0; i < num; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");
}

int shunxu(int data[], int num, int x)
{
    int i;
    for (i = 0; i < num; i++)
    {
        printf("第%d次查找%d\n", i + 1, data[i]);
        if (data[i] == x)
        {
            return 1;
        }
    }
    return 0;
}
int zheban(int data[], int num, int x)
{
    int min = 0;
    int midnum, maxnum;
    int i = 0;

    maxnum = num - 1;
    while (min < max)
    {
        midnum = (min + maxnum) / 2;
        printf("第%d次查找%d\n", i + 1, data[midnum]);
        if (x < data[midnum])
            maxnum = midnum - 1;
        if (x > data[midnum])
            min = midnum + 1;
        if (x == data[midnum])
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int zhishu(int num)
{
    int i;
    while (1)
    {
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                break;
            }
        }
        if (num == i)
        {
            return num;
        }
        num++;
    }
}
void creat_haxi(int data[], int num)
{
    haxi_num = zhishu(num+1);
    int i;
    for (i = 0; i < haxi_num; i++)
    {
        haxi_array[i] = -1;
    }
    for (i = 0; i < num; i++)
    {
        int n;
        n = data[i] % haxi_num;
        while (haxi_array[n] != -1)
        {
            n = (n + offset) % haxi_num;
        }
        haxi_array[n] = data[i];
    }
}

int haxi(int x)
{
    int n,count=0;
    n = x % haxi_num;
    while (count<haxi_num)
    {
        printf("第%d次查找%d\n", count + 1, haxi_array[n]);
        if (haxi_array[n] == x)
        {
            return 1;
        }
        n = (n + offset) % haxi_num;
        count++;
    }
    return 0;
}