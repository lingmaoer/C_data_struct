#define _CRT_SECURE_NO_WARNINGS
/*

2、编程实现哈夫曼编码的算法。huffman
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50
int count; //统计个数

typedef struct tree
{
    int weight; // 权重
    char data;
    //char expression[size]; //表达式
    struct tree* lchild, * rchild;
}Tree;

void creat(Tree tr[]);
Tree find_min(Tree tr[]);
void insert(Tree tr[], Tree tree);
Tree huffman(Tree tr[]);
void preorder(Tree* root);

int main()
{
    Tree set[size], tr; //创建空树
    creat(set);         //创建二叉树
    tr = huffman(set);  //哈夫曼树
    preorder(&tr);      //遍历
}

void creat(Tree tr[])
{
    printf("输入数据个数");
    scanf("%d", &count);
    getchar();
    int i; //计数
    for (i = 0; i < count; i++)
    {
        scanf("%c", &tr[i].data);    //要编写的字符
        scanf("%d", &tr[i].weight); //字符的个数/权重
        tr[i].lchild = NULL;
        tr[i].rchild = NULL;
    }
    for (; i < size; i++)
    {
        tr[i].data = -1;
        tr[i].weight = -1;
        tr[i].lchild = NULL;
        tr[i].rchild = NULL;
    }
}

Tree find_min(Tree tr[])
{
    int i = 0, j;
    Tree tr1;
    tr1 = tr[i];
    for (i = 1; i < count; i++)
    {
        if (tr1.weight > tr[i].weight)
        {
            tr1 = tr[i];
        }
    }
    for (i = 0; i < count; i++)
    {
        if (tr1.weight == tr[i].weight)
        {
            for (j = i; j < count; j++)
            {
                tr[j] = tr[j + 1];
            }
            break;
        }
    }
    count--;
    return tr1;
}

void insert(Tree tr[], Tree tree)
{
    tr[count] = tree;
    count++;
}
Tree huffman(Tree tr[])
{
    Tree tr1, tr2; //接收两个最小值
    Tree temp;
    while (tr[1].weight != -1) //判断二叉树是否为空
    {
        tr1 = find_min(tr); //找最小值
        tr2 = find_min(tr); //找最小值
        temp.weight = tr1.weight + tr2.weight;
        temp.data = '\t';            //区分字符

        temp.lchild = (Tree*)malloc(sizeof(Tree));
        *temp.lchild = tr1;

        temp.rchild = (Tree*)malloc(sizeof(Tree));
        *temp.rchild = tr2;
        insert(tr, temp);
    }
    temp = tr[0];
    return temp;
}
int i = 0;
char bianma[size] = "";
void preorder(Tree* root)
{ //递归实现的先序遍历
    Tree* p;
    p = root;
    if (p != NULL)
    {
        if (p->data != '\t')
            printf("%c:\t%s\n", p->data ,bianma);
        strcat(bianma, "0");
        i++;     
        preorder(p->lchild);
        i--;
        bianma[i] = '\0';
        strcat(bianma, "1");
        i++;
        preorder(p->rchild);
        i--;
        bianma[i] = '\0';
    }
}
