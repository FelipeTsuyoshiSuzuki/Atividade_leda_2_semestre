#include <iostream>
#include <bits/stdc++.h>
#include <deque>

using namespace std;

struct wine {
  char name[50];
  char origin[25];
  char type[50];
  int safra;
};

wine receiveWine();
void showWine(wine);
void showFirst(deque<wine>);
void showLast(deque<wine>);

int main() {
  deque<wine> vinhos;
  int escolha = 1;
  while (escolha > 0) {
    cout << endl << "1- Para inserir novo vinho na adega";
    cout << endl << "2- Retirar vinho que esta a mais tempo na adega";
    cout << endl << "3- Retirar vinho que esta a menos tempo na adega";
    cout << endl << "4- Mostrar os vinhos adicionados a menos tempo";
    cout << endl << "5- Mostrar os vinhos adicionados a mais tempo";
    cout << endl << "Digite 0 ou um numero negativo para finalizar o programa"<< endl;
    cin >> escolha;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (escolha <= 0) {
      break;
    }
    switch (escolha) {
    case 1: {
      wine vinho = receiveWine();
      vinhos.push_front(vinho);
      showWine(vinhos.front());
      break;
    }
    case 2: {
      cout << endl << "O vinho retirado foi:" << endl;
      showWine(vinhos.back());
      vinhos.pop_back();
      break;
    }
    case 3: {
      cout << endl << "O vinho retirado foi:" << endl;
      showWine(vinhos.back());
      vinhos.pop_front();
      break;
    }
    case 4: {
      showFirst(vinhos);
    }
    case 5: {
      showLast(vinhos);
    }
    }
  }
}

wine receiveWine() {
  wine vinho;
  cout << "Nome do vinho: ";
  cin.getline(vinho.name, 50);
  cout << "Origem do vinho: ";
  cin.getline(vinho.origin, 25);
  cout << "Tipo da uva: ";
  cin.getline(vinho.type, 50);
  cout << "Safra: ";
  cin >> vinho.safra;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return vinho;
}

void showWine(wine vinho) {
  cout << "Nome do vinho: ";
  cout << vinho.name << endl;
  cout << "Origem do vinho: ";
  cout << vinho.origin << endl;
  cout << "Safra: ";
  cout << vinho.safra << endl;
  cout << "Tipo da uva: ";
  cout << vinho.type << endl << endl;
}

void showFirst(deque<wine> vinhos) {
  for (int i = 0; i < 5; i++) {
    if (!vinhos.empty()) {
      showWine(vinhos.front());
      vinhos.pop_front();
    } else
      return;
  }
}
void showLast(deque<wine> vinhos) {
  for (int i = 0; i < 5; i++) {
    if (!vinhos.empty()) {
      showWine(vinhos.back());
      vinhos.pop_back();
    } else
      return;
  }
}
