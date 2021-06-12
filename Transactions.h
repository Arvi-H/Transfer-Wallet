#ifndef TRANSACTIONS
#define TRANSACTIONS
#include "INTER_usr.h"
#include <string>
 
struct Transactions {
    std::string receiver;
    double amount;
    std::string message;
    std::string sender; // no longer will need this
};
  
#endif