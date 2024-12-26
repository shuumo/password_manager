#include <iostream>
#include <sodium.h>

#include "encrypt.hpp"

//TODO
std::string encryptor::encryptString(std::string str, std::string key) {
    std::cout << "encrypt called" << '\n'; 

    
    return str;
}

//TODO
std::string encryptor::decryptString(std::string str, std::string key, std::string nonce) {
    std::cout << "decrypt called" << '\n'; 
    

    return str;
}

std::string encryptor::generateNonce() {

}

std::string encryptor::generateHashSalt() {
    unsigned char salt[crypto_pwhash_SALTBYTES];
    randombytes_buf(salt, sizeof salt);
    std::string str(reinterpret_cast<char*>(salt), sizeof salt);
    return str;
}

std::string encryptor::masterToKey(std::string master, std::string salt) {
    unsigned char key[crypto_box_SEEDBYTES];

    if(crypto_pwhash
            (key, sizeof key, master.data(), master.size(), 
             reinterpret_cast<unsigned char*>(salt.data()),
             crypto_pwhash_OPSLIMIT_INTERACTIVE, 
             crypto_pwhash_MEMLIMIT_INTERACTIVE,
             crypto_pwhash_ALG_DEFAULT) != 0) {
        encryptor::errOccured();
    }
    std::string outputKey(reinterpret_cast<char*>(key), sizeof key);
    return outputKey;
}

std::string encryptor::storageMasterHash(std::string master) {
    char hashed_password[crypto_pwhash_STRBYTES];
    if(crypto_pwhash_str
            (hashed_password, master.data(), master.size(),
             crypto_pwhash_OPSLIMIT_SENSITIVE, 
             crypto_pwhash_MEMLIMIT_SENSITIVE) != 0) {
        encryptor::errOccured();
    }
    std::string outputHash(reinterpret_cast<char*>(hashed_password), sizeof hashed_password);
    return outputHash;
}

int encryptor::verifyMasterHash(std::string master, std::string storage_hash) {
    if(crypto_pwhash_str_verify
            (storage_hash.data(),
             master.data(),
             master.size()) != 0) {
        return 0;
    }
    return 1;
}

void encryptor::errOccured() {
    std::cout << "FAILURE IN ENCRYPTION" << std::endl;
    std::abort();
}
