#include <credential.hpp>

int id;
std::string name;
std::string pass;
std::string user;

credential::credential(int i, std::string n, std::string u, std::string p) : id(i), name(n), user(u), pass(p)  {
    // constructor;
}

void credential::setId(int i) {
    id = i;
}

void credential::setName(std::string n) {
    name = n;
}

void credential::setUser(std::string u) {
    user = u;
}

void credential::setPass(std::string p) {
    pass = p;
}

int credential::getCredentialIdentifier() {
    return id;
}

std::string credential::getCredentialName() {
    return name;
}

std::string credential::getCredentialUser() {
    return user;
}

std::string credential::getCredentialPass() {
    return pass;
}
