#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
int x_dhia;
int o_dhia;
int p_dhia;
int choix[]={0,0,0};
int x1,k,q;
int hg;
int xg;
int yg;
int zg;
int og;
int r;
int tm[6]={0,0,0,0,0,0};
menu m;
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


/*-------------------end gaston--------------------*/
/*******************RIMA**************************/

void
on_button15_suppr_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supprimer;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
gtk_widget_destroy(fenetre_afficher);

fenetre_supprimer=lookup_widget(objet_graphique,"supprimer_menu");
fenetre_supprimer= create_supprimer_menu ();
gtk_widget_show(fenetre_supprimer);
}


void
on_button_ajout_menu_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
gtk_widget_destroy(fenetre_afficher);

fenetre_ajout=lookup_widget(objet_graphique,"ajout_un_menu");
fenetre_ajout=create_ajout_un_menu ();
gtk_widget_show(fenetre_ajout);
}


void
on_button_meilleur_menu_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_meilleur;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
gtk_widget_destroy(fenetre_afficher);

fenetre_meilleur=lookup_widget(objet_graphique,"meilleur_menu");
fenetre_meilleur= create_meilleur_menu ();
gtk_widget_show(fenetre_meilleur);
}




void
on_button16_modifr_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
gtk_widget_destroy(fenetre_afficher);

fenetre_modifier=lookup_widget(objet_graphique,"modification_menu");
fenetre_modifier= create_modification_menu ();
gtk_widget_show(fenetre_modifier);
}


void
on_button_actualisermenu_clicked       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*fenetre_afficher1;
GtkWidget *treeview1;

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
gtk_widget_destroy (fenetre_afficher);

fenetre_afficher1= create_fenetre_affiche_menu();
gtk_widget_show(fenetre_afficher1);


treeview1=lookup_widget(fenetre_afficher1,"treeview1r");
afficher_menu(treeview1);
}


void
on_button_meilleur_plat_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_meilleur_plat;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
gtk_widget_destroy(fenetre_afficher);

fenetre_meilleur_plat=lookup_widget(objet_graphique,"meilleur_plat");
fenetre_meilleur_plat= create_meilleur_plat ();
gtk_widget_show(fenetre_meilleur_plat);
}


void
on_button19_retour_espace_admin_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button_authentification_nutritionnist_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_afficher,*window_login,*treeview;
GtkWidget *pseudo,*mdp,*output;
char util[40];
char pw[40];
int x;

pseudo= lookup_widget(objet_graphique,"entry_id");
mdp= lookup_widget(objet_graphique,"entry_mp");
strcpy(util, gtk_entry_get_text(GTK_ENTRY(pseudo)));
strcpy(pw, gtk_entry_get_text(GTK_ENTRY(mdp)));
x=verifr(util,pw);
if (x==1)
{
window_login=lookup_widget(objet_graphique,"authentification");
gtk_widget_destroy(window_login);
window_afficher=create_fenetre_affiche_menu ();
gtk_widget_show(window_afficher);
treeview=lookup_widget(window_afficher,"treeview1r");
afficher_menu(treeview);
}
else
{
output=lookup_widget(objet_graphique,"label111");
gtk_label_set_text(GTK_LABEL(output),"nutritionnist introuvable ! essayer de saisir à nouveau");
}
}


void
on_button4_confajout_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rjour;
GtkWidget *rmois;
GtkWidget *rannee;
GtkWidget *r_combobox;
GtkWidget *output ,*output1 ;
GtkWidget *numr,*contenu,*r_dechets;
menu m;
int y=-1;
char temps[50];
char nutri[50];
char text3[50];



numr=lookup_widget (objet_graphique,"entry3_nummenu");
m.num_menu=atoi(gtk_entry_get_text(GTK_ENTRY(numr)));



rjour=lookup_widget(objet_graphique,"spinbutton1_jr");
m.date_ajout.j1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rjour));
rmois=lookup_widget(objet_graphique,"spinbutton2_mr");
m.date_ajout.m1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rmois));
rannee=lookup_widget(objet_graphique,"spinbutton3_ar");
m.date_ajout.a1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(rannee));

r_combobox=lookup_widget(objet_graphique,"combobox1_jourr");

if(strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(r_combobox)))==0)
	{ strcpy(m.jour,"Lundi");}
else if(strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(r_combobox)))==0)
	{ strcpy(m.jour,"Mardi");}
else if(strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(r_combobox)))==0)
	{ strcpy(m.jour,"Mercredi");}
else if(strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(r_combobox)))==0)
	{ strcpy(m.jour,"Jeudi");}
else if(strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(r_combobox)))==0)
	{ strcpy(m.jour,"Vendredi");}
else if(strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(r_combobox)))==0)
	{ strcpy(m.jour,"Samedi");}
else if(strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(r_combobox)))==0)
	{ strcpy(m.jour,"Dimanche");}

/////////////radiobuton
fflush(stdin);
 if (r==1)
{strcpy(temps,"petitdejeuner");}
 else if (r==2)
{strcpy(temps,"dejeuner");}
 else if (r==3)
{strcpy(temps,"diner");}

strcpy(m.temps,temps);
//////////checkbox
fflush (stdin);
if (tm[0]==1)
{
fflush(stdin);
strcat(m.nut,"Lipides");
}
if (tm[1]==1)
strcat(m.nut,"Glucides");
if (tm[2]==1)
strcat(m.nut,"Proteines");
if (tm[3]==1)
strcat(m.nut,"Calcium");
if (tm[4]==1)
strcat(m.nut,"Fer");
if (tm[5]==1)
strcat(m.nut,"Vitamines");
fflush(stdin);
fflush(stdin);
//strcpy(m.nut,nutri);
sprintf(text3," votre %s est riche en %s \n",temps,m.nut);

contenu=lookup_widget (objet_graphique,"entry_entree");
strcpy(m.contenu,gtk_entry_get_text(GTK_ENTRY(contenu)));

r_dechets=lookup_widget (objet_graphique,"entry2_dechets");
m.dechets=atof(gtk_entry_get_text(GTK_ENTRY(r_dechets)));

output = lookup_widget(objet_graphique,"label106");
output1 = lookup_widget(objet_graphique,"label37");
gtk_label_set_text(GTK_LABEL(output1),text3);
y=rechr(m.num_menu);
if (y==1)
	gtk_label_set_text(GTK_LABEL(output),"menu existe deja");
else 
{
gtk_label_set_text(GTK_LABEL(output),"menu ajouté avec succé");
ajout_menu(m);
}
}




void
on_button8_affajout_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet_graphique,"ajout_un_menu");
gtk_widget_destroy(fenetre_ajout);

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
fenetre_afficher= create_fenetre_affiche_menu();
gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"treeview1r");
afficher_menu(treeview1);
}


void
on_button_annuler_ajout_menu_clicked   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;


fenetre_ajouter=lookup_widget(objet_graphique,"ajout_un_menu");
gtk_widget_destroy(fenetre_ajouter);

//fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
fenetre_afficher= create_fenetre_affiche_menu();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1r");
afficher_menu(treeview1);
}


void
on_button20_recherchermenu_clicked     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
menu m;
GtkWidget *numme, *jourr ,*moisr ,*anneer ,*jours ,*tempsr, *nutr ,*contenur,*dechetsr,*output9r;
int x=-1;
FILE *f;
int num_menu;
char jour[50];
char jr1[20];
char mr1[20];
char ar1[20];
char temps[50];
char nut[50];
char contenu[50];
char dech[50];
float dechets;
int numr1;

numme=lookup_widget (objet_graphique, "entry1_num");
jourr=lookup_widget (objet_graphique, "spinbutton_jours");
moisr=lookup_widget (objet_graphique, "spinbutton_mois");
anneer=lookup_widget (objet_graphique, "spinbutton_annee");
jours=lookup_widget (objet_graphique, "entry5_jsri");
tempsr=lookup_widget (objet_graphique, "entry6_tri");
nutr=lookup_widget (objet_graphique, "entry7_nutri");
contenur=lookup_widget (objet_graphique, "entry8_cri");
dechetsr=lookup_widget (objet_graphique, "entry9_dechetsri");
output9r = lookup_widget(objet_graphique,"label1_numri");

numr1=atoi(gtk_entry_get_text(GTK_ENTRY(numme)));
x=rechr(numr1);

f=fopen("menus.txt","r");
if(f!=NULL)
{
     while((fscanf(f,"%d %s %s %s %s %s %s %s %f \n",&num_menu,jour,jr1,mr1,ar1,temps,nut,contenu,&dechets)) != EOF)
	{if (numr1==num_menu)
           {x=1;
strcpy(m.jour,jour);
strcpy(m.temps,temps);
strcpy(m.nut,nut);
strcpy(m.contenu,contenu);
m.dechets=dechets;

}
}
fclose(f);
}
if (x==-1)
{
   
gtk_label_set_text(GTK_LABEL(output9r),"ce menu n'existe pas");
}
else 
{

//menu m=rechercher_menu(numr1);
gtk_label_set_text(GTK_LABEL(output9r),"succee");
gtk_entry_set_text(GTK_LABEL(jours),jour);
gtk_entry_set_text(GTK_LABEL(tempsr),temps);
gtk_entry_set_text(GTK_LABEL(nutr),nut);
gtk_entry_set_text(GTK_LABEL(contenur),contenu);
snprintf(dech,50,"%f",m.dechets);
gtk_entry_set_text(GTK_LABEL(dechetsr),dech);
}





}


void
on_button21_confirmer_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *numme, *jourr ,*moisr ,*anneer ,*jours ,*tempsr, *nutr ,*contenur,*dechetsr;
menu m;
int num;


numme=lookup_widget (objet_graphique, "entry1_num");
num=atoi(gtk_entry_get_text(GTK_ENTRY(numme)));
jours=lookup_widget (objet_graphique, "entry5_jsri");
tempsr=lookup_widget (objet_graphique, "entry6_tri");
nutr=lookup_widget (objet_graphique, "entry7_nutri");
contenur=lookup_widget (objet_graphique, "entry8_cri");
dechetsr=lookup_widget (objet_graphique, "entry9_dechetsri");
jourr=lookup_widget(objet_graphique,"spinbutton_jour");
moisr=lookup_widget(objet_graphique,"spinbutton_mois");
anneer=lookup_widget(objet_graphique,"spinbutton_annee");



numme=lookup_widget (objet_graphique, "entry1_num");
m.num_menu=atoi(gtk_entry_get_text(GTK_ENTRY(numme)));
strcpy(m.jour,gtk_entry_get_text(GTK_ENTRY(jours)));
strcpy(m.temps,gtk_entry_get_text(GTK_ENTRY(tempsr)));
strcpy(m.nut,gtk_entry_get_text(GTK_ENTRY(nutr)));
strcpy(m.contenu,gtk_entry_get_text(GTK_ENTRY(contenur)));
m.dechets=atof(gtk_entry_get_text(GTK_ENTRY(dechetsr)));
m.date_ajout.j1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourr));
m.date_ajout.m1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisr));
m.date_ajout.a1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneer));

modifier_menu (m,num);

//mise a jour treeview
/*
 GtkWidget* treeview1=lookup_widget(objet_graphique,"treeview1r");
afficher_menu(treeview1);*/
}


void
on_button_retourner_modif_menu_clicked (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;


fenetre_modifier=lookup_widget(objet_graphique,"modification_menu");
gtk_widget_destroy(fenetre_modifier);

//fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
fenetre_afficher= create_fenetre_affiche_menu();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1r");
afficher_menu(treeview1);

}


void
on_button2_annulersuppmenu_clicked     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supprimer;
GtkWidget *fenetre_afficher;
GtkWidget *treeview;


fenetre_supprimer=lookup_widget(objet_graphique,"supprimer_menu");
gtk_widget_destroy(fenetre_supprimer);

//fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
fenetre_afficher= create_fenetre_affiche_menu ();
gtk_widget_show(fenetre_afficher);

treeview=lookup_widget(fenetre_afficher,"treeview1r");
afficher_menu(treeview);
}


void
on_button1_suppmenu_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *num_r,*output;
int num;
int x;
output=lookup_widget(objet_graphique,"label2_suppmessage");
num_r=lookup_widget(objet_graphique,"entry_supp_menu");
num=atoi(gtk_entry_get_text(GTK_ENTRY(num_r)));
x=rechr(num);

if (x==1)
{
supp_menu (num);
gtk_label_set_text(GTK_LABEL(output),"menu supprimer avec succe");
}

else
gtk_label_set_text(GTK_LABEL(output),"menu n existe pas");
}


void
on_button_annuler_meilleur_menu_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_meilleur;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;


fenetre_meilleur=lookup_widget(objet_graphique,"meilleur_menu");
gtk_widget_destroy(fenetre_meilleur);

//fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
fenetre_afficher= create_fenetre_affiche_menu();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1r");
afficher_menu(treeview1);
}


void
on_button_trouver_meilleur_plat_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char meill11[10];
char meill13[10];
char meill21[10];
char meill23[10];
char meill31[10];
char meill33[10];
GtkWidget *fenetre_meilleur_plat;
GtkWidget *mm11,*mm13,*mm21,*mm23,*mm31,*mm33;

meilleur_plat(meill11,meill13,meill21,meill23,meill31,meill33);

fenetre_meilleur_plat=lookup_widget(objet_graphique,"meilleur_plat");

mm11=lookup_widget(fenetre_meilleur_plat,"label94");
gtk_label_set_text(GTK_LABEL(mm11),meill11);
//gtk_widget_show(mm11);

mm13=lookup_widget(fenetre_meilleur_plat,"label100");
gtk_label_set_text(GTK_LABEL(mm13),meill13);
//gtk_widget_show(mm13);

mm21=lookup_widget(fenetre_meilleur_plat,"label95");
gtk_label_set_text(GTK_LABEL(mm21),meill21);
//gtk_widget_show(mm21);

mm23=lookup_widget(fenetre_meilleur_plat,"label101");
gtk_label_set_text(GTK_LABEL(mm23),meill23);
//gtk_widget_show(mm23);

mm31=lookup_widget(fenetre_meilleur_plat,"label96");
gtk_label_set_text(GTK_LABEL(mm31),meill31);
//gtk_widget_show(mm31);

mm33=lookup_widget(fenetre_meilleur_plat,"label102");
gtk_label_set_text(GTK_LABEL(mm33),meill33);
//gtk_widget_show(mm33);
}


void
on_button_retourner_meilleur_plat_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_meilleur_plat;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;


fenetre_meilleur_plat=lookup_widget(objet_graphique,"meilleur_plat");
gtk_widget_destroy(fenetre_meilleur_plat);

//fenetre_afficher=lookup_widget(objet_graphique,"fenetre_affiche_menu");
fenetre_afficher= create_fenetre_affiche_menu();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1r");
afficher_menu(treeview1);
}


void
on_checkbutton6_calcium_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
   {tm[3]=1;}
}


void
on_checkbutton3_lipides_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
   {tm[0]=1;}
}


void
on_checkbutton4_glucides_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
   {tm[1]=1;}
}


void
on_checkbutton7_fer_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
   {tm[4]=1;}
}


void
on_checkbutton5_proteines_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
   {tm[2]=1;}
}


void
on_checkbutton8_vitamines_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
   {tm[5]=1;}
}


void
on_treeview1r_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

menu m;
GtkTreeIter iter;
gint *num_menu;
gchar *jourri;
gint *jr1;
gint *mr1;
gint *ar1;
gchar *temps;
gchar *nut;
gchar *contenu;
float dechets;


  
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
{

if (gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&num_menu,1,&jourri,2,&jr1,3,&mr1,4,&ar1,5,&temps,6,&nut,7,&contenu,8,&dechets,-1);
	m.num_menu=num_menu;
	strcpy(m.jour,jourri);
	m.date_ajout.j1=jr1;
	m.date_ajout.m1=mr1;
	m.date_ajout.a1=ar1;
	
	strcpy(m.contenu,contenu);
	strcpy(m.nut,nut);
	strcpy(m.temps,temps);
	m.dechets=dechets;

	supp_menu(num_menu);
	afficher_menu(treeview);

}

}
}


void
on_radiobutton1_ptdej_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
   {r=1;}
}


void
on_radiobutton2_dej_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
   {r=2;}
}


void
on_radiobutton3_diner_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
   {r=3;}

}


void
on_button_trouve_meilleur_menu_clicked (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *mm1,*mm2,*mm3,*mm4;
char text1[100];
char text2[100];
char text4[100];
char text3[100];
meilleur_menu(text1,text2,text3,text4);
mm1=lookup_widget (objet_graphique, "label71");
mm2=lookup_widget (objet_graphique, "label77");
mm3=lookup_widget (objet_graphique, "label114");
mm4=lookup_widget (objet_graphique, "label115");
gtk_label_set_text(GTK_LABEL(mm1),text1);
gtk_label_set_text(GTK_LABEL(mm2),text2);
gtk_label_set_text(GTK_LABEL(mm3),text3);
gtk_label_set_text(GTK_LABEL(mm4),text4);
}
/*------------------------------nouhe------------------------------*/



int x;
int y;



void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{y=2;}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{y=3;}
}


void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{y=4;}
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{y=5;}
}


void
on_checkbutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{y=6;}
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{y=1;}
}



void
on_journouha_changed                 (GtkEditable     *editable,
                                        gpointer         user_data)
{

}
void
on_moisnouha_changed                 (GtkEditable     *editable,
                                        gpointer         user_data)
{

}
void
on_anneenouha_changed                 (GtkEditable     *editable,
                                        gpointer         user_data)
{

}


void
on_button111_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb;

windowb=create_modification();
gtk_widget_show(windowb);

GtkWidget *windowa;

windowa=lookup_widget(objet_graphique,"identifiant");
gtk_widget_destroy(windowa);
}


void
on_button222_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb;

windowb=create_modification();
gtk_widget_show(windowb);

GtkWidget *windowa;

windowa=lookup_widget(objet_graphique,"nom");
gtk_widget_destroy(windowa);
}


void
on_button333_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb;

windowb=create_modification();
gtk_widget_show(windowb);

GtkWidget *windowa;

windowa=lookup_widget(objet_graphique,"marque");
gtk_widget_destroy(windowa);
}


void
on_button444_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb;

windowb=create_modification();
gtk_widget_show(windowb);

GtkWidget *windowa;

windowa=lookup_widget(objet_graphique,"categorie");
gtk_widget_destroy(windowa);
}


void
on_button555_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb;


windowb=create_modification();
gtk_widget_show(windowb);

GtkWidget *windowa;

windowa=lookup_widget(objet_graphique,"quantite");
gtk_widget_destroy(windowa);
}


void
on_button666_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb;


windowb=create_modification();
gtk_widget_show(windowb);

GtkWidget *windowa;

windowa=lookup_widget(objet_graphique,"datefab");
gtk_widget_destroy(windowa);
}



void
on_authnouhaa_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget* input1, *input2 ;
GtkWidget* output ;
GtkWidget *windowa;
GtkWidget *windowb;
char nom[100];
char mdp[100];
char hello[100];
input1 = lookup_widget(objet_graphique, "loginnouhaa") ;
input2 = lookup_widget(objet_graphique, "passwordnouhaa") ;
output = lookup_widget(objet_graphique, "nouhaa") ;
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(mdp,gtk_entry_get_text(GTK_ENTRY(input2)));

if ((strcmp(nom,"nouha")==0) && (strcmp(mdp,"123")==0))

{

windowa = lookup_widget(objet_graphique,"authnouha");
gtk_widget_destroy(windowa);

windowb = create_Bienvenue ();
gtk_widget_show(windowb);         
         		GtkWidget *treeview1;
		treeview1=lookup_widget(windowb,"treeview1n");
		afficher_tous(treeview1);}
else

  {gtk_label_set_text(GTK_LABEL(output),"données incorrecte");}              
            
}



void
on_button1111_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input, *identifiant;
int id,ident;

input= lookup_widget (objet_graphique, "entry1");
id=atoi(gtk_entry_get_text(GTK_ENTRY(input)));
identifiant= lookup_widget (objet_graphique, "entry11");
ident=atoi(gtk_entry_get_text(GTK_ENTRY(identifiant)));

GtkWidget* output ;
output = lookup_widget(objet_graphique, "out1") ;
int t;
    	t=veriff(id);
	if(t==1)
	{modifier_identifiant(id,ident);
	gtk_label_set_text(GTK_LABEL(output),"le produit a été modifier avec succès");}
	else
	{gtk_label_set_text(GTK_LABEL(output),"ce produit n'existe pas");}

}





void
on_button2222_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *input, *nom;
int id;
char n[20];
input= lookup_widget (objet_graphique, "entry2");
id=atoi(gtk_entry_get_text(GTK_ENTRY(input)));
nom= lookup_widget (objet_graphique, "entry22");
strcpy(n, gtk_entry_get_text(GTK_ENTRY(nom)));

GtkWidget* output ;
output = lookup_widget(objet_graphique, "out2") ;
int t;
    	t=veriff(id);
	if(t==1)
	{modifier_nom(id, n);
	gtk_label_set_text(GTK_LABEL(output),"le produit a été modifier avec succès");}
	else
	{gtk_label_set_text(GTK_LABEL(output),"ce produit n'existe pas");}

}


void
on_button3333_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input, *marque;
int id;
char marq[20];
input= lookup_widget (objet_graphique, "entry3");
id=atoi(gtk_entry_get_text(GTK_ENTRY(input)));
marque= lookup_widget (objet_graphique, "entry33");
strcpy(marq, gtk_entry_get_text(GTK_ENTRY(marque)));

GtkWidget* output ;
output = lookup_widget(objet_graphique, "out3") ;
int t;
    	t=veriff(id);
	if(t==1)
	{modifier_marque( id, marq);
	gtk_label_set_text(GTK_LABEL(output),"le produit a été modifier avec succès");}
	else
	{gtk_label_set_text(GTK_LABEL(output),"ce produit n'existe pas");}
}


void
on_button4444_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input, *categorie;
int id;
char cat[20];
input= lookup_widget (objet_graphique, "entry4");
id=atoi(gtk_entry_get_text(GTK_ENTRY(input)));
categorie= lookup_widget (objet_graphique, "entry44");
strcpy(cat, gtk_entry_get_text(GTK_ENTRY(categorie)));

GtkWidget* output ;
output = lookup_widget(objet_graphique, "out4") ;
int t;
    	t=veriff(id);
	if(t==1)
	{modifier_categorie( id, cat);
	gtk_label_set_text(GTK_LABEL(output),"le produit a été modifier avec succès");}
	else
	{gtk_label_set_text(GTK_LABEL(output),"ce produit n'existe pas");}
}


void
on_button5555_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input, *quantite;
int id,q;

input= lookup_widget (objet_graphique, "entry5");
id=atoi(gtk_entry_get_text(GTK_ENTRY(input)));
quantite= lookup_widget (objet_graphique, "entry55");
q=atoi(gtk_entry_get_text(GTK_ENTRY(quantite)));

GtkWidget* output ;
output = lookup_widget(objet_graphique, "out5") ;
int t;
    	t=veriff(id);
	if(t==1)
	{modifier_quantite(id,q);
	gtk_label_set_text(GTK_LABEL(output),"le produit a été modifier avec succès");}
	else
	{gtk_label_set_text(GTK_LABEL(output),"ce produit n'existe pas");}
}


void
on_button6666_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input, *jour, *mois, *annee;
int id,j,m,a;

input= lookup_widget (objet_graphique, "entry6");
id=atoi(gtk_entry_get_text(GTK_ENTRY(input)));
jour= lookup_widget (objet_graphique, "entry66j");
j=atoi(gtk_entry_get_text(GTK_ENTRY(jour)));
mois= lookup_widget (objet_graphique, "entry66m");
m=atoi(gtk_entry_get_text(GTK_ENTRY(mois)));
annee= lookup_widget (objet_graphique, "entry66a");
a=atoi(gtk_entry_get_text(GTK_ENTRY(annee)));

GtkWidget* output ;
output = lookup_widget(objet_graphique, "out6") ;
int t;
    	t=veriff(id);
	if(t==1)
	{modifier_date( id, j, m, a);
	gtk_label_set_text(GTK_LABEL(output),"le produit a été modifier avec succès");}
	else
	{gtk_label_set_text(GTK_LABEL(output),"ce produit n'existe pas");}
}




void
on_treeview1n_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* marque;
gchar* categorie;
uint* quantite;
uint* id;
uint* jour;
uint* mois;
uint* annee;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &id, 0, &nom, 1, &marque, 2, &categorie, 3, &jour, 4, &mois, 5, &annee, 6, &quantite, -1);
afficher_tous(treeview);
}
}


void
on_radiobutton1n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_radiobutton2n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_radiobutton3n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=3;}
}


void
on_radiobutton4n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=4;}
}


void
on_radiobutton6n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=6;}
}


void
on_bienvenue_n_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowaj;
GtkWidget *windowmod;
GtkWidget *windowsup;
GtkWidget *windowrech;
GtkWidget *windowaff0;
GtkWidget *treeview2;
 switch (x)
        {
        case 1:
            {
                windowaj=create_ajout();
		gtk_widget_show(windowaj);
                break;
			}

        case 2:
            {
		windowmod=create_modification();
		gtk_widget_show(windowmod);
                break;

            }
        case 3:
             {	windowsup=create_suppression();
		gtk_widget_show(windowsup);
                break;
             }
        case 4:
            {   
		windowrech=create_recherche();
		gtk_widget_show(windowrech);
                break;
            }
        
        case 6:
            {
                windowaff0=create_affichage0();
		gtk_widget_show(windowaff0);
		treeview2=lookup_widget(windowaff0,"treeview2n");
		afficher_les_produits_en_rupture(treeview2);
                break;
            }
        }

GtkWidget *windowa;

windowa=lookup_widget(button,"Bienvenue");
gtk_widget_destroy(windowa);

}


void
on_ajouter_n_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
produit p;
GtkWidget  *id, *nom, *marque, *quantite, *jour, *mois, *annee, *categorie;
int t;
    GtkWidget* output ;
    output = lookup_widget(objet_graphique, "ajouterounon") ;
jour=lookup_widget(objet_graphique,"journouha");
p.date_fab.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
mois=lookup_widget(objet_graphique,"moisnouha");
p.date_fab.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
annee=lookup_widget(objet_graphique,"anneenouha");
p.date_fab.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

categorie=lookup_widget(objet_graphique,"comboboxnouha");
strcpy(p.categorie, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categorie)));

nom= lookup_widget(objet_graphique,"entry_n");
marque= lookup_widget (objet_graphique, "entry_m");
quantite= lookup_widget (objet_graphique, "entry_q");
id= lookup_widget (objet_graphique, "entry_id1");
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.marque, gtk_entry_get_text(GTK_ENTRY(marque)));
p.id=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
p.quantite=atoi(gtk_entry_get_text(GTK_ENTRY(quantite)));
t=veriff(atoi(gtk_entry_get_text(GTK_ENTRY(id))));

	if(t==0)
	{ajouter(p);
	gtk_label_set_text(GTK_LABEL(output),"le produit a été ajouter avec succès");}
	else
	{gtk_label_set_text(GTK_LABEL(output),"ce produit existe déjà");}


}


void
on_retour_ajout_bienvenue_n_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowb;
windowb=create_Bienvenue();
gtk_widget_show(windowb);
         		GtkWidget *treeview1;
		treeview1=lookup_widget(windowb,"treeview1n");
		afficher_tous(treeview1);

GtkWidget *windowa;

windowa=lookup_widget(button,"ajout");
gtk_widget_destroy(windowa);
}


void
on_retour_modif_bienvenue_n_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowa;

windowa=lookup_widget(button,"modification");
gtk_widget_destroy(windowa);
GtkWidget *windowb;
windowb=create_Bienvenue();
gtk_widget_show(windowb);
         		GtkWidget *treeview1;
		treeview1=lookup_widget(windowb,"treeview1n");
		afficher_tous(treeview1);
}


void
on_modification_n_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowid;
GtkWidget *windownom;
GtkWidget *windowmarq;
GtkWidget *windowcat;
GtkWidget *windowq;
GtkWidget *windowdat;
GtkWidget *windowa;



 switch (y)
        {
        case 1:
            {
                windowid=create_identifiant();
		gtk_widget_show(windowid);

                break;
			}

        case 2:
            {
		windownom=create_nom();
		gtk_widget_show(windownom);
                break;

            }
        case 3:
             {	windowmarq=create_marque();
		gtk_widget_show(windowmarq);
                break;
             }
        case 4:
            {   
		windowcat=create_categorie();
		gtk_widget_show(windowcat);
                break;
            }
        case 5:
            {
                windowq=create_quantite();
		gtk_widget_show(windowq);
                break;
            }
        case 6:
            {
                windowdat=create_datefab();
		gtk_widget_show(windowdat);
                break;
            }
        }

windowa=lookup_widget(button,"modification");
gtk_widget_destroy(windowa);
}


void
on_supprimer_n_clicked                 (GtkWidget       *objet_graphique,
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
on_retour_supp_bienvenue_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowb;

windowb=create_Bienvenue();
gtk_widget_show(windowb);
         		GtkWidget *treeview1;
		treeview1=lookup_widget(windowb,"treeview1n");
		afficher_tous(treeview1);

GtkWidget *windowa;

windowa=lookup_widget(button,"suppression");
gtk_widget_destroy(windowa);
}


void
on_recherche_n_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
 produit p;
char ch[100];
char i[100];
char n[100];
char m[100];
char c[100];
char d[100];
char q[100];
    int t;
    int id;
    GtkWidget* input ;
    GtkWidget* output ;
    output = lookup_widget(objet_graphique, "sortie") ;
    input = lookup_widget(objet_graphique, "entryrech") ;
    id=atoi(gtk_entry_get_text(GTK_ENTRY(input)));
	t=veriff(id);
	if (t==1)
    	{p=chercher(id);
	sprintf(i,"%d",p.id);
	sprintf(q,"%d",p.quantite);
	sprintf(d,"%d/%d/%d",p.date_fab.jour,p.date_fab.mois,p.date_fab.annee);
	strcpy(n,p.nom);
	strcpy(m,p.marque);
	strcpy(c,p.categorie);
	strcpy(ch," ");
	strcat(ch,i);strcat(ch," ");strcat(ch,n);strcat(ch," ");strcat(ch,m);strcat(ch," ");strcat(ch,c);strcat(ch," ");strcat(ch,d);strcat(ch," ");strcat(ch,q);
	gtk_label_set_text(GTK_LABEL(output),ch);}
	else
	{gtk_label_set_text(GTK_LABEL(output),"ce produit n'existe pas");}
	
}


void
on_retour_rech_bienvenue_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowb;
GtkWidget *windowa;

windowa=lookup_widget(button,"recherche");
gtk_widget_destroy(windowa);
windowb=create_Bienvenue();
gtk_widget_show(windowb);
         		GtkWidget *treeview1;
		treeview1=lookup_widget(windowb,"treeview1n");
		afficher_tous(treeview1);
}


void
on_treeview2n_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* marque;
gchar* categorie;
uint* quantite;
uint* id;
uint* jour;
uint* mois;
uint* annee;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &id, 0, &nom, 1, &marque, 2, &categorie, 3, &jour, 4, &mois, 5, &annee, 6, &quantite, -1);
afficher_les_produits_en_rupture(treeview);
}
}


void
on_retour_affichage0_bienvenue_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowb;
windowb=create_Bienvenue();
gtk_widget_show(windowb);
         		GtkWidget *treeview1;
		treeview1=lookup_widget(windowb,"treeview1n");
		afficher_tous(treeview1);
GtkWidget *windowa;

windowa=lookup_widget(button,"affichage0");
gtk_widget_destroy(windowa);
}
/*------------------------------end nouha------------------------------*/







