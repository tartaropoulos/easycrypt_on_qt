#include <QApplication>
#include "easycrypt.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    EasyCrypt *window(new EasyCrypt);
    window->show();

    return app.exec();
}
