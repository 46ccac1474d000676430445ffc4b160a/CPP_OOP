#include <iostream>
#include <stdio.h>
#include "FRACTION.H"


using namespace std;

int main()
{
    Fraction f1(2, 5, 4), f2(0, 6, 2), f3;
    f1.show();
    cout << endl;
    f2.show();
    f3 = f1.sum(f2);

    cout << endl << endl;

    f1.show();
    cout << endl;
    f2.show();
    cout << endl;
    f3.show();

    cout << endl;
    cout << f1.equls(f2)<<endl;
    cout << f1.equls(f1)<<endl;

    return 0;
}
