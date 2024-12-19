#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QFont>
#include <QApplication>

#include "login_window.hpp"

QWidget *window;
QPushButton *exit_button;

loginWindow::loginWindow(QWidget *parent) : window(parent) {  
    exit_button = new QPushButton(QApplication::translate("exit_button", "Exit"), window); 
    // constructor here;
}

void loginWindow::onExitClicked() {
    QCoreApplication::quit();
}

QWidget* loginWindow::getParent() {
    return window;
}

QPushButton* loginWindow::getExitButton() {
    return exit_button;
}

void loginWindow::drawWindow() {
    window->resize(500, 500);
    window->setMinimumSize(500,500);
    window->setWindowTitle(QApplication::translate("password_manager", "Password Manager"));
    
    //master key entry 
    QLabel *label = new QLabel(QApplication::translate("master_entry", "Master Key: "));
    QLineEdit *line_edit = new QLineEdit();
    line_edit->setEchoMode(QLineEdit::Password);
   
    //login and exit buttons
    QPushButton *button = new QPushButton(QApplication::translate("login_button", "Log In"), window);
    //QPushButton *exit_button = new QPushButton(QApplication::translate("exit_button", "Exit"), window); 
    button->setFixedSize(100, 50);
    exit_button->setFixedSize(100, 25);
     
    //layout box for master key entry and its corresponding label 
    QHBoxLayout *key_entry_layout = new QHBoxLayout();
    key_entry_layout->addSpacing(100);
    key_entry_layout->addWidget(label);
    key_entry_layout->addWidget(line_edit);
    key_entry_layout->addSpacing(100);

    //vertical and horizonal layout boxes for login button and exit button
    QVBoxLayout *button_layout = new QVBoxLayout();
    button_layout->addWidget(button, 2);
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







