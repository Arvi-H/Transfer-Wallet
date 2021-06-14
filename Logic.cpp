#include "Logic.h"

void Logic::intro_msg() {
   std::cout << "- - - - - - - - - - - - - Transfer Wallet Commands - - - - - - - - - - \n" << std::endl;
   std::cout << "1. Create a new user by typing \"New_User\" or \"1\".\n";
   std::cout << "2. Transfer money from one user to another by typing \"Money_Transfer\" or \"2\".\n";
   std::cout << "3. Check the status of your user by typing \"Check_Status\" or \"3\".\n";
   std::cout << "4. View Transfer Wallet fees by typing \"View_Fees\" or \"4\".\n";
   std::cout << "5. Stop the program by typing \"Quit\" or \"q\".\n";
   std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
}

bool Logic::overdraft_check(double amount) { 
    if (users.at(sender)->curr_balance > amount) {return true;}
    return false;
}


/*
    converter() {
        if sender.curr !== receiver.curr:
            if sender.curr == $:
                users.at(receiver)->curr_balance += transfer_amount * usd_gdp_rate;     
                users.at(sender)->curr_balance -= (transfer_amount + (transfer_amount * 0.02));
            else if sender = UK:
                users.at(sender)->curr_balance -= (transfer_amount + (transfer_amount * 0.02));
                users.at(receiver)->curr_balance += transfer_amount * gdp_usd_rate;
        else:
            users.at(sender)->curr_balance -= (transfer_amount + (transfer_amount * 0.02));
            users.at(receiver)->curr_balance += transfer_amount;
    }

 


*/
 
void Logic::transfer() {
 
    if (overdraft_check(transfer_amount)) { 
        // User Balance Calc
        users.at(sender)->curr_balance -= (transfer_amount + (transfer_amount * 0.02));
        users.at(receiver)->curr_balance += transfer_amount;
        
        // Record Transaction
        transactions.insert({sender, Transactions { receiver, transfer_amount, msg, sender}});
        sender_l.push_back(sender);

        std::cout << "- - Order Sent Successfully - -" << "\n" << std::endl;

    } else {
        std::cout << "- - Transaction failed: Insufficient funds - -" << "\n" << std::endl;
    }
}

void Logic::check_status(std::string active_usr) {

    for (auto i : sender_l) {
        // Receiver Message
        if (active_usr == transactions.at(i).receiver) {
            std::cout << active_usr << " has received " << users.at(active_usr)->currency << transactions.at(i).amount << " from " << transactions.at(i).sender << ".\n";
            std::cout << active_usr << " has " <<  users.at(active_usr)->currency << users.at(active_usr)->curr_balance << " remaining.\n";
            std::cout << "Message from " <<  transactions.at(i).sender << ": " << transactions.at(i).message << ".\n" << std::endl;
        // Sender Message
        } else if (active_usr == transactions.at(i).sender) {
            std::cout << active_usr << " has sent " <<  users.at(active_usr)->currency << transactions.at(i).amount << " to " << transactions.at(i).receiver << ".\n";
            std::cout << active_usr << " has " <<  users.at(active_usr)->currency << users.at(active_usr)->curr_balance << " remaining.\n" << std::endl;
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
            
            std::cout << "Enter \"US\" to create a US user or \"UK\" to create a UK user:\n";
            std::cin >> usr_location;
            std::cout << "Enter the new user's name:\n";
            std::cin >> usr_name;
            std::cout << "Enter the user's money amount:\n";
            std::cin >> balance;
          
            if (usr_location == "US") {
                users.insert({usr_name, new US_usr {usr_name, balance} }); 
            } else if (usr_location == "UK") {
                users.insert({usr_name, new UK_usr {usr_name, balance} });
            }
            
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
          
            transfer();
            intro_msg();
    
        } else if (input == "Check_Status" || input ==  "3") {

            std::cout << "Which user are you checking the status of?\n";
            std::cin >> active_usr;

            check_status(active_usr);
            intro_msg();

        } else if (input == "View_Fees" || input ==  "4") { 
            
            std::cout << "Which user is interested in looking at our fees?\n";
            std::cin >> active_usr;
            
            users.at(active_usr)->hidden_fees(users.at(active_usr));
        }
    }
}


/* - - - - - - - - - - - - - Fundamentally Broken Things - - - - - - - - - - - - - - - -

1. Enter "New_User" instead of "New User" Note the space

2. Msg only printing the first half or until the space or something? Probs until space in sentance which is also the problem above

3. Perform checks, i.e. if user exists, then continue. // prevent map out of range

4. UK Users - Done

5. Fee List + Intro msg - Done

6. Transfer_fees(); - Done

7. converter();

8. Smooth Flow

9. Crypto? or stop and do data structures instead idk

*/