#ifndef CSVREAD
#define CSVREAD

#include <vector>

#include "credential.hpp"

class readio {
public:
    static std::vector<credential> createCredentialVector();
    static void addCredToFile(credential cred);
    static void removeCredFromFile(credential cred);
    static void editCredInFile(credential cred);
};

#endif
