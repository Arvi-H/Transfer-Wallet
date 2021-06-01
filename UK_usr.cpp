#include "UK_usr.h"
#include <string>
#include <iostream>
 
UK_usr::UK_usr(std::string usr_name, double balance_amount) {
    name = usr_name;
    curr_balance = balance_amount;
    init_bal = balance_amount;
}

void UK_usr::check_status() { 
    
    // There has to be a better way to do this
    if (curr_balance == init_bal) {
        std::cout << ""; } 
    else { 
        std::cout << "UK Transaction: " << std::endl;
        transfer_msg();
     }
 }

void UK_usr::fee_list() {
    std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "\tFees for UK transactions:" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - -" << "\n" << std::endl;

    std::cout << "1. Global Bank: UK (£) -> US ($) money transfers: 2%." << std::endl;
    std::cout << "2. Global Bank: Bitcoin (BTC) -> UK ($) conversions: 1%." << std::endl;
    std::cout << "3. Crypto Bank: UK ($) -> Bitcoin (BTC) conversions: 0.1%.\n" << std::endl;

}
