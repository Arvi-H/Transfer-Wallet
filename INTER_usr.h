#ifndef INTER_USR
#define INTER_USR
#include <string>

class INTER_usr {

public:
    double usr_money;
    std::string message;
    std::string name;
    
    void check_status();
    void money_transfer(INTER_usr receiver, double amount, std::string msg);

};

#endif