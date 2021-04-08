#ifndef INTER_USR
#define INTER_USR
#include <string>

class INTER_usr {
    double convert();
    double money_transfer();
    std::string currency();
    virtual std::string message();
    void get_message();
    virtual double fees();
};

#endif