#ifndef TEST_H
#define TEST_H

#include "calc.h"


namespace NTL {
    void checkIfOnCurve(const Point&); // Тест 1
    void checkIdentity(const Point&); // Тест 2
    void checkNeighbors(const Point&); // Тест 3
    void checkLinearity(const Point&, const ZZ& k1, const ZZ& k2); // Тест 4
}

#endif //TEST_H
