#ifndef LOGIC
#define LOGIC

#include "INTER_usr.h"
#include "US_usr.h"
#include "UK_usr.h"
#include "Transactions.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
 
class Logic {

public:

Transactions t;

std::map<std::string, INTER_usr*> users;
std::map<std::string, std::vector <Transactions>> transactions;
std::vector<Transactions> t_vec;
std::map<std::string, std::vector<Transactions>>::iterator itr;

std::string usr_name;
std::string sender;
std::string receiver;
std::string active_usr;
std::string msg;
std::string usr_location;

double balance;
double transfer_amount;
const double usd_gbp_rate = 0.71;
const double gbp_usd_rate = 1.40;

bool status = true;


void intro_msg();
void new_usr();
void transfer(std::string receiver, double transfer_amount, std::string msg,  std::string sender);
bool overdraft_check(double amount);
void check_status(std::string active_usr);
};

#endif

