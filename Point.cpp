#include "Point.h"


namespace NTL {
    Point::Point() : X(u), Y(v) {}

    Point::Point(ZZ &X, ZZ &Y, ZZ &Z) : X(X), Y(Y), Z(Z) {}
}