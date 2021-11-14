#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *left_child;
	struct node *right_child;
};

//typedef struct node {} node;
//->struct node = node

struct node *insert_node(struct node *root_node, int value)
{
	if (root_node == NULL)
	{
		root_node = (struct node *)malloc(sizeof(struct node));
		root_node->left_child = root_node->right_child = NULL;
		root_node->value = value;

		return root_node;
	}
	else
	{
		if (root_node->value > value)
			root_node->left_child = insert_node(root_node->left_child, value);
		else
			root_node->right_child = insert_node(root_node->right_child, value);
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

struct node *delete_node(struct node *root_node, int value)
{
	struct node *min_node;

	if (root_node == NULL)
		return NULL;
	//자식이 0인 경우
	if (root_node->value > value) 
		root_node->left_child = delete_node(root_node->left_child, value);
	else if (root_node->value < value)
		root_node->right_child = delete_node(root_node->right_child, value);
	else
	{
		//자식이 2인 경우
		if (root_node->right_child != NULL && root_node->left_child != NULL)
		{
			min_node = find_min_node(root_node->right_child);
			root_node->value = min_node->value;
			root_node->right_child = delete_node(root_node->right_child, min_node->value);
		}
		//자식이 1인 경우
		else
		{
			if (root_node->left_child == NULL)
				min_node = root_node->right_child;
			else
				min_node = root_node->left_child;
			//min_node = (root_node->left_child == NULL) ? root_node->right_child : root_node->left_child;
			free(root_node);
			return min_node;
		}
	}
	return root_node;
}

struct node *binary_search(struct node *root_node, int value)
{
	if (root_node == NULL)
		return NULL;
	if (root_node->value == value)
		return root_node;
	else if (root_node->value > value) //검색한 값이 루트노드 값보다 작은 경우
		return binary_search(root_node->left_child, value);
	else //검색한 값이 루트노드 값보다 큰 경우
		return binary_search(root_node->right_child, value);
}

void print_tree(struct node *root_node)
{
	if (root_node == NULL)
		return;
	else
	{
		printf("%d\n", root_node->value);
		print_tree(root_node->left_child);
		print_tree(root_node->right_child);
	}
}

int main()
{
	struct node *root_node;
	struct node *find_node;
	int delete;
	int value;

	root_node = NULL;
	root_node = insert_node(root_node, 5);
	insert_node(root_node, 3);
	insert_node(root_node, 7);
	insert_node(root_node, 1);
	insert_node(root_node, 9);
	insert_node(root_node, 6);
	print_tree(root_node);
	printf("\n");

	printf("삭제할 키 입력 : ");
	scanf("%d", &delete);
	delete_node(root_node, delete);
	print_tree(root_node);
	printf("\n");

	printf("찾고자 하는 키 입력 : ");
	scanf("%d", &value);
	printf("\n");

	find_node = binary_search(root_node, value);
	if (find_node == NULL)
		printf("%d not exist\n", value);
	else
		printf("찾은 노드의 값 : %d\n", find_node->value);
	print_tree(root_node);
}