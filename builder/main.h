#pragma once

#include <iostream>
#include <queue>

class Product {
private:
  unsigned id;
  double cost;

public:
  Product() : id(0), cost(0.0) {}
  void setCost(double newCost) { cost = newCost; }
  void output() { std::cout << id << ", " << cost << std::endl; }
};

class ProductBuilder {
private:
  double cost;

public:
  ProductBuilder() : cost(1.0) {}

  void setCost(double new_cost) { cost = new_cost; }

  virtual Product *build() {
    Product *product_pt = new Product;
    product_pt->setCost(cost);
    return product_pt;
  }
};

class Robot {
private:
  unsigned arms;
  bool isSwitchedOn;

public:
  Robot(unsigned a, bool o) : arms(a), isSwitchedOn(o) {}

  void poke() {
    if (this->isSwitchedOn) {
      for (unsigned n = 0; n < arms; n++) {
        std::cout << "Oi!" << std::endl;
      }
    }
  }
};

class RobotBuilder {
  unsigned arms;
  unsigned legs;

public:
  RobotBuilder() : arms(0), legs(0) {}
  void add_arm() { arms++; }
  void add_leg() { legs++; }
  Robot build() { return Robot(arms, true); }
};

class RobotDirector {
public:
  Robot parseInputInstructions(std::queue<unsigned> inputInstructions) {
    RobotBuilder builder;
    while (!inputInstructions.empty()) {
      unsigned instruction = inputInstructions.front();
      switch (instruction) {
      case 0:
        builder.add_arm();
        break;
      case 1:
        builder.add_leg();
        break;
      case 2:
        break;
      default:
        break;
      }
      inputInstructions.pop();
    }
    return builder.build();
  }
};
