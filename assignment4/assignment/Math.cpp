#include "Number.h"
#include "Math.h"

// computes fibonacci and factorial numbers
// uses pointers (Number*) to allow subclassing the Number class

Number *Math::fibonacci(Number *n) {
    Number *fib0 = n->factoryMethod("0"); // zero-th number is defined
    if (*n == fib0)
        return fib0;
    Number *fib1 = n->factoryMethod("1"); // first number is defined
    if (*n == fib1) {
        delete fib0;
        return fib1;
    }
    Number *result = NULL;
    Number *i = n->factoryMethod("1");
    for (; (*i) != n; (*i)++) // later numbers are computed by adding previous two
    {
        result = (*fib0) + fib1; // add
        delete fib0;
        fib0 = fib1;
        fib1 = result;
    }
    delete i;
    delete fib0;
    return result;
}

Number *Math::factorial(Number *n) {
    Number *result = n->factoryMethod("1");
    Number *i = n->factoryMethod("0");
    if ((*i) == n) // zero-th number is defined
    {
        delete i;
        return result;
    }
    (*i)++;
    while ((*i) != n) // later numbers are computed by multiplying by all i from 1 to n
    {
        (*i)++;
        Number *temp = result;
        result = (*result) * i; // multiply
        delete temp;
    }
    delete i;
    return result;
}

Number *Math::permutationNoRepetition(Number *n, Number *k) {
    Number *result = n->factoryMethod("0");
    (*k)++;
    result = *result + k;
    while (*n != k) {
        (*k)++;
        result = (*result) * k;
    }
    return result;
}

Number *Math::permutationWithRepetition(Number *n, Number *k) {
    Number *result = n->factoryMethod("1");
    for (Number *i = k->factoryMethod("0"); (*i) != k; (*i)++) {
        cout << result << endl;
        result = *result * n;
    }

    return result;
}
