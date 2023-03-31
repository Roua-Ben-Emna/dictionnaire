#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

TArbre arbreConsVide()
{
    return NULL;
}

bool arbreEstVide(TArbre a)
{
    if (a == NULL)
    {
        return true;
    }
    return false;
}

TArbre arbreCons(char caractere, int entier, TArbre filsGauche, TArbre filsDroit)
{
    TArbre a = (Noeud *)malloc(sizeof(Noeud));
    a->caractere = caractere;
    a->nbrOccurrence = entier;
    a->filsGauche = filsGauche;
    a->filsDroit = filsDroit;
    return a;
}

char arbreRacineLettre(TArbre a)
{
    if (!arbreEstVide(a))
    {
        return a->caractere;
    }
    return '\0';
}

int arbreRacineNbOcc(TArbre a)
{
    if (!arbreEstVide(a))
    {
        return a->nbrOccurrence;
    }
    return 0;
}

TArbre noeudFilsGauche(TArbre a)
{
    if (a != NULL)
    {
        return a->filsGauche;
    }
    return NULL;
}

TArbre noeudFilsDroit(TArbre a)
{
    if (a != NULL)
    {
        return a->filsDroit;
    }
    return NULL;
}

void arbreSuppr(TArbre *noeud)
{
    if (*noeud != NULL)
    {
        arbreSuppr(&((*noeud)->filsDroit));
        arbreSuppr(&((*noeud)->filsGauche));
        free(*noeud);
        *noeud = NULL;
    }
}

int hauteurArbre(TArbre a)
{
    if (a != NULL)
    {
        return 1 + MAX(hauteurArbre(a->filsGauche), hauteurArbre(a->filsDroit));
    }
    return -1;
}
void afficherNoeuds(TArbre noeud, int espace, int x, int y, int d)
{
    if (noeud != NULL)
    {
        // Afficher le caractère du nœud
        char str[2];
        str[0] = noeud->caractere;
        str[1] = '\0';
        int textWidth = textwidth(str);
        int textHeight = textheight(str);
        outtextxy(x - textWidth/2, y - textHeight/2, str);

        // Dessiner une ellipse pour représenter le nœud
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, BLACK);
        ellipse(x, y, 0, 360, 30, 15);
        floodfill(x, y, WHITE);

        // Dessiner une flèche vers le fils gauche
        if (noeud->filsGauche != NULL)
        {
            setcolor(WHITE);
            setlinestyle(SOLID_LINE, 0, 2);
            line(x, y + 10, x - d, y + 40);
            afficherNoeuds(noeud->filsGauche, espace + 1, x - d, y + 50, d / 2 + 13);
        }

        // Dessiner une flèche vers le fils droit
        if (noeud->filsDroit != NULL)
        {
            setcolor(WHITE);
            setlinestyle(SOLID_LINE, 0, 2);
            line(x, y + 10, x + d, y + 40);
            afficherNoeuds(noeud->filsDroit, espace + 1, x + d, y + 50, d / 2 + 13);
        }
    }
}

void afficherArbre(TArbre a)
{
    if (a != NULL)
    {
initwindow(1350, 800, "My Window");

        setbkcolor(BLACK);
        cleardevice();

        afficherNoeuds(a, 1, getmaxx() / 2, 30, 270);

        getch();

    }
}






