#ifndef US_USR
#define US_USR
#include "INTER_usr.h"
#include <string>

class US_usr : public INTER_usr {

public:
    
    US_usr(std::string usr_name = "Unknown User", double balance_amount = 0.0);
    
    
    void check_status();
    void hidden_fees(US_usr usr);

private:
    void fee_list();

};

#endif