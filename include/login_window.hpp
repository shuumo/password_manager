#ifndef LOGIN_WINDOW
#define LOGIN_WINDOW

#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include <QObject>

#include "successor_window.hpp"

class loginWindow : public QObject {
private:
    // parent widget for login window 
    QWidget *window;
    // parent widget for main window
    QWidget *successor_window;

    QPushButton *exit_button;
    QPushButton *login_button;
    QLineEdit *line_edit;
    
    successorWindow *successorWindowObj;

public:
    loginWindow(QWidget *parent, QWidget *successor);
    
    // Draws the window elements using QT to the window parent widget
    void drawWindow();
    
    QWidget* getParent();
    QPushButton* getExitButton();
    QPushButton* getLoginButton();
    QLineEdit* getLineEdit();
    successorWindow *getSuccessorWindowObj();

public slots:
    void onExitClicked();
    void onLoginClicked();
};

#endif
