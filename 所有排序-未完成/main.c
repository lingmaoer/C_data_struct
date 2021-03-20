//���һ��С����ʵ�����������㷨��������ʾ���̡�
#include <stdio.h>
#include <time.h>
#define max 50

void show();
void produce_data(int data[], int num);
void zhi_jie_cha_ru(int data[], int num);
void print(const int data[], int num);
void xi_er(int data[],int num);
void jian_dan_xuan_ze(int data[],int num);

int main()
{
    int data[max];
    int n, i, chioce;
    printf("�����������Ŀ:");
    scanf("%d", &n);
    produce_data(data, n);
    print(data, n);
    while (1)
    {
        show();
        printf("�������ѡ��:");
        scanf("%d", &chioce);
        switch (chioce)
        {
        case 1:
            zhi_jie_cha_ru(data, n);
            break;
        case 3:
            jian_dan_xuan_ze(data, n);
            break;
        case 4:
            mao_pao(data,n);
            break;
        case 9:
            printf("��ӭ�´�ʹ��\n");
            return 0;
        default:
            printf("ѡ�����\n");
        }
    }
}

void show()
{
    printf("\t\t1.ֱ�Ӳ�������\n");
    printf("\t\t2.ϣ������\n");
    printf("\t\t3.��ѡ������\n");
    printf("\t\t4.ð������\n");
    printf("\t\t5.��������\n");
    printf("\t\t6.������\n");
    printf("\t\t7.�鲢����\n");
    printf("\t\t8.��������\n");
    printf("\t\t9.�˳�\n");
}

void produce_data(int data[], int num) //�������һ����
{
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < num; i++)
        data[i] = rand() % 100;
}

void zhi_jie_cha_ru(int data[], int num)
{
    int i,j,temp;
    for(i=1;i<num;i++)
    {
        temp=data[i];
        for(j=i-1;j>=0&&temp<data[j];j--)
        {
            data[j+1]=data[j];
        }
        data[j+1]=temp;
        printf("��%d������\t", i + 1);
        print(data, num);
    }
}

void print(const int data[], int num)
{
    int i = 0;
    for (; i < num; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void xi_er(int data[],int num)
{

}

void jian_dan_xuan_ze(int data[],int num)
{
    int t, i, j, k,temp;
    for (i = 0; i < num ; i++)
    {
        t = i;
        for (j = i + 1; j < num; j++)
        {
            if (data[t] > data[j])
            {
                t = j;
            }
        }
        temp = data[t];
        data[t] = data[i];
        data[i] = temp;
        printf("��%d������\t", i + 1);
        print(data, num);
    }
}

void mao_pao(int data[], int num)
{
    int i, j,temp;
    for (i = 1; i <= num-1; i++)
    {
        for (j = 1; j <= num-i; j++)
        {
            if (data[j - 1] > data[j])
            {
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            }
        }
        printf("��%d������\t", i);
        print(data, num);
    }
}