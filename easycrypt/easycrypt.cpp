#include <QtGui>
#include "easycrypt.h"

EasyCrypt::EasyCrypt(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    //Setting of input in numberLineEdit
    QRegExp regExp("[1-9][0-9]{0,1}");
    numberLineEdit->setValidator(new QRegExpValidator(regExp, this));

    //Enabling of buttons
    connect(textEdit, SIGNAL(textChanged()), SLOT(enableNumberLineEdit()));
    connect(numberLineEdit, SIGNAL(textChanged(const QString&)), SLOT(enableEncryptButton()));
    connect(numberLineEdit, SIGNAL(textChanged(const QString&)), SLOT(enableDecryptButton()));

    //Connecting of buttons
    connect(encryptButton, SIGNAL(clicked()), SLOT(encrypt()));
    connect(decryptButton, SIGNAL(clicked()), SLOT(decrypt()));
    connect(closeButton, SIGNAL(clicked()), SLOT(close()));
}

void EasyCrypt::enableNumberLineEdit()
{
    //Enabled when text is input in textEdit
    numberLineEdit->setEnabled(true);
}

void EasyCrypt::enableEncryptButton()
{
    //Enabled if input is correct
    encryptButton->setEnabled(numberLineEdit->hasAcceptableInput());
}

void EasyCrypt::enableDecryptButton()
{
    //Enabled if input is correct
    decryptButton->setEnabled(numberLineEdit->hasAcceptableInput());
}

void EasyCrypt::encrypt()
{
    QString text(textEdit->toPlainText());
    int number(numberLineEdit->text().toInt());
    int size(text.size());

    for(int i(0); i < number && number > 0 && !text.isEmpty(); ++i)
    {
        QString temp;

        //Add even character to the left side
        //and add odd character to the right side
        for(int count(1); count < size; count += 2)
          temp.push_back(text[count]);

        for(int count(0); count < size; count += 2)
          temp.push_back(text[count]);

        text = temp;
    }

    textEdit->clear();
    textEdit->setPlainText(text);
}

void EasyCrypt::decrypt()
{
    QString text(textEdit->toPlainText());
    int number(numberLineEdit->text().toInt());
    int size(text.size());
    int leftMiddle(size / 2);
    int rightMiddle(leftMiddle);

    //For odd strings
    if(size % 2 != 0)
        ++rightMiddle;

    for(int i(0); i < number && number > 0 && !text.isEmpty(); ++i)
    {
        QString left(text.left(leftMiddle)),
        right(text.right(rightMiddle));

        //Combining strings through a character
        int count(1);
        for(QChar leftSymbol : left)
        {
          right.insert(count, leftSymbol);
          count += 2;
        }

        text = right;
    }

    textEdit->clear();
    textEdit->setPlainText(text);
}
