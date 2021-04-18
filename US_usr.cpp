#include "US_usr.h"
#include <string>
#include <iostream>
 
US_usr::US_usr(std::string usr_name, double balance_amount) {
    name = usr_name;
    usr_money = balance_amount;
}

void US_usr::check_status() {
    std::cout << name << " has " << currency << usr_money << " remaining." << std::endl;

    std::cout << "Recent Messages: " << message << std::endl;
}

