#include <stdio.h>

int mat[1000][1000];
int node, edge;

int main()
{
	printf("Node 개수, Edge 개수 입력 : ");
	scanf("%d, %d", &node, &edge);

	for (int i = 0; i < edge; i++)
	{
		int x, y;
		printf("연결된 Node, Node 입력 : ");
		scanf("%d, %d", &x, &y);
		//서로 이어져 있는지 상태를 입력 받는다.
		
		mat[x][y] = 1;
		mat[y][x] = 1;
		//방향성이 없기 때문에 서로 이어져 있음을 1로 표시한다.
	}
	printf("\nAdjecent Matrix\n");
	for (int i = 0; i < node; i++)
	{
		for (int j = 0; j < node; j++)
			printf("%d", mat[i + 1][j + 1]);
		printf("\n");
	}
	return 0;
}