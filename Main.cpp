#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "arbre.h"
#include "arbre.cpp"
#include "dico.h"
#include "dico.c"

int main(){
    TArbre dico;
	dico = arbreConsVide();



int i=0;
srand(time(NULL));

    char* mot = (char*)malloc(255);

while(i<5)
{

	int x=piocherMot(mot);

	if(x==1){
		dicoInsererMot(mot,&dico);
		i++;
	}

}
dicoInsererMot("cas",&dico);
dicoInsererMot("cas",&dico);
dicoInsererMot("pull",&dico);
afficherArbre(dico);
dicoAfficher(dico);
printf("\n\nArbre vide? : %i \n",arbreEstVide(dico));
printf("Racine : %c \n",arbreRacineLettre(dico));
TArbre racineFilsDroit = noeudFilsDroit(dico);
TArbre racineFilsGauche = noeudFilsGauche(dico);
printf("noeud fils gauche : %c \n",arbreRacineLettre(racineFilsGauche ));
printf("noeud fils droit : %c \n",arbreRacineLettre(racineFilsDroit));
printf("nombre de Mots Total : %i \n",dicoNbMotsTotal(dico));
printf("nombre de Mots differents : %i \n",dicoNbMotsDifferents(dico));
printf("nombre d'occurrence du mot cas : %i \n",dicoNbOccMot("cas",dico));

lettrespercentage(dico);
arbreSuppr(&dico);
printf("Arbre vide ? : %i \n",arbreEstVide(dico));


return 0;
}
