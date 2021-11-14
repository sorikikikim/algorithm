#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char value[100];
	struct node *left_child;
	struct node *right_child;
};

struct node *insert_node(struct node *root_node, char *value)
{
	int i;

	if (root_node == NULL)
	{
		root_node = (struct node *)malloc(sizeof(struct node));
		root_node->left_child = root_node->right_child = NULL;
		for (i = 0; i < strlen(value); i++)
			root_node->value[i] = value[i];
		root_node->value[i] = '\0';

		return root_node;
	}
	else
	{
		if (strcmp(root_node->value, value) > 0)
			root_node->left_child = insert_node(root_node->left_child, value);
		else if (strcmp(root_node->value, value) < 0)
			root_node->right_child = insert_node(root_node->right_child, value);
		else
			return NULL;
		return root_node;
	}
}

struct node *find_min_node(struct node *root_node)
{
	struct node *temp;

	temp = root_node;
	while (temp->left_child != NULL)
		temp = temp->left_child;
	return temp;
}

struct node *delete_node(struct node *root_node, char *value)
{
	struct node *min_node;

	if (root_node == NULL)
		return NULL;
	//자식이 0인 경우
	if (strcmp(root_node->value, value) > 0) 
		root_node->left_child = delete_node(root_node->left_child, value);
	else if (strcmp(root_node->value, value) < 0)
		root_node->right_child = delete_node(root_node->right_child, value);
	else
	{
		//자식이 2인 경우
		if (root_node->right_child != NULL && root_node->left_child != NULL)
		{
			min_node = find_min_node(root_node->right_child);
			strcpy(root_node->value, min_node->value);
			root_node->right_child = delete_node(root_node->right_child, min_node->value);
		}
		//자식이 1인 경우
		else
		{
			if (root_node->left_child == NULL)
				min_node = root_node->right_child;
			else
				min_node = root_node->left_child;
			free(root_node);
			return min_node;
		}
	}
	return root_node;
}

struct node *binary_search(struct node *root_node, char *value)
{
	if (root_node == NULL)
		return NULL;
	if (!strcmp(root_node->value, value))
		return root_node;
	else if (strcmp(root_node->value, value) > 0) //검색한 값이 루트노드 값보다 작은 경우
		return binary_search(root_node->left_child, value);
	else if (strcmp(root_node->value, value) < 0)//검색한 값이 루트노드 값보다 큰 경우
		return binary_search(root_node->right_child, value);
	else
		return NULL;
}

void print_in_order(struct node *root_node)
{
	if (root_node == NULL)
		return;
	else
	{
		print_in_order(root_node->left_child);
		printf("%s ", root_node->value);
		print_in_order(root_node->right_child);
	}
}

void print_pre_order(struct node *root_node)
{
	if (root_node == NULL)
		return;
	else
	{
		printf("%s ", root_node->value);
		print_pre_order(root_node->left_child);
		print_pre_order(root_node->right_child);
	}
}

void print_post_order(struct node *root_node)
{
	if (root_node == NULL)
		return;
	else
	{
		print_post_order(root_node->left_child);
		print_post_order(root_node->right_child);
		printf("%s ", root_node->value);
	}
}

int main()
{
	struct node *root_node;
	struct node *find_node;
	char delete[100];
	char value[100];

	root_node = NULL;
	//1. 문자열 노드 삽입(10개)
	root_node = insert_node(root_node, "imperceivable");
	insert_node(root_node, "demultiplex");
	insert_node(root_node, "eggplant");
	insert_node(root_node, "cyclotomic");
	insert_node(root_node, "gristmill");
	insert_node(root_node, "ketchup");
	insert_node(root_node, "barrier");
	insert_node(root_node, "futile");
	insert_node(root_node, "coconut");
	insert_node(root_node, "earthquake");

	//출력
	printf("1. In Order (중위순회)\n");
	print_in_order(root_node);
	printf("\n");
	printf("2. Pre Order (전위순회)\n");
	print_pre_order(root_node);
	printf("\n");
	printf("3. Post Order (후위순회)\n");
	print_post_order(root_node);
	printf("\n");

	//3. 문자열 노드 삭제 및 출력
	printf("\n삭제할 키 입력 : ");
	scanf("%s", delete);
	delete_node(root_node, delete);

	printf("1. In Order (중위순회)\n");
	print_in_order(root_node);
	printf("\n");
	printf("2. Pre Order (전위순회)\n");
	print_pre_order(root_node);
	printf("\n");
	printf("3. Post Order (후위순회)\n");
	print_post_order(root_node);
	printf("\n");

	//4. 문자열 노드 검색
	printf("\n찾고자 하는 키 입력 : ");
	scanf("%s", value);

	find_node = binary_search(root_node, value);
	if (find_node == NULL) //못찾은 경우
		printf("'%s'를 찾을 수 없습니다.\n", value);
	else //찾은 경우
		printf("찾은 노드의 값은 '%s' 입니다.\n", find_node->value);
	printf("\n");

	//5. 출력
	printf("1. In Order (중위순회)\n");
	print_in_order(root_node);
	printf("\n");
	printf("2. Pre Order (전위순회)\n");
	print_pre_order(root_node);
	printf("\n");
	printf("3. Post Order (후위순회)\n");
	print_post_order(root_node);
	printf("\n");
}