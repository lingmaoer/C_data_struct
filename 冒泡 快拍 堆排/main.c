#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
void bubbleSort(int *list, int index)
{ //利用冒泡排序算法，完成对数组list中的index个数进行排序。
    int i, j;
    int temp;
    for (i = 0; i <= index - 1; i++)
    {
        for (j = 0; j < index - i - 1; j++)
        {
            if (list[j] < list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void QuickSort(int *list, int left, int right, int index)
{ //利用快速排序算法，完成对数组list中的index个数进行排序。
    int i = left, j = right, t;
    int temp;
    if (left < right)
    {
        temp = list[left];
        while (i != j)
        {
            while (j > i && list[j] > temp)
                j--;
            if (i < j)
            {
                list[i] = list[j];
                i++;
            }
            while (i < j && list[i] < temp)
                i++;
            if (i < j)
            {
                list[j] = list[i];
                j--;
            }
        }
        list[i] = temp;
        for (t = 0; t < index; t++)
            printf("%d\t", *(list + t));
        printf("\n");
        QuickSort(list, left, i - 1, index);
        QuickSort(list, i + 1, right, index);
    }
}
void produce_data(int data[], int num) //随机产生一批数
{
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < num; i++)
        data[i] = rand() % 100;
}
void produce1_data(int data[], int num) //随机产生一批数
{                                       //专门用于堆排序，数据从data[1]开始存放
    int i;
    srand((unsigned)time(NULL));
    for (i = 1; i <= num; i++)
        data[i] = rand() % 100;
}
void print_data(int data[], int num) //输出数据
{
    int i;
    int count;
    for (i = 0; i < num; i++)
    {
        printf("%5d", data[i]);
        count++;
        if (count % 10 == 0)
            printf("\n");
    }
}
void print1_data(int data[], int num) //输出数据
{                                     //专门用于堆排序，数据从data[1]开始输出
    int i;
    int count;
    for (i = 1; i <= num; i++)
    {
        printf("%5d", data[i]);
        count++;
        if (count % 10 == 0)
            printf("\n");
    }
}
void createHeap(int *heap, int root, int index)
{
    int i, j;
    int temp;          //于数值交换时的暂存变量
    int finish;        //判断堆是否建立完成
    j = 2 * root;      //子结点的index
    temp = heap[root]; //暂存heap的root值
    finish = 0;        //默认堆建立尚未完成
    while (j <= index && finish == 0)
    {
        if (j < index)
            if (heap[j] < heap[j + 1])
                j++;
        if (temp >= heap[j])
            finish = 1; //堆建立完成
        else
        {
            heap[j / 2] = heap[j]; //父结点=目前结点
            j = 2 * j;
        }
    }
    heap[j / 2] = temp; //父结点=root值
}
void HeapSort(int *heap, int index)
{ //堆排序
    int i, j, temp;
    for (i = (index / 2); i >= 1; i--) //将二叉树转成heap
        createHeap(heap, i, index);
    for (i = index - 1; i >= 1; i--) //开始进行堆排序
    {
        temp = heap[i + 1]; //heap的root值和最后一个值交换
        heap[i + 1] = heap[1];
        heap[1] = temp;
        createHeap(heap, 1, i);    //对其余数值重建堆*/
        printf("\n目前的排序为:"); //打印堆处理过程*/
        for (j = 1; j <= index; j++)
            printf("%3d", heap[j]);
        //printf("\n");
    }
}
void showmenu()
{ //显示菜单
    printf("    欢迎使用数据排序小软件\n");
    printf("\t1、冒泡排序\n");
    printf("\t2、快速排序\n");
    printf("\t3、堆排序\n");
    printf("\t4、退出程序\n");
}
int main()
{
    int list[MAX]; //默认数组最大长度为20
    int i, num;    //数组索引/
    int node;      //读入输入值所使用的暂存变量
    int choice;
    while (1)
    {
        showmenu();
        printf("    请输入你的选择：");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("请输入需要排序的元素个数：");
            scanf("%d", &num);
            produce_data(list, num);
            printf("排序前的数据为:\n");
            print_data(list, num);
            bubbleSort(list, num);
            printf("\n最终的排序结果为:\n");
            print_data(list, num);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            printf("请输入需要排序的元素个数：");
            scanf("%d", &num);
            produce_data(list, num);
            printf("排序前的数据为:\n");
            print_data(list, num);
            printf("\n排序过程如下：\n");
            QuickSort(list, 0, num - 1, num);
            printf("\n最终的排序结果为:\n");
            print_data(list, num);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("请输入需要排序的元素个数：");
            scanf("%d", &num);
            produce1_data(list, num);
            printf("排序前的数据为:\n");
            print1_data(list, num);
            printf("\n排序过程如下：\n");
            HeapSort(list, num);
            printf("\n最终的排序结果为:\n");
            print1_data(list, num);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            return 0;
        default:
            printf("你的选择有误，请从新输入！\n");
        }
    }
}
