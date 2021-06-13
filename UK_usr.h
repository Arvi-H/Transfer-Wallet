#ifndef UK_USR
#define UK_USR
#include "INTER_usr.h"
#include <string>

class UK_usr : public INTER_usr {

public:
    UK_usr(std::string name = "Unknown UK User", double balance_amount = 0.0);
      
private:
    void fee_list();
    
};

#endif