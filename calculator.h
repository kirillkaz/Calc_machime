#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

#include "logger/logFactory/logger.h"
#include "stack/stack.h"
#include "longInteger/BigInt/Include/bigInt.h"

#ifndef CALC_MACHIME_CALCULATOR_H
#define CALC_MACHIME_CALCULATOR_H

bigInt ADD(bigInt a, bigInt b);

bigInt SUB(bigInt a, bigInt b);

bigInt MUL(bigInt a, bigInt b);

using comandStack = stack<std::pair<std::string,std::string>>;

class calculator {
private:
    std::map<std::string, bigInt (*)(bigInt a, bigInt b)> commands;
    comandStack* CommandsList = new comandStack;
    std::string filename;

    void fillStack(std::string filename,comandStack* arr);

public:
    calculator(std::string instructions);

    void uploadInstructions(std::string instructions);

    void calculate(bigInt& num);
};


#endif
