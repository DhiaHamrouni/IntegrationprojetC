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
int valmax;
int valmin;
int val;
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
void modifier_capteur(int ref,capteur t,capteur c);
int cherche_id(int num);
void afficher_capteur (GtkWidget * liste);
void vider (GtkWidget *liste);

///////////////////////////////////////end Dhia////////////////////////////////////


/////////////////////////////////////////nouha/////////////////////////////////////



void ajouter(produit p);
void modifier(int id);
int supprimer(int id);
produit chercher(int id);
void afficher_tous(produit p);
void afficher_les_produits_en_rupture(produit p);
