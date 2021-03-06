#include "stdafx.h"
#include "stdlib.h"
#include "stack"
using namespace std;
#define MaxVertexNum 100
#define MAXSIZE 1024
int n,m;
int graph[MAXSIZE][MAXSIZE];
int visit[MAXSIZE];
int degree[1001];
int flag = 0;
typedef enum Type
{
	WAG,
	DAG
}Type;
typedef struct Edge
{
	Edge(int x, int y) :_x(x), _y(y) {}
	int _x;
	int _y;
}Edge;
stack<Edge> stackEdge;
void DFS(int s, int c)
{
	if (flag)
		return;
	if (c == n)
	{
		flag = 1;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] || graph[s][i] == 0)
			continue;
		visit[i] = 1;
		DFS(i, c + 1);
		visit[i] = 0;
	}
}
int check()
{
	for (int i = 1; i <= n; i++)
		if (degree[i] % 2)return 0;
	return 1;
}
int main()
{
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
		degree[a] ++;
		degree[b] ++;
	}
	visit[1] = 1;
	DFS(1, 1);
	if (flag&&check())printf("1");
	else printf("0");
}