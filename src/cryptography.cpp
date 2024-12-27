#include <iostream>
#include <sodium.h>

#include "cryptography.hpp"

std::string encryptor::encryptString(std::string str, std::string key) {
    unsigned char nonce[crypto_aead_aes256gcm_NPUBBYTES];
    unsigned char *ciphertext = new unsigned char[str.size() + crypto_aead_aes256gcm_ABYTES];
    unsigned long long ciphertext_len;
    
    randombytes_buf(nonce, sizeof nonce);

    crypto_aead_aes256gcm_encrypt(ciphertext, &ciphertext_len, 
            reinterpret_cast<const unsigned char*>(str.data()), str.size(), 
            NULL, 0,
            NULL, nonce, reinterpret_cast<const unsigned char*>(key.data()));
    std::string encrypted_str(reinterpret_cast<char*>(ciphertext), sizeof ciphertext);
    std::string nonce_string(reinterpret_cast<char*>(nonce), sizeof nonce);
    delete[] ciphertext;
    return nonce_string + encrypted_str;
}

std::string encryptor::decryptString(std::string str, std::string key) {
    std::string nonce = str.substr(0, 12);
    std::string ciphertext = str.substr(12);

    unsigned char *decrypted = new unsigned char[ciphertext.size()];
    unsigned long long decrypted_len;
    
    if(ciphertext.size() < crypto_aead_aes256gcm_ABYTES ||
            crypto_aead_aes256gcm_decrypt(decrypted, &decrypted_len,
                NULL,
                reinterpret_cast<const unsigned char*>(ciphertext.data()), ciphertext.size(),
                NULL, 0,
                reinterpret_cast<const unsigned char*>(nonce.data()), 
                reinterpret_cast<const unsigned char*>(key.data())) != 0) {

    }
    std::string decrypted_str(reinterpret_cast<char*>(decrypted), decrypted_len);
    delete[] decrypted;
    return decrypted_str;
}

std::string encryptor::encodeString(std::string str) {
    unsigned int b64_maxlen = sodium_base64_encoded_len(str.size(), sodium_base64_VARIANT_URLSAFE);
    char *b64 = new char[b64_maxlen];
    sodium_bin2base64(b64, b64_maxlen, 
            reinterpret_cast<unsigned char*>(str.data()), str.size(),
            sodium_base64_VARIANT_URLSAFE);

    std::string b64_encoded(b64, sizeof b64);
    delete[] b64;
    return b64_encoded;
}

std::string encryptor::decodeString(std::string str) {
   unsigned int bin_maxlen = str.size() / 4 * 3 + 1;
   unsigned char *bin = new unsigned char[bin_maxlen];
   size_t bin_len;
   sodium_base642bin(bin, bin_maxlen,
           str.data(), str.size(),
           NULL, &bin_len, NULL, sodium_base64_VARIANT_URLSAFE);
   std::string b64_decoded(reinterpret_cast<char*>(bin), bin_len);
   delete[] bin;
   return b64_decoded;
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
