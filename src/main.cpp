#include <iostream>
#include <QWidget>
#include <QApplication>

#include "login_window.hpp"

/*
 * Login GUI Stuff using QT6
 *
*/
int main(int argc, char **argv) {
    QApplication app(argc, argv); 
    QWidget window;
    
    loginWindow loginWindowSetup(&window);
    loginWindowSetup.drawWindow(); 

    window.show();
   
    QObject::connect(loginWindowSetup.getExitButton(), &QPushButton::clicked, &loginWindowSetup, &loginWindow::onExitClicked);
    
    return app.exec();
}


