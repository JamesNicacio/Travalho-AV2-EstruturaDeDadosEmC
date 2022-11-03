#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

// Create a new Node
struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int main() {
  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
}














// // struct node {
// // 	int data;
// // 	struct node* left;
// // 	struct node* right;
// // };

// // /* newNode() allocates a new node
// // with the given data and NULL left
// // and right pointers. */
// // struct node* newNode(int data)
// // {
// // 	// Allocate memory for new node
// // 	struct node* node
// // 		= (struct node*)malloc(sizeof(struct node));

// // 	// Assign data to this node
// // 	node->data = data;

// // 	// Initialize left and
// // 	// right children as NULL
// // 	node->left = NULL;
// // 	node->right = NULL;
// // 	return (node);
// // }

// // int main()
// // {
// // 	/*create root*/
// // 	struct node* root = newNode(1);
// // 	/* following is the tree after above statement
// // 		1
// // 		/ \
// // 	NULL NULL
// // 	*/

// // 	root->left = newNode(2);
// // 	root->right = newNode(3);
// // 	/* 2 and 3 become left and right children of 1
// // 			1
// // 		/ \
// // 		2	 3
// // 	/ \ / \
// // NULL NULL NULL NULL
// // 	*/

// // 	root->left->left = newNode(4);
// // 	/* 4 becomes left child of 2
// // 			1
// // 		/ \
// // 		2	 3
// // 	/ \ / \
// // 	4 NULL NULL NULL
// // 	/ \
// // NULL NULL
// // 	*/

// // 	getchar();
// // 	return 0;
// // }








// typedef struct node {
//     int data;
//     struct node *left;
//     struct node *right;
// } node;

// node * build_node(int data) {
//     node* n = malloc(sizeof *n);
//     n->data = data;
//     n->right = NULL;
//     n->left = NULL;
//     return n;
// }

// node *build_subtree(int **a) {
//     if(**a == -1) return NULL;
//     node *n = build_node(**a);
//     (*a)++;
//     n->left = build_subtree(a);
//     (*a)++;
//     n->right = build_subtree(a);
//     return n;
// }

// node *build_tree(int *a) {
//     return build_subtree(&a);
// }

// void print_subtree(node *n, size_t level) {
//     if(!n) return;
//     level++;
//     print_subtree(n->right, level);
//     for(int i = 0; i < 3 * (level - 1); i++)
//         printf("%c", ' ');
//     printf("%d <\n", n->data);
//     print_subtree(n->left, level);
// }

// void print_tree(node *n) {
//     print_subtree(n, 0);
// }

// int main() {
//     node *root = build_tree(
//        (int []) {4, 2, 9, -1, -1, 8, -1, -1, 7, -1, -1}
//     );
//     print_tree(root);
// }