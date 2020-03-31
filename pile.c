#include "pile.h"



void initPile( T_Pile * P)
{
  P->nbElts = 0;
}


int pilepleine(const  T_Pile *P)
{
  if (P->nbElts == MAX) {
    return 1;
  }

return 0;
}



int pilevide(const  T_Pile *P)
{
  if (P->nbElts == 0) {
    return 1;
  }

return 0;
}



int empiler( T_Pile *P, T_Elt e) //renvoie 0 si pile pleine, sinon 1
{
  if (P->nbElts == MAX){
    return 0;
  }

  (P->nbElts)++;
  P->Elts[P->nbElts] = e;
  return 1;
}



int depiler( T_Pile *P, T_Elt *pelt)  //renvoie 0 si pile vide, sinon 1
{
  if(P->nbElts == 0) {
    return 0;
  }

  *pelt = P->Elts[P->nbElts];
  (P->nbElts)--;
  return 1;
}



T_Elt sommet(const  T_Pile *P)
{
 return P->Elts[P->nbElts];
}



int hauteur(const  T_Pile *P)
{
return P->nbElts;
}


void afficherPile(  T_Pile *P)
{

  T_Pile P2;
	T_Elt S;
	initPile(&P2);
	if (pilevide(P) != 1)
	{
		while(pilevide(P) != 1)
		{
			depiler(P,&S);	
			afficherElt(&S);
			empiler(&P2,S);
		}

		while(pilevide(&P2) != 1)
		{
			empiler(P,S);
			depiler(&P2,&S);

		}
	}
  printf("\n");
}











