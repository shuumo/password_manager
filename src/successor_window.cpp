#include <QApplication>
#include <QVBoxLayout>
#include <QFont>
#include <QSpacerItem>
#include <QSizePolicy>
#include <QListWidgetItem>
#include <QMessageBox>
#include <vector>

#include "successor_window.hpp"
#include "credential.hpp"
#include "csvreading.hpp"

#include <iostream>
/*
 * Main screen (home menu, post login)
*/

QWidget *main_window;
QPushButton *add_button;
QPushButton *logout_button;
QPushButton *edit_button;
QPushButton *remove_button;
QListWidget *credential_list_widget;
QLabel *cred_title;
QLabel *cred_user;
QLabel *cred_pass;
std::vector<credential> credentialList;

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
}

void successorWindow::onLogoutClicked() {
    QCoreApplication::quit();
}

void successorWindow::onAddClicked() {
    // Create a "dialogue box"
    // Dialogue box contains 3 entries: credential name, credential user, credential password
    // on confirm buttoon: get all 3 values and create a new Credential object
    // pass it to readio::addCredToFile();
    // close Dialogue Box 
}

void successorWindow::onEditClicked() {
    // Qinputdialog?
    // open an edit credential window
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
    cred_title->setText(QString::fromStdString(credentialList[selectedIdx].getCredentialName()));
    cred_user->setText(QString::fromStdString(credentialList[selectedIdx].getCredentialUser()));
    cred_pass->setText(QString::fromStdString(credentialList[selectedIdx].getCredentialPass()));
}

QListWidget* successorWindow::getListWidget() {
    return credential_list_widget;
}

QPushButton* successorWindow::getLogoutButton() {
    return logout_button;
}

QPushButton* successorWindow::getRemoveButton() {
    return remove_button;
}

void successorWindow::drawWindow() {
    main_window->resize(600, 500);
    main_window->setMinimumSize(600, 500); 
    main_window->setWindowTitle(QApplication::translate("vault", "Password Vault")); 
    
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
        credential_list_widget->addItem(QString::fromStdString(i.getCredentialName()));
    }
}
