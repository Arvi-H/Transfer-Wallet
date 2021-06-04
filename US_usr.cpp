#include "US_usr.h"
#include <string>
#include <iostream>
#include "Transactions.h"

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
        std::cout << "US Transaction: " << std::endl;
        transfer_msg();
    }
 }

void US_usr::fee_list() {
    std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "\tFees for US transactions:" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - -" "\n" << std::endl;

    std::cout << "1. Global Bank: US ($) -> UK (£) money transfers: 2%." << std::endl;
    std::cout << "2. Global Bank: Bitcoin (BTC) -> US ($) conversions: 1%." << std::endl;
    std::cout << "3. Crypto Bank: US ($) -> Bitcoin (BTC) conversions: 0.1%.\n" << std::endl;

}

  