#include <stdio.h>
#include "Struct_Func_Header.h"

int main()
{
    // Your code goes here
    printf ("\n\n");
    printf("\t\t\t*****************************\n");
    printf("\t\t\t**\tSELAMAT DATANG     **\t\t\n");
    menu();
    KTP isi_data;
    int jumlah_data = 1;
    int perintah;
    scanf("%d", &perintah);

    while (perintah != 0)
    {
        switch (perintah)
        {
        case 1:
            input_KTP(&jumlah_data);
            break;
        case 2:
            cari_KTP();
            break;
        case 3:
            load_KTP(jumlah_data);
            break;
        case 4:
            hapus_KTP(&jumlah_data);
            break;
        }
        menu();
        scanf("%d", &perintah);
    }
    printf("\nTerima kasih !!!\n");
    return 0;
}