#include "INTER_usr.h"
#include "US_usr.h"
#include "UK_usr.h"
#include <iostream>
#include <vector>
#include <map>

int main() {
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - -   Command Line I/O  Pseudocode - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

/* 
   while (cin != Quit) {

      
      if (cin == "New User" || "1") {
         
         print("Enter User Name")
         usr_name = std::cin;
         print("Enter money amount")
         amount = std::cin
         
         users.insert({usr_name, new US_usr {usr_name, amount} }); 
      
      } else if (cin == "Money Transfer" || "2") {
         
         print("Who is sending the money?")
         sender = std::cin;
         print("Who is receiveing the money?")
         receiver = std::cin
         print("How much money is $sender sending to $receiver?")
         amount = std::cin
         print("Enter Your message")
         message = std::cin

         users.at(sender)->money_transfer(receiver, amount, message);


      } else if (cin == "Check Status" || "3") {

         print("Which user are you checking the status of??")
         active_usr = std::cin;

         users.at(active_usr)->check_status();


      } else {
         print(Try a different command.)
         std::cin;
      }


   }




*/






// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// US_usr user1; 


std::string usr_name = "arvi";
double amount = 1000.0;


std::map<std::string, INTER_usr*> users;
users.insert({usr_name, new US_usr {usr_name, amount} }); 
 
usr_name = "casey";
amount = 2000.0;

users.insert({usr_name, new US_usr {usr_name, amount} }); 

INTER_usr receiver;
users.at("casey") = &receiver;

users.at("arvi")->money_transfer(receiver, 400, "test");
users.at("arvi")->check_status();

std::cout << users.at("arvi")->curr_balance;
std::cout << users.at("casey");

//user1.check_status();

}