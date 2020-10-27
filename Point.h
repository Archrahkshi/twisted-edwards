#ifndef POINT_H
#define POINT_H

#include "params.h"


namespace NTL {
    class Point {
    public:
        ZZ X, Y, Z;

        Point();
        Point(ZZ& X, ZZ& Y, ZZ& Z);
    };
}

#endif // POINT_H