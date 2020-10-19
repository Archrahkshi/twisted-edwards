#ifndef CALC_H
#define CALC_H

#include "Point.h"


namespace NTL {
    Point transform(const Point&);
    Point addPoints(const Point&, const Point&);
    Point doublePoint(const Point&);
    Point binaryMethod(const Point&, const ZZ&);
}

#endif //CALC_H
