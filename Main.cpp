#include "INTER_usr.h"
#include "US_usr.h"
#include "UK_usr.h"
#include <iostream>
#include <vector>
#include <map>

int main() {
    US_usr user1("Arvi", 3000.0);
    US_usr user2("Casey", 2000.0);
    US_usr user3("Brock", 1000.0);

    user1.money_transfer(user2, 500.0, "Here's Casey's lunch money,");
    user1.money_transfer(user3, 500.0, "Here's Brock's lunch money.");    
        
    user1.check_status();
    user2.check_status();
    user3.check_status();

/*- - Order Sent Successfully - -

- - Order Sent Successfully - -

US Transaction:
Arvi has sent $1000 to Brock
Arvi has $2000 remaining.
Recent Messages: None.

US Transaction:
Casey has received $500 from Arvi
Casey has $2500 remaining.
Recent Messages: From Arvi: Here's Casey's lunch money,

US Transaction:
Brock has received $500 from Arvi
Brock has $1500 remaining.
Recent Messages: From Arvi: Here's Brock's lunch money.*/