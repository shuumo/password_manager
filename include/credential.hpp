#ifndef CREDENTIAL
#define CREDENTIAL

#include <string>

class credential {
private:
    int id;
    std::string name;
    std::string user;
    std::string pass;

public:
    credential(int i, std::string n, std::string u, std::string p);
   
    // member modifiers
    void setId(int i);
    void setName(std::string n);
    void setUser(std::string u);
    void setPass(std::string p);

    // getters
    int getCredentialIdentifier();
    std::string getCredentialName();
    std::string getCredentialUser();
    std::string getCredentialPass();
};

#endif
