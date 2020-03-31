#include "es.h" 	 
#define MAX 10 //pile STATIQUE (limitée à MAX éléments)


typedef struct  
{
T_Elt Elts[MAX];  // stockage d'éléments de la case 0 à la case MAX-1
int nbElts; 
} T_Pile;


void initPile( T_Pile * ); //mettre nbElts à 0
int pilepleine(const  T_Pile *); //renvoie 1  qd nbElts == MAX
int pilevide(const  T_Pile *); // renvoie 1  qd nbElts == 0 
int empiler( T_Pile *, T_Elt ); //push de e dans la case nbElts de Elts, renvoie 1 si empiler OK, 0 sinon (qd pilePleine) 
int depiler( T_Pile *, T_Elt *); //pop retourne le T_Elt via pelt et renvoie 0 si pile vide, 1 sinon.
T_Elt sommet(const  T_Pile *);// valeur au sommet de la pile
int hauteur(const  T_Pile *);
void afficherPile(T_Pile *); //vous devez depiler la pile pour afficher chacune de ses valeurs (puis surtout la rempiler)


