#include <stdio.h>
#include "Struct_Func_Header.h"

int main()
{
    // Your code goes here
    printf ("\n\n");
    printf("\t\t\t*****************************\n");
    printf("\t\t\t**\tSELAMAT DATANG     **\t\t\n");
    menu();
    int perintah;
    scanf("%d", &perintah);

    while (perintah != 0)
    {
        switch (perintah)
        {
        case 1:
            input_KTP();
            break;
        case 2:
            cari_KTP();
            break;
        }
        menu();
        scanf("%d", &perintah);
    }
    return 0;
}