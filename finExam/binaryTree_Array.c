#include <stdio.h>

/*

           D
          / \
         /   \
        /     \
       A       F
      / \     / \    
     /   \   /   \
    E     B R     T
   / \     /     / \
  G   Q   V     J   L
*/
//0번째 노드는 비워둠.
//1번(root node)부터 시작
//lever order 매우 중요!!
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};
int complete_node = 15;

int get_right_child(int index) {
	if (tree[index] != '\0' && ((2 * index) + 1) <= complete_node)
		return (2 * index) + 1;
	return -1;	
}

int get_left_child(int index)
{
    if(tree[index]!='\0' && (2 * index) <= complete_node)
        return 2 * index;
    return -1;
}

//부모노드 (int)i/2;
//루트노드 1;

int main(){
	int nodeIndex ,findRIndex, findLIndex;
	int size;

	size = sizeof(tree) / sizeof(tree[0]); //배열의 크기
	for (int i = 0; i < size; i++)
		printf("tree[%d] = %c\n", i, tree[i]);
	
	printf("node index : ");
	scanf("%d", &nodeIndex);

	findLIndex = get_left_child(nodeIndex);
	printf("tree[%d] = %c의 left child = %c\n", nodeIndex, tree[nodeIndex], tree[findLIndex]);

	findRIndex = get_right_child(nodeIndex);
	printf("tree[%d] = %c의 right child = %c\n", nodeIndex, tree[nodeIndex], tree[findRIndex]);

	return 0;
}