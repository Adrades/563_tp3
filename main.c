#include <stdio.h>
#include "structPLY.h"

int main() {
    printf("Hello, World!\n");

    MONOME m1 = CreerM(2, 1);
    MONOME m2 = CreerM(3, 1);
    MONOME m3 = CreerM(3, 4);
    MONOME m4 = CreerM(1, 2);

    POLYNOME p = CreerP(m1);

    Ajouter(&p, m2);
    Ajouter(&p, m3);
    Ajouter(&p, m4);

    AfficherP(p, "", 0);

    MONOME m5 = Chercher(p, 1);

    if (m5 != NULL) {
        printf("\n");
        AfficherM(m5, 0);
        printf("\n");
        AfficherM(m1, 0);
        printf("\n");
    }

    return 0;
}
