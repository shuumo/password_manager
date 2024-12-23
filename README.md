## Technology Stack, Dependencies and Compilation
- Programming Language: C++17 with g++ v14.2.1 compiler
- GUI: Qt6
- Data storage: CSV format file
- Build tool: cmake

To compile, simply run `cmake CMakeLists.txt` and then `make`. 


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


## Concepts to use
#### Drawing the GUI
QT is "a cross-platform framework that is usually used as a graphical toolkit". We can use it in C++ to draw a graphical user interface for our program. 

#### Credential Unlocking
Can use a one-way hash to check if the login credential is correct. If the given passwords hash matches the hash stored, unlock the application. Can salt and pepper the hash as well.

#### Storing the Passwords
We can use basic symmetric cryptography, or more advanced asymmetric cryptography. Start with symmetric and move from there. Encrypt the password string then store it in the database. If the credential unlocking hash is correct we can fetch and decrypt the stored passwords.

#### General Structure
- `main.cpp` is the entry point of the program. It will create the initial objects required for QT6 to draw windows.
- `login_window.cpp` will be an object that is responsible for the login screen and its related sockets.
- `successor_window.cpp` will be an object that is responsible for the main post-login home screen and its related sockets. 
- `csvreading.cpp` will be responsible for file io.
- `hashing.cpp` will be responsible for hash related functions and checking in regards to the master key.
- `encryption.cpp` will be responsible for the encryption and decryption of credential data.
- `credential.cpp` will be objects that contain the credentials data in their encrypted form.

## UI GOALS

#### Unlock the Password Manager:
Enter a master password and unlock access.

#### View Stored Credentials:
Display a list of saved credentials.

#### Add/Edit/Delete Credentials:
Provide forms or buttons for creating, modifying, or removing entries.

#### Search for Credentials:
Allow users to search for specific credentials.

#### Log Out or Exit:
Provide an option to lock or exit the application securely.
