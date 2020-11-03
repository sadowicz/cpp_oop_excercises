#include "Calculator.h"
#include <iostream>

int main() {

    Calculator calculator{1, 2};
    std::cout << "Sum: " << calculator.add() << std::endl;

    return 0;
}