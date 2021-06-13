#include "UK_usr.h"
#include <string>
#include <iostream>
#include "Transactions.h"

UK_usr::UK_usr(std::string name, double balance_amount) {
    usr_name = name;
    curr_balance = balance_amount;
    currency = "£";
}
 
void UK_usr::fee_list() {
    std::cout << "- - - - - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "\tFees for UK transactions:" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - -" "\n" << std::endl;

    std::cout << "4. Global Bank: UK (£) -> US ($) money transfers: 2%." << std::endl;
    std::cout << "5. Global Bank: Bitcoin (BTC) -> UK ($) conversions: 1%." << std::endl;
    std::cout << "6. Crypto Bank: UK ($) -> Bitcoin (BTC) conversions: 0.1%.\n" << std::endl;
    
}

  