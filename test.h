#ifndef TEST_H
#define TEST_H

#include "calc.h"


namespace NTL {
    void checkIfOnCurve(const Point&);
    void checkIdentity(const Point&);
    void checkNeighbors(const Point&);
    void checkLinearity(const Point&, const ZZ&, const ZZ&);
}

#endif //TEST_H
