#ifndef CALC_H
#define CALC_H

#include "Point.h"


namespace NTL {
    Point transform(const Point &); // Преобразование проективных координат в аффинные
    Point addPoints(const Point &, const Point &); // Сложение точек
    Point doublePoint(const Point &); // Удвоение точки
    Point binaryMethod(const Point &, const ZZ &); // Бинарный метод нахождения кратной точки
}

#endif //CALC_H
