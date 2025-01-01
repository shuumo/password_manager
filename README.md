## Technology Stack, Dependencies and Compilation
- Programming Language: C++17 with g++ v14.2.1 compiler
- GUI: Qt6
- Encryption Library: ~~OpenSSL~~ Libsodium 
- Data storage: CSV format file vault_data (stores encrypted values, comma seperated)
- Build tool: cmake

To compile, simply run `cmake CMakeLists.txt` and then `make`. 

## TO DO
- Implemen: Credential Search Feature.
- Change: Optimize usage of strings by using string_view. Particularly in cryptography.cpp.
- Change: Pass things by address (&) instead of copies and raw pointers.
- Change: Use smart pointers.
- Change: Replace credential class with a credential struct.
- Change: Currently missing some delete keywords for Qt widgets (I think?)
- Implement: Make the main-screen UI/UX nicer. Currently abit dry.

## MVP Requirements
1. Has a graphical user interface
3. Add credentials  to database
4. Encrypt the credentials using symmetric encryption
5. Decrypt the credentials using symmetric encryption
6. Modify the credentials
7. Remove the credentials
8. Store multiple credentials in the database
9. View all stored credentials
10. Lock the credentials behind one password using a HASH algorithm


## Some Info
#### Drawing the GUI
QT is "a cross-platform framework that is usually used as a graphical toolkit". Its what Im using in this.

#### Credential Unlocking
Can use a one-way hash to check if the login credential is correct. If the given passwords hash matches the hash stored, unlock the application. Can salt and pepper the hash as well.

#### Storing the Passwords
We can use basic symmetric cryptography, or more advanced asymmetric cryptography. Start with symmetric and move from there. Encrypt the password string then store it in the database. If the credential unlocking hash is correct we can fetch and decrypt the stored passwords.

#### General Structure
- `main.cpp` is the entry point of the program. It will create the initial objects required for QT6 to draw windows.
- `login_window.cpp` is an object that is responsible for the login screen. (needs refactoring)
- `successor_window.cpp` is an object that is responsible for the main post-login home screen. (needs refactoring)
- `csvreading.cpp` is responsible for file io.
- `hashing.cpp` is responsible for hash related functions and checking in regards to the master key.
- `encryption.cpp` is responsible for the encryption and decryption of credential data.
- `credential.cpp` is objects that contain the credentials data in their encrypted form.

## UI GOALS

#### Unlock the Password Manager:
Enter a master password and unlock access.

#### View Stored Credentials:
Display a list of saved credentials.

#### Add/Edit/Delete Credentials:
Provide forms or buttons for creating, modifying, or removing entries.

#### TODO: Search for Credentials:    
Allow users to search for specific credentials.

#### Log Out or Exit:
Provide an option to lock or exit the application securely.

use 1password or somthing instead ;)
