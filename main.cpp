#include "dialog.h"

#include <QApplication>
//########################################################################################################
#include <iostream>
//#include <random>
#include <limits>
using namespace std;
//########################################################################################################
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
//########################################################################################################

}
