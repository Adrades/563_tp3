#include <stdio.h>
#include "structPLY.h"

int main() {
    printf("Hello, World!\n");

    MONOME m1 = CreerM(2, 1);
    MONOME m2 = CreerM(3, 1);
    MONOME m3 = CreerM(1, 4);
    MONOME m4 = CreerM(1, 2);

    POLYNOME p = CreerP(m1);

    Ajouter(&p, m2);
    Ajouter(&p, m3);
    Ajouter(&p, m4);

    return 0;
}
