#include <iostream>
#include <QtWidgets>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget window;
    window.resize(500, 500);
    window.show();
    window.setWindowTitle(QApplication::translate("password_manager", "Password Manager"));
    return app.exec();
}

