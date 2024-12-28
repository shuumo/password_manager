#include <QApplication>
#include <QVBoxLayout>
#include <QFont>
#include <QSpacerItem>
#include <QSizePolicy>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QLineEdit>
#include <QDialog>
#include <vector>

#include "successor_window.hpp"
#include "cryptography.hpp"
#include "credential.hpp"
#include "csvreading.hpp"

#include <iostream>
/*
 * Main screen (home menu, post login)
*/


successorWindow::successorWindow(QWidget *parent) : main_window(parent) {
    add_button = new QPushButton(QApplication::translate("add_credential", "Add Credential")); 
    edit_button = new QPushButton(QApplication::translate("edit_credential", "Edit Credential"));  
    remove_button = new QPushButton(QApplication::translate("remove_credential", "Destroy Credential"));
    logout_button = new QPushButton(QApplication::translate("exit_program", "Log Out"));
    
    credential_list_widget = new QListWidget(); 
    
    cred_title = new QLabel(QApplication::translate("cred_title", " "));
    cred_user = new QLabel(QApplication::translate("cred_user", " "));
    cred_pass = new QLabel(QApplication::translate("cred_pass", " "));

    readio::createCredentialVector(&credentialList);
    
    decryptkey = "";
}

void successorWindow::onLogoutClicked() {
    QCoreApplication::quit();
}

void successorWindow::onAddClicked() { 
    QDialog addCredPopUp(main_window);
    QLabel name_label(QApplication::translate("name_label_add", "Enter Credential Name"));
    QLineEdit name_entry;
    QLabel user_label(QApplication::translate("user_label_add", "Enter Credential Username"));
    QLineEdit user_entry;
    QLabel pass_label(QApplication::translate("pass_label_add", "Enter Credential Password"));
    QLineEdit pass_entry;
    pass_entry.setEchoMode(QLineEdit::Password);
    QVBoxLayout internal_add_vbox; 
    internal_add_vbox.addWidget(&name_label); 
    internal_add_vbox.addWidget(&name_entry); 
    internal_add_vbox.addWidget(&user_label); 
    internal_add_vbox.addWidget(&user_entry); 
    internal_add_vbox.addWidget(&pass_label); 
    internal_add_vbox.addWidget(&pass_entry); 
    QPushButton confirm_add_button(QApplication::translate("confirm_add_button", "Confirm")); 
    QPushButton cancel_add_button(QApplication::translate("cancel_add_button", "Cancel"));  
    QHBoxLayout internal_add_hbox;
    internal_add_hbox.addWidget(&confirm_add_button);
    internal_add_hbox.addWidget(&cancel_add_button); 
    internal_add_vbox.addLayout(&internal_add_hbox);
    addCredPopUp.setLayout(&internal_add_vbox); 
    
    // confirm button
    QObject::connect(&confirm_add_button, &QPushButton::clicked, &addCredPopUp, 
           [&]() {
           if(name_entry.text().toStdString().size() < 1) { addCredPopUp.close(); return;} 
           std::string title_entered = encryptor::encryptString(name_entry.text().toStdString(), decryptkey);
           std::string user_entered = encryptor::encryptString(user_entry.text().toStdString(), decryptkey);
           std::string pass_entered = encryptor::encryptString(pass_entry.text().toStdString(), decryptkey);
           credential new_credential(0, encryptor::encodeString(title_entered), encryptor::encodeString(user_entered), 
                   encryptor::encodeString(pass_entered));
           readio::addCredToFile(new_credential);
           successorWindow::buildList();
           addCredPopUp.close();
           });

    // cancel button
    QObject::connect(&cancel_add_button, &QPushButton::clicked, &addCredPopUp, 
           [&addCredPopUp]() { addCredPopUp.close(); });    
     

    addCredPopUp.exec();

}

void successorWindow::onEditClicked() { 
    int targetIdx = credential_list_widget->currentRow();
    if(targetIdx == -1) {
        QMessageBox editCredPopUp(main_window);
        editCredPopUp.setText("You have not selected any credential to perform this operation on.");
        editCredPopUp.setStandardButtons(QMessageBox::Ok);
        editCredPopUp.setDefaultButton(QMessageBox::Ok);
        editCredPopUp.exec();
        return;
    }
    
    QDialog editCredPopUp(main_window);
    QLabel name_label(QApplication::translate("name_label_edit", "Enter New Credential Name"));
    QLineEdit name_entry;
    name_entry.setText(QString::fromStdString(credentialList[targetIdx].getCredentialName()));
    QLabel user_label(QApplication::translate("user_label_edit", "Enter New Credential Username"));
    QLineEdit user_entry;
    user_entry.setText(QString::fromStdString(credentialList[targetIdx].getCredentialUser()));
    QLabel pass_label(QApplication::translate("pass_label_edit", "Enter New Credential Password"));
    QLineEdit pass_entry;
    pass_entry.setText(QString::fromStdString(credentialList[targetIdx].getCredentialPass()));
    pass_entry.setEchoMode(QLineEdit::Password);
    QVBoxLayout internal_edit_vbox; 
    internal_edit_vbox.addWidget(&name_label); 
    internal_edit_vbox.addWidget(&name_entry); 
    internal_edit_vbox.addWidget(&user_label); 
    internal_edit_vbox.addWidget(&user_entry); 
    internal_edit_vbox.addWidget(&pass_label); 
    internal_edit_vbox.addWidget(&pass_entry); 
    QPushButton confirm_edit_button(QApplication::translate("confirm_edit_button", "Confirm")); 
    QPushButton cancel_edit_button(QApplication::translate("cancel_edit_button", "Cancel"));  
    QHBoxLayout internal_edit_hbox;
    internal_edit_hbox.addWidget(&confirm_edit_button);
    internal_edit_hbox.addWidget(&cancel_edit_button); 
    internal_edit_vbox.addLayout(&internal_edit_hbox);
    editCredPopUp.setLayout(&internal_edit_vbox); 
    
    // confirm button
    QObject::connect(&confirm_edit_button, &QPushButton::clicked, &editCredPopUp, 
           [&]() { 
           std::string title_entered = name_entry.text().toStdString();
           if(title_entered.size() < 1) { editCredPopUp.close(); return; }
           std::string user_entered = user_entry.text().toStdString();
           std::string pass_entered = pass_entry.text().toStdString();
           credentialList[targetIdx].setName(title_entered);
           credentialList[targetIdx].setUser(user_entered);
           credentialList[targetIdx].setPass(pass_entered);
           readio::rebuildDataVault(credentialList);
           successorWindow::buildList();
           editCredPopUp.close();
           });

    // cancel button
    QObject::connect(&cancel_edit_button, &QPushButton::clicked, &editCredPopUp, 
           [&editCredPopUp]() { editCredPopUp.close(); });    
     

    editCredPopUp.exec();
}

void successorWindow::onRemoveClicked() {
    QMessageBox removeCredPopUp(main_window);
    int targetIdx = credential_list_widget->currentRow();
    if(targetIdx == -1) {
        removeCredPopUp.setText("You have not selected any credential to perform this operation on.");
        removeCredPopUp.setStandardButtons(QMessageBox::Ok);
        removeCredPopUp.setDefaultButton(QMessageBox::Ok);
        removeCredPopUp.exec();
        return;
    }
    removeCredPopUp.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    removeCredPopUp.setDefaultButton(QMessageBox::Cancel);
    removeCredPopUp.setText("Are you sure you want to permanently erase the credential from the Vault?");
    int selection = removeCredPopUp.exec();
    if(selection == QMessageBox::Yes) {
        readio::removeCredFromFile(credentialList[targetIdx], credentialList);
        successorWindow::buildList();
    }
}

void successorWindow::onListItemSelected() {
    int selectedIdx = credential_list_widget->currentRow();
    std::string name_decoded = encryptor::decryptString(encryptor::decodeString(
                credentialList[selectedIdx].getCredentialName()), decryptkey); 
    std::string user_decoded = encryptor::decryptString(encryptor::decodeString(
                credentialList[selectedIdx].getCredentialUser()), decryptkey);  
    std::string pass_decoded = encryptor::decryptString(encryptor::decodeString(
                credentialList[selectedIdx].getCredentialPass()), decryptkey); 
    cred_title->setText(QString::fromStdString(name_decoded));
    cred_user->setText(QString::fromStdString(user_decoded));
    cred_pass->setText(QString::fromStdString(pass_decoded));
}

QListWidget* successorWindow::getListWidget() {
    return credential_list_widget;
}

QPushButton* successorWindow::getLogoutButton() {
    return logout_button;
}

QPushButton* successorWindow::getAddButton() {
    return add_button;
}

QPushButton* successorWindow::getEditButton() {
    return edit_button;
}

QPushButton* successorWindow::getRemoveButton() {
    return remove_button;
}

void successorWindow::drawWindow(std::string passkey) {
    main_window->resize(600, 500);
    main_window->setMinimumSize(600, 500); 
    main_window->setWindowTitle(QApplication::translate("vault", "Password Vault")); 
    
    decryptkey += passkey;
    passkey.erase();

    // top title text 
    QLabel *top_title = new QLabel(QApplication::translate("title_text", "Password Vault")); 
    QFont *title_font = new QFont("Ariel", 20); 
    top_title->setFont(*title_font);
    top_title->setAlignment(Qt::AlignCenter); 
   
    // outer most QT vertical box with title text and bottom grid
    QVBoxLayout *outer_most_vbox = new QVBoxLayout();
    outer_most_vbox->addWidget(top_title, 1);
    
    // widgets of the bottom grid
   
    // grid for info box
    QGridLayout *info_box_grid = new QGridLayout();
    
    //QLabel *cred_name_id = new QLabel(QApplication::translate("cred_name_id", "id: "));
    QLabel *cred_name_title = new QLabel(QApplication::translate("cred_name_title", "name: "));
    QLabel *cred_name_user = new QLabel(QApplication::translate("cred_name_user", " user: "));
    QLabel *cred_name_pass = new QLabel(QApplication::translate("cred_name_pass", " pass: "));
    
    QFont *data_font = new QFont("Ariel", 14);
    cred_title->setFont(*data_font);
    cred_user->setFont(*data_font);
    cred_pass->setFont(*data_font);
    cred_title->setTextInteractionFlags(Qt::TextSelectableByMouse);
    cred_user->setTextInteractionFlags(Qt::TextSelectableByMouse);
    cred_pass->setTextInteractionFlags(Qt::TextSelectableByMouse);
    cred_title->setAlignment(Qt::AlignRight);
    cred_user->setAlignment(Qt::AlignRight);
    cred_pass->setAlignment(Qt::AlignRight);
    
    //QLabel *cred_id = new QLabel(QApplication::translate("cred_id", " "));
    
    info_box_grid->addWidget(cred_name_title, 0, 0); 
    info_box_grid->addWidget(cred_title, 0, 1); 
    info_box_grid->addWidget(cred_name_user, 1, 0); 
    info_box_grid->addWidget(cred_user, 1, 1);
    info_box_grid->addWidget(cred_name_pass, 2, 0); 
    info_box_grid->addWidget(cred_pass, 2, 1);
    //info_box_grid->addWidget(cred_name_id, 3, 0);
    //info_box_grid->addWidget(cred_id, 3, 1);

    // wrapper for infobox
    QWidget *info_grid_wrapper = new QWidget();
    info_grid_wrapper->setLayout(info_box_grid);

    // options box Vbox
    QVBoxLayout *options_vbox = new QVBoxLayout();
    add_button->setMinimumSize(225, 25); 
    logout_button->setMinimumSize(225, 25); 
    edit_button->setMinimumSize(225, 25);
    remove_button->setFixedSize(225, 25);
    QSpacerItem *options_spacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    options_vbox->addItem(options_spacer); 
    options_vbox->addWidget(add_button);
    options_vbox->addWidget(edit_button);
    options_vbox->addWidget(remove_button);
    options_vbox->addWidget(logout_button); 
    options_vbox->setAlignment(add_button, Qt::AlignHCenter);
    options_vbox->setAlignment(remove_button, Qt::AlignHCenter);
    options_vbox->setAlignment(logout_button, Qt::AlignHCenter);
    options_vbox->setAlignment(edit_button, Qt::AlignHCenter);

    // wrapper for options Vbox
    QWidget *option_box_wrapper = new QWidget(); 
    option_box_wrapper->setLayout(options_vbox); 

    successorWindow::buildList();

    // add widgets to bottom grid 
    QGridLayout *grid_layout = new QGridLayout();
    grid_layout->addWidget(info_grid_wrapper, 0, 0, 2, 1);
    grid_layout->addWidget(option_box_wrapper, 2, 0);
    grid_layout->addWidget(credential_list_widget, 0, 1, 3, 1);
    
    // wrap bottom grid as a widget and add to outer most vertical box
    QWidget *grid_wrapper = new QWidget();
    grid_wrapper->setLayout(grid_layout);
    outer_most_vbox->addWidget(grid_wrapper, 6);
    
    main_window->setLayout(outer_most_vbox);
}

void successorWindow::buildList() { 
    readio::createCredentialVector(&credentialList);
    credential_list_widget->clear();
    for(auto& i : credentialList) {
        std::string credential_name_decrypted = encryptor::decryptString(encryptor::decodeString(
                    i.getCredentialName()), decryptkey);
        credential_list_widget->addItem(QString::fromStdString(credential_name_decrypted));
    }
}
