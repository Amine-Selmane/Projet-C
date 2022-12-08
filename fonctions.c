#include<stdio.h>
#include"le.h"
 enum
{
	ID,
	NOMLE,
	NB_CANDIDATS,
	ORIENTATION,
	JOUR,
	MOIS,
	ANNEE,
	ID_CAND1,
	ID_CAND2,
	ID_CAND3,
	COLUMNS
};
int Ajouter_LE(char* le,LE L)
{  
    FILE * f=fopen(le,"a+");
  
    if (f!=NULL){
      fprintf(f,"%d %s %d %s %d/%d/%d %d %d %d ",L.id,L.NomLE,L.Nb_candidats,L.orientation,L.jour,L.mois,L.annee,L.id_cand1,L.id_cand2,L.id_cand3);
 
      
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
    FILE * v=fopen("new.txt", "w+");
    if (f!=NULL && v!=NULL)
    {    
        while (fscanf(f,"%d %s %d %s %d/%d/%d %d %d %d",&L.id,L.NomLE,&L.Nb_candidats,L.orientation,&L.jour,&L.mois,&L.annee,&L.id_cand1,&L.id_cand2,&L.id_cand3) != EOF )
       {    
           if(L.id==id)
           { fprintf(v,"%d %s %d %s %d/%d/%d %d %d %d\n" ,L1.id,L1.NomLE,L1.Nb_candidats,L1.orientation,L1.jour,L1.mois,L1.annee,L1.id_cand1,L1.id_cand2,L1.id_cand3);}
           else
           { fprintf(v,"%d %s %d %s %d/%d/%d %d %d %d\n" ,L.id,L.NomLE,L.Nb_candidats,L.orientation,L.jour,L.mois,L.annee,L.id_cand1,L.id_cand2,L.id_cand3);}
}
    fclose(f);
    fclose(v);
    remove("le.txt");
    rename("new.txt","le.txt");
    return rep;
}
}
int Supprimer_LE(char* le,int id)
{   FILE *f=NULL;
    FILE *f1=NULL;
    LE l;
    f=fopen("le.txt","r");
    f1=fopen("new.txt","w+");
    while (fscanf(f,"%d %s %d %s %d/%d/%d %d %d %d",&l.id,l.NomLE,&l.Nb_candidats,l.orientation,&l.jour,&l.mois,&l.annee,&l.id_cand1,&l.id_cand2,&l.id_cand3) != EOF)
{
if (l.id!=0)
{ fprintf(f1,"%d %s %d %s %d/%d/%d %d %d %d",l.id,l.NomLE,l.Nb_candidats,l.orientation,l.jour,l.mois,l.annee,l.id_cand1,l.id_cand2,l.id_cand3);}
}
fclose(f);
fclose(f1);
remove("le.txt");
rename("new.txt","le.txt");
}

LE Chercher_LE(char * le,int id)
{
   LE L;
   int rep;
   FILE * f=fopen(le, "r");
   if (f!=NULL)
   {
       while(rep==0 && fscanf(f ,"%d %s %d %s %d/%d/%d %d %d %d\n" ,&L.id,L.NomLE,&L.Nb_candidats,L.orientation,&L.jour,&L.mois,&L.annee,&L.id_cand1,&L.id_cand2,&L.id_cand3)!= EOF )
       {
           if(L.id==id)
             rep=1;
       }
   }

if (rep==0)
   L.id=-1;
return L;
fclose(f);
}


void afficher_LE(GtkTreeView *liste)
{
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter ;
    GtkListStore *store;
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
    store=NULL;
    LE L;
    FILE *f;
    store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
    if(store==NULL){
        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("NomLE",renderer,"text",NOMLE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("Nb_candidats",renderer,"text",NB_CANDIDATS,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);  


	 renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("orientation",renderer,"text",ORIENTATION,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


 
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("id_cand1",renderer,"text",ID_CAND1,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
     
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("id_cand2",renderer,"text",ID_CAND2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("id_cand3",renderer,"text",ID_CAND3,NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



         
    }
          
    store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    f=fopen("le.txt","r");
    if(f==NULL)
      return;
    else
    {
                 f=fopen("le.txt","a+");
         while(fscanf(f ,"%d %s %d %s %d/%d/%d %d %d %d\n" ,&L.id,L.NomLE,&L.Nb_candidats,L.orientation,&L.jour,&L.mois,&L.annee,&L.id_cand1,&L.id_cand2,&L.id_cand3)!=EOF)
         {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,&id,&NomLE,&Nb_candidats,&orientation,&jour,&mois,&annee,&id_cand1,&id_cand2,&id_cand3);
         }
     fclose(f);
     gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
     g_object_unref(store);
    }
}


void rechercher_LE(GtkTreeView *liste,int id1 )
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=GTK_LIST_STORE(gtk_tree_view_get_model(liste));
if (store==NULL)
{



renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",
                                                            renderer,
                                                            "text", ID,
                                                            NULL);
       
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOMLE",
                                                            renderer,
                                                            "text", NOMLE,
                                                            NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NB_CANDIDATS",
                                                            renderer,
                                                            "text", NB_CANDIDATS,
                                                            NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);





        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ORIENTATION",
                                                            renderer,
                                                            "text", ORIENTATION,
                                                            NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);





        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            renderer,
                                                            "text", JOUR,
                                                            NULL);
       
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("MOIS",
                                                            renderer,
                                                            "text", MOIS,
                                                            NULL);
       
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ANNEE",
                                                            renderer,
                                                            "text", ANNEE,
                                                            NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);




renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID_CAND1",
                                                            renderer,
                                                            "text", ID_CAND1,
                                                            NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID_CAND2",
                                                            renderer,
                                                            "text", ID_CAND2,
                                                            NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID_CAND3",
                                                            renderer,
                                                            "text", ID_CAND3,
                                                            NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);






}
store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f=fopen("le.txt","r");
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



{
f=fopen("le.txt","a+");
while(fscanf(f,"%d %s %d %s %d/%d/%d %d %d %d",&id,NomLE,&Nb_candidats,orientation,&jour,&mois,&annee,&id_cand1,&id_cand2,&id_cand3)!=EOF)
{ if(id==id1) {
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,id,NOMLE,NomLE,NB_CANDIDATS,Nb_candidats,ORIENTATION,orientation,JOUR,jour,MOIS,mois,ANNEE,annee,ID_CAND1,id_cand1,ID_CAND2,id_cand2,ID_CAND3,id_cand3,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


































