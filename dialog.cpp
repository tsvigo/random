#include "dialog.h"
#include "ui_dialog.h"
//########################################################################################################
#include <iostream>
//#include <random>
#include <limits>
using namespace std;
#include <stdio.h>
#include <time.h>
#include <inttypes.h>
//########################################################################################################
#define rotl(r,n) (((r)<<(n)) | ((r)>>((8*sizeof(r))-(n))))
 
static uint64_t xx, yy, zz;  // obviously these and the two functions should be in a separate file
 
void seedRand64(uint32_t seed) {
    size_t n;
    xx =    914489ULL;
    yy =   8675416ULL;
    zz = 439754684ULL;
    for (n=((seed>>22)&0x3ff)+20; n>0; n--) { xx = rotl(xx,8) - rotl(xx,29); }
    for (n=((seed>>11)&0x7ff)+20; n>0; n--) { yy = rotl(yy,21) - yy;  yy = rotl(yy,20); }
    for (n=((seed    )&0x7ff)+20; n>0; n--) { zz = rotl(zz,42) - zz;  zz = rotl(zz,14) + zz; }
}
 
uint64_t rand64() {
    xx = rotl(xx,8) - rotl(xx,29);
    yy = rotl(yy,21) - yy;  yy = rotl(yy,20);
    zz = rotl(zz,42) - zz;  zz = zz + rotl(zz,14);
    return xx ^ yy ^ zz;
}
 
void printBinary(uint64_t n) {
    uint64_t m = 0x8000000000000000;
    for ( ; m; m >>= 1)
        putchar(n & m ? '1' : '0');
    putchar('\n');
}
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//########################################################################################################
//########################################################################################################
    uint64_t n;
    size_t i;
 
    seedRand64(time(0));  // would be nice to have a better seed
 
    for (i = 0; i < 20; i++) {
        n = rand64();
        printf("%" PRIu64 "\n", n);
//        printBinary(n);
    }
 

}

Dialog::~Dialog()
{
    delete ui;
}

