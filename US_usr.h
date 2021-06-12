#ifndef US_USR
#define US_USR
#include "INTER_usr.h"
#include <string>

class US_usr : public INTER_usr {

public:
    US_usr(std::string name = "Unknown US User", double balance_amount = 0.0);
      
private:
    void fee_list();
    
};

#endif