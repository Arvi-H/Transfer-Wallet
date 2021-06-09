#include "Logic.h"

void Logic::intro() {
   std::cout << "- - - - - - - - - - - - - Transfer Wallet Commands - - - - - - - - - - \n" << std::endl;
   std::cout << "1. Create a new user by typing \"New_User\" or \"1\".\n";
   std::cout << "2. Transfer money from one user to another by typing \"Money_Transfer\" or \"2\".\n";
   std::cout << "3. Check the status of your user by typing \"Check_Status\" or \"3\".\n";
   std::cout << "4. Stop the program by typing \"Quit\" or \"Q\".\n";
   std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
}

bool Logic::sufficient_bal2(double amount) { 
    if (users.at(sender)->curr_balance > amount) {return true;}
    return false;
}

void Logic::transfer(std::string receiver, double transfer_amount, std::string msg) {

    if (sufficient_bal2(transfer_amount)) { 
        users.at(sender)->curr_balance -= transfer_amount;
        users.at(receiver)->curr_balance += transfer_amount;
        
        transactions.insert({sender, Transactions { receiver, transfer_amount, msg, sender}});

        std::cout << "- - Order Sent Successfully - -" << "\n" << std::endl;

    } else {
        std::cout << "- - Transaction failed: Insufficient funds - -" << "\n" << std::endl;
    }
}

void Logic::transfer_msg2() {
    // If statement consistently failing
    if ( active_usr == transactions.at(active_usr).sender ) {

        std::cout << "Sender Name:" << active_usr << "." << std::endl;

    } else  {
        std::cout << "Receiver Name:" << active_usr << "." << std::endl;
    }

    std::cout << active_usr; 

    /*

    if (active_usr == transactions.at(active_usr).receiver)

     // Balance on account  
    std::cout <<usr_name << " has " << currency << curr_balance << " remaining." << std::endl;

    // Print recent messages
    recent_msg();
    */
} 

void Logic::new_usr() {

    std::cout << " - - - - - - - - - - - - Welcome to Transfer-Wallet - - - - - - - - - -\n" << std::endl;

    intro();

    while (status) {
        std::string input;
        std::cin >> input;
    
        if (input == "Quit" || input == "Q") {
        status = false;
        break;

        } else if (input == "New_User" || input == "1") {
            
            std::cout << "Enter the new user's name:\n";
            std::cin >> usr_name;
            std::cout << "Enter the user's money amount:\n";
            std::cin >> balance;
                
            users.insert({usr_name, new US_usr {usr_name, balance} }); 
            
            intro();

        } else if (input == "Money_Transfer" || input ==  "2") {
            // Perform the following checks: 1. Sender and receiver have to exist. 2. transfer amnt and msg have to be the appropriate types. 3. Maybe use a templatized function to independently check for strings, objects and ints/doubles.
            std::cout << "Who is sending the money?\n";
            std::cin >> sender;
            std::cout << "Who is receiveing the money?\n";
            std::cin >> receiver;
            std::cout << "How much money is " << sender << " sending to " << receiver << "?\n";
            std::cin >> transfer_amount;
            std::cout << "Enter Your message:\n";
            std::cin >> msg;
          
            transfer(receiver, transfer_amount, msg);
         
            intro();
    
        } else if (input == "Check_Status" || input ==  "3") {

            std::cout << "Which user are you checking the status of?\n";
            std::cin >> active_usr;

            // users.at(active_usr)->transfer_msg2();
            transfer_msg2();
    
            intro();
        } 
    }
}

