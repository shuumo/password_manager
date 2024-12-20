#include <iostream>
#include <QWidget>
#include <QApplication>

#include "login_window.hpp"

/*
 * Main
 * 
*/
int main(int argc, char **argv) {
    QApplication app(argc, argv); 
    QWidget login_parent_widget;
    QWidget main_parent_widget; 

    loginWindow login_window_qobj(&login_parent_widget, &main_parent_widget);
    login_window_qobj.drawWindow(); 

    login_parent_widget.show();
    
    // Slots
    QObject::connect(login_window_qobj.getExitButton(), &QPushButton::clicked, &login_window_qobj, &loginWindow::onExitClicked);
    QObject::connect(login_window_qobj.getLoginButton(), &QPushButton::clicked, &login_window_qobj, &loginWindow::onLoginClicked);     

    return app.exec();
}


