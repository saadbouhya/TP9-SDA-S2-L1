#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
  ptrF->Tete = -1;
  ptrF->Queue = -1;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
  if (ptrF->Queue == -1) {
    printf("La file est vide.\n");
    return 0;
  }
  else if (ptrF->Tete == ((ptrF->Queue)+1)) {
    printf("La file est vide.\n");
    return 0;
  }
  *ptrE = ptrF->Elts[ptrF->Tete];
  (ptrF->Tete)++;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
  if (ptrF->Queue == MAX-1) {
    printf("File pleine.\n");
  }
  if (ptrF->Queue == -1) {
    ptrF->Tete = 0;
  }
  (ptrF->Queue)++;
  ptrF->Elts[ptrF->Queue] = *ptrE;
return 0;
} 

int fileVide(const  T_File *ptrF) // qd Tete == 0 
{
  if (ptrF->Queue == -1) {
    return 1;
  }
  else if (ptrF->Tete == ((ptrF->Queue)+1)) {
    return 1;
  }
  else 
    return 0;

}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
  if (ptrF->Queue == MAX-1) {
    return 1;
  }
  else
    return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
return ptrF->Elts[ptrF->Tete];
}

void afficherFile(T_File *F)
{
  T_File F2;
	T_Elt S;
	initFile(&F2);
	if (fileVide(F) != 1)
	{
		while(fileVide(F) != 1)
		{
			retirer(F,&S);	
			afficherElt(&S);
			ajouter(&F2,&S);
		}

		while(fileVide(&F2) != 1)
		{
			ajouter(F,&S);
			retirer(&F2,&S);

		}
	}
  printf("\n");
}






