#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <gtk/gtk.h>

typedef struct
{
int id;
char NomLE[20];
int Nb_candidats;
char orientation[20];
int id_cand1;
int id_cand2;
int id_cand3;
int jour;
int mois;
int annee;
}LE;




int Ajouter_LE(char* le, LE L);
int Modifier_LE(char* le,int id ,LE L1);
int Supprimer_LE(char* le, int id);
LE Chercher_LE(char *le,int id);
void afficher_LE(GtkTreeView *liste);
void rechercher_LE(GtkTreeView *liste,int id1 );






#endif // HEADER_H_INCLUDED
