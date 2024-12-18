## Getting Started

Requirements of the program
1. Has a graphical user interface
3. Add credentials  to database
4. Encrypt the credentials 
5. Modify the credentials
6. Remove the credentials
7. Store multiple credentials in the database
8. View all stored credentials
9. Lock the credentials behind one password

## Technology Stack
Programming Language: C++
GUI: Qt
Database: CSV file, or any non-relational way of storing data

## Concepts to use
#### Drawing the GUI
QT is "a cross-platform framework that is usually used as a graphical toolkit". We can use it in C++ to draw a graphical user interface for our program. 

#### Credential Unlocking
Can use a one-way hash to check if the login credential is correct. If the given passwords hash matches the hash stored, unlock the application. Can salt and pepper the hash as well.

#### Storing the Passwords
We can use basic symmetric cryptography, or more advanced asymmetric cryptography. Start with symmetric and move from there. Encrypt the password string then store it in the database. If the credential unlocking hash is correct we can fetch and decrypt the stored passwords.

#### General Structure
The files are going to be as follows:
- `main.cpp`: General stuff like drawing the QT GUI. I am trying to keep the GUI logic separate.
- `control.cpp`: The main central back end system.  The brains of the program, it'll let the other modules be simple and should hopefully reduce coupling. Will maybe have most of the code in it, communicates with the other modules.
- `credential.cpp`: These will be the objects that store credential data.
- `encryption.cpp`: In charge of hashing, encrypting and decrypting shit. The cyber security module of the password manager. Will also be in charge of salt and peppering data.
- `writer.cpp`: Reads and writes to a file that will be a database.


The `main.cpp` needs to stay focused on drawing the GUI and delegating tasks to `control.cpp`. A button press in the QT GUI should be a call to the `control.cpp`.
Since `control.cpp` is the "brain" of the system, it’s a good place for core workflows like:
- Adding credentials.
- Saving/loading from `writer.cpp`.
- Encrypting/decrypting using `encryption.cpp`.
This keeps the other modules "dumb" and hopefully should avoid tight coupling. Other modules can then be easily modified when needed. The `credential.cpp` file will be a simple object for storing credential data in a simple class. It is important to avoid bloating this file keep it purely data focused. The other files will do operations on the `credential.cpp` file. The functions this file can have will be to modify itself. The `encryption.cpp`file handles all security concerns like hashing master passwords, encrypting and decrypting credentials and salt and pepper logic. This is where the modular nature of this architecture comes in handy: It would be very easy to swap algorithms later if needed.  Its important to ensure`writer.cpp` solely handles file I/O when called by `control.cpp`. `writer.cpp` writes encrypted data to disk and reads it back securely. Keeps `control.cpp` clean by abstracting file operations.

Why am I doing it this way? The main reason is that this project  is to help me **LEARN**. By dividing the program up into modular sections like this it means I can tackle each module one by one.  Focusing and learning one concept at a time. I reckon this design is simple and modular, maintainable and scalable. Each file has a clear responsibility. You can debug and modify each module independently. The centralized control makes it easy for me (and hopefully others) to understand what's going on: `control.cpp` becomes the "mediator", delegating tasks to other modules. Its like an in between between the front and back end. If I add more features (e.g., password strength checks), I can extend `control.cpp` or create more small modules that add onto the central file depending on how much I would need to add for each feature. 



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
