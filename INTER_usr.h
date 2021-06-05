#ifndef INTER_USR
#define INTER_USR
#include <string>

class INTER_usr {

public:
    double curr_balance;
    double init_bal;
    double bal_change;

    std::string usr_name;
    std::string receiver_name;
    std::string sender_name;

    std::string message = "";
    std::string currency = "$";

    // Func overriden in all classes | Runtime Polymorphism
    virtual void check_status();
    // virtual void check_status() = 0;


    void money_transfer(INTER_usr &receiver, double amount, std::string msg = "");


    void transfer_msg();


    void recent_msg();


    bool sufficient_bal(double amount);


    void hidden_fees(INTER_usr &usr);
 
 private:
    virtual void fee_list();
};

#endif 