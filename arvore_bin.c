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

int removeNode(Tree* t, int num) {
  Node* parent = NULL;
  Node* aux = t->root;

  while(aux != NULL && aux->data != num) {
    parent = aux;

    if(num >= aux->data) aux = aux->right;
    else aux = aux->left;
  }

  if(aux == NULL) return 0;

  if(aux->left != NULL && aux->right != NULL) {
    Node* sucParent = aux;
    Node* sucessor = aux->right;

    while(sucessor->left != NULL) {
      sucParent = sucessor;
      sucessor = sucessor->left;
    }

    aux->data = sucessor->data;

    parent = sucParent;
    aux = sucessor;
  }

  Node* child = (aux->left != NULL) ? aux->left : aux->right;

  if(parent == NULL) {
    t->root = child;
  } else if(parent->left == aux) {
    parent->left = child;
  } else {
    parent->right = child;
  }

  free(aux);

  return 1;
}

int main(void) {

    Tree t;

    initialize(&t);

    insert(&t, 5);
    insert(&t, 7);
    insert(&t, 2);
    insert(&t, 6);
    insert(&t, 9);
    insert(&t, 3);
    insert(&t, 1);

    removeNode(&t, 7);

    return 0;
}
