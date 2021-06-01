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
    
    // Current user name details
    this->receiver_name = receiver.name;
    this->sender_name = this->name;

    // Transfer Calc
    if (sufficient_bal(amount)) { 
        this->curr_balance -= amount;  
        receiver.curr_balance += amount;
        std::cout << "- - Order Sent Successfully - -" << "\n" << std::endl;

    } else {
        // std::cout << name << "'s transfer attempt of " << currency << amount << " to " << receiver_name << " failed.";
        std::cout << "- - Transaction failed: Insufficient funds - -" << "\n" << std::endl;
    }
    
  
    // Receiver name details
    receiver.receiver_name = receiver.name;
    receiver.sender_name = sender_name;

    // Current user's message to receiver
    receiver.message = msg;

    // Confirmation Msg
 
}
  
// Fill with all of the fees combined from US and UK
void INTER_usr::fee_list() {
    std::cout << "- - - - - - - - - - - -" << std::endl;
}


