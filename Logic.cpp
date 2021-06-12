#include "Logic.h"

void Logic::intro_msg() {
   std::cout << "- - - - - - - - - - - - - Transfer Wallet Commands - - - - - - - - - - \n" << std::endl;
   std::cout << "1. Create a new user by typing \"New_User\" or \"1\".\n";
   std::cout << "2. Transfer money from one user to another by typing \"Money_Transfer\" or \"2\".\n";
   std::cout << "3. Check the status of your user by typing \"Check_Status\" or \"3\".\n";
   std::cout << "4. Stop the program by typing \"Quit\" or \"q\".\n";
   std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
}

bool Logic::overdraft_check(double amount) { 
    if (users.at(sender)->curr_balance > amount) {return true;}
    return false;
}

void Logic::transfer(std::string receiver, double transfer_amount, std::string msg) {

    if (overdraft_check(transfer_amount)) { 
        // User Balance Calc
        users.at(sender)->curr_balance -= transfer_amount;
        users.at(receiver)->curr_balance += transfer_amount;
        
        // Record Transaction
        transactions.insert({sender, Transactions { receiver, transfer_amount, msg, sender}});
        sender_l.push_back(sender);

        std::cout << "- - Order Sent Successfully - -" << "\n" << std::endl;

    } else {
        std::cout << "- - Transaction failed: Insufficient funds - -" << "\n" << std::endl;
    }
}

// Rename to check status
void Logic:: transfer_msg(std::string active_usr) {

    for (auto i : sender_l) {
        if (active_usr == transactions.at(i).receiver) {
            std::cout << "Receiver Name:" << active_usr << "." << std::endl;
        } else if (active_usr == transactions.at(i).sender) {
            std::cout << "Sender Name:" << active_usr << "." << std::endl;
        } else {
            std::cout << "No activity shown.";
        }
    }
 
} 

void Logic::new_usr() {

    std::cout << " - - - - - - - - - - - - Welcome to Transfer-Wallet - - - - - - - - - -\n" << std::endl;
    intro_msg();

    while (status) {
        std::string input;
        std::cin >> input;
    
        if (input == "Quit" || input == "q") {
        status = false;
        break;

        } else if (input == "New_User" || input == "1") {
            
            std::cout << "Enter the new user's name:\n";
            std::cin >> usr_name;
            std::cout << "Enter the user's money amount:\n";
            std::cin >> balance;
                
            users.insert({usr_name, new US_usr {usr_name, balance} }); 
            intro_msg();

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
            intro_msg();
    
        } else if (input == "Check_Status" || input ==  "3") {

            std::cout << "Which user are you checking the status of?\n";
            std::cin >> active_usr;

            transfer_msg(active_usr);
            intro_msg();
        } 
    }
}

