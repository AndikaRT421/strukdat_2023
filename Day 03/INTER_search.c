#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Struct_Func_Header.h"

int Inter_Search(KTP data[], long long loww, long long highh, long long kunci)
{
    do
    {
        double pembilang = (double)(kunci - data[loww].NIK);
        double penyebut = (double)(data[highh].NIK - data[loww].NIK);
        double pos1 = pembilang / penyebut;
        pos1 *= (highh - loww);
        pos1 += loww;
        long long indekss = floor(pos1);
        if (data[indekss].NIK == kunci)
            return indekss;

        if (data[indekss].NIK > kunci)
            highh = indekss - 1;
        else if (data[indekss].NIK < kunci)
            loww = indekss + 1;
    } while (kunci >= data[loww].NIK && kunci <= data[highh].NIK);
    return -1;
}