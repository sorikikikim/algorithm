#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 50

typedef struct GraphNode
{
	int vertex; //정점을 나타내는 데이터 필드
	struct GraphNode *link; //다음 인접 정점을 연결하는 링크필드
} GraphNode;

typedef struct GraphType
{
	int n; //그래프의 정점의 개수
	GraphNode *adj_list[MAX_VERTEX]; //그래프 정점에 대한 헤드노드
} GraphType;

void init_graph(GraphType *g)
{
	g->n = 0; //그래프 정점의 개수 0으로 초기화
	for (int i = 0; i < MAX_VERTEX; i++)
		g->adj_list[i] = NULL; //그래프 정점에 대한 헤드 노드의 배열을 NULL로 초기화
}

void insert_vertex(GraphType *g, int v) //그래프에 정점 v를 삽입하는 연산
{
	printf("g = %p, v = %d\n", g, v);
	if (((g->n) + 1) > MAX_VERTEX)
	{//그래프에 정점을 삽입했을 때 최대 사이즈보다 크다면 오류 출력
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return ;
	}
	g->n++;
}

void insert_edge(GraphType *g, int i, int j) //그래프에 간선(i, j)을 삽입하는 연산
{
	GraphNode *node;
	if (i >= g->n || j >= g->n)
	{ //정점 i, j의 번호가 그래프의 정점 개수보다 크다면 오류 문구를 출력
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return ;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode)); //간선을 나타내는 노드를 생성
	node->vertex = j;
	node->link = g->adj_list[i];
	g->adj_list[i] = node;
	//정점 i의 인접리스트에 node를 삽입
	//위치는 상관이 없으므로 연결리스트의 맨 처음에 삽입
}

void print_adj_list(GraphType *g) //각 정점에 대한 인접리스트를 하나씩 출력
{ 
	for (int i = 0; i < g->n ; i++) //정점의 개수까지 반복
	{
		GraphNode *p = g->adj_list[i]; 
		printf("정점 %d의 인접 리스트", i);
		while (p != NULL)
		{
			printf("-> %d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int main()
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));

	init_graph(g);
	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 0, 5);

	insert_edge(g, 1, 0);
	insert_edge(g, 1, 2);

	insert_edge(g, 2, 0);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 5);

	insert_edge(g, 3, 0);
	insert_edge(g, 3, 4);

	insert_edge(g, 4, 3);

	insert_edge(g, 5, 0);
	insert_edge(g, 5, 2);

	print_adj_list(g);
	free(g);
	
	return 0;
}
