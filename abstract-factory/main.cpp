#include "main.h"
#include <iostream>
using namespace std;

int main() {
  cout << "Abstract factory" << endl;

  Client client1;
  ConcreteFactory1 factory1;
  ConcreteFactory2 factory2;

  client1.createA(factory1);
  client1.createB(factory2);

  client1.itemise();

  return 0;
}
