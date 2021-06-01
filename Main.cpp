#include "INTER_usr.h"
#include "US_usr.h"
#include "UK_usr.h"
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
    // user1.fee_list();

    UK_usr user4("Adam", 100.0);
    UK_usr user5("Casper", 100.0);

    user4.money_transfer(user1, 50);
    user4.check_status();
    user1.check_status();

}

/* Problems List:

1. check_status always showing the first activity of the usr
2. message says that the usr recieved a total of 1000 from someone when istead usr recieved 500 from one person and 500 from someone esle
3. why does usr.fee_list() work in hidden fees?


*/

