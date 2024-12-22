#include <QApplication>
#include <QVBoxLayout>
#include <QFont>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QSpacerItem>
#include <QSizePolicy>

#include "successor_window.hpp"
/*
 * Main screen (home menu, post login)
*/

QWidget *main_window;
QPushButton *add_button;
QPushButton *logout_button;
QPushButton *edit_button;

successorWindow::successorWindow(QWidget *parent) : main_window(parent) {
    add_button = new QPushButton(QApplication::translate("add_credential", "Add Credential")); 
    edit_button = new QPushButton(QApplication::translate("edit_credential", "Edit Credential"));  
    logout_button = new QPushButton(QApplication::translate("exit", "Exit"));
}

void successorWindow::onLogoutClicked() {
    QCoreApplication::quit();
}

QPushButton* successorWindow::getLogoutButton() {
    return logout_button;
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
   
    QLabel *cred_name_title = new QLabel(QApplication::translate("cred_name_title", "name: "));
    QLabel *cred_name_user = new QLabel(QApplication::translate("cred_name_user", " user: "));
    QLabel *cred_name_pass = new QLabel(QApplication::translate("cred_name_pass", " pass: "));
    
    QLabel *cred_title = new QLabel(QApplication::translate("cred_title", " "));
    QLabel *cred_user = new QLabel(QApplication::translate("cred_user", " "));
    QLabel *cred_pass = new QLabel(QApplication::translate("cred_pass", " "));
    
    info_box_grid->addWidget(cred_name_title, 0, 0); 
    info_box_grid->addWidget(cred_title, 0, 1); 
    info_box_grid->addWidget(cred_name_user, 1, 0); 
    info_box_grid->addWidget(cred_user, 1, 1);
    info_box_grid->addWidget(cred_name_pass, 2, 0); 
    info_box_grid->addWidget(cred_pass, 2, 1);

    // wrapper for infobox
    QWidget *info_grid_wrapper = new QWidget();
    info_grid_wrapper->setLayout(info_box_grid);

    // options box Vbox
    QVBoxLayout *options_vbox = new QVBoxLayout();
    add_button->setFixedSize(150, 25); 
    logout_button->setFixedSize(150, 25); 
    edit_button->setFixedSize(150, 25); 
    options_vbox->addWidget(add_button);
    options_vbox->addWidget(edit_button);
    options_vbox->addWidget(logout_button); 
    options_vbox->setAlignment(add_button, Qt::AlignHCenter);
    options_vbox->setAlignment(logout_button, Qt::AlignHCenter);
    options_vbox->setAlignment(edit_button, Qt::AlignHCenter);
    QSpacerItem *options_spacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    options_vbox->addItem(options_spacer); 

    // wrapper for options Vbox
    QWidget *option_box_wrapper = new QWidget(); 
    option_box_wrapper->setLayout(options_vbox); 

    // right side credential list
    QListWidget *credential_list = new QListWidget();



    // add widgets to bottom grid 
    QGridLayout *grid_layout = new QGridLayout();
    grid_layout->addWidget(info_grid_wrapper, 0, 0, 2, 1);
    grid_layout->addWidget(option_box_wrapper, 2, 0);
    grid_layout->addWidget(credential_list, 0, 1, 3, 1);
    
    // wrap bottom grid as a widget and add to outer most vertical box
    QWidget *grid_wrapper = new QWidget();
    grid_wrapper->setLayout(grid_layout);
    outer_most_vbox->addWidget(grid_wrapper, 6);
    
    main_window->setLayout(outer_most_vbox);
}
