#include "main.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Factory method" << endl;

  ConcreteProductCreator creator;

  creator.createProduct();
  creator.createProduct();
  creator.createProduct();

  creator.listProduct();

  MyProductCreator myCreator;

  myCreator.createProduct();

  myCreator.listProduct();

  return 0;
}
