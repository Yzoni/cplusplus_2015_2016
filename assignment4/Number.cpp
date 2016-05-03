//
// Created by yorick on 27-4-16.
//

#include "Number.h"

ostream &operator<<(ostream &os, const Number *n) // this enables "cout<<Number();" type printing
{
    n->print(os);
    return os;
}