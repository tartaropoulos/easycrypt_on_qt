#ifndef EASYCRYPT_H
#define EASYCRYPT_H

#include <QMainWindow>
#include "ui_easycrypt.h"

class EasyCrypt : public QMainWindow, public Ui::EasyCryptWindow
{
    Q_OBJECT

public:
    explicit EasyCrypt(QWidget *parent = 0);
signals:
    void signalEncrypt(QString& text, int& number);
    void signalDecrypt(QString& text, int& number);
private slots:
    void enableNumberLineEdit();
    void enableEncryptButton();
    void enableDecryptButton();
    void slotEncrypt();
    void slotDecrypt();
    void encrypt(QString& text, int& number);
    void decrypt(QString& text, int& number);
};

#endif // EASYCRYPT_H
