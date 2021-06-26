#ifndef TRANSACTIONS
#define TRANSACTIONS
#include "INTER_usr.h"
#include <string>
#include <iostream>
 
struct Transactions {
    std::string receiver;
    double amount;
    std::string message;
    std::string sender;

    // friend std::ostream& operator<<(std::ostream& os, const Transactions& right) {

    //     os << "receiver: " << right.receiver << '\n';
    //     os << "amount: " << right.amount << '\n';
    //     os << "message: " << right.message << '\n';
    //     os << "sender: " << right.sender << '\n';


    //     return os;
    // }
};
  
#endif