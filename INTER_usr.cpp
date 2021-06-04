#include "INTER_usr.h"
#include <iostream>

void INTER_usr::recent_msg() {
    if (message == "") {
        std::cout << "Recent Messages: None." << "\n" << std::endl;
    } else {
        std::cout << "Recent Messages: From " << sender_name << ": "<< message << "\n" << std::endl;
    }
}

void INTER_usr::transfer_msg() {
    
    bal_change = curr_balance - init_bal;

    // Determine whether the user sent or received money
    if (bal_change < 0) {
        std::cout << name << " has sent " << currency << -bal_change << " to " << receiver_name << std::endl;
    } else {
        std::cout << name << " has received " << currency << bal_change << " from " << sender_name << std::endl;
    }

    // Balance on account  
    std::cout << name << " has " << currency << curr_balance << " remaining." << std::endl;

    // Print recent messages
    recent_msg();
}

bool INTER_usr::sufficient_bal(double amount) {
    if (this->curr_balance > amount) { return true; } 
    return false;
}

void INTER_usr::money_transfer(INTER_usr &receiver, double amount, std::string msg) {
    
    // INTER_usr *admin; Line 55

    // Current user name details
    this->receiver_name = receiver.name;
    this->sender_name = this->name;

    // Transfer Calc
    if (sufficient_bal(amount)) { 
        // reset init_bal to curr_balance
        this->curr_balance -= amount;  
        receiver.curr_balance += amount;
        std::cout << "- - Order Sent Successfully - -" << "\n" << std::endl;

    } else {
        // std::cout << name << "'s transfer attempt of " << currency << amount << " to " << receiver_name << " failed.";
        std::cout << "- - Transaction failed: Insufficient funds - -" << "\n" << std::endl;
    }
    
    // admin->log_data(); Call test function somehow

    // Receiver name details
    receiver.receiver_name = receiver.name;
    receiver.sender_name = sender_name;

    // Current user's message to receiver
    receiver.message = msg;

    // Confirmation Msg
 
}
  
// Fill with all of the fees combined from US and UK
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
    INTER_usr* admin = &usr;
     admin->fee_list();
    
    usr.fee_list(); // Why does this work?

    // Fun fact do admin->INTER_usr::fee_list(); to print out the INTER_usr version of the function | Try later with UK
}
