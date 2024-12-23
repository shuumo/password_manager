#ifndef SUCCESSOR_WINDOW
#define SUCCESSOR_WINDOW

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>

#include "credential.hpp"

class successorWindow : public QObject {
private:
    //parent widget for main window 
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

public:
    successorWindow(QWidget *parent);
    void drawWindow();
    
    QListWidget* getListWidget();
    QPushButton* getLogoutButton();

public slots:
    void onEditClicked();
    void onAddClicked();
    void onLogoutClicked();
    void onListItemSelected();
};

#endif
