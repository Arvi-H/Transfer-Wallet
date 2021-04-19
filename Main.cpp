#include "INTER_usr.h"
#include "US_usr.h"
#include <iostream>


int main() {
    US_usr user1("Foo", 3500.0);
    US_usr user2("Bar", 2000.0);

    user1.money_transfer(user2, 500.0, "Here's the lunch money.");
    
    user1.check_status();

    std::cout << "\n";

    user2.check_status();

}




