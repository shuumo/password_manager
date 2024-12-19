#include <iostream>
#include <QtWidgets>

/*
 * Login GUI Stuff using QT6
 *
*/
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget window;
    window.resize(500, 500);
    window.setMinimumSize(500,500);
    window.setWindowTitle(QApplication::translate("password_manager", "Password Manager"));

    QLabel *label = new QLabel(QApplication::translate("master_entry", "Master Key: "));
    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setEchoMode(QLineEdit::Password);
    
    QPushButton *button = new QPushButton(QApplication::translate("childwidget", "log in"), &window); 
    button->setFixedSize(100, 50);

    QHBoxLayout *keyEntryLayout = new QHBoxLayout();
    keyEntryLayout->addSpacing(100);
    keyEntryLayout->addWidget(label);
    keyEntryLayout->addWidget(lineEdit);
    keyEntryLayout->addSpacing(100);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(button);

    QVBoxLayout *verticalLayout = new QVBoxLayout();
    verticalLayout->addLayout(keyEntryLayout);
    verticalLayout->addLayout(buttonLayout);
    verticalLayout->setSpacing(0);

    window.setLayout(verticalLayout);    

    window.show();
    return app.exec();
}

