#include <stdio.h>
#include <stdlib.h>
#include "Struct_Func_Header.h"

int banding(const void *a, const void *b)
{
    KTP *varA = (KTP *)a;
    KTP *varB = (KTP *)b;
    return (varA->NIK - varB->NIK);
}