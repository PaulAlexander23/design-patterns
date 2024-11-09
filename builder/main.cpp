#include "main.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Builder" << endl;

  ProductBuilder builder1;

  builder1.setCost(1.0);

  Product *product = builder1.build();

  product->output();

  delete product;

  queue<unsigned> inputInstructions;
  inputInstructions.push(1);
  inputInstructions.push(1);
  inputInstructions.push(0);
  inputInstructions.push(2);
  inputInstructions.push(1);

  RobotDirector director;

  Robot robot1 = director.parseInputInstructions(inputInstructions);

  robot1.poke();

  return 0;
}
