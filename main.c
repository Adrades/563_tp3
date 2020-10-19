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

    // aff 5 x1, 1x 2, 3 x4

    MONOME m5 = Chercher(p, 1);

    if (m5 != NULL) {
        printf("\n");
        AfficherM(m5, 0);
        printf("\nTest de la copie: ");
        AfficherM(m1, 0);
        printf("\n");
    }

    POLYNOME p2 = PolyCpy(p);

    Ajouter(&p, m1);

    printf("\n");
    AfficherP(p2, "", 0);
    // Idem que précedement

    printf("\n");

    POLYNOME p3 = Add(p, p2);

    printf("\n");
    AfficherP(p3, "", 0);

    POLYNOME p4 = Sub(p3, p2);

    printf("\n");
    AfficherP(p4, "", 0);

    POLYNOME p5 = Mul(p4, p3);

    printf("\n");
    AfficherP(p5, "", 0);

//    POLYNOME pr = CreerP(NULL);
//
//    POLYNOME p6 = Div(p5, p3, &pr);
//
//    printf("\n");
//    AfficherP(p6, "", 0);
//
//    printf("\n");
//    AfficherP(pr, "", 0);




    return 0;
}
