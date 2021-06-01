#include "INTER_usr.h"
#include "US_usr.h"
#include <iostream>


int main() {
    US_usr user1("Arvi", 3000.0);
    US_usr user2("Casey", 2000.0);
    US_usr user3("Brock", 1000.0);

    user1.money_transfer(user2, 5000.0, "Here's Casey's lunch money.");
    
    user2.money_transfer(user3, 500.0, "test");

    user1.money_transfer(user3, 500.0, "Here's Brock's lunch money.");    
        
    user1.check_status();
    user2.check_status();
    user3.check_status();

    // Automatically take in user1 as the arg
    user1.hidden_fees(user1);
}



