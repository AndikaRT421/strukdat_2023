#include <stdio.h>

int main (int argc, char *argv[])
{
    //Your code goes here
    FILE *F_awal, *F_akhir;
    size_t n, m;
    char simbol;
    F_awal = fopen (argv[1], "rb");
    F_akhir = fopen (argv[2], "wb");
    do
    {
        n = fread (&simbol, 1, sizeof simbol, F_awal);
        if (n) m = fwrite (&simbol, 1, n, F_akhir);
    } while ((n > 0) && (n == m)) ;
    fclose (F_awal);
    fclose (F_akhir);
    return 0;
}