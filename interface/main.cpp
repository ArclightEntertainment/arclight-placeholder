#include <QApplication>
#include "MainWindow.h"
#include <cstdlib>
#include <ctime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand((unsigned)time(0));
    MainWindow w;
    w.show();

    return a.exec();
}
