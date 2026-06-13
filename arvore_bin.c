#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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

int search(Node* node, int num) {
  if(node == NULL) return 0;

  if(node->data == num) return 1;

  if(num >= node->data) return search(node->right, num);

  return search(node->left, num);
}

Node* removeNodeHelper(Node* node, int num, int* removed) {
  if(node == NULL) return NULL;

  if(num < node->data) {
    node->left = removeNodeHelper(node->left, num, removed);
  } else if(num > node->data) {
    node->right = removeNodeHelper(node->right, num, removed);
  } else {
    *removed = 1;

    if(node->left == NULL) {
      Node* child = node->right;
      free(node);
      return child;
    }
    if(node->right == NULL) {
      Node* child = node->left;
      free(node);
      return child;
    }

    Node* successor = node->right;
    while(successor->left != NULL) {
      successor = successor->left;
    }

    node->data = successor->data;
    node->right = removeNodeHelper(node->right, successor->data, removed);
  }

  return node;
}

int removeNode(Tree* t, int num) {
  int removed = 0;
  t->root = removeNodeHelper(t->root, num, &removed);
  return removed;
}

void inorder(Node* node) {
  if(node == NULL) return;
  inorder(node->left);
  printf("%d ", node->data);
  inorder(node->right);
}

int main(void) {

    Tree t;

    initialize(&t);

    insert(&t, 5);
    insert(&t, 7);
    insert(&t, 2);
    insert(&t, 6);

    removeNode(&t, 5);

    return 0;
}
