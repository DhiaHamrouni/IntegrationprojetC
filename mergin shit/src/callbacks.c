#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
int x_dhia;
int y_nouha;
int o_dhia;
int p_dhia;
int choix[]={0,0,0};
//////////////////////////tron commun////////////////////////////////


void
on_button_retourto_accueil_from_capteur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*windowcapteur,*windowconnexion;
gtk_widget_destroy(windowcapteur);
windowconnexion=create_connexion();
gtk_widget_show(windowconnexion);
}
void
on_button_connexion_alterne_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login, *password , *windowcapteur,*w;
GtkWidget *output;
GtkWidget *treeview3;
char log[30];
char pw[20];
int trouve;
login=lookup_widget(button,"entry1_login_connexion");
password=lookup_widget(button,"entry_password_connexion");
strcpy(log,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(pw,gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif_dhia(log,pw);
if(trouve==1)
{
w=lookup_widget(button,"connexion");
gtk_widget_destroy(w);
windowcapteur=create_capteur();
gtk_widget_show(windowcapteur);
treeview3=lookup_widget(windowcapteur,"treeview3");
afficher_capteur(treeview3);
}
else
{
output=lookup_widget(button,"label72");
gtk_label_set_text(GTK_LABEL(output),"Incorrect Values");
}
}
///////////////////////////////////////////:nocta:////////////////////////////////////////
void
on_refresh_alarmes_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_alarmes_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}
void
on_fumer_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[0]=1 ;}
}


void
on_mouvement_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[1]=1 ;}
}


void
on_tout_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[2]=1 ;}
}

void
on_search_dhia_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget
*ref,*output;
capteur t;
int x;
ref=lookup_widget(objet_graphique,"entry_cherchdhia");
output=lookup_widget(objet_graphique,"label81");
t.ref=atoi(gtk_entry_get_text(GTK_ENTRY(ref)));
x=cherche_id(t.ref);
if (x==1)
{
gtk_label_set_text(GTK_LABEL(output),"capteur existe !");
}
else
{
gtk_label_set_text(GTK_LABEL(output),"capteur non existant");
}
}


void
on_tache2_dhia_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*w,*windowtype_alarme;
w=lookup_widget(button,"capteur");
gtk_widget_destroy(w);
windowtype_alarme=create_type_alarme();
gtk_widget_show(windowtype_alarme);
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}




void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_confirm_alarme_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
*output,*w,*windowAlarmes_dhia,*treeview4;
int s=0;
output=lookup_widget(objet_graphique,"label82");
for (int i=0;i<3;i++)
{
if (choix[i]==1)
s+=1;
}
if (s==1)
{
w=lookup_widget(objet_graphique,"capteur");
gtk_widget_destroy(w);
windowAlarmes_dhia=create_Alarmes_dhia();
gtk_widget_show(windowAlarmes_dhia);
if (choix[2]==1)
{
treeview4=lookup_widget(windowAlarmes_dhia,"treeview4");
afficher_capteur(treeview4);
}
else if(choix[0]==1)
{
treeview4=lookup_widget(windowAlarmes_dhia,"treeview4");
afficher_capteur_fume(treeview4);
}
else if(choix[1]==1)
{
treeview4=lookup_widget(windowAlarmes_dhia,"treeview4");
afficher_capteur_infra(treeview4);
}
}
else
{
gtk_label_set_text(GTK_LABEL(output),"choisissez un seul type de capteur \n s'il vous plait! \n hint: décocher tous les cases puis cocher une case \n et ressayer");
choix[0]=0;
choix[1]=0;
choix[2]=0;
}
}


void
on_button_ajout_capteur_dhia_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*w,*window_ajout_capteur_dhia;
w=lookup_widget(button,"capteur");
gtk_widget_destroy(w);
window_ajout_capteur_dhia=create_ajout_capteur_dhia();
gtk_widget_show(window_ajout_capteur_dhia);
}


void
on_button_supprimercapteur_dhia_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*w,*window_supprission_capteur_dhia;
w=lookup_widget(button,"capteur");
gtk_widget_destroy(w);
window_supprission_capteur_dhia=create_supprission_capteur_dhia();
gtk_widget_show(window_supprission_capteur_dhia);
}


void
on_button_modifiercapteur_dhia_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*w,*windowmodifier_capteur_noctis2;
w=lookup_widget(button,"capteur");
gtk_widget_destroy(w);
windowmodifier_capteur_noctis2=create_modifier_capteur_noctis2();
gtk_widget_show(windowmodifier_capteur_noctis2);
}


void
on_button_cherchercapteur_dhia_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*w,*windowchercher_dhia;
w=lookup_widget(button,"capteur");
gtk_widget_destroy(w);
windowchercher_dhia=lookup_widget(button,"chercher_dhia");
windowchercher_dhia=create_chercher_dhia();
gtk_widget_show(windowchercher_dhia);
}


void
on_button_affichiercapteur_dhia_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*windowcapteur,*windowaffichage_capteur_dhia;
GtkWidget *treeview1;
windowcapteur=lookup_widget(button,"windowcapteur");
gtk_widget_destroy(windowcapteur);
windowaffichage_capteur_dhia=lookup_widget(button,"windowaffichage_capteur_dhia");
windowaffichage_capteur_dhia=create_affichage_capteur_dhia();
gtk_widget_show(windowaffichage_capteur_dhia);


treeview1=lookup_widget(windowaffichage_capteur_dhia,"treeview1");

afficher_capteur(treeview1);
}



void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_actualiser_affichage_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowaffichage_capteur_dhia,*w1;
GtkWidget *treeview1;
w1=lookup_widget(button,"windowaffichage_capteur_dhia");
windowaffichage_capteur_dhia=create_affichage_capteur_dhia();
gtk_widget_show(windowaffichage_capteur_dhia);
gtk_widget_hide(w1);
treeview1=lookup_widget(windowaffichage_capteur_dhia,"treeview1");
afficher_capteur(treeview1);
}


void
on_retour_accueil_affichage_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*windowcapteur,*windowaffichage_capteur_dhia;
gtk_widget_destroy(windowaffichage_capteur_dhia);
windowcapteur=create_capteur();
gtk_widget_show(windowcapteur);
}


void
on_button_verifmodif_noctis_clicked    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
 *nomcapt,*ref,*marque,*j1,*m1,*a1,*type,*garantie,*ch;

capteur t;
int i,z;
char t1[50],t2[30],t3[50];
ref=lookup_widget(objet_graphique,"entry5");
nomcapt=lookup_widget(objet_graphique,"entry2");
marque=lookup_widget(objet_graphique,"entry3");
garantie=lookup_widget(objet_graphique,"entry4");
type=lookup_widget(objet_graphique,"entry6");
j1=lookup_widget(objet_graphique,"spinbutton1");
m1=lookup_widget(objet_graphique,"spinbutton3");
a1=lookup_widget(objet_graphique,"spinbutton4");
ch=lookup_widget(objet_graphique,"label65");
z=atoi(gtk_entry_get_text(GTK_ENTRY(ref)));
i=cherche_id(z);
if (i==1)
{
   	t=trouvage(x_dhia);
	gtk_label_set_text(GTK_LABEL(ch),"capteur trouver");
	sprintf(t1,"%d",t.ref);
	gtk_entry_set_text(GTK_ENTRY(ref),t1);
	gtk_entry_set_text(GTK_ENTRY(nomcapt),t.nomcapt);
	gtk_entry_set_text(GTK_ENTRY(marque),t.marque);
	sprintf(t2,"%d",t.gar);
	gtk_entry_set_text(GTK_ENTRY(garantie),t2);
	sprintf(t3,"%d",x_dhia);
	gtk_entry_set_text(GTK_ENTRY(type),t3);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(j1),t.date.j1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(m1),t.date.m1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(a1),t.date.a1);
	

	}
else {
gtk_label_set_text(GTK_LABEL(ch),"non trouve");}

}

void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
 *nomcapt,*ref,*marque,*j1,*m1,*a1,*type,*garantie,*ch;

capteur t;
int i,x;
char t1[50],t2[30],t3[50];
ref=lookup_widget(objet_graphique,"entry5");
nomcapt=lookup_widget(objet_graphique,"entry2");
marque=lookup_widget(objet_graphique,"entry3");
garantie=lookup_widget(objet_graphique,"entry4");
type=lookup_widget(objet_graphique,"entry6");
j1=lookup_widget(objet_graphique,"spinbutton1");
m1=lookup_widget(objet_graphique,"spinbutton3");
a1=lookup_widget(objet_graphique,"spinbutton4");
ch=lookup_widget(objet_graphique,"label65");
t.ref=atoi(gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(t.nomcapt,gtk_entry_get_text(GTK_ENTRY(nomcapt)));
strcpy(t.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
t.gar=atoi(gtk_entry_get_text(GTK_ENTRY(garantie)));
t.type=atoi(gtk_entry_get_text(GTK_ENTRY(type)));
if ((t.type!=1) && (t.type!=2) && (t.type!=3))
{
gtk_label_set_text(GTK_LABEL(ch),"veuiller saisir un de ces inputs 1, 2 ou 3 \n qui reference respectivement 'de temperature' \n 'de fumer' \n 'infrarouge'");
type=lookup_widget(objet_graphique,"entry6");
t.type=atoi(gtk_entry_get_text(GTK_ENTRY(type)));
}
else
{

t.date.j1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j1));
t.date.m1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m1));
t.date.a1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a1));
modifier_capteur(t.ref,t);
gtk_label_set_text(GTK_LABEL(ch),"success");}
}

void
on_radiobutton_temp_dhia_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x_dhia=1;
}


void
on_radiobutton_fum__e_dhia_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x_dhia=2;
}


void
on_radiobutton_infrarouge_dhia_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x_dhia=3;
}


void
on_button_ajoutcapt_interface_dhia_clicked
                                        (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
 *nomcapt,*ref,*marque,*j1,*m1,*a1,*type,*garantie,*output,*windowcapteur,*window_ajout_capteur_dhia,*treeview3;

int y;
capteur t;

j1=lookup_widget(objet_graphique,"spinbutton_j1_dhia");
t.date.j1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j1));

m1=lookup_widget(objet_graphique,"spinbutton2");
t.date.m1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m1));

a1=lookup_widget(objet_graphique,"spinbutton_a1_dhia");
t.date.a1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a1));

nomcapt=lookup_widget(objet_graphique,"entry_nomcapt_dhia");
ref=lookup_widget(objet_graphique,"entry_refcapt_dhia");
marque=lookup_widget(objet_graphique,"entry_marquecapt_dhia");
garantie=lookup_widget(objet_graphique,"entry_gar_dhia");
strcpy(t.nomcapt,gtk_entry_get_text(GTK_ENTRY(nomcapt)));
t.ref=atoi(gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(t.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
t.gar=atoi(gtk_entry_get_text(GTK_ENTRY(garantie)));
output=lookup_widget(objet_graphique,"result_ajout");
t.type=x_dhia;
y=cherche_id(t.ref);
if (y==1)
{
gtk_label_set_text(GTK_LABEL(output),"capteur existe deja,essayez une autre reference");
}
else
{
ajout_capteur(t);
gtk_label_set_text(GTK_LABEL(output),"capteur ajouter avec succes");
gtk_widget_destroy(window_ajout_capteur_dhia);
windowcapteur=create_capteur();
gtk_widget_show(windowcapteur);
treeview3=lookup_widget(windowcapteur,"treeview3");
afficher_capteur(treeview3);
}

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
if (x==1)
gtk_label_set_text(GTK_LABEL(output),"capteur supprimer avec succe");
else
gtk_label_set_text(GTK_LABEL(output),"capteur n est pas supprimer ou reference n existe pas");

}
void
on_retour_ajout_capt_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*windowcapteur,*windowajout_capteur_dhia;
gtk_widget_destroy(windowajout_capteur_dhia);
windowcapteur=create_capteur();
gtk_widget_show(windowcapteur);
}


void
on_retour_acc_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*windowcapteur,*windowmodifier_capteur_noctis2;
gtk_widget_destroy(windowmodifier_capteur_noctis2);
windowcapteur=create_capteur();
gtk_widget_show(windowcapteur);
}


/////////////////////////////////////:nocta://////////////////////////////////////////////
void
on_button_annuler_nouha_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowb;
windowb=create_Bienvenue_nouha();
gtk_widget_show(windowb);
}


void
on_button_valider_nouha_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
produit p;
GtkWidget *window_Bienvenue_nouha, *id, *nom, *marque, *quantite, *j1, *m1, *a1, *categorie;

j1=lookup_widget(objet_graphique,"journouha");
p.date_fab.j1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j1));
m1=lookup_widget(objet_graphique,"moisnouha");
p.date_fab.m1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m1));
a1=lookup_widget(objet_graphique,"anneenouha");
p.date_fab.a1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a1));

categorie=lookup_widget(objet_graphique,"comboboxnouha");
strcpy(p.categorie, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categorie)));

nom=lookup_widget(objet_graphique,"entry_n");
marque= lookup_widget (objet_graphique, "entry_m");
quantite= lookup_widget (objet_graphique, "entry_q");
id= lookup_widget (objet_graphique, "entry_id1");
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.marque, gtk_entry_get_text(GTK_ENTRY(marque)));
p.id=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
p.quantite=atoi(gtk_entry_get_text(GTK_ENTRY(quantite)));

ajouter(p);

window_Bienvenue_nouha=create_Bienvenue_nouha();
gtk_widget_show(window_Bienvenue_nouha);
}


void
on_button_Bienvenue_stock_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowaj;
GtkWidget *windowmod;
GtkWidget *windowsup;
GtkWidget *windowrech;
GtkWidget *windowaff;
GtkWidget *windowaff0;

 switch (y_nouha)
        {
        case 1:
            {
                windowaj=create_ajout_nouha();
		gtk_widget_show(windowaj);
                break;
		}

       	case 3:
             {	windowsup=create_supprimer_nouha();
		gtk_widget_show(windowsup);
                break;
             }
        }
}


void
on_button_retour_nouha_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowb;
windowb=create_Bienvenue_nouha();
gtk_widget_show(windowb);
}


void
on_button_supprimer_nouha_clicked      (GtkButton      *objet_graphique,
                                        gpointer         user_data)
{
    produit p;
    int id, t;
    GtkWidget* input ;
    GtkWidget* output ;
    output = lookup_widget(objet_graphique, "yesorno") ;
    input = lookup_widget(objet_graphique, "entrysuppnouha") ;
    id=atoi(gtk_entry_get_text(GTK_ENTRY(input)));
    	t=supprimer(id);
	if(t==1)
	{gtk_label_set_text(GTK_LABEL(output),"le produit a été bien supprimer");}
	else
	{gtk_label_set_text(GTK_LABEL(output),"ce produit n'existe pas");}

}


void
on_radiobutton_ajout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_nouha=1;}
}


void
on_radiobutton_modif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_nouha=2;}
}


void
on_radiobutton_supp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_nouha=3;}
}


void
on_radiobutton_cherch_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_nouha=4;}
}


void
on_radiobutton_affichier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_nouha=5;}
}


void
on_radiobutton_affichunique_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y_nouha=6;}
}

