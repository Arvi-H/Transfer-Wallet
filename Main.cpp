#include "INTER_usr.h"
#include "US_usr.h"
#include "UK_usr.h"
#include <iostream>
#include <vector>
#include <map>


void intro() {
   std::cout << "- - - - - - - - - - - - - Transfer Wallet Commands - - - - - - - - - - \n" << std::endl;
   std::cout << "Create a new user by typing \"New_User\" or \"1\".\n";
   std::cout << "Transfer money from one user to another by typing \"Money_Transfer\" or \"2\".\n";
   std::cout << "Check the status of your user by typing \"Check_Status\" or \"3\".\n";
   std::cout << "Stop the program by typing \"Quit\" or \"Q\".\n";
   std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n" << std::endl;
}

int main() {

std::map<std::string, INTER_usr*> users;

std::string usr_name;
std::string sender;
std::string active_usr;
std::string msg;
INTER_usr rec;

std::string receiver;
double balance;
double transfer_amount;

bool status = true;

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
        
      std::cout << "Who is sending the money?";
      std::cin >> sender;
      std::cout << "Who is receiveing the money?";
      std::cin >> receiver;
      std::cout << "How much money is " << sender << " sending to $receiver?";
      std::cin >> transfer_amount;
      std::cout << "Enter Your message";
      std::cin >> msg;

      users.at(receiver) = &rec;

      users.at(sender)->money_transfer(rec, transfer_amount, msg);

      intro();

   } else if (input == "Check_Status" || input ==  "3") {

      std::cout << "Which user are you checking the status of?";
      std::cin >> active_usr;

      users.at(active_usr)->check_status();

      intro();
   } 
}







// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// US_usr user1; 




// users.insert({usr_name, new US_usr {usr_name, amount} }); 
 
// usr_name = "casey";
// amount = 2000.0;

// users.insert({usr_name, new US_usr {usr_name, amount} }); 

// INTER_usr receiver;
// users.at("casey") = &receiver;

// users.at("arvi")->money_transfer(receiver, 400, "test");
// users.at("arvi")->check_status();

// std::cout << users.at("arvi")->curr_balance;
// std::cout << users.at("casey");

//user1.check_status();

}