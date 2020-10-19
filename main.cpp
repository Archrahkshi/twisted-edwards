#include "test.h"


using namespace NTL;

int main() {
    Point P;

    checkIfOnCurve(P);
    checkIdentity(P);
    checkNeighbors(P);
    checkLinearity(P, RandomBnd(p), RandomBnd(p));
}
