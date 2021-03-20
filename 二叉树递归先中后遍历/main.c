// 递归建立二叉树，递归输出先序，中序和后序遍历的结果。
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
{ //先序递归创建二叉树
    char ch;
    BTREE *bt;
    ch = getchar();
    if (ch == '#')
        bt = NULL;
    else
    
    {
        bt = (BTREE *)malloc(sizeof(BTREE));
        bt->data = ch;
        bt->lchild = create(); //递归创建左子树
        bt->rchild = create(); //递归创建右子树
    }
    return (bt);
}

void preorder(BTREE *root)
{ //递归实现的先序遍历
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
{ //递归实现的中序遍历
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
{ //递归实现的后序遍历
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
{                          //非递归实现的层次遍历
    BTREE *q[MAXSIZE], *p; // maxsize为最大容量
    int f, r;              // f,r类似于头尾指针
    q[1] = root;
    f = r = 1;
    while (f <= r)
    {
        p = q[f];
        f++; //出队
        printf("%c", p->data);
        if (p->lchild != NULL)
        {
            r++;
            q[r] = p->lchild;
        } //入队
        if (p->rchild != NULL)
        {
            r++;
            q[r] = p->rchild;
        } //入队
    }
}

void showmenu()
{ //显示菜单
    printf("    欢迎使用二叉树操作演示软件\n");
    printf("\t1、创建二叉树\n");
    printf("\t2、先序遍历二叉树\n");
    printf("\t3、中序遍历二叉树\n");
    printf("\t4、后序遍历二叉树\n");
    printf("\t5、层次遍历二叉树\n");
    printf("\t6、退出程序\n");
}

void main()
{
    BTREE *root = NULL;
    int no;
    while (1)
    {
        showmenu();
        printf("   请输入你的选择：");
        scanf("%d", &no);
        fflush(stdin); //清除键盘缓冲区
        switch (no)
        {
        case 1:
            printf("请按先序依次输入二叉树的结点，\n");
            printf("空结点用#号表示.\n");
            root = create();
            printf("二叉树创建成功，按任意键继续…\n");
            getch();
            system("cls"); 
            break;
        case 2:
            printf("二叉树先序遍历结果为：\n");
            preorder(root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("二叉树中序遍历结果为：\n");
            inorder(root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            printf("二叉树后序遍历结果为：\n");
            postorder(root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 5:
            printf("二叉树层次遍历结果为：\n");
            lorder(root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 6:
            return;
        default:
            printf("你的输入有误，请从新输入！\n");
            system("pause");
            system("cls");
        }
    }
}
