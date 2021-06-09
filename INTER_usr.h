#ifndef INTER_USR
#define INTER_USR
#include <string>
#include "Transactions.h"

class INTER_usr {

public:

  
    double curr_balance;
    std::string usr_name;
   
    // std::string currency = "$";

    // Func overriden in all classes | Runtime Polymorphism
    virtual void check_status();
 
  
    // void recent_msg();

    // bool sufficient_bal(double amount);
 
    void hidden_fees(INTER_usr &usr);
 
 private:
    virtual void fee_list();
};

#endif 