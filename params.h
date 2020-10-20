#ifndef PARAMS_H
#define PARAMS_H

#include <NTL/ZZ.h>


namespace NTL {
    // Набор параметров id-tc26-gost-3410-2012-256-paramSetA
    // https://docplayer.ru/46408167-Tehnicheskiy-komitet-026-zadanie-parametrov-skruchennyh-ellipticheskih-krivyh-edvardsa-v-sootvetstvii-s-gost-r.html
    const ZZ a = conv<ZZ>("1");
    const ZZ d = conv<ZZ>("2724414110474605931834268501164757645998726878473076809432604223414351675387");
    const ZZ p = conv<ZZ>("115792089237316195423570985008687907853269984665640564039457584007913129639319");
    const ZZ q = conv<ZZ>("28948022309329048855892746252171976963338560298092253442512153408785530358887");
    const ZZ u = conv<ZZ>("13");
    const ZZ v = conv<ZZ>("43779144989398987843428779166090436406934195821915183574454224403186176950503");
}

#endif //PARAMS_H
