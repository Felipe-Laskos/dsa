#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int c;
  struct Node *prox;
} Node;

typedef struct Pilha {
  int qtd;
  Node *head;
} Pilha;


void inicializar(Pilha *p) {
  p->head = NULL;
  p->qtd = 0;
}


int desempilhar(Pilha *p) {
  Node *aux;

  aux = p->head;

  p->head = aux->prox;

  int c = aux->c;

  free(aux);

  return c;
}

int empilhar(Pilha *p, Node *no) {
  if(p->head == NULL) {
    p->head = no;
    return 1;
  }

  Node *aux = p->head;

  p->head = no;

  no->prox = aux;
  return 1;
}

Node* criarNo(int c) {
  Node *novo = (Node *) malloc(sizeof(Node));

  novo->c = c;
  novo->prox = NULL;

  return novo;
}

int calculaPosfix(char expressao[]) {
  Pilha p;

  inicializar(&p);

  int i = 0;

  while(expressao[i] != '\0') {
    if(expressao[i] >= '0' && expressao[i] <= '9') {
      int c = expressao[i] - '0';

      Node *n = criarNo(c);

      empilhar(&p, n);
    } else {
      int num_a = desempilhar(&p);
      int num_b = desempilhar(&p);

      int resultado;

      char operador = expressao[i];

      if(operador == '+') {
        resultado = num_a + num_b;
      }else if(operador == '-') {
        resultado = num_b - num_a;
      } else if (operador == '*') {
        resultado = num_a * num_b;
      } else if (operador == '/') {
        resultado = num_b / num_a;
      }

      Node *n = criarNo(resultado);

      empilhar(&p, n);
    }
    i++;
  }

  return desempilhar(&p);
}

int main(void) {
  printf("%d\n", calculaPosfix("58+3*"));

  return 1;
}
