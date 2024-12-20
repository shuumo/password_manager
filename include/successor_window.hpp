#ifndef SUCCESSOR_WINDOW
#define SUCCESSOR_WINDOW

#include <QWidget>
#include <QObject>

class successorWindow : public QObject {
private:
    QWidget *main_window;

public:
    successorWindow(QWidget *parent);
    void drawWindow();
};

#endif
