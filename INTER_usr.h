#ifndef INTER_USR
#define INTER_USR
#include <string>

class INTER_usr {

public:
    double usr_money;
    double init_bal;
    double bal_change;

    std::string message = "- - None - -";
    std::string name;
    std::string receiver_name;
    std::string currency = "$";

    void check_status();
    void money_transfer(INTER_usr &receiver, double amount, std::string msg);
    void transfer_msg();
};

#endif