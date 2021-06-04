#ifndef TRANSACTIONS
#define TRANSACTIONS
#include "INTER_usr.h"
#include <string>


struct Transactions {

};
 

// - - - - - - Logic Order - - - - - - - - - 

// user2 and user3 created by magic

// user3.money_transfer(user2, 500, "test")


/* void money_transfer(receiver, amount, msg) {
    
    if (sufficient_bal(amount)) {
        init_bal = curr_balance;
        sender - amount;
        receiver + amount;
        log_data();
    } else {
        print("Insufficient funds. Try Again.")
    }
}
*/

/*  void update_usr(INTER_usr &receiver) {
    this->receiver_name = receiver.name;
    this->sender_name = this->name;
    receiver.receiver_name = receiver.name;
    receiver.sender_name = sender_name;
}

*/

/* void Logic::log_data(receiver, amount, msg) {
    
    // key = this.name value = [receiver.name, transfer_amount, msg ]

}
*/



// user3.check_status 

/* void check_stauts() {

    if (user3.name = key) {
    
        print(key has sent value[1] to value[0]. 
        Transfer Message: value[2])
    
    } else if (user3.name = value[0]){

        print(value[0] has received value[1] from key. 
        Transfer Message: value[2])

    } else {

        print(No transactions have been made. Remaining bal: curr_balance)

    }
}
*/

#endif