#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED

typedef struct Date
{
    int jour;
    int mois;
    int annee;
} date;


typedef struct 
{
    int id_municipalite;
    int nbr_habitant;
    int nbr_conseilles;
} muni;
	
typedef struct 
{
    int id_eletion;
    muni municipalite;
    date Date;
} election;

int rechercher_election(int id);
int ajouter_election(file.txt);
int modifier_election(int id, char municipalité, date date);
int supprimer_election(int id, file);


#endif // ELECTION_H_INCLUDED

