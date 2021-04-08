#ifndef UK_USR
#define UK_USR
#include "INTER_usr.h"


class UK_usr : public INTER_usr {
    // Implementing virtual function message
    std::string message(); 

    // Implementing virtual function fees
    double fees();
};

#endif
