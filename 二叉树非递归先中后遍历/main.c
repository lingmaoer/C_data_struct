//�ǵݹ齨�������������Էǵݹ鷽ʽ�ֱ������������ͺ�������Ľ����

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef char elemtype;
typedef struct bitree
{
    elemtype data;
    struct bitree *lchild, *rchild;
} BTREE;

BTREE *create()
{                               //�ǵݹ鴴��������
    BTREE *q[100];              //����q������Ϊ���д�Ŷ��������н�㣬100Ϊ�������
    BTREE *s;                   //���������еĽ��
    BTREE *root;                //��������ĸ�ָ��
    int front = 1, rear = 0, i; //������е�ͷ��βָ��
    char ch;                    //����data��ֵ
    root = NULL;
    for (i = 0; i < 100; i++)
        q[i] = NULL;
    printf("�밴�����������������еĽ��:\n");
    printf("�ս���Զ��Ŵ��棬��#�Ž���!\n");
    ch = getchar();
    while (ch != '#') //����ֵΪ#��,�㷨����
    {
        s = NULL;
        if (ch != ',') //�������ݲ�Ϊ����,��ʾ��Ϊ����,����Ϊ����
        {
            s = (BTREE *)malloc(sizeof(BTREE));
            s->data = ch;
            s->lchild = NULL;
            s->rchild = NULL;
        }
        rear++;
        q[rear] = s; //�½����������
        if (rear == 1)
            root = s;
        else
        {
            if ((s != NULL) && (q[front] != NULL))
            {
                if (rear % 2 == 0)
                    q[front]->lchild = s; //rearΪż��,sΪ˫������
                else
                    q[front]->rchild = s; //rearΪ����,sΪ˫���Һ���
            }
            if (rear % 2 == 1)
                front++; //����
        }
        ch = getchar();
    }
    return root;
}

void preorder(BTREE *root)
{ //�ǵݹ�ʵ�ֵ��������
    BTREE *p, *s1[100];      //s1ջ������н��
    int s2[100], top = 0, b; //s2ջ��Ž�ջ��־
    p = root;
    do
    {
        while (p != NULL)
        {
            s1[top] = p;
            s2[top++] = 0; //��һ�ν�ջ��־Ϊ0
            p = p->lchild;
        }
        if (top > 0)
        {
            b = s2[--top];
            p = s1[top];
            if (b == 0)
            {
                s1[top] = p;
                s2[top++] = 1; //�ڶ��ν�ջ��־Ϊ0
                p = p->rchild;
            }
            else
            {
                printf("%c", p->data);
                p = NULL;
            }
        }
    } while (top > 0);
}

void inorder(BTREE *root)
{ //�ǵݹ�ʵ�ֵ��������
}

void postorder(BTREE *root)
{                            //�ǵݹ�ʵ�ֵĺ������
    BTREE *p, *s1[100];      //s1ջ������н��
    int s2[100], top = 0, b; //s2ջ��Ž�ջ��־
    p = root;
    do
    {
        while (p != NULL)
        {
            s1[top] = p;
            s2[top++] = 0; //��һ�ν�ջ��־Ϊ0
            p = p->lchild;
        }
        if (top > 0)
        {
            b = s2[--top];
            p = s1[top];
            if (b == 0)
            {
                s1[top] = p;
                s2[top++] = 1; //�ڶ��ν�ջ��־Ϊ0
                p = p->rchild;
            }
            else
            {
                printf("%c", p->data);
                p = NULL;
            }
        }
    } while (top > 0);
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
    printf("    ��ӭʹ�ö�����������ʾС���\n");
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
            root = create();
            printf("�����������ɹ����������������\n");
            system("pause");           
            //getchar();
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
        }
    }
}
