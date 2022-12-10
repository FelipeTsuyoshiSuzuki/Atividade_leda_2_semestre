#include <iostream>
using namespace std;

struct Node{
  int number;
  struct Node* next;
};

struct Stack {
    struct Node *top;
    int max_items; //Quantidade máxima de itens da pilha
    int qty = 0; //Quantidade de elementos presentes na pilha
};

//Verifica se a pilha está cheia e retorna true (pilha cheia) ou false (pilha não cheia).
bool isFull(Stack *stack){
  if(stack->max_items == stack->qty){
    return true; //está cheio
  }else{
    return false; //não está cheio
  }
}

bool isEmpty(Stack *stack){
  if(stack->max_items == 0){
    return true;
  }else{
    return false;
  }
}

bool procuraElemento(Stack *stack, int valorProcurado){
  Node *aux = stack->top;
  while (aux!=NULL) {
    if (aux->number == valorProcurado){
      cout<<"O valor procurado esta na pilha.";
        return true;
    }
    aux = aux -> next;
  }
  cout<<"O valor procurado não esta na pilha";
  return false;
}

void exibirElementos(Stack *stack){
  Node *aux = stack->top;
  if(isEmpty(stack)){
    cout<<"A pilha esta vazia";
  }else{
    while(aux!=NULL){
      cout<<aux->number<<"\n";
    }
  }
}

bool push(Stack *stack, int numero){ //Empilha item
  if(isFull(stack)){ 
    cout << "A pilha está cheia.";
    return false;
  }else{
    struct Node *novo = (struct Node *) calloc(1, sizeof(struct Node));
    novo->number = numero;
    novo->next = stack->top;
    stack->top = novo;
    stack->qty += 1;
    cout << "Push realizado com sucesso.";
    return true;
  }
}

bool pop(Stack *stack){
  if(isEmpty(stack)){
    cout<<"A pilha esta vazia.";
    return false;
  }else{
    struct Node *topRemover = stack->top;
    stack->top= stack->top->next;
    topRemover = NULL;
    free(topRemover);
    stack->qty -= 1;
    cout<<"Pop realizado com sucesso.";
    return true;
  }
}