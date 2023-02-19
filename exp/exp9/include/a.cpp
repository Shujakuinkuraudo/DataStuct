#include <stdio.h>
typedef char datatype;
const int maxD = 0x3f3f3f3f;
const int maxV = 1000;
typedef struct
{
    datatype vexs[maxV];
    int edges[maxV][maxV];
    int n;
} graph;
void dijkstra(int **dist_output, int **path_output, graph *G, int v)
{
    int *dist = new int[maxV], *path = new int[maxV];
    int visited[maxV];
    int i, j, k, pre, min_path, iter = 0;
    for (i = 1; i <= G->n; i++)
    {
        visited[i] = 0;
        dist[i] = G->edges[v][i];
        path[i] = v;
    }
    visited[v] = 1;
    dist[v] = 0;
    for (iter = 1; iter <= G->n; iter++)
        printf("           d[%d]", iter);
    for (iter = 1; iter <= G->n; iter++)
        printf("           p[%d]", iter);
    printf("\n");
    for (iter = 1; iter <= G->n; iter++)
        printf("%15d", dist[iter]);
    for (iter = 1; iter <= G->n; iter++)
        printf("%15d", path[iter]);
    for (i = 1; i < G->n; i++)
    {
        min_path = maxD;
        for (j = 1; j <= G->n; j++)
            if (!visited[j] && dist[j] < min_path && dist[j] > 0)
            {
                min_path = dist[j];
                k = j;
            }
        if (min_path == maxD)
            break;
        visited[k] = 1;
        for (j = 1; j <= G->n; j++)
            if (!visited[j] && dist[j] > dist[k] + G->edges[k][j])
            {
                dist[j] = dist[k] + G->edges[k][j];
                path[j] = k;
            }
        printf("\n");
        for (iter = 1; iter <= G->n; iter++)
            printf("%15d", dist[iter]);
        for (iter = 1; iter <= G->n; iter++)
            printf("%15d", path[iter]);
    }
    *dist_output = dist, *path_output = path;
}
void createGraph(graph *G)
{
    int i, j, k, w, E;
    printf("图的顶点数和边数:");
    scanf("%d%d", &(G->n), &E);
    printf("顶点信息:");
    getchar();
    for (i = 0; i < G->n; i++)
    {
        scanf("%c", &(G->vexs[i]));
        getchar();
    }
    for (i = 0; i <= G->n; i++)
        for (j = 0; j <= G->n; j++)
            G->edges[i][j] = maxD;
    for (i = 0; i <= G->n; i++)
        G->edges[i][i] = 0;
    for (k = 0; k < E; k++)
    {
        printf("%d边: 顶点序号i,j 边权w:", k + 1);
        scanf("%d %d %d", &i, &j, &w);
        G->edges[i][j] = w;
    }
}
void printPath(int *dist, int *path, graph *G, int v)
{
    printf("\n 顶点%c到:",G->vexs[v-1]);
    int pre;
    for (int i = 1; i <= G->n; i++)
    {
        if (i == v)
            continue;
        printf("\n顶点%c的最短距离为:%d 路径为:%c",  G->vexs[i - 1], dist[i], G->vexs[i - 1]);
        if (dist[i] == maxD)
            printf("无路径\n");
        else
        {

            pre = path[i];
            while (pre != v)
            {
                printf(" <- %c", G->vexs[pre - 1]);
                pre = path[pre];
            }
            printf(" <- %c", G->vexs[pre - 1]);
        }
    }
}
int main()
{
    int i, j, m;
    char k;
    graph G;
    createGraph(&G);
    printf("请选择从哪一顶点开始:\n");
    getchar();
    scanf("%c", &k);
    printf("邻接矩阵:\n");
    for (i = 1; i <= G.n; i++)
    {
        for (j = 1; j <= G.n; j++)
            printf("%15d", G.edges[i][j]);
        printf("\n");
    }
    for (i = 0; i < G.n; i++)
        if (G.vexs[i] == k)
            m = i;
    int *dist, *path;
    dijkstra(&dist, &path, &G, m + 1);
    printPath(dist, path, &G, m + 1);
    delete[] dist, path;
    return 0;
}
