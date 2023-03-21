#include "recipe_info.h"
#include "mainwindow.h"

#include <QApplication>

//123
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
