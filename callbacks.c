#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "le.h"


int nb_cand=3;

void
on_button_valider1_chaima_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry_id_l;
GtkWidget *entry_nom_l;
GtkWidget *combo_ori;
GtkWidget *spin_jour_c;
GtkWidget *spin_mois_c;
GtkWidget *spin_annee_c;
GtkWidget *entry_id_c1;
GtkWidget *entry_id_c2;
GtkWidget *entry_id_c3;
GtkWidget *radio_nb_cand;
GtkWidget *label;
GtkWidget *label1;
char id0[10];
char id1[10];
char id2[10];
char id3[10];
LE l;

entry_id_l=lookup_widget(objet_graphique, "entry_id_liste_chaima");
strcpy(id0,gtk_entry_get_text(GTK_ENTRY(entry_id_l)));
l.id=atoi(id0);
entry_nom_l=lookup_widget(objet_graphique, "entry_nom_liste_chaima");
strcpy(l.NomLE,gtk_entry_get_text(GTK_ENTRY(entry_nom_l)));
combo_ori=lookup_widget(objet_graphique, "combo_ori_chaima");
strcpy(l.orientation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo_ori)));
l.Nb_candidats=nb_cand;
spin_jour_c=lookup_widget(objet_graphique, "spin_jour_chaima");
l.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_jour_c));
spin_mois_c=lookup_widget(objet_graphique, "spin_mois_chaima");
l.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_mois_c));
spin_annee_c=lookup_widget(objet_graphique, "spin_annee_chaima");
l.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_annee_c));
entry_id_c1=lookup_widget(objet_graphique, "entry_id_can1_chaima");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry_id_c1)));
l.id_cand1=atoi(id1);
entry_id_c2=lookup_widget(objet_graphique, "entry_id_can2_chaima");
strcpy(id2,gtk_entry_get_text(GTK_ENTRY(entry_id_c2)));
l.id_cand2=atoi(id2);
entry_id_c3=lookup_widget(objet_graphique, "entry_id_can3_chaima");
strcpy(id3,gtk_entry_get_text(GTK_ENTRY(entry_id_c3)));
l.id_cand3=atoi(id3);
label=lookup_widget(objet_graphique,"label24");
label1=lookup_widget(objet_graphique,"label27");
l=Chercher_LE("le.txt",l.id);
if (l.id!=-1)
gtk_label_set_text(GTK_LABEL(label1),"ID deja utilise");
else
{int test=Ajouter_LE("le.txt",l);
if(test==1)
gtk_label_set_text(GTK_LABEL(label),"ajout avec succes");
}


}


void
on_radio_nb_cand_chaima_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
nb_cand=3;
}


void
on_button_retour_ges2_chaima_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ajout_liste");
p=lookup_widget(objet_graphique, "menu");
p= create_menu();
gtk_widget_destroy(n);
}


void
on_button_valider2_chaima_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry_id_l;
GtkWidget *entry_nom_l;
GtkWidget *combo_ori;
GtkWidget *spin_jour_c;
GtkWidget *spin_mois_c;
GtkWidget *spin_annee_c;
GtkWidget *entry_id_c1;
GtkWidget *entry_id_c2;
GtkWidget *entry_id_c3;
GtkWidget *radio_nb_cand;
GtkWidget *label;
GtkWidget *label1;
char id0[10];
char id1[10];
char id2[10];
char id3[10];
LE L1;

entry_id_l=lookup_widget(objet_graphique, "entry_id_liste1_chaima");
strcpy(id0,gtk_entry_get_text(GTK_ENTRY(entry_id_l)));
L1.id=atoi(id0);
entry_nom_l=lookup_widget(objet_graphique, "entry_nom_liste1_chaima");
strcpy(L1.NomLE,gtk_entry_get_text(GTK_ENTRY(entry_nom_l)));
combo_ori=lookup_widget(objet_graphique, "combo_ori1_chaima");
strcpy(L1.orientation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo_ori)));
L1.Nb_candidats=nb_cand;
spin_jour_c=lookup_widget(objet_graphique, "spin_jour1_chaima");
L1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_jour_c));
spin_mois_c=lookup_widget(objet_graphique, "spin_mois1_chaima");
L1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_mois_c));
spin_annee_c=lookup_widget(objet_graphique, "spin_annee1_chaima");
L1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_annee_c));
entry_id_c1=lookup_widget(objet_graphique, "entry_id_can1_chaima1");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry_id_c1)));
L1.id_cand1=atoi(id1);
entry_id_c2=lookup_widget(objet_graphique, "entry_id_can2_chaima2");
strcpy(id2,gtk_entry_get_text(GTK_ENTRY(entry_id_c2)));
L1.id_cand2=atoi(id2);
entry_id_c3=lookup_widget(objet_graphique, "entry_id_can3_chaima3");
strcpy(id3,gtk_entry_get_text(GTK_ENTRY(entry_id_c3)));
L1.id_cand3=atoi(id3);
label=lookup_widget(objet_graphique,"label29");
label1=lookup_widget(objet_graphique,"label28");
L1=Chercher_LE("le.txt",L1.id);
if (L1.id!=-1)
gtk_label_set_text(GTK_LABEL(label1),"la liste n'existe pas!");
else
{int test=Modifier_LE("le.txt",L1.id ,L1);
if(test==1)
gtk_label_set_text(GTK_LABEL(label),"les donnees sont changees");
}
}




void
on_button_chercher_liste_chaima_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *n;
GtkWidget *label;
char ch[20];
int id ; 
LE L;
n=lookup_widget(objet_graphique, "entry_chercher_liste_chaima");
label=lookup_widget(objet_graphique, "label26");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(n)));
id=atoi(ch);
L=Chercher_LE("le.txt",id);
if (L.id==-1)
gtk_label_set_text(GTK_LABEL(label),"ID non trouve");
}














void
on_button_afficher_chaima_clicked      (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "affichage_liste");
p=lookup_widget(objet_graphique, "menu");
n= create_affichage_liste ();
gtk_widget_show(n);

}


void
on_button_ajouter_chaima_clicked       (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "ajout_liste");
p=lookup_widget(objet_graphique, "menu");
n= create_ajout_liste ();
gtk_widget_show(n);


}


void
on_button_modifier_chaima_clicked      (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "modification_liste");
p=lookup_widget(objet_graphique, "menu");
n= create_modification_liste ();
gtk_widget_show(n);

}


void
on_button_supprimer_chaima_clicked     (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "suppression_liste");
p=lookup_widget(objet_graphique, "menu");
n= create_suppression_liste ();
gtk_widget_show(n);


}


void
on_button_retour_ges1_chaima_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "affichage_liste");
p=lookup_widget(objet_graphique, "menu");
p= create_menu();
gtk_widget_destroy(n);

}


void
on_button_retour_ges4_chaima_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "suppression_liste");
p=lookup_widget(objet_graphique, "menu");
p= create_menu();
gtk_widget_destroy(n);

}


void
on_button_retour_ges5_chaima_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "statistique_liste");
p=lookup_widget(objet_graphique, "menu");
p= create_menu();
gtk_widget_destroy(n);
}


void
on_button_ges3_chaima_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "modification_liste");
p=lookup_widget(objet_graphique, "menu");
p= create_menu();
gtk_widget_destroy(n);
}




void
on_button_valider3_chaima_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *l;
GtkWidget *sortie;
char ch[10] ;
int id1,test;
l=lookup_widget(objet_graphique,"entry_id_iste2_chaima");
sortie=lookup_widget(objet_graphique,"label22");
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(l)));
id1=atoi(ch);
test=Supprimer_LE("le.txt",id1);
if(test==1)
gtk_label_set_text(GTK_LABEL(sortie),"ID  supprimee");
else 
gtk_label_set_text(GTK_LABEL(sortie),"error");
}


void
on_button_stat_liste_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*n;
GtkWidget*p;
n=lookup_widget(objet_graphique, "statistique_liste");
p=lookup_widget(objet_graphique, "menu");
n= create_modification_liste ();
gtk_widget_show(n);

}


void
on_radio_nb_cand1_chaima_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
nb_cand=3;
}


void
on_treeview_liste_chaima_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gint *id;
gchar *NomLE;
gint *Nb_candidats;
gchar *orientation;
gint *jour;
gint *mois;
gint *annee;
gint *id_cand1;
gint *id_cand2;
gint *id_cand3;

LE l2;
int t;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{ gtk_tree_model_get(GTK_TREE_MODEL(model),&iter,0,&id,1,&NomLE,2,&Nb_candidats,3,&orientation,4,&jour,5,&mois,6,&annee,7,&id_cand1,8,&id_cand2,9,&id_cand3,-1);
strcpy(l2.NomLE,NomLE);
strcpy(l2.orientation,orientation);
l2.id=*id;
l2.Nb_candidats=*Nb_candidats;
l2.jour=*jour;
l2.mois=*mois;
l2.annee=*annee;
l2.id_cand1=*id_cand1;
l2.id_cand2=*id_cand2;
l2.id_cand3=*id_cand3;
if(t=Supprimer_LE("le.txt",l2.id)==1)
afficher_LE(treeview);
}
}


void
on_button_afficher_liste_chaima_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *treeview;
treeview=lookup_widget(objet_graphique,"treeview_liste_chaima");
afficher_LE(GTK_TREE_VIEW(treeview));
}













