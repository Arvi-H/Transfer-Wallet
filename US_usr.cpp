#include "US_usr.h"
#include <string>
#include <iostream>
 
US_usr::US_usr(std::string usr_name, double balance_amount) {
    name = usr_name;
    curr_balance = balance_amount;
    init_bal = balance_amount;
}

void US_usr::check_status() { 
    
    // There has to be a better way to do this
    if (curr_balance == init_bal) {
        std::cout << ""; } 
    else { 
        transfer_msg();
    }
 }

