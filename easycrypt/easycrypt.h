#ifndef EASYCRYPT_H
#define EASYCRYPT_H

#include <QMainWindow>
#include "ui_easycrypt.h"

class EasyCrypt : public QMainWindow, public Ui::EasyCryptWindow
{
    Q_OBJECT

public:
    EasyCrypt(QWidget *parent = 0);
private slots:
    void enableNumberLineEdit();
    void enableEncryptButton();
    void enableDecryptButton();
    void encrypt();
    void decrypt();
};

#endif // EASYCRYPT_H
