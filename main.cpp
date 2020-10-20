#include "test.h"


using namespace NTL;

int main() {
    Point P;

    checkIfOnCurve(binaryMethod(P, RandomBits_ZZ(512)));
    checkIdentity(binaryMethod(P, q));
    checkNeighbors(P);
    checkLinearity(P, RandomBnd(q), RandomBnd(q));
}
