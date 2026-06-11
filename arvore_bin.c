#include <stddef.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* right;
    struct Node* left;
    int data;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

void initialize(Tree* t) {
    t->root = NULL;
}

Node* createNode(int data) {
  Node *node = (Node *) malloc(sizeof(Node));

  node->data = data;
  node->right = NULL;
  node->left = NULL;

  return node;
}

void insert_helper(Node* node, Node* newNode) {
  if(newNode->data >= node->data && node->right == NULL) {
    node->right = newNode;
  } else if (newNode->data >= node->data) {
    insert_helper(node->right, newNode);
  } else if (node->left == NULL) {
    node->left = newNode;
  } else {
    insert_helper(node->left, newNode);
  }
}

void insert(Tree* t, int num) {
  Node *node = createNode(num);

  if(t->root == NULL) {
    t->root = node;
    return; 
  }

  insert_helper(t->root, node); 
}

int main(void) {

    Tree t; 

    initialize(&t);

    insert(&t, 5);
    insert(&t, 7);
    insert(&t, 2);
    insert(&t, 9);
    insert(&t, 3);
    insert(&t, 1);
    insert(&t, 8);

    return 0;
}
