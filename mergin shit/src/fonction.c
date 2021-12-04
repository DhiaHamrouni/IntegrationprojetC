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
COLUMNS
};


///////////////////////::trouvage::///////////////////////////////////////////////

capteur trouvage(int ref)
{
capteur c1;
capteur c2;
    FILE *F;
    F = fopen("capteur.txt","r");
    if(F != NULL){
    	while(fscanf(F,"%s %d %s %d %d %d %d %d \n",c1.nomcapt,&c1.ref,c1.marque,&c1.date.j1,&c1.date.m1,&c1.date.a1,&c1.type,&c1.gar) != EOF){
        	if(c1.ref==ref)
		{
       		     c2=c1;
        	}
    	}
}

    fclose(F);
  return (c2);  
}
//////////////////////////////chercher/////////////////////////////////////////
int cherche_id(int num)
{
    FILE *F;
    capteur c ;
    F=fopen("capteur.txt","r");
    do
    {
        fscanf(F,"%s %d %s %d %d %d %d %d \n",c.nomcapt,&c.ref,c.marque,&c.date.j1,&c.date.m1,&c.date.a1,&c.type,&c.gar);
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
			fprintf(f,"%s %d %s %d %d %d %d %d  \n",c.nomcapt,c.ref,c.marque,c.date.j1,c.date.m1,c.date.a1,c.type,c.gar);
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
	while(fscanf(f,"%s %d %s %d %d %d %d %d  \n",c.nomcapt,&c.ref,c.marque,&c.date.j1,&c.date.m1,&c.date.a1,&c.type,&c.gar)!=EOF)
	{ 
 	 if(c.ref!=num)
{
	  fprintf(g,"%s %d %s %d %d %d %d %d  \n",c.nomcapt,c.ref,c.marque,c.date.j1,c.date.m1,c.date.a1,c.type,c.gar);
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
void modifier_capteur (int ref,capteur c)
{  
supprimer_capteur(ref);
ajout_capteur(c);
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
	store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT);
	f=fopen("capteur.txt","a+");
	if (f==NULL)
	{
		return;
	}
	else
	{ f=fopen("capteur.txt","a+");
		while (fscanf(f,"%s %d %s %d %d %d %d %d  \n",nomcapt,&ref,marque,&date.j1,&date.m1,&date.a1,&type,&gar)!=EOF)
			{
				if (type==1)
					strcpy(ch,"de temperature");
				else if (type==2)
					strcpy(ch,"de fummee"); 
				else if (type==3)
					strcpy(ch,"de mouvement");
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ENOM_CAPTEUR,nomcapt,EREFERENCE,ref,EMARQUE,marque,EJOUR,date.j1,EMOIS,date.m1,EANNEE,date.a1,ETYPE,ch,EGARANTIE,gar,-1);
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
	store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT);	
}
if (type==1)
strcpy(ch,"de temperature");
else if (type==2)
strcpy(ch,"de fummee"); 
else if (type==3)
strcpy(ch,"de mouvement");

store =gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}
//////////////////////////////////////////end Dhia.c//////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////nouha.c//////////////////////////////////////////////////////////////////////
void ajouter(produit p)
{

     FILE *f;
    f=fopen("produit.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %d %d %d %d\n",p.id,p.nom,p.marque,p.categorie,p.date_fab.j1,p.date_fab.m1,p.date_fab.a1,p.quantite);
        fclose(f);
    }

}

int supprimer(int id)
{
    FILE *f=NULL;
    FILE *tmp=NULL;
    int t=0;
    produit p;
    f=fopen("produit.txt","r");
    tmp=fopen("tmp.txt","w");
    if(f!=NULL)
    {
       while(fscanf(f,"%d %s %s %s %d %d %d %d\n",&p.id,p.nom,p.marque,p.categorie,&p.date_fab.j1,&p.date_fab.m1,&p.date_fab.a1,&p.quantite)!=EOF)
       {
        if(p.id!=id)
        {
         fprintf(tmp,"%d %s %s %s %d %d %d %d\n",p.id,p.nom,p.marque,p.categorie,p.date_fab.j1,p.date_fab.m1,p.date_fab.a1,p.quantite);
        }
	if(p.id==id)
	  {t=1;}

       }
        fclose(f);
        fclose(tmp);
        remove("produit.txt");
        rename("tmp.txt","produit.txt");

    }
return (t);
}
