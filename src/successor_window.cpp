#include <QApplication>

#include "successor_window.hpp"


QWidget *main_window;

successorWindow::successorWindow(QWidget *parent) : main_window(parent) {
   // Constructor here 
}

void successorWindow::drawWindow() {
    main_window->resize(800, 600);
    main_window->setMinimumSize(800, 600); 
    main_window->setWindowTitle(QApplication::translate("vault", "Password Vault"));
}
