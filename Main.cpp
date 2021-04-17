#include "INTER_usr.cpp"
#include "US_usr.cpp"
#include "UK_usr.cpp"
#include <iostream>


int main() {
    US_usr foo(3000);
    foo.check_status();
}




/*


// Set money amount in constructor and save to variable
US_usr foo;
UK_usr bar;

foo.money_transfer(bar, 1000); // calculate currency, fees, and conversion.

foo.message("Here's the money for lunch tomorrow.");

bar.check_status(); // print money amount by calling usr_money in the func, print message // Good Formating



*/

