#ifndef CREDS_HPP
#define CREDS_HPP

/* When credentials are read from the databaase,
 * stores credential data for the credential vector
 * in these credential object.
*/ 

#include <string>

class credential {
private:
    int id;
    std::string credName;
    std::string username;
    std::string password;
    
public:
    credential(int identifier, std::string name, std::string user, std::string pass);
    int getId();
    std::string getName();
    std::string getEncryptedUser();
    std::string getEncryptedPass();
}


#endif
