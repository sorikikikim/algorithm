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

void print_tree(struct node *root_node)
{
	if (root_node != NULL)
	{
		print_tree(root_node->left_child);
		printf("%d\n", root_node->value);
		print_tree(root_node->right_child);
	}
}

struct node *insert_node(struct node *node, int value)
{
	if (node == NULL)
		return new_node(value);
	if (value < node->value)
	{
		node->left_child = insert_node(node->left_child, value);
		//printf("node %d : %10p,\t node->left_child = %10p, \t node->value = %d, \t node->right_child = %10p\n",
		//node->value, node, node->left_child, node->value, node->right_child);
	}
	else if (value > node->value)
	{
		node->right_child = insert_node(node->right_child, value);
		//printf("node %d : %10p,\t node->left_child = %10p, \t node->value = %d, \t node->right_child = %10p\n",
		//node->value, node, node->left_child, node->value, node->right_child);
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

	print_tree(root_node);

	return 0;
}