#pragma once

#include <iostream>
#include <list>

class AbstractProductA {
public:
  virtual void output() = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
  virtual void output() override { std::cout << "I am an A1" << std::endl; }
};

class ConcreteProductA2 : public AbstractProductA {
public:
  virtual void output() override { std::cout << "I am an A2" << std::endl; }
};

class AbstractProductB {
public:
  virtual void shout() = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
  virtual void shout() override { std::cout << "I AM A B1" << std::endl; }
};

class ConcreteProductB2 : public AbstractProductB {
public:
  virtual void shout() override { std::cout << "I AM A B2" << std::endl; }
};

class AbstractFactory {
public:
  virtual AbstractProductA *createProductA() = 0;
  virtual AbstractProductB *createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
  AbstractProductA *createProductA() override { return new ConcreteProductA1; }

  AbstractProductB *createProductB() override { return new ConcreteProductB1; }
};

class ConcreteFactory2 : public AbstractFactory {
public:
  AbstractProductA *createProductA() override { return new ConcreteProductA2; }

  AbstractProductB *createProductB() override { return new ConcreteProductB2; }
};

class Client {
private:
  std::list<AbstractProductA *> inventoryA;
  std::list<AbstractProductB *> inventoryB;

public:
  Client() {}

  void createA(AbstractFactory &factory) {
    inventoryA.push_back(factory.createProductA());
  };
  void createB(AbstractFactory &factory) {
    inventoryB.push_back(factory.createProductB());
  };

  void itemise() {
    for (AbstractProductA *a : inventoryA) {
      a->output();
    }
    for (AbstractProductB *b : inventoryB) {
      b->shout();
    }
  };
};
