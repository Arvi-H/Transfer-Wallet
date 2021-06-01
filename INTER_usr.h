#ifndef INTER_USR
#define INTER_USR
#include <string>

class INTER_usr {

public:
    double curr_balance;
    double init_bal;
    double bal_change;

    std::string name;
    std::string receiver_name;
    std::string sender_name;

    std::string message = "";
    std::string currency = "$";

    void check_status();
    void money_transfer(INTER_usr &receiver, double amount, std::string msg);
    void transfer_msg();
    void recent_msg();
    bool sufficient_bal(double amount);
};

#endif 