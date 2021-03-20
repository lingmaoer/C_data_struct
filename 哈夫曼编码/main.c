#define _CRT_SECURE_NO_WARNINGS
/*

2�����ʵ�ֹ�����������㷨��huffman
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50
int count; //ͳ�Ƹ���

typedef struct tree
{
    int weight; // Ȩ��
    char data;
    //char expression[size]; //���ʽ
    struct tree* lchild, * rchild;
}Tree;

void creat(Tree tr[]);
Tree find_min(Tree tr[]);
void insert(Tree tr[], Tree tree);
Tree huffman(Tree tr[]);
void preorder(Tree* root);

int main()
{
    Tree set[size], tr; //��������
    creat(set);         //����������
    tr = huffman(set);  //��������
    preorder(&tr);      //����
}

void creat(Tree tr[])
{
    printf("�������ݸ���");
    scanf("%d", &count);
    getchar();
    int i; //����
    for (i = 0; i < count; i++)
    {
        scanf("%c", &tr[i].data);    //Ҫ��д���ַ�
        scanf("%d", &tr[i].weight); //�ַ��ĸ���/Ȩ��
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
    Tree tr1, tr2; //����������Сֵ
    Tree temp;
    while (tr[1].weight != -1) //�ж϶������Ƿ�Ϊ��
    {
        tr1 = find_min(tr); //����Сֵ
        tr2 = find_min(tr); //����Сֵ
        temp.weight = tr1.weight + tr2.weight;
        temp.data = '\t';            //�����ַ�

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
{ //�ݹ�ʵ�ֵ��������
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
