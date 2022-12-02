#include<stdio.h>
#include"le.h"
int Ajouter_LE(char* le,LE L)
{  
    FILE * f=fopen(le,"a");
  
    if (f!=NULL){
      do {
            fprintf(f,"%d",L.Nb_candidats);
      }while((L.Nb_candidats >10)||(L.Nb_candidats<0));
      fprintf(f,"%d %s %d/%d/%d",L.id,L.NomLE,L.date_ajout.jour,L.date_ajout.mois,L.date_ajout.annee);
      for(int i=0;i<L.Nb_candidats;i++){
   
    fprintf(f," %d %s %s %s  %d/%d/%d \n" ,L.T[i].id,L.T[i].Nom,L.T[i].Prenom,L.T[i].profession,L.T[i].date_ajout.jour,L.T[i].date_ajout.mois,L.T[i].date_ajout.annee);
 L.tete=L.T[0].id;}
 
      
 fclose(f);
        return 1;
    }
    else return 0;
}
int Modifier_LE(char* le,int id,LE L1)
{   
    int rep=0;
    LE L; 
    FILE * f=fopen(le, "r");
    FILE * v=fopen("nouv.txt", "w");
    if (f!=NULL && v!=NULL)
    {    
        while (fscanf(f,"%d %s %d %d %d/%d/%d",&L.id,L.NomLE,&L.Nb_candidats,&L.tete,&L.date_ajout.jour,&L.date_ajout.mois,&L.date_ajout.annee) != EOF )
       {    
           if(L.id==id)
           { fprintf(v,"%d %s %d %d %d/%d/%d\n" ,L1.id,L1.NomLE,L1.Nb_candidats,L1.tete,L1.date_ajout.jour,L1.date_ajout.mois,L1.date_ajout.annee);

      for (int i=0;i<L1.Nb_candidats;i++){
      fprintf(v," %d %s %s %s  %d/%d/%d \n" ,L1.T[i].id,L1.T[i].Nom,L1.T[i].Prenom,L1.T[i].profession,L1.T[i].date_ajout.jour,L1.T[i].date_ajout.mois,L1.T[i].date_ajout.annee);}
    fclose(f);
    fclose(v);
    remove(le);
    rename("nouv.txt",le);
    return rep;
}
}}}
int Supprimer_LE(char* le,int id)
{   LE L;
    int rep;
    FILE * f=fopen(le, "r");
    FILE * v=fopen("nouv.txt", "w");
    if (f!=NULL && v!=NULL)
    {
        while (fscanf(f ,"%d %s %d %d %d/%d/%d\n" ,&L.id,L.NomLE,&L.Nb_candidats,&L.id_can,&L.date_ajout.jour,&L.date_ajout.mois,&L.date_ajout.annee)!= EOF )
     {    
         if (L.id==id)
             rep=1;
         else {
            fprintf(v, "%d %s %d %d %d/%d/%d\n" ,L.id,L.NomLE,L.Nb_candidats,L.id_can,L.date_ajout.jour,L.date_ajout.mois,L.date_ajout.annee);
        for(int i=0;i<L.Nb_candidats;i++){
        fprintf(f,"%d %s %s %s %d/%d/%d\n" ,L.T[i].id,L.T[i].Nom,L.T[i].Prenom,L.T[i].profession,L.T[i].date_ajout.jour,L.T[i].date_ajout.mois,L.T[i].date_ajout.annee);}
      
}
     }
    }
fclose(f);
fclose(v);
remove(le);
rename("nouv.txt",le);
return rep;
}
LE Chercher_LE(char * le,int id)
{
   LE L;
   int rep;
   FILE * f=fopen(le, "r");
   if (f!=NULL)
   {
       while(rep==0 && fscanf(f ,"%d %s %d %d %d/%d/%d\n" ,&L.id,L.NomLE,&L.Nb_candidats,&L.can,&L.date_ajout.jour,&L.date_ajout.mois,&L.date_ajout.annee)!= EOF )
       {
           if(L.id==id)
             rep=1;
       }
   }
fclose(f);
if (rep==0)
   L.id=-1;
return L;
}





