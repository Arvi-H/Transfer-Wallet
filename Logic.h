#ifndef LOGIC
#define LOGIC
#include "INTER_usr.h"
#include "US_usr.h"
#include "Transactions.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
 
class Logic {

public:

Transactions t;

std::map<std::string, INTER_usr*> users;
std::map<std::string, Transactions> transactions;
std::vector<std::string> sender_l;

std::string usr_name;
std::string sender;
std::string receiver;
std::string active_usr;
std::string msg;

double balance;
double transfer_amount;
bool status = true;

void intro_msg();
void new_usr();
void transfer(std::string receiver, double transfer_amount, std::string msg);
bool overdraft_check(double amount);
void  transfer_msg(std::string active_usr);
};

#endif

