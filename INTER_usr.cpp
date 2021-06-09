#include "INTER_usr.h"
#include <iostream>
#include "Transactions.h"

  

void INTER_usr::fee_list() {
    std::cout << "- - - - - - - - - - - - - - - - - - - - -\n";
    std::cout << "\tFees for All Global transactions:" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - - - - - -\n"<< std::endl;
    
    std::cout << "1. Global Bank: US ($) -> UK (£) money transfers: 2%." << std::endl;
    std::cout << "2. Global Bank: Bitcoin (BTC) -> US ($) conversions: 1%." << std::endl;
    std::cout << "3. Crypto Bank: US ($) -> Bitcoin (BTC) conversions: 0.1%.\n" << std::endl;

    std::cout << "4. Global Bank: UK (£) -> US ($) money transfers: 2%." << std::endl;
    std::cout << "5. Global Bank: Bitcoin (BTC) -> UK ($) conversions: 1%." << std::endl;
    std::cout << "6. Crypto Bank: UK ($) -> Bitcoin (BTC) conversions: 0.1%.\n" << std::endl;
    
}

void INTER_usr::hidden_fees(INTER_usr &usr) {
    usr.fee_list(); 
}

void INTER_usr::check_status() { 
     
    // There has to be a better way to do this
    // if (curr_balance == init_bal) {
    //     std::cout << ""; } 
    // else { 
        std::cout << "INTER Transaction: " << std::endl;
     // }
 }
