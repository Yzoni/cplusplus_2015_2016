//
// Yorick de Boer (10786015)
//

#include <DoublyLinkedList.h>
#include <LargeNumber.h>
#include <Math.h>

int main(int argc, char **argv) {
    //EXTRA 1
    LargeNumber n1("96");
    LargeNumber k1("45"); // 96 - 45
    Number *extra1 = Math::permutationNoRepetition(&n1, &k1);
    cout << "Extra 1 " << extra1 << endl;

    //EXTRA 2
    LargeNumber n2("91");
    LargeNumber k2("46");
    Number *extra2 = Math::permutationWithRepetition(&n2, &k2);
    cout << "Extra 2 " << extra2 << endl;

    if (argc < 2) {
        cout << "Computes the n-th fibonacci and factorial." << endl;
        cout << "usage: " << argv[0] << " <n>" << endl;
        exit(0);
    }

    LargeNumber n(argv[1]);
//    SmallNumber n(argv[1]);

    Number *fib = Math::fibonacci(&n);
    cout << "fibonacci(" << &n << ") = " << fib << endl;
    delete fib;

    Number *fac = Math::factorial(&n);
    cout << "factorial(" << &n << ") = " << fac << endl;
    delete fac;

    return 0;
}