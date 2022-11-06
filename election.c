#include <studio.h>
#include <stdlib.h>
#include "election.h"

int ajouter(char * election.txt, election e, municipalite m,date d )
{
    FILE * f=fopen(election.txt, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d\n",e.id_election);
	fprintf(f,"%d %d %d\n",m.id_municipalite,m.nb_habitant,m.nbr_conseilles)
	fprintf(f,"%d %d %d\n",d.jour,d.mois,d.annee)
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * election.txt, int id, election nouv )
{
    int tr=0;
    election e;
    FILE * f=fopen(election.txt, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while((fscanf(f,"%d\n",e.id_election)!=EOF)&&(f,"%d %d %d\n",m.id_municipalite,m.nb_habitant,m.nbr_conseilles)&&(f,"%d %d %d\n",d.jour,d.mois,d.annee)!=EOF)
        {
            if(p.id== id)
            {
                fprintf(f2,"%d\n",nouv.id_election);
		fprintf(f2,"%d %d %d\n",m.id_municipalite,m.nb_habitant,m.nbr_conseilles);
		fprintf(f2,"%d %d %d\n",d.jour,d.mois,d.annee);
                tr=1;
            }
            else
                fprintf(f,"%d\n",e.id_election);
		fprintf(f,"%d %d %d\n",m.id_municipalite,m.nb_habitant,m.nbr_conseilles)
		fprintf(f,"%d %d %d\n",d.jour,d.mois,d.annee);

        }
    }
    fclose(f);
    fclose(f2);file
    remove(election.txt);
    rename("nouv.txt", election.txt);
    return tr;

}
int supprimer(char * election.txt, int id)
{
    int tr=0;
    election p;
    FILE * f=fopen(election.txt, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while((fscanf(f,"%d\n",e.id_election)!=EOF)&&(f,"%d %d %d\n",m.id_municipalite,m.nb_habitant,m.nbr_conseilles)&&(f,"%d %d %d\n",d.jour,d.mois,d.annee)!=EOF)
        {
            if(p.id== id)
                tr=1;
            else
                fprintf(f2,"%d\n",nouv.id_election);
		fprintf(f2,"%d %d %d\n",m.id_municipalite,m.nb_habitant,m.nbr_conseilles);
		fprintf(f2,"%d %d %d\n",d.jour,d.mois,d.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove(election.txt);
    rename("nouv.txt", election.txt);
    return tr;
}
election chercher(char * election.txt, int id)
{
    election p;
    int tr;
    FILE * f=fopen(election.txt, "r");
    if(f!=NULL)
    {
        while((fscanf(f,"%d\n",e.id_election)!=EOF)&&(f,"%d %d %d\n",m.id_municipalite,m.nb_habitant,m.nbr_conseilles)&&(f,"%d %d %d\n",d.jour,d.mois,d.annee)!=EOF)
        {
            if(p.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        p.id=-1;
    return p;

}
