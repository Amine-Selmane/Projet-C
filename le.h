#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
int jour;
int mois;
int annee;
}Date;

typedef struct
{
int id;
char Nom[20];
char Prenom[20];
char profession[20];
int age;
char sexe[10];
}Candidat;

typedef struct
{
int id;
char NomLE[20];
Candidat T[9];
int Nb_candidats;
int id_can;
Date date_ajout;
}LE;

int Ajouter_LE(char* le, LE L);
int Modifier_LE(char* le,int id ,LE L1);
int Supprimer_LE(char* le, int id);
LE Chercher_LE(char *le,int id);


#endif // HEADER_H_INCLUDED
