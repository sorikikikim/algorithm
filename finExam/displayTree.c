#include <stdio.h>
#include <stdlib.h>

 /*
          100
          / 
         /  
        9     
   	   / \       
   	  /   \   
   	 5     10
			 \
			  \ 
			  25
			    \ 
				 \
				  86 
*/

struct node
{
	int value;
	struct node *left_child;
	struct node *right_child;
};

struct node *new_node(int value)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	printf("node %d : %10p,\t node->left_child = %10p, \t node->value = %d, \t node->right_child = %10p\n",
	temp->value, temp, temp->left_child, temp->value, temp->right_child);
	temp->value = value;
	temp->left_child = NULL;
	temp->right_child = NULL;

	return temp;
}

void display_preorder(struct node *binary_tree)
{
	if (binary_tree)
	{
		printf("%d ", binary_tree->value);
		display_preorder(binary_tree->left_child);
		display_preorder(binary_tree->right_child);
	}
}

void display_inorder(struct node *binary_tree)
{
	if (binary_tree)
	{
		display_inorder(binary_tree->left_child);
		printf("%d ", binary_tree->value);
		display_inorder(binary_tree->right_child);
	}
}

void display_postorder(struct node *binary_tree)
{
	if (binary_tree)
	{
		display_postorder(binary_tree->left_child);
		display_postorder(binary_tree->right_child);
		printf("%d ", binary_tree->value);
	}
}

struct node *insert_node(struct node *node, int value)
{
	if (node == NULL)
		return new_node(value);
	if (value < node->value)
	{
		node->left_child = insert_node(node->left_child, value);
		printf("node %d : %10p,\t node->left_child = %10p, \t node->value = %d, \t node->right_child = %10p\n",
		node->value, node, node->left_child, node->value, node->right_child);
	}
	else if (value > node->value)
	{
		node->right_child = insert_node(node->right_child, value);
		printf("node %d : %10p,\t node->left_child = %10p, \t node->value = %d, \t node->right_child = %10p\n",
		node->value, node, node->left_child, node->value, node->right_child);
	}	
	
	return node;
}

int main()
{
	printf("Binary Tree\n");
	struct node *root_node = NULL;
	root_node = insert_node(root_node, 100);
	insert_node(root_node, 100);
	insert_node(root_node, 9);
	insert_node(root_node, 5);
	insert_node(root_node, 10);
	insert_node(root_node, 25);
	insert_node(root_node, 86);

	//print_tree(root_node);

	//1. pre order : N L R
	printf("Pre Order\n");
	display_preorder(root_node);
	printf("\n");
	//100, 9, 5, 10, 25, 86

	//2. in order : L N R
	printf("In Order\n");
	display_inorder(root_node);
	printf("\n");
	//5, 9, 10, 25, 86, 100

	//3. post order : L R N
	printf("Post Order\n");
	display_postorder(root_node);
	printf("\n");
	//5, 86, 25, 10, 9, 100
	
	return 0;
}