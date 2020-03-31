#include "es.h"



// lorsque T_ELt est un int  (c'est le case de notre TP)  
void saisirElt(T_Elt *e)
{
scanf("%d",e);
}
void afficherElt(T_Elt *e)
{
printf("\n%d",*e);
}
void affecterElt(T_Elt *d,T_Elt *s)
{
*d=*s;
}










// lorsque T_ELt est un char  (peut être un jour)
/*
void saisirElt(T_Elt *e)
{
scanf("%c",e);
}
void afficherElt(T_Elt *e)
{
printf("\n%c",*e);
}

void affecterElt(T_Elt *d,T_Elt *s)
{
*d=*s;
}
*/









// lorsque T_ELt est une chaine (peut être un jour)

/*
void saisirElt(T_Elt e)
{
scanf("%s",e);
}
void afficherElt(T_Elt e)
{
printf("\n%s",*e);
}


void affecterElt(T_Elt d,T_Elt s)
{
strcpy(d,s);
}
*/















