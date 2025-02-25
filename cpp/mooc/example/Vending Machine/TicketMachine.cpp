#include "TicketMachine.h"

TicketMachine::TicketMachine():PRICE(0){

    //TODO
}

TicketMachine::~TicketMachine(){
    //TODO
}

void TicketMachine::showPrompt(){
    cout << "something" << endl;
}

void TicketMachine::getMoney(int money){
    balance += money;
}

void TicketMachine::showBalance(){
    cout << balance << endl;
}

void