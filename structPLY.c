//
// Created by Adrades on 06/10/2020.
//
#include <stdlib.h>
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
POLYNOME CreerP(MONOME m){
    POLYNOME p = (POLYNOME) malloc(sizeof(Polynome));
    p->degres = 0;
    p->terme = m;
    return p;
}

// Ajoute un MONOME à un POLYNOME*
void Ajouter(POLYNOME* p, MONOME m){
    MONOME cur_monome = (*p)->terme;
    while (cur_monome->ordre > m->ordre){
        cur_monome = cur_monome->suiv;
    }

    if (m->ordre == cur_monome->ordre){
        cur_monome->coeff += m->coeff;
    } else {
        MONOME temp = cur_monome->suiv;
        cur_monome->suiv = m;
        cur_monome->suiv->suiv = temp;
    }
}

// Supprime un MONOME du POLYNOME*
void Supprimer(POLYNOME* p, MONOME m){

}

// permet d'afficher un POLYNOME. les params char* et int pourraient être utilisés comme 'options' d'affichage!
void AfficherP(POLYNOME p,char* str, int i){

}

// Affiche un MONOME. Le parametre int est utilisé comme option d'affichage!
void AfficherM(MONOME m, int i){

}

// Cherche un MONOME d'ordre int dans un POLYNOME
//MONOME Chercher(POLYNOME p, int i){
//
//}

// sert à faire une copie d'un POLYNOME
//POLYNOME PolyCpy(POLYNOME);

// les 4 fonctions pour une 'arithmétique' polynomiale!!!
//POLYNOME Add(POLYNOME, POLYNOME);
//POLYNOME Sub(POLYNOME, POLYNOME);
//POLYNOME Mul(POLYNOME, POLYNOME);
//POLYNOME Div(POLYNOME, POLYNOME,POLYNOME*);