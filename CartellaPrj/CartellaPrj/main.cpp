#include "mainwindow.h"
#include <QApplication>
#include "runguard.h"

int main(int argc, char *argv[])
{
    RunGuard guard( "some_random_key" );
    if ( !guard.tryToRun() )
        return 0;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
