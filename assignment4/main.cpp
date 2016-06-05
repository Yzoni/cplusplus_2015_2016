//
// Yorick de Boer (10786015)
//

#include <DoublyLinkedList.h>
#include <LargeNumber.h>

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
//    LargeNumber *largeNumber = new LargeNumber("1234567");
//    cout << largeNumber << endl;
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
//    LargeNumber *testEqual1 = new LargeNumber("12334");
//    LargeNumber *testEqual2 = new LargeNumber("12334");
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
    LargeNumber *plusplus = new LargeNumber("99999998");
    plusplus->printArray();
    (*plusplus)++;
    plusplus->printArray();
    (*plusplus)++;
    plusplus->printArray();
    /*
     * TEST SUM
     */
//    LargeNumber *plus1 = new LargeNumber("12345");
//    LargeNumber *plus2 = new LargeNumber("123");
//    cout << (*plus1) + plus2 << endl;

//    if (argc < 2) {
//        cout << "Computes the n-th fibonacci and factorial." << endl;
//        cout << "usage: " << argv[0] << " <n>" << endl;
//        exit(0);
//    }
//
//    //LargeNumber n(argv[1]);
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