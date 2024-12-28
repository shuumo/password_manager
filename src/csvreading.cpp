#include <fstream>
#include <string>

#include "csvreading.hpp"
#include "cryptography.hpp"

void readio::createCredentialVector(std::vector<credential> *listVector) { 
    std::ifstream fileReader("vault_data"); 
    listVector->clear(); 
    
    int id = -1;
    std::string hash;
    std::getline(fileReader, hash, '\n');
    std::getline(fileReader, hash, '\n');
    std::string n, u, p;

    while(std::getline(fileReader, n, ',')
            && std::getline(fileReader, u, ',')
            && std::getline(fileReader, p, '\n')) {
        id++;
        credential cred(id, n, u, p);
        listVector->push_back(cred);
    }
    fileReader.close();
    return;
}

void readio::addCredToFile(credential cred) {
    std::string toAppend = cred.getCredentialName()
        += std::string(",") += cred.getCredentialUser()
        += std::string(",") += cred.getCredentialPass();

    std::ofstream fileWriter("vault_data", std::ios::app);
    fileWriter << toAppend << '\n';
    fileWriter.close();
    return;
}

void readio::removeCredFromFile(credential cred, std::vector<credential> rebuildTemplate) {
    int targetIdx = cred.getCredentialIdentifier();
    rebuildTemplate.erase(std::next(rebuildTemplate.begin(), targetIdx));
    readio::rebuildDataVault(rebuildTemplate); 
    return;
}

void readio::editCredInFile(credential cred, std::vector<credential> rebuildTemplate) {
    int targetIdx = cred.getCredentialIdentifier();
    rebuildTemplate[targetIdx].setName(cred.getCredentialName());
    rebuildTemplate[targetIdx].setUser(cred.getCredentialUser());
    rebuildTemplate[targetIdx].setPass(cred.getCredentialPass());
    readio::rebuildDataVault(rebuildTemplate); 
    return;
}

void readio::rebuildDataVault(std::vector<credential> rebuildTemplate) {
    std::ifstream fileReader("vault_data");  
    std::string hash;
    std::string salt;
    std::getline(fileReader, hash, '#');
    std::getline(fileReader, salt, '#');
    fileReader.close();
    std::fstream fileWriter;
    fileWriter.open("vault_data", std::ofstream::out|std::ofstream::trunc);
    fileWriter.flush();
    fileWriter.close();
    std::ofstream fileRestore("vault_data", std::ios::app);
    fileRestore << hash << '#';
    fileRestore << salt << '#' << '\n';
    fileRestore.close();
    for(auto& cred : rebuildTemplate) {
        readio::addCredToFile(cred);
    } 
    return;
}

void readio::newStorageHash(std::string storage_hash, std::string storage_salt) {
    std::fstream fileDestroy;
    fileDestroy.open("vault_data", std::ofstream::out|std::ofstream::trunc);
    fileDestroy.flush();
    fileDestroy.close(); 
    std::ofstream fileWriter("vault_data", std::ios::app);
    std::string hashedKey = encryptor::storageMasterHash(storage_hash);
    fileWriter << hashedKey << '#' << '\n';
    std::string encodedSalt = encryptor::encodeString(storage_salt); 
    fileWriter << encodedSalt << '#' << '\n';
    fileWriter.close();
    return;
}

std::string readio::getStorageHash() { 
    std::ifstream fileReader("vault_data"); 
    std::string storageHash;
    std::getline(fileReader, storageHash, '#'); 
    fileReader.close();
    return storageHash;
}

std::string readio::getStorageSalt() {
    std::ifstream fileReader("vault_data"); 
    std::string storageHash;
    std::string storageSalt;
    std::getline(fileReader, storageHash, '#');
    std::getline(fileReader, storageSalt, '#'); 
    fileReader.close();
    return encryptor::decodeString(storageSalt);

}

int readio::keyHashExists() { 
    std::ifstream fileReader("vault_data"); 
   
    if(!fileReader.is_open()) {
        std::ofstream fileWriter("vault_data"); 
        fileWriter.close();
        return 0;
    }
    
    std::string storageHash;
    if(!std::getline(fileReader, storageHash, '#')) {
        fileReader.close();
        return 0;
    }
    
    if(fileReader.eof() || fileReader.fail()) {
        fileReader.close();
        return 0;
    }

    fileReader.close();
    return 1;
}
