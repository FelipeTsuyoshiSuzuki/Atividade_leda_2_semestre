#include <iostream>
#include <stack>

using namespace std;

stack<int> createStack(int inicio, int fim);
void showStack(stack<int> pilha);

int main() {
  // Criando 2 pilhas de forma crescente a partir do topo
  stack<int> pilha = createStack(10, 1);
  stack<int> pilha2 = createStack(100, 80);

  // Mostrando primeira pilha
  cout << "Primeira pilha" << endl;
  showStack(pilha);

  // Mostrando segunda pilha
  cout << endl << "Segunda pilha" << endl;
  showStack(pilha2);

  // Criando pilha 3 a partir da 1 e 2
  stack<int> pilha3;
  // Inserir primeiro pilha menor para ficar embaixo
  while (!pilha.empty()) {
    pilha3.push(pilha.top());
    pilha.pop();
  }
  // Inserir pilha maior para ficar em cima
  while (!pilha2.empty()) {
    pilha3.push(pilha2.top());
    pilha2.pop();
  }

  // Mostrando terceira pilha
  cout << endl << "Terceira pilha" << endl;
  showStack(pilha3);
}

void showStack(stack<int> pilha) {
  while (!pilha.empty()) {
    cout << pilha.top() << endl;
    pilha.pop();
  }
}

stack<int> createStack(int inicio, int fim) {
  stack<int> pilha;
  if (inicio < fim) {
    for (int i = inicio; i <= fim; i++) {
      pilha.push(i);
    }
  } else {
    for (int i = inicio; i >= fim; i--) {
      pilha.push(i);
    }
  }
  return pilha;
}