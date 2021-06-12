#ifndef INTER_USR
#define INTER_USR
#include <string>
#include "Transactions.h"

class INTER_usr {

public:
 
    double curr_balance;
    std::string usr_name;
   
    // std::string currency = "$";
   
    void hidden_fees(INTER_usr &usr);
 
 private:
    virtual void fee_list();
};

#endif 