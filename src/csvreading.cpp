#include <fstream>
#include <string>

#include "csvreading.hpp"

std::vector<credential> readio::createCredentialVector() { 
    std::vector<credential> listVector;
    std::ifstream fileReader("vault_data");
    
    if(!fileReader.is_open()) {
        std::ofstream fileWriter("vault_data"); 
        fileWriter.close();
    }
    
    int id = 0;
    std::string n, u, p;

    while(std::getline(fileReader, n, ',')
            && std::getline(fileReader, u, ',')
            && std::getline(fileReader, p, '\n')) {
        id++;
        credential cred(id, n, u, p);
        listVector.push_back(cred);
    }
    
    fileReader.close();
    return listVector;
}

void readio::addCredToFile(credential cred) {
    cred.setName("hello world");
    return;
}

void readio::removeCredFromFile(credential cred) {
    cred.setName("hello world");
    return;
}

void readio::editCredInFile(credential cred) {
    cred.setName("hello world");
    return;
}
