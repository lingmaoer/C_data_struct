#include<stdio.h>

#define INFINITY 9999
#define MAX 10
int CreateAMGraph(int G[][]);
void dijikstra(int G[MAX][MAX], int n, int startnode);

int main() {
    int G[MAX][MAX], i, j, n, u;

    n=CreateAMGraph(G);
    printf("\n输入开始节点");
    scanf("%d", &u);
    dijikstra(G, n, u);
}

int CreateAMGraph(int G[MAX][MAX])
{
    int dingdian,bianshu;
    int i, j, u,v,w;
    printf("请输入顶点数：");
    scanf("%d", &dingdian);
    printf("请输入边数:");
    scanf("%d", &bianshu);
    printf("请输入顶点信息:");
    for (i = 0; i < bianshu; i++) //初始化邻接矩阵为无穷大
        for (j = 0; j < bianshu; j++)
            G[i][j] = INFINITY;
    printf("请输入每条边依附的两个顶点及权值：\n");
    while (bianshu--)
    {
        scanf(" %d %d %d", &u, &v, &w);
        if (u != -1 && v != -1)
            G[u][v] = w; //有向图邻接矩阵
        else
        {
            printf("输入顶点信息错！请重新输入！");
            bianshu++; //本次输入不算
        }
    }
    return dingdian;
}

void dijikstra(int G[MAX][MAX], int n, int startnode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];

    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1) {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != startnode) {
            printf("\nDistance of %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            do {
                j = pred[j];
                printf(" <-%d", j);
            } while (j != startnode);
        }
    printf("\n");
}