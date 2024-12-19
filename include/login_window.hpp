#ifndef LOGIN_WINDOW
#define LOGIN_WINOW

#include <QPushButton>
#include <QWidget>
#include <QObject>

class loginWindow : public QObject {
private:
    QWidget *window;
    QPushButton *exit_button;

public:
    loginWindow(QWidget *parent);

    void drawWindow();
    QWidget* getParent();
    QPushButton* getExitButton();

public slots:
    void onExitClicked();
};

#endif
