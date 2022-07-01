//
// Created by vladi on 29.06.2022.
//

#include "calculator.h"

bigInt ADD(bigInt a, bigInt b){
    return a+b;
}

bigInt SUB(bigInt a, bigInt b){
    return a-b;
}

bigInt MUL(bigInt a, bigInt b){
    return a*b;
}

void calculator::fillStack(std::string filename, comandStack *arr) {
    std::ifstream file(filename);
    std::string stroke = "";
    while(getline(file,stroke)){

        std::string command = stroke.substr(0,3);
        std::string num = stroke.substr(4,stroke.length()-4);

        arr->push({command,num});
    }
    file.close();
}

calculator::calculator(std::string FileOfInstructions) {
    this->filename = FileOfInstructions;
    this->commands["ADD"] = ADD;
    this->commands["SUB"] = SUB;
    this->commands["MUL"] = MUL;
    fillStack(this->filename,this->CommandsList);
}

void calculator::calculate(bigInt& num){
    int size = this->CommandsList->size();

    for(int i = 0;i<size;i++){
        std::pair<std::string,std::string> data = this->CommandsList->pop();
        bigInt* secondNum = new bigInt(data.second);
        if(this->commands[data.first] != nullptr) num = this->commands[data.first](num,*secondNum);
        else{
            logger* mainlog = new logger();
            Ilogger* log = mainlog->create();
            std::string stroke = "Attention! \""+data.first+"\" - is incorrect command!.";
            log->logError(stroke);
            return;
        }
    }
}

void calculator::uploadInstructions(std::string instructions) {
    this->CommandsList = new comandStack;
    fillStack(instructions,this->CommandsList);
}