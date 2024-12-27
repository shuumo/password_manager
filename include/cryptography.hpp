#ifndef ENCRYPTION
#define ENCRYPTION

#include <string>

class encryptor {
public:
    static std::string encryptString(std::string str, std::string key); 
    static std::string decryptString(std::string str, std::string key);
    static std::string encodeString(std::string str);
    static std::string decodeString(std::string str);
    static std::string masterToKey(std::string master, std::string salt);
    static std::string generateHashSalt();
    static std::string storageMasterHash(std::string master);
    static int verifyMasterHash(std::string master, std::string sotrage_hash);
    static void errOccured();
};


#endif
