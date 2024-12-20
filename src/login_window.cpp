#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QApplication>
#include <QString>

#include "login_window.hpp"
#include "successor_window.hpp"

/*
 * Login Screen
 *  
*/


QWidget *window;
QWidget *successor_window;

QPushButton *exit_button;
QPushButton *login_button;
QLineEdit *line_edit;

loginWindow::loginWindow(QWidget *parent, QWidget *successor) : window(parent), successor_window(successor) {  
    exit_button = new QPushButton(QApplication::translate("exit_button", "Exit"), window);  
    login_button = new QPushButton(QApplication::translate("login_button", "Log In"), window);
    line_edit = new QLineEdit();
}

void loginWindow::onExitClicked() {
    QCoreApplication::quit();
}

void loginWindow::onLoginClicked() {
    QString correct_entry = QString::fromStdString("passkey");
    QString input_entry = line_edit->text();
    if(correct_entry == input_entry) { 
        successorWindow successor_window_qobj(successor_window);   
        successor_window_qobj.drawWindow();
        successor_window->show(); 
        window->close();
    } else {
        line_edit->setEchoMode(QLineEdit::Password);
    }
}

QWidget* loginWindow::getParent() {
    return window;
}

QPushButton* loginWindow::getExitButton() {
    return exit_button;
}

QPushButton* loginWindow::getLoginButton() {
    return login_button;
}

QLineEdit* loginWindow::getLineEdit() {
    return line_edit;
}

void loginWindow::drawWindow() {
    window->resize(500, 500);
    window->setMinimumSize(500,500);
    window->setWindowTitle(QApplication::translate("password_manager", "Password Manager"));
    
    //master key entry 
    QLabel *label = new QLabel(QApplication::translate("master_entry", "Master Key: "));
    line_edit->setEchoMode(QLineEdit::Password);
   
    //login and exit buttons
    login_button->setFixedSize(100, 50);
    exit_button->setFixedSize(100, 25);
     
    //layout box for master key entry and its corresponding label 
    QHBoxLayout *key_entry_layout = new QHBoxLayout();
    key_entry_layout->addSpacing(100);
    key_entry_layout->addWidget(label);
    key_entry_layout->addWidget(line_edit);
    key_entry_layout->addSpacing(100);

    //vertical and horizonal layout boxes for login button and exit button
    QVBoxLayout *button_layout = new QVBoxLayout();
    button_layout->addWidget(login_button, 2);
    button_layout->addWidget(exit_button, 1);
    
    QHBoxLayout *button_outer_layout = new QHBoxLayout();
    button_outer_layout->addLayout(button_layout);

    //title of the page
    QLabel *title_label = new QLabel(QApplication::translate("title_label", "Password Vault"));
    QFont *title_font = new QFont("Ariel", 30);
    title_label->setFont(*title_font);
    title_label->setMinimumSize(200, 50);
    title_label->setAlignment(Qt::AlignCenter);
    QHBoxLayout *title_layout = new QHBoxLayout();
    title_layout->addWidget(title_label);
    title_label->setMaximumSize(500, 800);
    
    //vertical layout for all components of login screen
    QVBoxLayout *vertical_layout = new QVBoxLayout();
    vertical_layout->addSpacing(150);
    vertical_layout->addLayout(title_layout);
    vertical_layout->addLayout(key_entry_layout);
    vertical_layout->addLayout(button_outer_layout);
    vertical_layout->addSpacing(150);

    window->setLayout(vertical_layout); 
}







