#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QApplication>
#include <QString>
#include <QInputDialog>
#include <QTime>

#include "login_window.hpp"
#include "csvreading.hpp"
#include "cryptography.hpp"

#include <iostream>
/*
 * Login Screen
 *
*/


loginWindow::loginWindow(QWidget *parent, QWidget *successor) : window(parent), successor_window(successor) {  
    exit_button = new QPushButton(QApplication::translate("exit_button", "Exit"), window);  
    login_button = new QPushButton(QApplication::translate("login_button", "Log In"), window);
    line_edit = new QLineEdit();
    successorWindowObj = new successorWindow(successor_window);

}

void loginWindow::onExitClicked() {
    QCoreApplication::quit();
}

void loginWindow::onLoginClicked() {
    login_button->setText(QApplication::translate("exit_button", "Hashing..."));
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    
    std::string correct_entry = readio::getStorageHash();
    std::string input_entry = line_edit->text().toStdString();
    if(encryptor::verifyMasterHash(input_entry, correct_entry)) {
        std::string salt = readio::getStorageSalt();
        successorWindowObj->drawWindow(encryptor::masterToKey(input_entry, salt));
        successor_window->show(); 
        window->close();
    }
    login_button->setText(QApplication::translate("login_button", "Log In"));
}

successorWindow* loginWindow::getSuccessorWindowObj() {
    return successorWindowObj;
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
    window->resize(600, 500);
    window->setMinimumSize(600,500);
    window->setWindowTitle(QApplication::translate("password_manager", "Password Manager"));
    
    //master key entry 
    QLabel *label = new QLabel(QApplication::translate("master_entry", "Master Key: "));
    line_edit->setEchoMode(QLineEdit::Password);

    //login and exit buttons
    login_button->setFixedSize(100, 50);
    login_button->setDefault(true);
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

    window->setFocusProxy(line_edit); 
    window->setTabOrder(line_edit, login_button);
    
    if(readio::keyHashExists() == 0) {
        bool passkey_selection;
        QString passkey = QInputDialog::getText(window, tr("Vault Setup"), tr("Setup a Passkey to enter your vault: "), 
                QLineEdit::PasswordEchoOnEdit, "", &passkey_selection);
        std::string stdpasskey = passkey.toStdString();
        if(passkey_selection == false || stdpasskey.size() > 128) {
            QCoreApplication::quit();
            std::exit(0);
        }
        std::string key_salt = encryptor::generateHashSalt();
        readio::newStorageHash(stdpasskey, key_salt);

    }

}


