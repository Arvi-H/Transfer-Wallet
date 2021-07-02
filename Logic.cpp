#include "Logic.h"
#include <algorithm>

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
 
void Logic::transfer(std::string receiver, double transfer_amount, std::string msg, std::string sender) {
    
    std::map<std::string, std::vector<Transactions>>::iterator itr = transactions.find(sender);
    std::map<std::string, std::vector<Transactions>>::iterator itr2 = r_transactions.find(receiver);
    
    if (overdraft_check(transfer_amount)) { 
        // User Balance Calc
        users.at(sender)->curr_balance -= (transfer_amount + (transfer_amount * 0.02));
        users.at(receiver)->curr_balance += transfer_amount;

        if (itr == transactions.end()) { 
            transactions.insert({sender, t_vec});
        }  

        if (itr2 == r_transactions.end()) { 
            r_transactions.insert({receiver, t_vec2});
        }  

        transactions.at(sender).push_back({receiver, transfer_amount, msg, sender});
        r_transactions.at(receiver).push_back({receiver, transfer_amount, msg, sender});


        std::cout << "- - Order Sent Successfully - -" << "\n" << std::endl;

    } else {
        std::cout << "- - Transaction failed: Insufficient funds - -" << "\n" << std::endl;
    }
}

void Logic::check_status(std::string active_usr) {
    
    std::map<std::string, std::vector<Transactions>>::iterator itr = transactions.find(active_usr);

    std::map<std::string, std::vector<Transactions>>::iterator itr2 = r_transactions.find(active_usr);


   

    if (active_usr == itr->first) {
        
        for (int i = 0; i < itr->second.size(); i++) {
            std::cout << active_usr << " has sent " <<  users.at(active_usr)->currency << itr->second.at(i).amount << " to " << itr->second.at(i).receiver << ".\n";

            std::cout << active_usr << " has " <<  users.at(active_usr)->currency << users.at(active_usr)->curr_balance << " remaining.\n" << std::endl;        }

    } else if (active_usr == itr2->first) {
    
        for (int i = 0; i < itr2->second.size(); i++) {

            std::cout << active_usr << " has received " <<  users.at(active_usr)->currency << itr2->second.at(i).amount << " from " << itr2->second.at(i).sender << ".\n";

            std::cout << active_usr << " has " <<  users.at(active_usr)->currency << users.at(active_usr)->curr_balance << " remaining.\n" << std::endl;

            std::cout << "Message from " <<  itr2->second.at(i).sender << ": " << itr2->second.at(i).message << ".\n" << std::endl;     }

    } else {
        std::cout << "test failed 2";
    }

}

  

void Logic::new_usr() {

    std::cout << " - - - - - - - - - - - - Welcome to Transfer-Wallet - - - - - - - - - -\n" << std::endl;
    intro_msg();

    while (status) {
        std::string input;
        getline(std::cin, input);
    
        if (input == "Quit" || input == "q") {
            status = false;
            break;
        } else if (input == "New User" || input == "1") {
            
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
                        
            transfer(receiver, transfer_amount, msg, sender);
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

1. Enter "New_User" instead of "New User" Note the space -> Get line

2. Msg only printing the first half or until the space or something? Probs until space in sentance which is also the problem above

3. Perform checks, i.e. if user exists, then continue. // prevent map out of range

4. UK Users - Done

5. Fee List + Intro msg - Done

6. Transfer_fees(); - Done

7. converter();

8. Smooth Flow

9. Crypto? or stop and do data structures instead idk

10. Creating a new user with the same name as an existing user.
*/