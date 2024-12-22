#ifndef SUCCESSOR_WINDOW
#define SUCCESSOR_WINDOW

#include <QWidget>
#include <QObject>
#include <QPushButton>

class successorWindow : public QObject {
private:
    //parent widget for main window 
    QWidget *main_window;
   
    QPushButton *add_button;
    QPushButton *logout_button;
    QPushButton *edit_button;

public:
    successorWindow(QWidget *parent);
    void drawWindow();
    QPushButton* getLogoutButton();

public slots:
    void onEditClicked();
    void onAddClicked();
    void onLogoutClicked();
};

#endif
