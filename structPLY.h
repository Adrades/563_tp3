#ifndef __STRUCT_PLY_H
#define __STRUCT_PLY_H

typedef struct monome Monome, *MONOME;
typedef struct polynome Polynome, *POLYNOME;

struct monome {
  int ordre;
  double coeff;
  MONOME suiv;
};

struct polynome {
  int degres;
  MONOME terme;
};


// Crée un MONOME de coeff double et d'ordre int
MONOME CreerM(double, int);

// Crée un POLYNOME à partir d'un MONOME
POLYNOME CreerP(MONOME);

// Ajoute un MONOME à un POLYNOME*
void Ajouter(POLYNOME*, MONOME);

// Supprime un MONOME du POLYNOME*
void Supprimer(POLYNOME*, MONOME);

// permet d'afficher un POLYNOME. les params char* et int pourraient être utilisés comme 'options' d'affichage!
void AfficherP(POLYNOME,char*,int);

// Affiche un MONOME. Le parametre int est utilisé comme option d'affichage!
void AfficherM(MONOME,int);

// Cherche un MONOME d'ordre int dans un POLYNOME
MONOME Chercher(POLYNOME,int);

// sert à faire une copie d'un POLYNOME
POLYNOME PolyCpy(POLYNOME);

// les 4 fonctions pour une 'arithmétique' polynomiale!!!
POLYNOME Add(POLYNOME, POLYNOME);
POLYNOME Sub(POLYNOME, POLYNOME);
POLYNOME Mul(POLYNOME, POLYNOME);
POLYNOME Div(POLYNOME, POLYNOME,POLYNOME*);
#endif
