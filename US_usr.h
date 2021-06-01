#ifndef US_USR
#define US_USR
#include "INTER_usr.h"
#include <string>

class US_usr : public INTER_usr {

public:
    US_usr(std::string usr_name = "Unknown US User", double balance_amount = 0.0);
    void check_status();

private:
    void fee_list();
    
};

#endif