#include "INTER_usr.cpp"

class US_usr : public INTER_usr {

public:

    US_usr(int amount) {
        amount = usr_money;
    }


    // Implementing virtual function message
    std::string message(); 

    // Implementing virtual function fees
    double fees();




};
