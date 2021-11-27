#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
int x;
void
on_button_gestionfoyer_accueil_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_gestionstock_acceuil_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_nutritionniste_accueil_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_gestioncapteur_accueil_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowaccueil2,*windowcapteur;
gtk_widget_destroy(windowaccueil2);
windowcapteur=create_capteur();
gtk_widget_show(windowcapteur);
}


void
on_button_inscription_accueil_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_retour_to_accueil_de_connexion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_authentification_jesser_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_jesser_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajout_capteur_dhia_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ajout_capteur_dhia;
window_ajout_capteur_dhia=create_window_ajout_capteur_dhia();
gtk_widget_show(window_ajout_capteur_dhia);
}


void
on_button_supprimercapteur_dhia_clicked
                                        (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_supprission_capteur_dhia,*windowcapteur;
gtk_widget_destroy(windowcapteur);
window_supprission_capteur_dhia=create_window_supprission_capteur_dhia();
gtk_widget_show(window_supprission_capteur_dhia);
}


void
on_button_retourto_accueil_from_capteur_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
*windowcapteur,*windowaccueil2;
gtk_widget_destroy(windowcapteur);
windowaccueil2=create_accueil2();
gtk_widget_show(windowaccueil2);
}


void
on_button_connexion_alterne_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton_temp_dhia_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=1;
}


void
on_radiobutton_fum__e_dhia_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=2;
}


void
on_radiobutton_infrarouge_dhia_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=3;
}


void
on_button_ajoutcapt_interface_dhia_clicked
                                        (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
 *nomcapt,*ref,*marque,*j1,*m1,*a1,*type,*garantie,*valmax,*valmin,*windowcapteur,*window_ajout_capteur_dhia;


capteur t;

j1=lookup_widget(objet_graphique,"spinbutton_j1_dhia");
t.date.j1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j1));

m1=lookup_widget(objet_graphique,"spinbutton_m1_dhia");
t.date.m1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m1));

a1=lookup_widget(objet_graphique,"spinbutton_a1_dhia");
t.date.a1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a1));

nomcapt=lookup_widget(objet_graphique,"entry_nomcapt_dhia");
ref=lookup_widget(objet_graphique,"entry_refcapt_dhia");
marque=lookup_widget(objet_graphique,"entry_marquecapt_dhia");
garantie=lookup_widget(objet_graphique,"entry_gar_dhia");
valmax=lookup_widget(objet_graphique,"entry_valmax_dhia");
valmin=lookup_widget(objet_graphique,"entry_valmin_dhia");
strcpy(t.nomcapt,gtk_entry_get_text(GTK_ENTRY(nomcapt)));
t.ref=atoi(gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(t.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
t.gar=atoi(gtk_entry_get_text(GTK_ENTRY(garantie)));
t.valmax=atoi(gtk_entry_get_text(GTK_ENTRY(valmax)));
t.valmin=atoi(gtk_entry_get_text(GTK_ENTRY(valmin)));
if (x==1)
t.type=1;
else if (x==2)
t.type=2;
else if (x==3)
t.type=3;
ajout_capteur(t);
gtk_widget_destroy(window_ajout_capteur_dhia);
windowcapteur=create_capteur();
gtk_widget_show(windowcapteur);
}


void
on_button_confirmer_supprission_capteur_dhia_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
*ref,*type,*output;
int x;
output=lookup_widget(objet_graphique,"label_output_message_supprission");
ref=lookup_widget(objet_graphique,"entry_ref_capteur_supprission");
ref=atoi(gtk_entry_get_text(GTK_ENTRY(ref)));
x=supprimer_capteur (ref);
if (x==0)
gtk_label_set_text(GTK_LABEL(output),"capteur supprimer avec succe");
else
gtk_label_set_text(GTK_LABEL(output),"capteur n est pas supprimer ou reference n existe pas");

}

