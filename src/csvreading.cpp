#include <fstream>
#include <string>

#include "csvreading.hpp"

std::vector<credential> readio::createCredentialVector() { 
    std::vector<credential> listVector;
    std::ifstream fileReader("vault_data");
    
    if(!fileReader.is_open()) {
        std::ofstream fileWriter("vault_data"); 
        fileWriter.close();
        return listVector;
    }
    
    int id = -1;
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
    std::string toAppend = cred.getCredentialName()
        += std::string(",") += cred.getCredentialUser()
        += std::string(",") += cred.getCredentialPass();

    std::ofstream fileWriter("vault_data", std::ios::app);
    fileWriter << toAppend << '\n';
    fileWriter.close();
    return;
}

void readio::removeCredFromFile(credential cred, std::vector<credential> rebuildTemplate) {
    // delete credential from parameter vector then rebuild
    // the file using the vector
    int targetIdx = cred.getCredentialIdentifier();
    rebuildTemplate.erase(std::next(rebuildTemplate.begin(), targetIdx));
    readio::rebuildDataVault(rebuildTemplate); 
    return;
}

void readio::editCredInFile(credential cred, std::vector<credential> rebuildTemplate) {
    // modify the credential in parameter vector then rebuild
    // the file using the vector
    int targetIdx = cred.getCredentialIdentifier();
    rebuildTemplate[targetIdx].setName(cred.getCredentialName());
    rebuildTemplate[targetIdx].setUser(cred.getCredentialUser());
    rebuildTemplate[targetIdx].setPass(cred.getCredentialPass());
    readio::rebuildDataVault(rebuildTemplate); 
    return;
}

void readio::rebuildDataVault(std::vector<credential> rebuildTemplate) {
    std::fstream fileWriter;
    fileWriter.open("vault_data", std::ofstream::out|std::ofstream::trunc);
    fileWriter.flush();
    fileWriter.close();
    for(auto& cred : rebuildTemplate) {
        readio::addCredToFile(cred);
    } 
    return;
}
