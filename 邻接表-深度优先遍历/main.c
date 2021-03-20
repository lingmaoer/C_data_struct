//��һ��ͼ�����ڽӱ�洢�����ڸô洢�����Ͻ���������ȱ�����
//����˼��
//�û�����������������ߣ��ٽ���ת���ڽ�����
//Ȼ��Բ����ڽӱ��ʾ��ͼ����������ȱ�����

#include <stdio.h>
#include <stdlib.h>
#define vertexnum 100 //������������Ľ�����
typedef struct node   //����ͼ�εĶ���ṹ
{
    int vertex; //ͼ�еĶ�����ϢΪ����

    struct node *next;
} Graph;
Graph head[vertexnum];  //�ڽӱ�ı�ͷ���
int Visited[vertexnum]; //������¼

void Create_l_Graph(int Vertex1, int Vertex2, int no)
{                   //���ڽ�������ͼ��
    Graph *searchP; //�������
    Graph *New;     //�½������
    New = (Graph *)malloc(sizeof(struct node));
    if (New != NULL)
    {
        New->vertex = Vertex2;
        New->next = NULL;
        searchP = &(head[Vertex1]);
        while (searchP->next != NULL)
            searchP = searchP->next;
        searchP->next = New;
        if (no == 0)
        {
            New = (Graph *)malloc(sizeof(struct node));
            New->vertex = Vertex1;
            New->next = NULL;
            searchP = &(head[Vertex2]);
            while (searchP->next != NULL)
                searchP = searchP->next;
            searchP->next = New;
        }
    }
}

void showmenu()
{ //��ʾ�˵�
    printf("    ��ӭʹ��ͼ�Ĳ�����ʾ���\n");
    printf("\t1������ͼ���ڽӱ�\n");
    printf("\t2��ͼ�����\n");
    printf("\t3��ͼ��������ȱ���\n");
    printf("\t4���˳�����\n");
}

void print_l_graph(Graph *head)
{ //����ڽ����������
    Graph *searchP;
    searchP = head->next;
    while (searchP != NULL)
    {
        printf("%d\t", searchP->vertex);
        searchP = searchP->next;
    }
    printf("\n");
}

void DFS(int vertex)
{                        //������ȱ���
    Graph *SearchP;      //�������
    Visited[vertex] = 1; //���ĳ������ѱ�����
    printf("[%d]==>", vertex);
    SearchP = head[vertex].next;
    while (SearchP != NULL)
    {
        if (Visited[SearchP->vertex] != 1) //�жϽ��δ��������
            DFS(SearchP->vertex);          //�ݹ����������ȱ�������
        SearchP = SearchP->next;           //��һ���ڽӵ�
    }
}

void main()
{
    int source;      //ͼ��һ���ߵ���ʼ����
    int destination; //ͼ��һ���ߵ���ֹ����
    int i, j;
    int vermax;  //����ͼ�����Ķ�����
    int edgemax; //����ͼ�����ı���
    int choice;
    int no;

    while (1)
    {
        showmenu();
        printf("   ���������ѡ��");
        scanf("%d", &choice);
        fflush(stdin); //������̻�����
        switch (choice)
        {
        case 1:
            printf("������ͼ���������ͼ-1������ͼ-0��:");
            scanf("%d", &no);
            printf("������ͼ�е��ܶ������ͱ���:");
            scanf("%d%d", &vermax, &edgemax);
            for (i = 1; i < vermax; i++)
            {
                head[i].vertex = i;
                head[i].next = NULL;
            }
            for (i = 1; i <= edgemax; i++)
            {
                printf("�������%d���ߵ���㣺", i);
                scanf("%d", &source);
                printf("�������%d���ߵ��յ㣺", i);
                scanf("%d", &destination);
                if (source == destination)
                    printf("��������\n"); //��������ѭ��
                else                        //���ý����ڽ�����
                    Create_l_Graph(source, destination, no);
            }
            printf("ͼ�����ɹ����������������\n");
            getch();
            system("cls");
            break;
        case 2:
            printf("ͼ���ڽӱ����£�\n");
            for (i = 1; i <= vermax; i++)
            {
                printf("����[%d]:", i);
                print_l_graph(&head[i]); //��������ڽ���������
            }
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            for (i = 1; i <= vermax; i++)
                Visited[i] = 0;
            printf("��������������:");
            scanf("%d", &source);
            printf("ͼ��������ȱ������Ϊ��\n");
            DFS(source);
            printf("END\n");
            system("pause");
            system("cls");
            break;
        case 4:
            return;
        default:
            printf("�������������������룡\n");
            system("pause");
            system("cls");
        }
    }
}
