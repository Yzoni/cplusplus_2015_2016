//
// Created by yorick on 3-5-16.
//

#include <cstdlib>
#include "SmallNumber.h"
#include "Math.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Computes the n-th fibonacci and factorial." << endl;
        cout << "usage: " << argv[0] << " <n>" << endl;
        exit(0);
    }

    //LargeNumber n(argv[1]);
    SmallNumber n(argv[1]);

    Number *fib = Math::fibonacci(&n);
    cout << "fibonacci(" << &n << ") = " << fib << endl;
    delete fib;

    Number *fac = Math::factorial(&n);
    cout << "factorial(" << &n << ") = " << fac << endl;
    delete fac;

    return 0;
}