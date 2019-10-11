#include <QCoreApplication>
#include "dynamicarray.h"
#include "simulator.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // add existing file to onother distination that contain the file
    QString path = "/home/amrelsersy/Gates_Simulaotr/Gates.txt";

    Simulator Gate_Simulator(path);
    Gate_Simulator.Conect_Gates_Nodes();
    return a.exec();
}
