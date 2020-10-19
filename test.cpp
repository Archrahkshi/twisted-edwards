#include "test.h"


namespace NTL {
    void checkIfOnCurve(const Point &kP) {
        ZZ X2 = PowerMod(kP.X, 2, p);
        ZZ Y2 = PowerMod(kP.Y, 2, p);
        if (AddMod(MulMod(a, X2, p), Y2, p) == AddMod(1, MulMod(MulMod(d, X2, p), Y2, p), p))
            std::cout << "Test 1: +\n";
        else
            std::cout << "Test 1: -\n";
    }

    void checkIdentity(const Point &qP) {
        if (qP.X == 0 && qP.Y == 1 && qP.Z == 0)
            std::cout << "Test 2: +\n";
        else
            std::cout << "Test 2: -\n";
    }

    void checkNeighbors(const Point &P) {
        Point P1 = binaryMethod(P, AddMod(q, 1, p));
        if (P1.X == P.X && P1.Y == P.Y && P1.Z == P.Z)
            std::cout << "Test 3: +";
        else
            std::cout << "Test 3: -";
        Point P2 = binaryMethod(P, SubMod(q, 1, p));
        if (P2.X == NegateMod(P.X, p) && P2.Y == P.Y && P2.Z == NegateMod(P.Z, p))
            std::cout << "+\n";
        else
            std::cout << "-\n";
    }

    void checkLinearity(const Point &P, const ZZ &k1, const ZZ &k2) {
        Point P1 = addPoints(binaryMethod(P, k1), binaryMethod(P, k2));
        Point P2 = binaryMethod(P, k1 + k2);
        if (P1.X == P2.X && P1.Y == P2.Y && P1.Z == P2.Z)
            std::cout << "Test 4: +\n";
        else
            std::cout << "Test 4: -\n";
    }
}
