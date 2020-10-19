#include "test.h"


using namespace NTL;

int main() {
    Point P;

    checkIfOnCurve(binaryMethod(P, RandomBnd(q)));
    checkIdentity(binaryMethod(P, q));
    checkNeighbors(P);
    checkLinearity(P, RandomBnd(q), RandomBnd(q));
}
