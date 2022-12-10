#include <iostream>
#include <queue>

using namespace std;

queue<int> createFila(int, int);
void showQueue(queue<int>);

int main() {
  queue<int> fila1 = createFila(0, 15);
  queue<int> fila2 = createFila(50, 75);

  cout << "Primeira Fila:" << endl;
  showQueue(fila1);
  cout << "\nSegunda Fila:"<< endl;
  showQueue(fila2);

  queue<int> fila3;
  while(!fila1.empty()) {
    fila3.push(fila1.front());
    fila1.pop();
  }
  while(!fila2.empty()) {
    fila3.push(fila2.front());
    fila2.pop();
  }

  cout <<"\nTerceira Fila: "<< endl;
  showQueue(fila3);
}

void showQueue(queue<int> fila) {
  while (!fila.empty()) {
    cout << fila.front() << endl;
    fila.pop();
  }
}

void showByEnd(queue<int> fila) {
  while (!fila.empty()) {
    cout << fila.back() << endl;
    fila.pop();
  }
}

queue<int> createFila(int inicio, int fim) {
  queue<int> fila;
  if (inicio < fim) {
    for (int i = inicio; i <= fim; i++) {
      fila.push(i);
    }
  } else {
    for (int i = inicio; i >= fim; i--) {
      fila.push(i);
    }
  }
  return fila;
}