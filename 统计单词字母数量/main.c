/*
    ͳ���ı��ļ�������Ϣ����������������
�ı��ļ������ȴ�������ģ�Ӣ�ģ��Լ����ֱ����ţ��Ա�д����ͳ�������ַ����������ո񣩣�
�ո���������ĸ���������ָ����������Ÿ��������ָ����������ֱ�㣩�����ʸ����������Ͷ�������
*/
//  #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define strsize 100
#define filename "readme.txt"

typedef struct c_list cl;
typedef struct s_list sl;
typedef struct w_list wl;
cl* creat_clist();//�����޲���ͷ�ڵ�
sl* creat_slist();
wl* creat_wlist();
void c_node(cl* head, char c);//�������ݽڵ�
void s_node(sl* head, char* c);
void w_node(wl* head, char c[]);
void w_file();
void r_file(cl* chead, sl* shead, wl* whead);//���ļ�
int c_isexist(cl* chead, char c);//�ַ��Ƿ����
int s_isexist(sl* shead, char c[2]);//�����Ƿ����
int w_isexist(wl* chead, char c[]);//�����Ƿ����
void c_show(cl* chead);//��ʾ����
void s_show(sl* shead);
void w_show(wl* shead);

struct c_list
{
    char c;
    int count;
    cl* next;
};
struct s_list
{
    char s[3];
    int count;
    sl* next;
};
struct w_list
{
    char s[50];
    int count;
    wl* next;
};

int main()
{
    cl* chead = creat_clist();
    sl* shead = creat_slist();
    wl* whead = creat_wlist();
    //w_file();
    r_file(chead, shead, whead);
    c_show(chead);
    s_show(shead);
    w_show(whead);
    return 0;
}

cl* creat_clist()
{
    cl* q;
    q = (cl*)malloc(sizeof(cl));
    q->next = NULL;
    return q;
}
sl* creat_slist()
{
    sl* q;
    q = (sl*)malloc(sizeof(sl));
    q->next = NULL;
    return q;
}
wl* creat_wlist()
{
    wl* q;
    q = (wl*)malloc(sizeof(wl));
    q->next = NULL;
    return q;
}
void c_node(cl* head, char c)
{
    cl* q = head, * p;
    p = (cl*)malloc(sizeof(cl));
    p->c = c;
    p->count = 1;
    p->next = NULL;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
}
void s_node(sl* head, char* c)
{
    sl* q = head, * p;
    p = (sl*)malloc(sizeof(sl));
    p->s[0] = *c;
    c++;
    p->s[1] = *c;
    c++;
    p->s[2] = *c;
    p->count = 1;
    p->next = NULL;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
}
void w_node(wl* head, char c[])
{
    wl* q = head, * p;
    //int i = 0;
    p = (wl*)malloc(sizeof(wl));
    strcpy(p->s, c);
    p->count = 1;
    p->next = NULL;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
}

void r_file(cl* chead, sl* shead, wl* whead)
{
    char str[3];
    char s[50];
    char c;
    int i = 0;
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(0);
    }

    while (!feof(fp))
    {
        c = fgetc(fp);
        if (feof(fp))
        {
            s[i] = '\0';
            if (s[0] != '\0')
            {
                if (w_isexist(whead, s) != 1)
                    w_node(whead, s);
            }
            i = 0;
            continue;
        }
        if (c < 0)
        {
            str[0] = c;
            c = fgetc(fp);
            str[1] = c;
            str[2] = '\0';
            if (s_isexist(shead, str) != 1)
                s_node(shead, str);
            s[i] = '\0';
            if (s[0] != '\0')
            {
                if (w_isexist(whead, s) != 1)
                    w_node(whead, s);
            }
            i = 0;
        }
        else
        {
            if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
            {
                s[i++] = c;
            }
            else
            {
                s[i] = '\0';
                if (s[0] != '\0')
                {
                    if (w_isexist(whead, s) != 1)
                        w_node(whead, s);
                }
                i = 0;
            }
            if (c_isexist(chead, c) != 1)
                c_node(chead, c);
        }
    }
    fclose(fp);
}

int c_isexist(cl* chead, char c)
{
    cl* q = chead->next;
    int flag = 0;
    while (q != NULL)
    {
        if (q->c == c)
        {
            q->count++;
            flag = 1;
            break;
        }
        q = q->next;
    }
    return flag;
}
int s_isexist(sl* shead, char c[2])
{
    sl* q = shead->next;
    int flag = 0;
    while (q != NULL)
    {
        if (q->s[0] == c[0] && q->s[1] == c[1])
        {
            q->count++;
            flag = 1;
            break;
        }
        q = q->next;
    }
    return flag;
}
int w_isexist(wl* whead, char c[])
{
    wl* q = whead->next;
    int flag = 0;
    while (q != NULL)
    {
        if (strcmp(q->s, c) == 0)
        {
            flag = 1;
            q->count++;
            break;
        }
        q = q->next;
    }
    return flag;
}

void c_show(cl* chead)
{
    cl* q = chead->next;
    while (q != NULL)
    {
        if (q->c == ' ')
        {
            printf("�ո�%d\t\t", q->count);
            q = q->next;
            continue;
        }
        if (q->c == '\n')
        {
            printf("���䣺%d\t\t", q->count + 1);
            q = q->next;
            continue;
        }
        if (q->c == '\t')
        {
            printf("������%d\t\t", q->count);
            q = q->next;
            continue;
        }
        printf("%c��%d\t\t", q->c, q->count);
        q = q->next;
    }
}
void s_show(sl* shead)
{
    sl* q = shead;
    while (q->next != NULL)
    {
        q = q->next;
        printf("%s��%d\t\t", q->s, q->count);
    }
}
void w_show(wl* shead)
{
    wl* q = shead;
    while (q->next != NULL)
    {
        q = q->next;
        printf("%s��%d\t\t", q->s, q->count);
    }
}

void w_file()
{
    char str[200];
    printf("�������ı�����\n");
    gets(str);
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fputs(str, fp);
    fclose(fp);
    printf("д�����\n");
}