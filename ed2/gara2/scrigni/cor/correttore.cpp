#include "testlib.h"
#include <stdio.h>
#include <math.h>

const double EPS = 1E-5;

int main(int argc, char * argv[])
{
    setName("compare two doubles, maximal absolute or relative error = %.10f", EPS);
    registerTestlibCmd(argc, argv);

//    double correct = ans.readDouble();
//    double tocheck = ouf.readDouble();

    /** Sadly, testlib.h and CMS have a different order of arguments... **/
    double tocheck = ans.readDouble();
    double correct = ouf.readDouble();

    if (!doubleCompare(correct, tocheck, EPS))
        quitf(_wa, "Output errato");

    quitf(_ok, "Output corretto");
}
