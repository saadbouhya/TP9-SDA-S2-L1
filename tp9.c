// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"
#include <stdlib.h>
#include <string.h>

#define passerAuPremierFils(adrP,E) empiler(adrP,E)
#define remonterAuPere(adrP,adrE) depiler(adrP,adrE)
#define passerAuFrereSuivant(adrP,adrE) depiler(adrP,adrE),empiler(adrP,1+(*adrE))
#define naPlusDeFrere(adrP,TailleChaine) sommet(adrP)==(int)TailleChaine
#define noeudTerminal(adrP,TailleChaine) hauteur(adrP)==(int)TailleChaine
#define rechercheTerminee(adrP) pilevide(adrP)




int menu()
{

int choix;
printf("\n\n\n SDA1 TP9");
printf("\n\n\n 1 : tester mon fichier pile.c");
printf("\n 2 : tester mon fichier file.c");
printf("\n 3 : afficher et compter les permutations d'une chaine");
printf("\n 4 : afficher et compter les solutions pour un échiquier ");
printf("\n 5 : Tester Afficherpermut ");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}

void testPile(T_Pile *P);
void testFile(T_File *F);
void permut(T_Pile P, char chaine[20]);
//void permut(T_Pile *P,char *ch);
int pileValide(T_Pile *P);
//void afficherPermut(T_Pile *P, char chaine[20], int len);
void permutEch(T_Pile P, int taille);
int echValide(T_Pile *P);

int main()
{
T_File mafile;
T_Pile mapile;
int chx;
int taille;
char chaine[20];

do
{
chx=menu();
switch (chx)
	{
	case 1 :  
		//testez toutes vos fonctions par un jeu de test de votre choix
		testPile(&mapile); //TP9 partie 1 : à ecrire 
		break;
	case 2 : //testez toutes vos fonctions par un jeu de test de votre choix
		testFile(&mafile); //TP9 partie 1 : à ecrire 
		break; 
	case 3 : 
		printf("Veuillez saisir la chaine: ");
		scanf("%s",chaine); //une chaine de longueur <=MAX
		permut(mapile,chaine); //TP9 partie 2: ecrire permut
		break;
	case 4 : 
		scanf("%d",&taille);//taille echiquier <=MAX
		permutEch(mapile,taille); //TP9 partie 3: ecrire echiquier
		break;



	}
}while(chx!=0);

printf("\nau plaisir de vous revoir ...\n");
return 0;
}


void testPile(T_Pile *P) {
	
	initPile(P);
	printf("1. empiler\n");
	printf("2. depiler\n");
	printf("3. afficher la pile\n");
	printf("4. Le sommet de la pile.\n");
	printf("5. La hauteur de la pile.\n");
	printf("6. Est-ce que la pile est vide.\n");
	printf("7. Est-ce que la pile pleine.\n");
	printf("0. quitter\n");
	int choix, valeur;

	while(1) {
		printf("saisir votre choix: ");
		scanf("%d", &choix);
		switch(choix) {
			case 1:	printf("Saisir la valeur: ");
							scanf("%d", &valeur);
							empiler(P, valeur);
							break;
			case 2: if (depiler (P, &valeur) != 0)
								printf("La valeur depilee est: %d\n", valeur);
							break;
			case 3:	afficherPile(P);
							break; 
			case 4: printf("Le sommet est %d\n", sommet(P));
							break;
			case 5: printf("La hateur de la pile est %d\n", hauteur(P));
							break;
			case 6: if (pilevide(P) == 1)
								printf("La pile est vide.\n");
							else
								printf("Pile non vide.\n");
							break;
			case 7: if(pilepleine(P) == 1) 
								printf("La pile est pleine.\n");
							else 
								printf("Pile non pleine.\n");
							break;
			case 0: exit(0);
			default: printf("Choix invalide\n"); 

		}
	}
}

void testFile(T_File *F) {
	
	initFile(F);
	printf("1. ajouter\n");
	printf("2. retirer\n");
	printf("3. afficher la file\n");
	printf("4. Le premier element.\n");
	printf("5. Est-ce que la file est vide.\n");
	printf("6. Est-ce que la file est pleine.\n");
	printf("7. quitter\n");
	int choix, valeur;

	while(1) {
		printf("saisir votre choix: ");
		scanf("%d", &choix);
		switch(choix) {
			case 1:	printf("Saisir la valeur: ");
							scanf("%d", &valeur);
							ajouter(F, &valeur);
							break;
			case 2: if (retirer (F, &valeur) != 0)
								printf("La valeur retiree est: %d\n", valeur);
							break;
			case 3:	afficherFile(F);
							break; 
			case 4: printf("Le premier element de la file est %d\n", premier(F));
							break;
			case 5: if (fileVide(F) == 1)
								printf("La file est vide.\n");
							else
								printf("File non vide.\n");
							break;
			case 6: if (filePleine(F) == 1) 
								printf("La file est pleine.\n");
							else 
								printf("File non pleine.\n");
							break;
			case 7: exit(0);
			default: printf("Choix invalide\n"); 

		}
	}
}


void permut(T_Pile P, char *chaine) {
	int compteur=0;
	T_Elt a;

	do {
		while (pileValide(&P)) {
			if (noeudTerminal(&P, strlen(chaine))) {
				for (int i=0; i < (P.nbElts); i++) {
					printf("%c", chaine[(P.Elts[i])-1]);
				}
				printf(" ");
				compteur++;
				break;
			}
			else {
				passerAuPremierFils(&P, 1);
			}
		}

		while (rechercheTerminee(&P) != 1 && naPlusDeFrere(&P, strlen(chaine))) {
			remonterAuPere(&P,&a);
		}

		if (rechercheTerminee(&P) != 1) {
			passerAuFrereSuivant(&P,&a);
		}
	} while(rechercheTerminee(&P) != 1);
	printf("\n");
	printf("Le nombre de permutations possible est %d\n", compteur);
}

// int pileValide(T_Pile *P) {
// 	int i, j;

// 	for(i=0;i<hauteur(P);i++) 
// 	{
// 		for(j=i+1;j<hauteur(P);j++) // comparer la pile et la chaine
// 		{
// 			if(P->Elts[i]==P->Elts[j]) // si élément similaire -> ne pas empiler
// 			{
// 				return 0;
// 			}
// 		}
// 	}
// 	return 1;
// }

int pileValide(T_Pile *P)
{
	int i=0,j,trouve=0;
	while(i<P->nbElts-1 && trouve==0)
	{
		j=i+1;
		while(j<P->nbElts && trouve==0)
		{
			if(P->Elts[i]==P->Elts[j])
				trouve++;

			j++;
		}
		i++;
	}
	if(trouve>0)
		return 0;

	else
		return 1;
}

// void afficherPermut(T_Pile *P, char chaine[20], int len) {
// 	for (int i=1; i<=len; i++) {
// 		printf("%c", chaine[P->Elts[i]]);
// 	}
// 	printf(" ");
// }


/*void permut(T_Pile *P,char *ch)
{
	T_Elt E;

	int end=0,cpt=0,k=0;	
	do
	{
	end=0;
	while(pileValide(P)==1 && end==0){	
		if(noeudTerminal(P,strlen(ch))){
			for(k=0;k<P->nbElts;k++)
			{
				printf("%c",ch[P->Elts[k]-1]);
			}
			
			printf(" - ");			
			end=1;	
			cpt++;	
		}
		else
		{
	
		passerAuPremierFils(P,1);
		}	
	}
	while(!rechercheTerminee(P) && naPlusDeFrere(P,strlen(ch))){
		 remonterAuPere(P,&E); 
	}
	if(!rechercheTerminee(P)){
		 passerAuFrereSuivant(P,&E);
	}	

} while(!rechercheTerminee(P));
	printf("\n Il y a %d permutations. \n",cpt);
}*/
void permutEch(T_Pile P, int taille) {
	int compteur=0;
	T_Elt a;

	do {
		while (echValide(&P)) {
			if (noeudTerminal(&P, taille)) {
				for (int i=0; i < (P.nbElts); i++) {
					printf("%d", P.Elts[i]);
				}
				printf(" ");
				compteur++;
				break;
			}
			else {
				passerAuPremierFils(&P, 1);
			}
		}

		while (rechercheTerminee(&P) != 1 && naPlusDeFrere(&P, 4)) {
			remonterAuPere(&P,&a);
		}

		if (rechercheTerminee(&P) != 1) {
			passerAuFrereSuivant(&P,&a);
		}
	} while(rechercheTerminee(&P) != 1);
	printf("\n");
	printf("Le nombre de permutations possible est %d\n", compteur);
}

int echValide(T_Pile *P) {
	int i, j;

	for(i=1; i<hauteur(P); i++) 
	{
			if(P->Elts[i]==P->Elts[i-1] || P->Elts[i]==(P->Elts[i-1]+1) || P->Elts[i]==(P->Elts[i-1]-1))
			{
				return 0;
			}
	}
	return 1;
}