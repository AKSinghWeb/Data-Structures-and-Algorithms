/* Binary Search Tree implementation in C  with following functions */

#include <stdio.h>
#include <stdlib.h>

// Structure of a node in a tree
typedef struct bstNode
{
	int data;
	struct bstNode *left;
	struct bstNode *right;
} bstNode;

// Function Prototypes
bstNode *Insert(bstNode *root, int value); // (1) Insert Function
int Search(bstNode *root, int value);	   // (2) Search Function
bstNode *Delete(bstNode *root, int value); // (3) Delete Function
int findNodeCount(bstNode *root);		   // (4) Find no. of nodes
int findHeight(bstNode *root);			   // (5) Height/Max Depth of BST
int findMin(bstNode *root);				   // (6) Find Minimun among nodes of BST
int findMax(bstNode *root);				   // (7) Find Minimun among nodes of BST
void inOrderTraverse(bstNode *root);	   // (8) Print Node values in In-Order
void preOrderTraverse(bstNode *root);	   // (9) Print Node values in Pre-Order
void postOrderTraverse(bstNode *root);	   // (10) Print Node values in Post-Order
void freeTree(bstNode *root);			   // Function to free dynamically allocatted memory

int main(void)
{
	bstNode *root = NULL;
	int choice = 0;
	int value;

	while (choice != 11)
	{
		printf("-----------------------------------------------------------------------------");
		printf("\nChoose for Queue between: \n");
		printf("(1) Insert\n(2) Search\n(3) Delete a Node from the BST\n(4) No. of Nodes\n(5) Height/Max Depth\n(6) Minimum value");
		printf("\n(7) Maximum Value\n(8) In Order Traverse\n(9)Pre Order Traverse\n(10) Post Order Traverse\n(11) Exit\n\n");
		printf("Enter your Choice: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			printf("Enter Value to Insert in the Binary Search Tree: ");
			scanf("%d", &value);
			root = Insert(root, value);
			break;
		case 2:
			printf("Enter Value to Search: ");
			scanf("%d", &value);
			Search(root, value) ? printf("\nValue %d found!\n", value)
								: printf("\nValue %d not found\n", value);
			break;
		case 3:
			printf("Enter node value to delete: ");
			scanf("%d", &value);
			Delete(root, value);
			break;
		case 4:
			printf("No. of nodes in the BST are: %d \n\n", findNodeCount(root));
			break;
		case 5:
			printf("Heigh/Maximum Depth of the BST is %d \n\n", findHeight(root));
			break;
		case 6:
			printf("Minimum value in the Tree is %d \n\n", findMin(root));
			printf("\n");
			break;
		case 7:
			printf("Maximum value in the Tree is %d \n\n", findMax(root));
			printf("\n");
			break;
		case 8:
			inOrderTraverse(root);
			printf("\n");
			break;
		case 9:
			preOrderTraverse(root);
			break;
		case 10:
			postOrderTraverse(root);
			break;
		case 11:
			break;
		default:
			printf("Invalid Choice\n");
			break;
		}
	}
	// Free Nodes Explicitly
	freeTree(root);
	return 0;
}

// Create and return a pointer of new node with data
bstNode *createNewNode(int value)
{
	bstNode *newNode = (bstNode *)malloc(sizeof(bstNode));

	newNode->data = value;
	newNode->left = newNode->right = NULL;

	return newNode;
}

// Recursive function that inserts a node depending on the value of data
bstNode *Insert(bstNode *root, int value)
{
	// Add node when root is empty
	if (root == NULL)
	{
		root = createNewNode(value);
	}
	else if (value <= root->data)
	{
		// If value is less than node value then Insert in left of the node
		root->left = Insert(root->left, value);
	}
	else if (value > root->data)
	{ // If value is greater than node value then Insert in right of the node
		root->right = Insert(root->right, value);
	}
	return root;
}

// Search for an item in the tree
int Search(bstNode *root, int value)
{
	// If tree is empty return false
	if (root == NULL)
	{
		return 0;
	}
	// If value to be Searched is less than root value, then
	// search on left of root  using left node as new root
	else if (value < root->data)
	{
		return Search(root->left, value);
	}
	// If value to be Searched is greater than root value, then
	// search on right of root  using right node as new root
	else if (value > root->data)
	{
		return Search(root->right, value);
	}
	// If value is equal to root data, then the value is found
	else if (value == root->data)
	{
		return 1;
	}
}

// Function to delete a node
bstNode *Delete(bstNode *root, int value)
{
	if (root == NULL)
	{
		return root;
	}
	else if (value < root->data) // If data to be deleted is less than root, then Search in left sub-tree and delete
	{
		root->left = Delete(root->left, value);
	}
	else if (value > root->data) // If data to be deleted is greater than root, then Search in right sub-tree and delete
	{
		root->right = Delete(root->right, value);
	}
	else // Item to be deleted
	{
		// When children nodes are present
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		// When only one children is present(right child)
		else if (root->left == NULL)
		{
			bstNode *temp = root;
			root = root->right;
			free(temp);
		}
		// When only one children is present(left child)
		else if (root->right == NULL)
		{
			bstNode *temp = root;
			root = root->left;
			free(temp);
		}
		// When both children are present
		else
		{
			root->data = findMin(root->right);			   // Make root data, minimum of right sub tree as doing so, right sub-tree
			root->right = Delete(root->right, root->data); // will always be greater than root data, then delete minimum value from
		}												   // right sub-tree
	}
	return root;
}

// Function to return no. of nodes in the BST
int findNodeCount(bstNode *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return (findNodeCount(root->left) + (findNodeCount(root->right)) + 1);
}

// Finding height of the tree
int findHeight(bstNode *root)
{
	if (root == NULL)
	{
		return -1;
	}
	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);

	if (leftHeight > rightHeight)
	{
		return (leftHeight + 1);
	}
	else
	{
		return (rightHeight + 1);
	}
}

// Find manimum element using recursion
int findMin(bstNode *root)
{
	if (root == NULL)
	{
		printf("Error: Empty Tree!\n");
		return -1;
	}
	else if (root->left == NULL)
	{
		return root->data;
	}

	return findMin(root->left);
}

// Find maximum element using recursion
int findMax(bstNode *root)
{
	if (root == NULL)
	{
		printf("Error: Empty Tree!\n");
		return -1;
	}
	else if (root->right == NULL)
	{
		return root->data;
	}

	return findMax(root->right);
}

// Traverse tree in In-Order
void inOrderTraverse(bstNode *root)
{
	if (root == NULL)
	{
		return;
	}

	inOrderTraverse(root->left);  //First print left of root
	printf("\t%d", root->data);	  // then print root data
	inOrderTraverse(root->right); // then right of root
}

// Traverse tree in Pre-Order
void preOrderTraverse(bstNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("\t%d", root->data);	   // First print root data
	preOrderTraverse(root->left);  // then left of root
	preOrderTraverse(root->right); // then right of root
}

// Traverse tree in Post-Order
void postOrderTraverse(bstNode *root)
{
	if (root == NULL)
	{
		return;
	}

	postOrderTraverse(root->left);	//First print left of root
	postOrderTraverse(root->right); // then right of root
	printf("\t%d", root->data);		// then print root data
}

// Free dynamically created nodes from heap
void freeTree(bstNode *root)
{
	if (root != NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}
