#include "Logic.h"

void Logic::intro() {
   std::cout << "- - - - - - - - - - - - - Transfer Wallet Commands - - - - - - - - - - \n" << std::endl;
   std::cout << "1. Create a new user by typing \"New_User\" or \"1\".\n";
   std::cout << "2. Transfer money from one user to another by typing \"Money_Transfer\" or \"2\".\n";
   std::cout << "3. Check the status of your user by typing \"Check_Status\" or \"3\".\n";
   std::cout << "4. Stop the program by typing \"Quit\" or \"Q\".\n";
   std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
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

        users.at(receiver) = &rec; // Problem: users.at(receiver) cant be passed in as INTER_usr * 
    
        users.at(sender)->money_transfer(rec, transfer_amount, msg); 

        transactions.insert({sender, Transactions { receiver, transfer_amount, msg}});
        
        intro();

    } else if (input == "Check_Status" || input ==  "3") {

        std::cout << "Which user are you checking the status of?\n";
        std::cin >> active_usr;

        users.at(active_usr)->check_status();
        intro();
    } 
}

}

 
void Logic::transfer() {
}
