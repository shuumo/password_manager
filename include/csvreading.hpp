#ifndef CSVREAD
#define CSVREAD

#include <vector>

#include "credential.hpp"

class readio {
public:
    static void createCredentialVector(std::vector<credential> *listVector);
    static void addCredToFile(credential cred);
    static void removeCredFromFile(credential cred, std::vector<credential> rebuildTemplate);
    static void editCredInFile(credential cred, std::vector<credential> rebuildTemplate);
    static void rebuildDataVault(std::vector<credential> rebuildTemplate);
    static int keyHashExists();
    static void newStorageHash(std::string storage_hash, std::string storage_salt);
    static std::string getStorageHash();
    static std::string getStorageSalt();
};

#endif
