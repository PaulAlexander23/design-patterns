#pragma once

#include <iostream>
#include <vector>

class Product {
public:
  virtual void output() = 0;
};

class ConcreteProduct : public Product {

public:
  void output() override { std::cout << "hello" << std::endl; }
};

class Creator {
private:
  std::vector<Product *> storedProduct;

public:
  virtual Product *factoryMethod() = 0;

  void createProduct() { storedProduct.push_back(this->factoryMethod()); }

  void listProduct() {
    for (auto p : storedProduct) {
      p->output();
    }
  }
};

class ConcreteProductCreator : public Creator {
public:
  Product *factoryMethod() override { return new ConcreteProduct; }
};

// -----------------------------------------------------------------------------
class MyProduct : public Product {
public:
  void output() override { std::cout << "Good morning" << std::endl; }
};

class MyProductCreator : public Creator {
public:
  Product *factoryMethod() override { return new MyProduct; }
};
