#include <iostream>
using namespace std;

struct Node {
  int number;
  Node *next;
};

struct Queue {
  Node *head; //Nó inicial da fila
  Node *tail; //Nó final da fila
  int max_items;//Quantidade máxima de itens da fila
  int qty;//Quantidade de elementos presentes na fila
};

int qtdElementos(Queue *fila){
  cout<<"Ha "<<fila->qty<<" elemento(s) na fila";
  return fila->qty;
}

bool isFull(Queue *fila){
  if(fila->qty >= fila->max_items){
    return true;
  }else{
    return false;
  }
}

bool isEmpty(Queue *fila){
  if(fila->qty == 0){
    return true;
  }else{
    return false;
  }
}

bool procuraElemento(Queue *fila, int valorProcurado){
  Node *aux = fila->head;
  while (aux->next){
    if (aux->number==valorProcurado) {
      cout<<"O valor procurado esta na fila.";
      return true;
    }
    aux= aux->next;
  }
  cout<<"O valor procurado nao esta na fila.";
  return false;
}

void exibeElementos(Queue *fila){
  Node *aux = fila->head;
  int cont = fila->qty;
  while(cont>=0){
    cout<<aux->number <<"\n";
    aux = aux->next;
    cont--;
  }
}

bool enqueue(Queue *fila, int valor){
  if(isFull(fila)){
    cout<<"A fila esta cheia.";
    return false;
  }else{
    Node aux, *novo=(Node*)calloc(1, sizeof(Node));
    novo->number = valor;
    novo->next = NULL;
    if(fila==NULL){
      fila->head->number = novo->number;
      fila->tail->number = novo->number;
    }else {
      fila->head->next = novo;
      fila->head = novo;
    }
    fila->qty += 1;
    printf("Enqueue realizado com sucesso.\n");
    return true;
  }
}

bool dequeue(Queue *fila){
  if(isEmpty(fila)){
    cout<<"A fila esta vazia.";
    return false;
  }else{
    Node *aux = fila->head;
    fila->head = fila->head->next;
    free(aux);
    cout<<"Dequeue realizado com sucesso.";
    return true;
  }
}
