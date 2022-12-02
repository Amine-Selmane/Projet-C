#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "le.h"


void
on_button_ajouter_liste_chaima_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry_id_l;
GtkWidget *entry_nom_l;
GtkWidget *combo_gov;
GtkWidget *spin_jour_c;
GtkWidget *spin_mois_c;
GtkWidget *spin_annee_c;
GtkWidget *entry_id_c1;
GtkWidget *entry_id_c2;
GtkWidget *entry_id_c3;
GtkWidget *radio_nb_cand;

char id0[10];
char id1[10];
char id2[10];
char id3[10];
LE l;
entry_id_l=lookup_widget(objet_graphique, "entry_id_liste_chaima");
entry_id_c1=lookup_widget(objet_graphique, "entry_id_can1_chaima");
entry_id_c2=lookup_widget(objet_graphique, "entry_id_can2_chaima");
entry_id_c3=lookup_widget(objet_graphique, "entry_id_can3_chaima");
entry_nom_l=lookup_widget(objet_graphique, "entry_nom_liste_chaima");
combo_gov=lookup_widget(objet_graphique, "combo_gov_chaima");
radio_nb_cand=lookup_widget(objet_graphique, "radio_nb_cand_chaima");
spin_jour_c=lookup_widget(objet_graphique, "spin_jour_chaima");
spin_mois_c=lookup_widget(objet_graphique, "spin_mois_chaima");
spin_annee_c=lookup_widget(objet_graphique, "spin_annee_chaima");

l.date_ajout.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_jour_c));
l.date_ajout.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_mois_c));
l.date_ajout.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_annee_c));

strcpy(id0,gtk_entry_get_text(GTK_ENTRY(entry_id_l)));
l.id=atoi(id0);
strcpy(id0,gtk_entry_get_text(GTK_ENTRY(entry_id_c1)));
l.id_can=atoi(id1);
strcpy(id0,gtk_entry_get_text(GTK_ENTRY(entry_id_c2)));
l.id_can=atoi(id2);
strcpy(id0,gtk_entry_get_text(GTK_ENTRY(entry_id_c3)));
l.id_can=atoi(id3);
strcpy(l.date_ajout.jour,gtk_entry_get_text(GTK_ENTRY(spin_jour_c)));
strcpy(l.date_ajout.mois,gtk_entry_get_text(GTK_ENTRY(spin_mois_c)));
strcpy(l.date_ajout.annee,gtk_entry_get_text(GTK_ENTRY(spin_annee_c)));
gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo_gov));

}


