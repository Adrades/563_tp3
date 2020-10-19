//
// Created by Adrades on 06/10/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "structPLY.h"

// Crée un MONOME de coeff double et d'ordre int
MONOME CreerM(double coeff, int ordre) {
    MONOME m = (MONOME) malloc(sizeof(Monome));
    m->coeff = coeff;
    m->ordre = ordre;
    m->suiv = NULL;
    return m;
}

// Crée un POLYNOME à partir d'un MONOME
POLYNOME CreerP(MONOME m) {
    POLYNOME p = (POLYNOME) malloc(sizeof(Polynome));

    p->degres = 0;

    if (m != NULL) {
        p->degres = m->ordre;

        MONOME cpy_m = (MONOME) malloc(sizeof(Monome));
        p->terme = cpy_m;
        cpy_m->ordre = m->ordre;
        cpy_m->coeff = m->coeff;
        cpy_m->suiv = NULL;
    } else {
        p->degres = 0;
        p->terme = NULL;
    }
    return p;
}


// Ajoute un MONOME à un POLYNOME*
void Ajouter(POLYNOME *p, MONOME m) {

    if ((*p)->terme == NULL) {
        (*p)->degres = m->ordre;
        (*p)->terme = m;
        (*p)->terme->suiv = NULL;
        return;
    }

    if ((*p)->degres < m->ordre) {
        (*p)->degres = m->ordre;
    }

    MONOME cur_monome = (*p)->terme;
    while (cur_monome->suiv != NULL && cur_monome->suiv->ordre <= m->ordre) {
        cur_monome = cur_monome->suiv;
    }

    if (cur_monome != NULL && m->ordre == cur_monome->ordre) {
        cur_monome->coeff += m->coeff;
    } else {
        MONOME cpy_m = (MONOME) malloc(sizeof(Monome));
        MONOME temp = cur_monome->suiv;
        cur_monome->suiv = cpy_m;
        cpy_m->suiv = temp;
        cpy_m->ordre = m->ordre;
        cpy_m->coeff = m->coeff;
    }
}

// Supprime un MONOME du POLYNOME*
void Supprimer(POLYNOME *p, MONOME m) {

}

// permet d'afficher un POLYNOME. les params char* et int pourraient être utilisés comme 'options' d'affichage!
void AfficherP(POLYNOME p, char *str, int i) {
    MONOME cur_monome = p->terme;
    while (cur_monome->suiv != NULL) {
        AfficherM(cur_monome, i);
        printf(" + ");
        cur_monome = cur_monome->suiv;
    }
    AfficherM(cur_monome, i);
}

// Affiche un MONOME. Le parametre int est utilisé comme option d'affichage!
void AfficherM(MONOME m, int i) {
    printf("%f x%d", m->coeff, m->ordre);
}

// Cherche un MONOME d'ordre int dans un POLYNOME
MONOME Chercher(POLYNOME p, int i) {
    MONOME cur_monome = p->terme;
    while (cur_monome->ordre < i && cur_monome->suiv != NULL) {
        cur_monome = cur_monome->suiv;
    }
    if (i == cur_monome->ordre) {
        return cur_monome;
    }
    return NULL;
}

// sert à faire une copie d'un POLYNOME
POLYNOME PolyCpy(POLYNOME p) {

    POLYNOME cpy_p = CreerP(p->terme);

    MONOME cur_monome = p->terme;

    while (cur_monome->suiv != NULL) {
        cur_monome = cur_monome->suiv;
        Ajouter(&cpy_p, cur_monome);
    }

    return cpy_p;
}

// les 4 fonctions pour une 'arithmétique' polynomiale!!!
POLYNOME Add(POLYNOME p1, POLYNOME p2) {
    POLYNOME p3 = PolyCpy(p1);
    MONOME cur_monome_p2 = p2->terme;

    while (cur_monome_p2 != NULL) {
        Ajouter(&p3, cur_monome_p2);
        cur_monome_p2 = cur_monome_p2->suiv;
    }

    return p3;
}

POLYNOME Sub(POLYNOME p1, POLYNOME p2) {
    POLYNOME p3 = PolyCpy(p1);
    MONOME cur_p2 = p2->terme;

    while (cur_p2 != NULL) {
        Ajouter(&p3, CreerM(-cur_p2->coeff, cur_p2->ordre));
        cur_p2 = cur_p2->suiv;
    }
    return p3;
}

POLYNOME Mul(POLYNOME p1, POLYNOME p2) {
    POLYNOME p3 = PolyCpy(p1);
    MONOME mul, cur_p3 = p3->terme;

    while (cur_p3 != NULL) {
        mul = Chercher(p2, cur_p3->ordre);
        if (mul != NULL) {
            cur_p3->coeff *= mul->coeff;
        }
        cur_p3 = cur_p3->suiv;
    }
    return p3;

}

POLYNOME Div(POLYNOME p1, POLYNOME p2, POLYNOME *p3) {
    POLYNOME quotient = CreerP(NULL);
    //POLYNOME copiePl = PolyCpy(pl);
    *p3 = PolyCpy(p1);

    //Tant qu'on peut faire la division
    while (p1->degres <= (*p3)->degres) {

        //On crée un polynome grace au dividende
        MONOME degreMax = Chercher(*p3, (*p3)->degres); //Degré max du truc a diviser
        //On en crée un qui a un ordre - 1
        MONOME monomeQuotient = CreerM(degreMax->coeff, degreMax->ordre - 1);
        //On l'ajoute dans notre quotient
        Ajouter(&quotient, monomeQuotient);
        //On multiplie notre dividende avec notre monomeQuotient
        POLYNOME pSous = Mul(p2, CreerP(monomeQuotient));
        //On soustrait notre diviseur par notre pSous
        *p3 = Sub(*p3, pSous);
//        AfficherP(*p3, "reste = ", 43);

    }

    return quotient;
}