#include "INTER_usr.h"
#include "US_usr.h"
#include <iostream>


int main() {
    US_usr user1("foo", 3000.0);
    user1.check_status();

    US_usr user2("bar", 2000);
    user1.money_transfer(user2, 500.0, "Test");

    user1.check_status();
    user2.check_status();
}




