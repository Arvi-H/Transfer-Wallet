#include "INTER_usr.h"
#include <iostream>

// Remove func when class becomes abstract 
 void INTER_usr::check_status() {
    std::cout << "General status check" << std::endl;
}

void INTER_usr::money_transfer(INTER_usr receiver, double amount, std::string msg) {
    
    usr_money -= amount;
    receiver.usr_money += amount;
    message = msg;


    std::cout << "Order sent successfully." << std::endl;
}
 
// Make INTER_usr an abstract class because you wont need INTER_usr instances, but will need to inherit from it