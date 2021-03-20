// �ݹ齨�����������ݹ������������ͺ�������Ľ����
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
//#include<iostream.h>
#define MAXSIZE 100
typedef char elemtype;
typedef struct bitree

{
    elemtype data;
    struct bitree *lchild, *rchild;
} BTREE;

BTREE *create()
{ //����ݹ鴴��������
    char ch;
    BTREE *bt;
    ch = getchar();
    if (ch == '#')
        bt = NULL;
    else
    
    {
        bt = (BTREE *)malloc(sizeof(BTREE));
        bt->data = ch;
        bt->lchild = create(); //�ݹ鴴��������
        bt->rchild = create(); //�ݹ鴴��������
    }
    return (bt);
}

void preorder(BTREE *root)
{ //�ݹ�ʵ�ֵ��������
    BTREE *p;
    p = root;
    if (p != NULL)
    {
        printf("%c",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(BTREE *root)
{ //�ݹ�ʵ�ֵ��������
    BTREE *p;
    p = root;
    if (p != NULL)
    {
        inorder(p->lchild);
        printf("%c",p->data);
        inorder(p->rchild);
    }
}

void postorder(BTREE *root)
{ //�ݹ�ʵ�ֵĺ������
    BTREE *p;
    p = root;
    if (p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%c",p->data);

    }
}

void lorder(BTREE *root)
{                          //�ǵݹ�ʵ�ֵĲ�α���
    BTREE *q[MAXSIZE], *p; // maxsizeΪ�������
    int f, r;              // f,r������ͷβָ��
    q[1] = root;
    f = r = 1;
    while (f <= r)
    {
        p = q[f];
        f++; //����
        printf("%c", p->data);
        if (p->lchild != NULL)
        {
            r++;
            q[r] = p->lchild;
        } //���
        if (p->rchild != NULL)
        {
            r++;
            q[r] = p->rchild;
        } //���
    }
}

void showmenu()
{ //��ʾ�˵�
    printf("    ��ӭʹ�ö�����������ʾ���\n");
    printf("\t1������������\n");
    printf("\t2���������������\n");
    printf("\t3���������������\n");
    printf("\t4���������������\n");
    printf("\t5����α���������\n");
    printf("\t6���˳�����\n");
}

void main()
{
    BTREE *root = NULL;
    int no;
    while (1)
    {
        showmenu();
        printf("   ���������ѡ��");
        scanf("%d", &no);
        fflush(stdin); //������̻�����
        switch (no)
        {
        case 1:
            printf("�밴������������������Ľ�㣬\n");
            printf("�ս����#�ű�ʾ.\n");
            root = create();
            printf("�����������ɹ����������������\n");
            getch();
            system("cls"); 
            break;
        case 2:
            printf("����������������Ϊ��\n");
            preorder(root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("����������������Ϊ��\n");
            inorder(root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            printf("����������������Ϊ��\n");
            postorder(root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 5:
            printf("��������α������Ϊ��\n");
            lorder(root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 6:
            return;
        default:
            printf("�������������������룡\n");
            system("pause");
            system("cls");
        }
    }
}
