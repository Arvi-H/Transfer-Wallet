#ifndef LOGIC
#define LOGIC
#include "INTER_usr.h"
#include "US_usr.h"
#include "Transactions.h"
#include <iostream>
#include <string>
#include <map>

 
class Logic : public INTER_usr{

public:

Transactions t;

std::map<std::string, INTER_usr*> users;
std::map<std::string, Transactions> transactions;

std::string usr_name;
std::string sender;
std::string active_usr;
std::string msg;
US_usr rec;

std::string receiver;
double balance;
double transfer_amount;
bool status = true;

// struct Transactions foo { transfer_amount, usr_name, msg, sender, receiver, active_usr };

void intro();
void new_usr();
void transfer();

};

#endif

