#include "US_usr.h"
#include <string>
#include <iostream>
#include "Transactions.h"

US_usr::US_usr(std::string name, double balance_amount) {
    usr_name = name;
    curr_balance = balance_amount;
    currency = "$";
}
 
void US_usr::fee_list() {
    std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "\tFees for US transactions:" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - -" "\n" << std::endl;

    std::cout << "1. Global Bank: US ($) -> UK (£) money transfers: 2%." << std::endl;
    std::cout << "2. Global Bank: Bitcoin (BTC) -> US ($) conversions: 1%." << std::endl;
    std::cout << "3. Crypto Bank: US ($) -> Bitcoin (BTC) conversions: 0.1%.\n" << std::endl;

}

  