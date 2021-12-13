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
int x1,k,q;
int hg;
int xg;
int yg;
int zg;
int og;
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

/*------------------nouha----------------------*/
/*
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
{/*
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

/
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
*/
/*--------------------------end nouha----------------------*/


///////////:jesser///////////








void
on_button5_trouver_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_principale;
GtkWidget *fenetre_trouve;


fenetre_principale=lookup_widget(objet,"fenetre_principale");

gtk_widget_destroy(fenetre_principale);
fenetre_trouve=lookup_widget(objet,"fenetre_trouve");
fenetre_trouve=create_fenetre_trouve();

gtk_widget_show(fenetre_trouve);
}
void
on_button4_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_principale;
GtkWidget *fenetre_suppression;


fenetre_principale=lookup_widget(objet,"fenetre_principale");

gtk_widget_destroy(fenetre_principale);
fenetre_suppression=lookup_widget(objet,"fenetre_suppression");
fenetre_suppression=create_fenetre_suppression();

gtk_widget_show(fenetre_suppression);
}


void
on_button3_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_principale;
GtkWidget *fenetre_modification;


fenetre_principale=lookup_widget(objet,"fenetre_principale");

gtk_widget_destroy(fenetre_principale);
fenetre_modification=lookup_widget(objet,"fenetre_modification");
fenetre_modification=create_fenetre_modification();

gtk_widget_show(fenetre_modification);
}


void
on_button2_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_principale;
GtkWidget *fenetre_ajout;


fenetre_principale=lookup_widget(objet,"fenetre_principale");

gtk_widget_destroy(fenetre_principale);
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
fenetre_ajout=create_fenetre_ajout();

gtk_widget_show(fenetre_ajout);
}


void
on_radiobuttontechnicien_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=1;}
}


void
on_radiobuttonnutrionniste_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=2;}
}


void
on_radiobuttonagentfoyer_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=3;}
}


void
on_radiobuttonagentrestaurant_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=4;}
}


void
on_radiobuttonetudiant_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=5;}
}


void
on_button6_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
int a,i,b,c;
GtkWidget *combobox1;
GtkWidget *output;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;

char cin[50];

utilisateur u;
GtkWidget *input1 ,*input2 ,*input3;
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

input1=lookup_widget(objet,"entry3_cin");
input2=lookup_widget(objet,"entry4_nom");
input3=lookup_widget(objet,"entry5_prenom");

			strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
a=recherche(cin);
if (a==0)
{
if(strlen(cin)!=8)
{
output = lookup_widget(objet, "label22j");
gtk_label_set_text(GTK_LABEL(output),"numéro cin doit etre composé de 8 chiffres");
}
else
{
			strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(input1)));






			strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
			strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
			if(x1==1)
{
strcpy(u.fonction,"Technicien");
}
if(x1==2)
{
strcpy(u.fonction,"Nutrionniste");
}
if(x1==3)
{
strcpy(u.fonction,"Agent_de_foyer");
}
if(x1==4)
{
strcpy(u.fonction,"Agent_de_restaurant");
}
if(x1==5)
{
strcpy(u.fonction,"Etudiant");
}
			if(strcmp(u.fonction,"Etudiant")==0)
			{
			combobox1=lookup_widget(objet, "combobox1");
			strcpy(u.niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
			}
			else
			{
			strcpy(u.niveau,"---");
			}
jour=lookup_widget(objet, "jour");
mois=lookup_widget(objet, "mois");
annee=lookup_widget(objet, "annee");
i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
b=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
c=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
sprintf(u.daten,"%d/%d/%d",i,b,c);
			
			
			ajouter_utilisateur(u);
			output = lookup_widget(objet, "label22j");
			gtk_label_set_text(GTK_LABEL(output),"ajout succée");
}
}
else
{
output = lookup_widget(objet, "label22j");
gtk_label_set_text(GTK_LABEL(output),"ce cin existe déja");
}

}


void
on_button7_retourner_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_principale;
GtkWidget *treeview1j;


fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_principale=lookup_widget(objet,"fenetre_principale");
fenetre_principale=create_fenetre_principale();

gtk_widget_show(fenetre_principale);
treeview1j=lookup_widget(fenetre_principale,"treeview1j");
afficher_utilisateur(treeview1j);
}


void
on_button8_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output,*input;
char cin[30];
int y;
utilisateur u;
GtkWidget *input1;
GtkWidget *fenetre_suppression;
input=lookup_widget(objet,"entry6_cin");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
y=recherche(cin);
if(y!=0)
{
supprimer1(cin);
output = lookup_widget(objet, "label26j");
gtk_label_set_text(GTK_LABEL(output),"suppression effectué avec succee");
}
else
{
output = lookup_widget(objet, "label26j");
gtk_label_set_text(GTK_LABEL(output),"ce cin n'existe pas");
}
}


void
on_button9_retourner_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_suppression;
GtkWidget *fenetre_principale;
GtkWidget *treeview1j;


fenetre_suppression=lookup_widget(objet,"fenetre_suppression");

gtk_widget_destroy(fenetre_suppression);
fenetre_principale=lookup_widget(objet,"fenetre_principale");
fenetre_principale=create_fenetre_principale();

gtk_widget_show(fenetre_principale);
treeview1j=lookup_widget(fenetre_principale,"treeview1j");
afficher_utilisateur(treeview1j);
}


void
on_button_nombre_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_principale;
GtkWidget *fenetre_nombre;
GtkWidget *treeview1j;


fenetre_principale=lookup_widget(objet,"fenetre_principale");

gtk_widget_destroy(fenetre_principale);
fenetre_nombre=lookup_widget(objet,"fenetre_nombre");
fenetre_nombre=create_fenetre_nombre();

gtk_widget_show(fenetre_nombre);
treeview1j=lookup_widget(fenetre_nombre,"treeview1j");
afficher_utilisateur(treeview1j);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{k=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{k=2;}
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{k=3;}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{k=4;}
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{k=5;}
}


void
on_button2_retourner_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_nombre;
GtkWidget *fenetre_principale;
GtkWidget *treeview1j;


fenetre_nombre=lookup_widget(objet,"fenetre_nombre");

gtk_widget_destroy(fenetre_nombre);
fenetre_principale=lookup_widget(objet,"fenetre_principale");
fenetre_principale=create_fenetre_principale();

gtk_widget_show(fenetre_principale);
treeview1j=lookup_widget(fenetre_principale,"treeview1j");
afficher_utilisateur(treeview1j);
}


void
on_button1_calculer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{ char niv[20],o1[10];
int o;
GtkWidget *output;
if(k==1)
{
strcpy(niv,"1ére");
}
if(k==2)
{
strcpy(niv,"2éme");
}
if(k==3)
{
strcpy(niv,"3éme");
}
if(k==4)
{
strcpy(niv,"4éme");
}
if(k==5)
{
strcpy(niv,"5éme");
}


o=nombre_etudiant(niv);
sprintf(o1,"%d",o);
output = lookup_widget(objet, "label30j");
gtk_label_set_text(GTK_LABEL(output),o1);
}


void
on_radiobutton6tech_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{q=1;}
}


void
on_radiobutton7nut_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{q=2;}
}


void
on_radiobutton8foyer_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{q=3;}
}


void
on_radiobutton9resto_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{q=4;}
}


void
on_radiobutton10etud_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{q=5;}
}


void
on_button1modifierm_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)

{
int j,i,b,c;
GtkWidget *combobox2;
GtkWidget *output;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;

char cin[50];

utilisateur u;
GtkWidget *input1 ,*input2 ,*input3;
GtkWidget *fenetre_modification;

fenetre_modification=lookup_widget(objet,"fenetre_modification");

input1=lookup_widget(objet,"entry1_cinm");
input2=lookup_widget(objet,"entry2_nomm");
input3=lookup_widget(objet,"entry3_prenomm");

			strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
j=recherche(cin);
if (j==1)
{
			strcpy(u.cin,cin);
			strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
			strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
if(q==1)
{
strcpy(u.fonction,"Technicien");
}
if(q==2)
{
strcpy(u.fonction,"Nutrionniste");
}
if(q==3)
{
strcpy(u.fonction,"Agent_de_foyer");
}
if(q==4)
{
strcpy(u.fonction,"Agent_de_restaurant");
}
if(q==5)
{
strcpy(u.fonction,"Etudiant");
}
			if(strcmp(u.fonction,"Etudiant")==0)
			{
			combobox2=lookup_widget(objet, "combobox2");
			strcpy(u.niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
			}
			else
			{
			strcpy(u.niveau,"---");
			}
jour=lookup_widget(objet, "spinbutton1jourm");
mois=lookup_widget(objet, "spinbutton2moism");
annee=lookup_widget(objet, "spinbutton3anneem");
i=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
b=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
c=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
sprintf(u.daten,"%d/%d/%d",i,b,c);
			
supprimer1(cin);
ajouter_utilisateur(u);			


			output = lookup_widget(objet, "label44j");
			gtk_label_set_text(GTK_LABEL(output),"modification succée");
}
else
{
output = lookup_widget(objet, "label44j");
gtk_label_set_text(GTK_LABEL(output),"ce cin n'existe pas");
}

}




void
on_button2retournerm_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modification;
GtkWidget *fenetre_principale;
GtkWidget *treeview1j;


fenetre_modification=lookup_widget(objet,"fenetre_modification");

gtk_widget_destroy(fenetre_modification);
fenetre_principale=lookup_widget(objet,"fenetre_principale");
fenetre_principale=create_fenetre_principale();

gtk_widget_show(fenetre_principale);
treeview1j=lookup_widget(fenetre_principale,"treeview1j");
afficher_utilisateur(treeview1j);
}

void
on_button1_recherche_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
int a;

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;

char cin[50];


utilisateur u;
GtkWidget *input1;
GtkWidget *fenetre_trouve;

fenetre_trouve=lookup_widget(objet,"fenetre_trouve");

input1=lookup_widget(objet,"entry1_cinr");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));

a=recherche(cin);
if (a==1)
{
output6 = lookup_widget(objet, "label53j");
gtk_label_set_text(GTK_LABEL(output6),"cin trouvé ");
u=chercher_utilisateur(cin);

output1 = lookup_widget(objet, "label54j");
gtk_label_set_text(GTK_LABEL(output1),u.nom);

output2 = lookup_widget(objet, "label55j");
gtk_label_set_text(GTK_LABEL(output2),u.prenom);

output3 = lookup_widget(objet, "label56j");
gtk_label_set_text(GTK_LABEL(output3),u.fonction);

output4 = lookup_widget(objet, "label57j");
gtk_label_set_text(GTK_LABEL(output4),u.niveau);

output5 = lookup_widget(objet, "label58j");
gtk_label_set_text(GTK_LABEL(output5),u.daten);
}
else
{
output6 = lookup_widget(objet, "label53j");
gtk_label_set_text(GTK_LABEL(output6),"ce cin n'existe pas");
}

}


void
on_button2_retournerrecher_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_trouve;
GtkWidget *fenetre_principale;
GtkWidget *treeview1j;


fenetre_trouve=lookup_widget(objet,"fenetre_trouve");

gtk_widget_destroy(fenetre_trouve);
fenetre_principale=lookup_widget(objet,"fenetre_principale");
fenetre_principale=create_fenetre_principale();

gtk_widget_show(fenetre_principale);
treeview1j=lookup_widget(fenetre_principale,"treeview1j");
afficher_utilisateur(treeview1j);
}




void
on_checkbutton1_afich_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
int a;

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;


char cin[50];


utilisateur u;
GtkWidget *input1;
GtkWidget *fenetre_modification;

fenetre_modification=lookup_widget(togglebutton,"fenetre_modification");

input1=lookup_widget(togglebutton,"entry1_cinm");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));

a=recherche(cin);
if (a==1)
{

u=chercher_utilisateur(cin);

output1 = lookup_widget(togglebutton, "label59j");
gtk_label_set_text(GTK_LABEL(output1),u.nom);

output2 = lookup_widget(togglebutton, "label60j");
gtk_label_set_text(GTK_LABEL(output2),u.prenom);

output3 = lookup_widget(togglebutton, "label61j");
gtk_label_set_text(GTK_LABEL(output3),u.fonction);

output4 = lookup_widget(togglebutton, "label62j");
gtk_label_set_text(GTK_LABEL(output4),u.niveau);

output5 = lookup_widget(togglebutton, "label63j");
gtk_label_set_text(GTK_LABEL(output5),u.daten);
}


}
}





void
on_treeview1j_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* date;
gchar* fonction;
gchar* cin;
gchar* niveau;
utilisateur u ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter ,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model) , &iter, 0,&cin,1,&nom,2,&prenom,3,&date,4,&fonction,5,&niveau, -1);
strcpy(u.cin,cin);
strcpy(u.nom,nom);
strcpy(u.prenom,prenom);
strcpy(u.fonction,fonction);
strcpy(u.niveau,niveau);
strcpy(u.daten,date);
supprimer_utilisateur(u);
afficher_utilisateur(treeview);
}


}

void
on_button1_sidentifier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username, *password, *windowEspaceAdmin,*w ;
GtkWidget* output;
GtkWidget *treeview1j;
char user[20];
char pasw[20];
int trouve;
username = lookup_widget (button, "entry1_cin");
password = lookup_widget (button, "entry2_motdepasse");

strcpy(user , gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw , gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(user,pasw);

if(trouve==1)
{
w=lookup_widget(button,"fenetre_authentification");
gtk_widget_destroy(w);
windowEspaceAdmin=create_fenetre_principale();
 gtk_widget_show (windowEspaceAdmin);
treeview1j=lookup_widget(windowEspaceAdmin,"treeview1j");
afficher_utilisateur(treeview1j);
}
else
{
output = lookup_widget(button, "label5j");
gtk_label_set_text(GTK_LABEL(output),"données incorrectes");
}
}
//////////end jesser////////


/*--------------gaston------------------*/





/*-------- bouton interface principale--------------*/

void
on_button_agent_actu_gas_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_agent,*treeview;

window_agent=lookup_widget(objet_graphique,"window_agent_gas");
gtk_widget_destroy(window_agent);

window_agent=create_window_agent_gas();
gtk_widget_show(window_agent);

treeview=lookup_widget(window_agent,"treeview2_gas");
affichageg(treeview);
}
/////////////////////////////////////////////////////////////
void
on_button1_agent_ajout_gas_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter,*window_agent;

window_agent=lookup_widget(objet_graphique,"window_agent_gas");
gtk_widget_destroy(window_agent);

window_ajouter=create_window_ajouter_gas();
gtk_widget_show(window_ajouter);
}

/////////////////////////////////////////////////////////////

void
on_button3_agent_supprimer_gas_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_agent,*window_supprimer;

window_agent=lookup_widget(objet_graphique,"window_agent_gas");
gtk_widget_destroy(window_agent);

window_supprimer=create_window_supprimer_gas();
gtk_widget_show(window_supprimer);
}

/////////////////////////////////////////////////////////////

void
on_button_afficher_gas_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *window_afficher,*window_agent,*treeview;

window_agent=lookup_widget(objet_graphique,"window_agent_gas");
gtk_widget_destroy(window_agent);

window_afficher=create_window_afficher_gas();
gtk_widget_show(window_afficher);


treeview=lookup_widget(window_afficher,"treeview1_gas");
affichageg(treeview);
}

////////////////////////////////////////////////////////////

void
on_button_agent_modifier_gas_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_modifier,*window_agent;

window_agent=lookup_widget(objet_graphique,"window_agent_gas");
gtk_widget_destroy(window_agent);

window_modifier=create_window_modifier_gas();
gtk_widget_show(window_modifier);
}
///////////////////////////////////////////////////////////
void
on_button_agent_rechercher_gas_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_rechercher,*window_agent;

window_agent=lookup_widget(objet_graphique,"window_agent_gas");
gtk_widget_destroy(window_agent);

window_rechercher=create_window_rechercher_gas();
gtk_widget_show(window_rechercher);
}

/*-------------bouton confirmer---------------*/
void
on_button_supprimer_confirmer_gas_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input,*output;
int id,a;

input=lookup_widget(objet_graphique,"entry_id_supprimer_gas");
id =atoi(gtk_entry_get_text(GTK_ENTRY(input)));

output=lookup_widget(objet_graphique,"label9_gas");
a=rechercher(id);
if (a==1)
	{gtk_label_set_text(GTK_LABEL(output),"Suppression effectué avec succés");
	supprim_etud(id);}
else  if (a==0)
	{gtk_label_set_text(GTK_LABEL(output),"ID inéxistant");}
	


}

///////////////////////////////////////////////////////////////////////////
void
on_button_rechercher_confirmer_gas_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *output,*input;
int a,k;
char id[100];
input=lookup_widget(objet_graphique,"entry_rechercher_gas");
strcpy(id, gtk_entry_get_text(GTK_ENTRY(input)));
k=atoi(id);
output=lookup_widget(objet_graphique,"label_rechercherx_gas");
a=rechercher(k);
if (a==1)
	{gtk_label_set_text(GTK_LABEL(output),"Etudiant existant");}
else  if (a==0)
	gtk_label_set_text(GTK_LABEL(output),"Etudiant inéxistant");

}

//////////////////////////////////////////////////////////////////////////
void
on_button_modif_confirmer_gas_clicked  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output;
etud e;
int idg;
GtkWidget *window, *id, *nom, *jour, *mois, *annee, *etat, *type, *acces;

id=lookup_widget(objet_graphique,"entry_modif_id_gas");
e.id=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
idg=e.id;

nom=lookup_widget(objet_graphique,"entry_modif_nom_gas");
strcpy(e.nom, gtk_entry_get_text(GTK_ENTRY(nom)));

jour=lookup_widget(objet_graphique,"spinbutton_modif_jour_gas");
e.d.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois=lookup_widget(objet_graphique,"spinbutton_modif_mois_gas");
e.d.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee=lookup_widget(objet_graphique,"spinbutton_modif_annee_gas");
e.d.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

type=lookup_widget(objet_graphique,"comboboxentry_typechambre_gas");
strcpy(e.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

if (yg==1)
	{strcpy(e.etat,"paye");}
if (yg==2)
	{strcpy(e.etat,"non_paye");}
if (zg==1)
	{strcpy(e.acces,"Avec");}
if (zg==2)
	{strcpy(e.acces,"Sans");}


modif_etud(e,idg);
output=lookup_widget(objet_graphique,"label54_modif_gas");
gtk_label_set_text(GTK_LABEL(output),"Modification effectué avec succés");

}
//////////////////////////////////////////////////////////////////////////
void
on_button_confirmer_ajout_gas_clicked  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output,*input;
int a=0;
int idg;
etud e;

GtkWidget *window, *id, *nom, *jour, *mois, *annee, *etat, *type, *acces;

id= lookup_widget (objet_graphique, "entry_id_ajout_gas");
e.id=atoi(gtk_entry_get_text(GTK_ENTRY(id)));


nom=lookup_widget(objet_graphique,"entry_nom_ajout_gas");
strcpy(e.nom, gtk_entry_get_text(GTK_ENTRY(nom)));

jour=lookup_widget(objet_graphique,"spinbutton1_ajout_date_jour_gas");
e.d.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois=lookup_widget(objet_graphique,"spinbutton2_ajout_date_mois_gas");
e.d.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee=lookup_widget(objet_graphique,"spinbutton2_ajout_date_annee_gas");
e.d.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

type=lookup_widget(objet_graphique,"comboboxentry_ajout_typechambre_gas");
strcpy(e.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));

if (xg==1)
	{strcpy(e.etat,"paye");}
if (xg==2)
	{strcpy(e.etat,"non_paye");}
if (hg==1)
	{strcpy(e.acces,"Avec");}
if (hg==2)
	{strcpy(e.acces,"Sans");}

input=lookup_widget(objet_graphique,"entry_id_ajout_gas");
idg=atoi(gtk_entry_get_text(GTK_ENTRY(input)));

output=lookup_widget(objet_graphique,"label55_succes_gas");
a=rechercher(idg);
if (a==1)
	{gtk_label_set_text(GTK_LABEL(output),"Etudiant existant, veuillez saisir à nouveau");}
else  
{ajouterg(e);
gtk_label_set_text(GTK_LABEL(output),"Ajout effectué avec succés");}
}

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void
on_button_id_a_modif_gas_clicked       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
int b,x;
GtkWidget *input,*output;

input=lookup_widget(objet_graphique,"entry_modif_id_gas");
output=lookup_widget(objet_graphique,"label50_gas");
x=atoi(gtk_entry_get_text(GTK_ENTRY(input)));
b= rechercher(x);
if (b==1)
{
gtk_label_set_text(GTK_LABEL(output),"id existant ");
}
else 
{
gtk_label_set_text(GTK_LABEL(output),"id introuvable");
}
}

/////////////////////////////////////////////////////////////////////////////

/*------------------bouton retourner----------------------*/
void
on_button_retourner_ajout_gas_clicked  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter,*window_agent,*treeview;

window_ajouter=lookup_widget(objet_graphique,"window_ajouter_gas");
gtk_widget_destroy(window_ajouter);

window_agent=create_window_agent_gas();
gtk_widget_show(window_agent);

treeview=lookup_widget(window_agent,"treeview2_gas");
affichageg(treeview);

}
///////////////////////////////////////////////////////////////////////////
void
on_button_retourner_supprimer_gas_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_supprimer,*window_agent,*treeview;

window_supprimer=lookup_widget(objet_graphique,"window_supprimer_gas");
gtk_widget_destroy(window_supprimer);

window_agent=create_window_agent_gas();
gtk_widget_show(window_agent);

treeview=lookup_widget(window_agent,"treeview2_gas");
affichageg(treeview);
}
////////////////////////////////////////////////////////////////////////////
void
on_button_retourner_afficher_gas_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_afficher,*window_agent,*treeview;

window_afficher=lookup_widget(objet_graphique,"window_afficher_gas");
gtk_widget_destroy(window_afficher);

window_agent=create_window_agent_gas();
gtk_widget_show(window_agent);

treeview=lookup_widget(window_agent,"treeview2_gas");
affichageg(treeview);
}

////////////////////////////////////////////////////////////////////////////
void
on_button_modif_retourner_gas_clicked  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_modifier,*window_agent,*treeview;

window_modifier=lookup_widget(objet_graphique,"window_modifier_gas");
gtk_widget_destroy(window_modifier);

window_agent=create_window_agent_gas();
gtk_widget_show(window_agent);

treeview=lookup_widget(window_agent,"treeview2_gas");
affichageg(treeview);
}

////////////////////////////////////////////////////////////////////////////
void
on_button_rech_retourner_gas_clicked   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_rechercher,*window_agent,*treeview;

window_rechercher=lookup_widget(objet_graphique,"window_rechercher_gas");
gtk_widget_destroy(window_rechercher);

window_agent=create_window_agent_gas();
gtk_widget_show(window_agent);

treeview=lookup_widget(window_agent,"treeview2_gas");
affichageg(treeview);
}
////////////////////////////////////////////////////////////////////////////

/*-----------------treeview------------------------*/
void
on_treeview1_gas_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
int id;
gchar* nom;
int jour;
int mois;
int annee;
gchar* etat;
gchar* type;
gchar* acces;

etud e;
GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter, path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter, 0, &id, 1, &nom, 2, &jour,3, &mois , 4, &annee , 5, &etat, 6, &type, 7, &acces,-1);
strcpy(e.nom,nom);
strcpy(e.etat,etat);
strcpy(e.type,type);
strcpy(e.acces,acces);
e.d.j=jour;
e.d.m=mois;
e.d.a=annee;
e.id=id;

affichageg(treeview);
}
}
////////////////////////////////////////////////////////////////////////////

void
on_treeview2_gas_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
int id;
gchar* nom;
int jour;
int mois;
int annee;
gchar* etat;
gchar* type;
gchar* acces;

etud e;
GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter, path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter, 0, &id, 1, &nom, 2, &jour,3, &mois , 4, &annee , 5, &etat, 6, &type, 7, &acces,-1);
strcpy(e.nom,nom);
strcpy(e.etat,etat);
strcpy(e.type,type);
strcpy(e.acces,acces);
e.d.j=jour;
e.d.m=mois;
e.d.a=annee;
e.id=id;

affichageg(treeview);
}
}


/*-----------------radio button------------------------*/
/*--------------------radio ajout-----------------------*/
void
on_radiobutton_ajout_nonpaye_gas_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if  (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{xg=2;}
}
///////////////////////////////////////////////////////////////////////////////////

void
on_radiobutton_ajout_paye_gas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if  (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{xg=1;}
}

//////////////////////////////////////////////////////////////////////////////////
void
on_gb_radiobutton1_gas_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if  (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{hg=1;}
}
/////////////////////////////////////////////////////////////////////////////////
void
on_gb_radiobutton2_gas_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if  (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{hg=2;}
}
////////////////////////////////////////////////////////////////////////////////
/*--------------------radio modif-----------------------*/
void
on_radiobutton_modif_paye_gas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if  (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{yg=1;}
}

/////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton_modif_nonpaye_gas_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if  (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{yg=2;}
}
/////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton_modif_avec_gas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if  (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{zg=1;}
}
/////////////////////////////////////////////////////////////////////////////////

void
on_radiobutton_modif_sans_gas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if  (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{zg=2;}
}




void
on_button_rech_affich_gas_clicked      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input,*output;
etud e;
int id;
char idd[30];
char nom[30];
char d[30];
char etat[30];
char type[30];
char acces[30];
char ch[100];



output=lookup_widget(objet_graphique,"gas");
input=lookup_widget(objet_graphique,"entry_rechercher_gas");
id= atoi(gtk_entry_get_text(GTK_ENTRY(input)));

if (og==1)
{
e=rechercher2(id);
sprintf(idd,"%d",e.id);
sprintf(d,"%d/%d/%d",e.d.j,e.d.m,e.d.a);
strcpy(nom,e.nom);
strcpy(etat,e.etat);
strcpy(type,e.type);
strcpy(acces,e.acces);
strcpy(ch," ");strcat(ch,"ID: ");strcat(ch,idd);strcat(ch,", Nom: ");strcat(ch,nom);strcat(ch,", Date: ");
strcat(ch,d);strcat(ch,", Etat: ");strcat(ch,etat);
strcat(ch,", Type :  ");strcat(ch,type);strcat(ch,", Acces : ");
strcat(ch,acces);

gtk_label_set_text(GTK_LABEL(output),ch);
og=0;
}
else 
gtk_label_set_text(GTK_LABEL(output),"Cocher pour recevoir les données ");
}





/*-------------checkbutton--------------*/


void
on_check_rech_gas_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if  (gtk_toggle_button_get_active(togglebutton))
	{og=1;}
}


/*-------------------end gaston--------------------*/




void
on_button_login_ghassen_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_agent,*window_login,*treeview;
GtkWidget *pseudo,*mdp,*output;
char util[40];
char pw[40];
int x;

pseudo= lookup_widget(objet_graphique,"entry_login_pseudo_gas");
mdp= lookup_widget(objet_graphique,"entry_login_mdp_gas");
strcpy(util, gtk_entry_get_text(GTK_ENTRY(pseudo)));
strcpy(pw, gtk_entry_get_text(GTK_ENTRY(mdp)));
x=verifg(util,pw);
if (x==1)
{
window_login=lookup_widget(objet_graphique,"window_login_gas");
gtk_widget_destroy(window_login);
window_agent=create_window_agent_gas();
gtk_widget_show(window_agent);
treeview=lookup_widget(window_agent,"treeview2_gas");
affichageg(treeview);
}
else
{
output=lookup_widget(objet_graphique,"label_connexion");
gtk_label_set_text(GTK_LABEL(output),"Pseudo introuvable ! essayer de saisir à nouveau");
}
}



