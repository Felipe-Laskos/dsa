#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  struct Node* left;
  struct Node* right;
  int data;
  int height;
} Node;

Node* createNode(int data) {
  Node* node = (Node*) malloc(sizeof(Node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;

  return node;
}

int height(Node* node) {
  if (node == NULL) return 0;
  return node->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

void updateHeight(Node* node) {
  node->height = 1 + max(height(node->left), height(node->right));
}

int getBalance(Node* node) {
  if (node == NULL) return 0;
  return height(node->left) - height(node->right);
}

Node* rotateRight(Node* y) {
  Node* x = y->left;
  Node* B = x->right;

  x->right = y;
  y->left = B;

  updateHeight(y);
  updateHeight(x);

  return x;
}

Node* rotateLeft(Node* x) {
  Node* y = x->right;
  Node* B = y->left;

  y->left = x;
  x->right = B;

  updateHeight(x);
  updateHeight(y);

  return y;
}

Node* insert(Node* node, int data) {
  if (node == NULL) return createNode(data);

  if(data < node->data) {
    node->left = insert(node->left, data);
  } else if (data > node->data) {
    node->right = insert(node->right, data);
  } else {
    return node;
  }

  updateHeight(node);

  int balance = getBalance(node);

  if(balance > 1 && getBalance(node->left) >= 0) {
    return rotateRight(node);
  }

  if(balance > 1 && getBalance(node->left) < 0) {
    node->left = rotateLeft(node->left);

    return rotateRight(node);
  }

  if(balance < -1 && getBalance(node->right) <= 0) {
    return rotateLeft(node);
  }

  if(balance < -1 && getBalance(node->right) > 0) {
    node->right = rotateRight(node->right);
    
    return rotateLeft(node);
  }

  return node;
}

int main(void) {
  Node* tree = NULL;

  tree = insert(tree, 1);
  tree = insert(tree, 2);
  tree = insert(tree, 3);
  tree = insert(tree, 4);
  tree = insert(tree, 5);
}
