#include "calc.h"


namespace NTL {
    // Проективные координаты для искривлённой формы Эдвардса
    // http://hyperelliptic.org/EFD/g1p/auto-twisted-projective.html

    Point transform(const Point &P) {
        Point Q;
        if (P.Z != 0) {
            Q.X = MulMod(P.X, InvMod(P.Z, p), p); // x=X/Z
            Q.Y = MulMod(P.Y, InvMod(P.Z, p), p); // y=Y/Z
            Q.Z = 0;
        }
        return Q;
    }

    Point addPoints(const Point &P1, const Point &P2) { // mmadd-2008-bbjlp
        ZZ X1 = P1.X;
        ZZ X2 = P2.X;
        ZZ Y1 = P1.Y;
        ZZ Y2 = P2.Y;

        ZZ C = MulMod(X1, X2, p); // X1*X2
        ZZ D = MulMod(Y1, Y2, p); // Y1*Y2
        ZZ E = MulMod(MulMod(d, C, p), D, p); // d*C*D

        ZZ X3 = MulMod(SubMod(1, E, p), SubMod(SubMod(MulMod(AddMod(X1, Y1, p), AddMod(X2, Y2, p), p), C, p), D, p), p); // (1-E)*((X1+Y1)*(X2+Y2)-C-D)
        ZZ Y3 = MulMod(AddMod(1, E, p), SubMod(D, MulMod(a, C, p), p), p); // (1+E)*(D-a*C)
        ZZ Z3 = SubMod(1, SqrMod(E, p), p); // 1-E^2

        return transform(Point(X3, Y3, Z3));
    }

    Point doublePoint(const Point &P) { // mdbl-2008-bbjlp
        ZZ X = P.X;
        ZZ Y = P.Y;

        ZZ B = SqrMod(AddMod(X, Y, p), p); // (X+Y)^2
        ZZ C = SqrMod(X, p); // X^2
        ZZ D = SqrMod(Y, p); // Y^2
        ZZ E = MulMod(a, C, p); // a*C
        ZZ F = AddMod(E, D, p); // E+D

        ZZ X3 = MulMod(SubMod(SubMod(B, C, p), D, p), SubMod(F, 2, p), p); // (B-C-D)*(F-2)
        ZZ Y3 = MulMod(F, SubMod(E, D, p), p); // F*(E-D)
        ZZ Z3 = SubMod(SqrMod(F, p), MulMod(2, F, p), p); // F^2-2*F

        return transform(Point(X3, Y3, Z3));
    }

    Point binaryMethod(const Point &P, const ZZ &k) { // Лекции, слайд 53
        ZZ X0(0), Y0(1), Z0(0);
        Point Q(X0, Y0, Z0);
        for (long i = NumBits(k) - 1; i >= 0; --i) {
            Q = doublePoint(Q);
            if (bit(k, i))
                Q = addPoints(Q, P);
        }
        return Q;
    }
}
