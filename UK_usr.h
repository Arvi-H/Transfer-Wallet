#ifndef UK_USR
#define UK_USR
#include "INTER_usr.h"
#include <string>

class UK_usr : public INTER_usr {

public:
    
    UK_usr(std::string usr_name = "Unknown UK User", double balance_amount = 0.0);

    void check_status();
    
private:
    void fee_list();

};


#endif