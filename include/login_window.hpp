#ifndef LOGIN_WINDOW
#define LOGIN_WINOW

#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include <QObject>

class loginWindow : public QObject {
private:
    QWidget *window;
    QWidget *successor_window;

    QPushButton *exit_button;
    QPushButton *login_button;
    QLineEdit *line_edit;
    

public:
    loginWindow(QWidget *parent, QWidget *successor);

    void drawWindow();
    QWidget* getParent();
    QPushButton* getExitButton();
    QPushButton* getLoginButton();
    QLineEdit* getLineEdit();

public slots:
    void onExitClicked();
    void onLoginClicked();
};

#endif
