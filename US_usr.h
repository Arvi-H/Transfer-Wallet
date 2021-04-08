#ifndef US_USR
#define US_USR
#include "INTER_usr.h"


class US_usr : public INTER_usr {
    // Implementing virtual function message
    std::string message(); 

    // Implementing virtual function fees
    double fees();
};

#endif