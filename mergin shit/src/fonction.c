///////////////////////////////////////////Dhia.C////////////////////////////////////////
#ifdef HAVE_CONFIG_H
#include "fonction.h"
#include <malloc.h>
#include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

enum
{
ENOM_CAPTEUR,
EREFERENCE,
EMARQUE,
EJOUR,
EMOIS,
EANNEE,
ETYPE,
EGARANTIE,
EVALEUR_MAX,
EVALEUR_MIN,
COLUMNS
};

//////////////////////////////chercher/////////////////////////////////////////
int cherche_id(int num)
{
    FILE *F;
    capteur c ;
    F=fopen("capteur.txt","r");
    do
    {
        fscanf(F,"%s %d %s %d %d %d %d %d %d %d \n",c.nomcapt,&c.ref,c.marque,&c.date.j1,&c.date.m1,&c.date.a1,&c.type,&c.gar,&c.valmax,&c.valmin);
        //fflush(stdin);
        if(c.ref==num)
        {
		printf("capteur trouve \n");
            fclose(F);
            return 1 ;
        }
    }while(!feof(F));
    fclose(F);
    return -1 ;
}
////////////////////////ajout///////////////////////////////////////
void ajout_capteur(capteur c)
{
FILE *f;
f=fopen("capteur.txt","a+");
		if(f!=NULL)
		{
			fprintf(f,"%s %d %s %d %d %d %d %d %d %d \n",c.nomcapt,c.ref,c.marque,c.date.j1,c.date.m1,c.date.a1,c.type,c.gar,c.valmax,c.valmin);
			fclose(f);
		}
}	

/////////////////////////////////////// supprimer  ///////////////////////////////////////////////////////////
int supprimer_capteur (int num)
{
FILE *f ;
FILE *g;
capteur c;
int x=0;
    f=fopen("capteur.txt","r");
    g=fopen("ancien_capteur","w+");
 if(f!=NULL)
    {
	while(fscanf(f,"%s %d %s %d %d %d %d %d %d %d \n",c.nomcapt,&c.ref,c.marque,&c.date.j1,&c.date.m1,&c.date.a1,&c.type,&c.gar,&c.valmax,&c.valmin)!=EOF)
	{ 
 	 if(c.ref!=num)
{
	  fprintf(g,"%s %d %s %d %d %d %d %d %d %d \n",c.nomcapt,c.ref,c.marque,c.date.j1,c.date.m1,c.date.a1,c.type,c.gar,c.valmax,c.valmin);
	  x=1;
}
else 
x=0;
}
}
fclose(f);
fclose(g);
remove("capteur.txt");
rename("ancien_capteur","capteur.txt");
return x;
}

///////////////////////// modifier///////////////////////////////////////////////
void modifier_capteur (int ref,capteur c,capteur c1)
{  
char rep='n';  
FILE *f;
FILE *g;
f=fopen("capteur.txt","r");
g=fopen("capteur_modifie.txt","a+");
while(fscanf(f,"%s %d %s %d %d %d %d %d %d %d \n",c.nomcapt,&c.ref,c.marque,&c.date.j1,&c.date.m1,&c.date.a1,&c.type,&c.gar,&c.valmax,&c.valmin)!=EOF)
            {
           
             if(c1.ref==ref)
              {
               
    		c1.ref=ref;
    		printf("le jour d'ajout:  ");
    		scanf("%d",&c.date.j1);
    		printf("le mois d'ajout: ");
    		scanf("%d",&c.date.m1);
    		printf("l'annee d'ajout: ");
    		scanf("%d",&c.date.a1);
    		printf("le nom du capteur: ");
                fflush (stdin);
    		scanf("%s",c.nomcapt);
    		printf("la marque du capteur");
                 fflush (stdin);
    		scanf("%s",c.marque);
		printf("donner le type de capteur:");
		scanf("%d",&c.type);
		printf("annee du garantie");
		scanf("%d",&c.gar);
		printf("donner la valeur max:");
		scanf("%d",&c.valmax);
		printf("donner la valeur min:");
		scanf("%d",&c.valmin);
		
                fprintf(f,"%s %d %s %d %d %d %d %d %d %d \n",c.nomcapt,c.ref,c.marque,c.date.j1,c.date.m1,c.date.a1,c.type,c.gar,c.valmax,c.valmin);
             }  else{
fprintf(g,"%s %d %s %d %d %d %d %d %d %d \n",c.nomcapt,c.ref,c.marque,c.date.j1,c.date.m1,c.date.a1,c.type,c.gar,c.valmax,c.valmin);
}  
}
         fclose(f);
         fclose(g);
         remove("capteur.txt");
         rename("capteur_modifie.txt","capteur.txt");
         printf("\n  modification reussit");

}
////////////////////////affichage/////////////////////////////////////////////
void afficher_capteur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nomcapt[50];
	int ref;
	char marque[50];
	date date;
	int type;
	int gar;
	int valmax;
	int valmin;
	char ch[20];
	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nom capt",renderer, "text",ENOM_CAPTEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" ref",renderer, "text",EREFERENCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" marque",renderer, "text",EMARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" type",renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" gar",renderer, "text",EGARANTIE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" valmax",renderer, "text",EVALEUR_MAX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" valmin",renderer, "text",EVALEUR_MIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	
	store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	f=fopen("capteur.txt","a+");
	if (f==NULL)
	{
		return;
	}
	else
	{ f=fopen("capteur.txt","a+");
		while (fscanf(f,"%s %d %s %d %d %d %d %d %d %d \n",nomcapt,&ref,marque,&date.j1,&date.m1,&date.a1,&type,&gar,&valmax,&valmin)!=EOF)
			{
				if (type==1)
					strcpy(ch,"de temperature");
				else if (type==2)
					strcpy(ch,"de fummee"); 
				else if (type==3)
					strcpy(ch,"de mouvement");
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ENOM_CAPTEUR,nomcapt,EREFERENCE,ref,EMARQUE,marque,EJOUR,date.j1,EMOIS,date.m1,EANNEE,date.a1,ETYPE,ch,EGARANTIE,gar,EVALEUR_MAX,valmax,EVALEUR_MIN,valmin,-1);
			}
			fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
}
}
void vider (GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;

	
	char nomcapt[50];
	int ref;
	char marque[50];
	date date;
	int type;
	int gar;
	int valmax;
	int valmin;
	char ch[20];
	store=NULL;
	FILE *f;
store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nom capt",renderer, "text",ENOM_CAPTEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	ref = gtk_tree_view_column_new_with_attributes(" ref",renderer, "text",EREFERENCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" marque",renderer, "text",EMARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois",renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee",renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" type",renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" gar",renderer, "text",EGARANTIE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" valmax",renderer, "text",EVALEUR_MAX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" valmin",renderer, "text",EVALEUR_MIN,NULL);
	store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);	
}
if (type==1)
strcpy(ch,"de temperature");
else if (type==2)
strcpy(ch,"de fummee"); 
else if (type==3)
strcpy(ch,"de mouvement");

store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}
//////////////////////////////////////////end Dhia.c//////////////////////////////////////////////////////////////////////
