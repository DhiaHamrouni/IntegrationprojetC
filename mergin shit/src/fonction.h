///////////////////////////////////Dhia//////////////////////////////////////////
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <gtk/gtk.h>

typedef struct
{
	int j1;
	int m1;
	int a1;
}date;


typedef struct //struct capteur
{
char nomcapt[50];
int ref;
char marque[50];
date date;
int type;
int gar;
}capteur;
typedef struct
{
    int  id;
    char nom[20];
    char marque[20];
    char categorie[20];
    date date_fab;
    int  quantite;
}produit;

void ajout_capteur(capteur c);
void affichage(capteur t);
int supprimer_capteur(int ref);
void modifier_capteur(int ref,capteur t);
int cherche_id(int num);
void afficher_capteur (GtkWidget * liste);
void vider (GtkWidget *liste);
capteur trouvage (int ref);
int verif_dhia (char log[] , char pw[]);

///////////////////////////////////////end Dhia////////////////////////////////////


/////////////////////////////////////////nouha/////////////////////////////////////

/*

void ajouter(produit p);
void modifier(int id);
int supprimer(int id);
produit chercher(int id);
void afficher_tous(produit p);
void afficher_les_produits_en_rupture(produit p);*/

/////////////////jesser///////////////

typedef struct Utilisateur
{
char cin[30];
char nom[20];
char prenom[20];
char fonction[50];
char niveau[20];
char daten[50]
 }utilisateur;

void ajouter_utilisateur(utilisateur u);
void afficher_utilisateur(GtkWidget *liste);
void supprimer_utilisateur(utilisateur u);
void modifier_utilisateur(utilisateur u,char cin[]);

int verif(char cin[],char mot[]);
void supprimer1(char cin[]);
int recherche(char cin[]);
int nombre_etudiant(char niv[]);
utilisateur chercher_utilisateur(char cin[]);

//////////////end jesser//////////

/*---------------------------gaston-------------------------------*/

typedef struct
{
int j;
int m;
int a;
}dateg;

typedef struct
{
int id;
char nom[30];
dateg d;
char etat[30];
char type[30];
char acces[30];
}etud;



void ajouterg(etud e);
void affichageg(GtkWidget *liste);
void supprim_etud(int id);
int rechercher(int id);
void modif_etud(etud e, int idg);
int verifg(char pseudo[], char mdp[]);
etud rechercher2(int id);
/*-------------------------------------end gaston-----------------------*/

