#ifndef TICKETMACHINE_H
#define TICKETMACHINE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class TicketMachine {
public:
    TicketMachine();
    virtual ~TicketMachine();
    void showPrompt();
    void getMoney();
    void printTicket();
    void showBalance();
    void printError();
private:
    const int PRICE;
    int balance;
    int total;
};

#endif // TICKETMACHINE_H