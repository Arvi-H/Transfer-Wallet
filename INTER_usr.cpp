#include "INTER_usr.h"
#include <iostream>

// Remove func when class becomes abstract 
void INTER_usr::check_status() {
    std::cout << "General status check" << std::endl;
}

void INTER_usr::transfer_msg() {
    if (init_bal > usr_money) {
        std::cout << name << " has sent " << currency << bal_change * -1 << " to " << receiver_name << std::endl;
    } else {
        std::cout << name << " has received " << currency << bal_change << " from " << receiver_name << std::endl;
    }
}

void INTER_usr::money_transfer(INTER_usr &receiver, double amount, std::string msg) {
    
    receiver_name = receiver.name;
 
    usr_money -= amount;

    receiver.usr_money += amount;

    receiver.message = msg;

    std::cout << "- - Order Sent Successfully - -" << "\n" << std::endl;
}
 
// Make INTER_usr an abstract class because you wont need INTER_usr instances, but will need to inherit from it