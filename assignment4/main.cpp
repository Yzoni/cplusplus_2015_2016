//
// Yorick de Boer (10786015)
//

#include <DoublyLinkedList.h>
#include <LargeNumber.h>
#include <Math.h>

int main(int argc, char **argv) {
//    DoublyLinkedList *doublyLinkedList = new DoublyLinkedList();
//    doublyLinkedList->insertHead(4);
//    doublyLinkedList->insertHead(5);
//
//    LinkedItem *tailItem = doublyLinkedList->getTail();
//    LinkedItem *headItem = doublyLinkedList->getHead();
//
//    cout << tailItem->carry << endl;
//    cout << headItem->carry << endl;
//
//    cout << headItem->prev->carry << endl;
//
//    LinkedItem *currentItem = doublyLinkedList->getHead();
//    while (currentItem != NULL) {
//        cout << currentItem->carry << endl;
//        currentItem = doublyLinkedList->getPrevItem(currentItem);
//    }
//
//    LargeNumber *largeNumber = new LargeNumber("12340005");
//    cout << largeNumber << endl;
//    largeNumber->printArray();
//    delete largeNumber;
//
//    SmallNumber *testEquals1 = new SmallNumber("12345679");
//    SmallNumber *testEquals2 = new SmallNumber("1234567");
//    if (*testEquals1 == testEquals2) {
//        cout << "equal" << endl;
//    } else {
//        cout << "not equal" << endl;
//    }
//    delete testEquals1;
//    delete testEquals2;
//
    /*
     * TEST EQUAL
     */
//    LargeNumber *testEqual1 = new LargeNumber("1235");
//    LargeNumber *testEqual2 = new LargeNumber("12350");
//    if (*testEqual1 == testEqual2) {
//        cout << "equal" << endl;
//    } else {
//        cout << "not equal" << endl;
//    }
//    delete testEqual1;
//    delete testEqual2;

    /*
     * TEST PLUSPLUS
     */
//    LargeNumber *plusplus = new LargeNumber("9293239048234800399399993902003993999999");
//    (*plusplus)++;
//    cout << plusplus << endl;
//    (*plusplus)++;
//    cout << plusplus << endl;
//    delete plusplus;
    /*
     * TEST SUM
     */
//    LargeNumber *plus1 = new LargeNumber("11");
//    LargeNumber *plus2 = new LargeNumber("9999");
//    cout << plus2 << endl;
//    cout << (*plus1) + plus2 << endl;

    /*
     * TEST MULTIPLY
     */
//    LargeNumber *plus1 = new LargeNumber("83493405");
//    LargeNumber *plus2 = new LargeNumber("3333");
//    cout << (*plus1) * plus2 << endl;
//    static_cast<LargeNumber *>((*plus1) + plus2)->printArray();
//    if (argc < 2) {
//        cout << "Computes the n-th fibonacci and factorial." << endl;
//        cout << "usage: " << argv[0] << " <n>" << endl;
//        exit(0);
//    }

    //EXTRA 1
//    LargeNumber n("96");
//    LargeNumber k("45");
//    Number *fib = Math::permutationNoRepetition(&n, &k);
//    cout << fib << endl;

//    LargeNumber n("16");
//    LargeNumber k("13");
//    Number *fib = Math::permutationNoRepetition(&n, &k);
//    cout << fib << endl;
//

    //EXTRA 2
//    LargeNumber n("10");
//    LargeNumber k("3");
//    Number *fib = Math::permutationWithRepetition(&n, &k);
//    cout << fib << endl;

    LargeNumber n("91");
    LargeNumber k("46");
    Number *fib = Math::permutationWithRepetition(&n, &k);
    cout << fib << endl;

//    LargeNumber n("200");
//    SmallNumber n(argv[1]);
//
//    Number *fib = Math::fibonacci(&n);
//    cout << "fibonacci(" << &n << ") = " << fib << endl;
//    delete fib;
//
//    Number *fac = Math::factorial(&n);
//    cout << "factorial(" << &n << ") = " << fac << endl;
//    delete fac;

    return 0;
}