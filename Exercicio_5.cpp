#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void showQueue(queue<int>);
void showStack(stack<int>);

int main() {
  int number = 1;
  queue<int> pares, impares;
  stack<int> numbers;
  cout << "Digite um numero(0 ou negativos para finalizar): "<< endl;
  while(number > 0) {
    cin >> number;
    if (number <= 0) {
      break;
    }
    numbers.push(number);
    if (number % 2 == 0) {
      pares.push(number);
    } else {
      impares.push(number);
    }
  }
  cout <<endl<<"Pilha com os numeros digitados"<<endl;
  showStack(numbers);
  if (pares.empty()) 
    cout <<endl<<"Nenhum numero par foi digitado"<<endl;
  else {
    cout << endl << "Fila com numeros pares" << endl;
    showQueue(pares);
  }

  if (impares.empty()) 
    cout <<endl<<"Nenhum numero impar foi digitado"<<endl;
  else {
    cout << endl << "Fila com numeros impares" << endl;
    showQueue(impares);
  }
}

void showStack(stack<int> pilha) {
  while (!pilha.empty()) {
    cout << pilha.top() << endl;
    pilha.pop();
  }
}

void showQueue(queue<int> fila) {
  while (!fila.empty()) {
    cout << fila.front() << endl;
    fila.pop();
  }
}