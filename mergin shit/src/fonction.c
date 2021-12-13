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
enum
{
EJOUR1,
EHEURE,
ENUM_CAPT,
EVALEUR,
COLUMNS1
};

///////////////////////connexion//////////////////////////////////////////////////
int verif_dhia (char log[] , char pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[30];
char ch2[30];
f=fopen("admins.txt","r");
if(f!=NULL)
{
while (fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{
if ((strcmp(ch1,log)==0) && (strcmp(ch2,pw)==0))
trouve=1;
}
fclose(f);
}
return trouve;
}
///////////////////////end_connexion//////////////////////////////////////////////
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
void afficher_capteur_fume(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	int jour;
	int heure;
	int num_capt;
	int valeur;
	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",EJOUR1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" heure",renderer, "text",EHEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" num_capt",renderer, "text",ENUM_CAPT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" valeur",renderer, "text",EVALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	store =gtk_list_store_new(COLUMNS1, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	f=fopen("fumee.txt","a+");
	while (fscanf(f,"%d %d %d %d \n",&jour,&heure,&num_capt,&valeur)!=EOF)
	{
			if (((heure==24) || (heure<=6)) && (valeur==1))
			{
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,EJOUR1,jour,EHEURE,heure,ENUM_CAPT,num_capt,EVALEUR,valeur,-1);
			}
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	
}
}
void afficher_capteur_infra(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	int jour;
	int heure;
	int num_capt;
	int valeur;
	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer, "text",EJOUR1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" heure",renderer, "text",EHEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" num_capt",renderer, "text",ENUM_CAPT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" valeur",renderer, "text",EVALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	store =gtk_list_store_new(COLUMNS1, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	f=fopen("mouvement.txt","a+");
	while (fscanf(f,"%d %d %d %d \n",&jour,&heure,&num_capt,&valeur)!=EOF)
	{
			if (((heure==24) || (heure<=6)) && (valeur==1))
			{
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,EJOUR1,jour,EHEURE,heure,ENUM_CAPT,num_capt,EVALEUR,valeur,-1);
			}
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	
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
/*void ajouter(produit p)
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
*/
///////////jesser///////////////:


enum
{
	CIN,
	NOM,
	PRENOM,
	FONCTION,
	NIVEAU,
	DATE,
	COLUMNSS
};

int verif(char cin[],char mot[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("authen.txt","r");
if(f!=NULL);
{
while(fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{
if((strcmp(ch1,cin)==0) &&(strcmp(ch2,mot)==0))
trouve=1;
}
fclose(f);
}
return trouve ;

}

void ajouter_utilisateur(utilisateur u)
{
FILE *f;
f=fopen("utilisateur.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s \n",u.cin,u.nom,u.prenom,u.fonction,u.niveau,u.daten);
fclose(f);
}
}

void modifier_utilisateur(utilisateur u,char cin[])
{

    FILE*F,*Fich;
             F=fopen("utilisateur.txt","r");
            Fich=fopen("temputil.txt","a");
            do
            {
                fscanf(F,"%s %s %s %s %s %s \n",u.cin,u.nom,u.prenom,u.fonction,u.niveau,u.daten);
            if(strcmp(cin,u.cin)==0)
            {
    
            fprintf(Fich,"%s %s %s %s %s %s \n",u.cin,u.nom,u.prenom,u.fonction,u.niveau,u.daten);
}


            }while(!feof(F));
            fclose(F);
            fclose(Fich);
            remove("utilisateur.txt");
            rename("temputil.txt","utilisateur.txt");
          
    }


void afficher_utilisateur(GtkWidget *liste)
{

char cin[30];
char nom[20];
char prenom[20];
char fonction[50];
char niveau[20];
char date[50];


	GtkCellRenderer *renderer;
       GtkTreeViewColumn *column;
       GtkTreeIter iter;	
       GtkListStore *store;
store=NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" fonction", renderer, "text",FONCTION, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" niveau", renderer, "text",NIVEAU, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes(" date_de_naissance", renderer, "text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


}
store=gtk_list_store_new (COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );

f=fopen("utilisateur.txt","r");
if(f==NULL)
{
	return;
}
else
{
f=fopen("utilisateur.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s \n",cin,nom,prenom,fonction,niveau,date)!=EOF)
{
gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter, CIN, cin, NOM, nom, PRENOM, prenom, FONCTION, fonction, NIVEAU, niveau, DATE, date, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

void supprimer_utilisateur(utilisateur u)
{
char cin[30];
char nom[20];
char prenom[20];
char fonction[50];
char niveau[20];
char date[50];
FILE *f,*g;
f=fopen("utilisateur.txt","r");
g=fopen("dump","w");
if(f==NULL || g==NULL)
{
	return;
}
else
{
	while(fscanf(f,"%s %s %s %s %s %s \n",cin,nom,prenom,fonction,niveau,date)!=EOF)
	{
		if( strcmp(u.cin,cin)!=0 || strcmp(u.nom,nom)!=0 || strcmp(u.prenom,prenom)!=0 || strcmp(u.fonction,fonction)!=0 ||
           strcmp(u.niveau,niveau)!=0 || strcmp(u.daten,date) )
			{
			fprintf(g,"%s %s %s %s %s %s \n",cin,nom,prenom,fonction,niveau,date);
			}			
	}
	fclose(f);
	fclose(g);
remove("utilisateur.txt");
rename("dump.txt", "utilisateur.txt");
}
}
	




void supprimer1(char cin[])
{
    	    	
                
            FILE*Fich,*F;
		utilisateur u;
            F=fopen("utilisateur.txt","r");
            Fich=fopen("temputil.txt","a");
            do
            {
                fscanf(F,"%s %s %s %s %s %s \n",u.cin,u.nom,u.prenom,u.fonction,u.niveau,u.daten);
                if(strcmp(cin,u.cin)!=0)
                {
                    fprintf(Fich,"%s %s %s %s %s %s \n",u.cin,u.nom,u.prenom,u.fonction,u.niveau,u.daten);
                }
            }while(!feof(F));
            fclose(Fich);
            fclose(F);
            remove("utilisateur.txt");
            rename("temputil.txt","utilisateur.txt");
          

        }


int recherche(char cin[])
{
int x=0;
utilisateur u;
FILE* F;
F=fopen("utilisateur.txt","r");
 do
            {
                fscanf(F,"%s %s %s %s %s %s \n",u.cin,u.nom,u.prenom,u.fonction,u.niveau,u.daten);

	if(strcmp(u.cin,cin)==0)
	{
		x=1;
		}


            }while(!feof(F));

fclose(F);
return x;
}

int nombre_etudiant(char niv[])
{
utilisateur u;
int nbr=0;

 FILE *f;
    f = fopen("utilisateur.txt","r");
 if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s %s \n",u.cin,u.nom,u.prenom,u.fonction,u.niveau,u.daten)!= EOF){
if (strcmp(niv,u.niveau)==0)
    nbr++;
}}

return nbr;
fclose(f);
}

utilisateur chercher_utilisateur(char cin[])
{
utilisateur u;
FILE *f;
f=fopen("utilisateur.txt","r");
if (f!=NULL )
{
while(fscanf(f,"%s %s %s %s %s %s \n",u.cin,u.nom,u.prenom,u.fonction,u.niveau,u.daten)!= EOF){
if(strcmp(cin,u.cin)==0)
{
return u;
}
}
}
fclose(f);
}

//////////end jesser///////////
/*--------------------------gaston------------------*/

enum
{

	EID,
	ENOM,
	EJOURG,
	EMOISG,
	EANNEEG,
	EETAT,
	ETYPEG,
	EACCES,
	COLUMNSG
};

/*---------ajout---------*/

void ajouterg(etud e)
{
FILE *f;

f=fopen("Etudiants.txt","a+");
if(f!=NULL)
fprintf(f,"%d %s %d %d %d %s %s %s \n", e.id, e.nom, e.d.j, e.d.m, e.d.a, e.etat, e.type, e.acces);
	
	fclose(f);
}




/*---------affichage---------*/
void affichageg(GtkWidget *liste)
{
etud e;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

int id;
char nom[30];
int jour;
int mois;
int annee;
char etat[30];
char type[30];
char acces[30];

store==NULL;
store=gtk_tree_view_get_model(liste);
FILE *f;
	if (store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",EID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Nom", renderer,"text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	



	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Jour", renderer,"text",EJOURG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Mois", renderer,"text",EMOISG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Annee", renderer,"text",EANNEEG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
  


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Etat de paiment", renderer,"text",EETAT, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Type de chambre", renderer,"text",ETYPEG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	



	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Acces Resto", renderer,"text",EACCES, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
}

store=gtk_list_store_new(COLUMNSG, G_TYPE_INT, G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("Etudiants.txt", "r");
if(f==NULL)
{
return;
}
else
{ f = fopen("Etudiants.txt", "a+");
	while (fscanf(f,"%d %s %d %d %d %s %s %s \n",&id,nom,&jour,&mois,&annee,etat,type,acces) !=EOF )
	{
	
	gtk_list_store_append(store,&iter);

	gtk_list_store_set(store,&iter,EID,id,ENOM,nom,EJOURG,jour,EMOISG,mois,EANNEEG,annee,EETAT,etat,ETYPEG,type,EACCES,acces,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}

}

/*---------------suppression---------------------*/
void supprim_etud(int id)
{
etud x;
FILE *f ,*g;
f=fopen("Etudiants.txt","r");
g=fopen("test.txt","w+");


if (f!=NULL)
	{
	while(fscanf(f,"%d %s %d %d %d %s %s %s \n",&x.id, x.nom, &x.d.j, &x.d.m, &x.d.a, x.etat, x.type, 		x.acces) !=EOF)
{
		if (id!=x.id)
	{
		fprintf(g,"%d %s %d %d %d %s %s %s \n", x.id, x.nom, x.d.j, x.d.m, x.d.a, x.etat, x.type, 		x.acces);
}}}
fclose(f);
fclose(g);

remove("Etudiants.txt");
rename("test.txt","Etudiants.txt");

}

/*---------------rechercher----------------*/
int rechercher(int id)
{ 
int x=0;
FILE *F;
etud e;
F=fopen("Etudiants.txt","r");
if(F!=NULL)
{
while(fscanf(F,"%d %s %d %d %d %s %s %s \n", &e.id, e.nom, &e.d.j, &e.d.m, &e.d.a, e.etat, e.type, e.acces)!=EOF)
{
if (e.id==id)
 x=1;
}
}
fclose(F);
return x;
}

/*------------------modifier--------------------*/

void modif_etud(etud e, int idg)
{
/*
FILE *g,*f;
etud p;
GtkWidget *pInfo;
f=fopen("Etudiants.txt","r");
g=fopen("test.txt","a+");

if (f==NULL || g==NULL)
	return;
else
{	
	while 
	(fscanf(f,"%d %s %d %d %d %s %s %s \n",&e.id, e.nom, &e.d.j, &e.d.m, &e.d.a, e.etat, e.type, e.acces)!=EOF);
	{
	if (e.id==idg)
		{
		fprintf(g,"%d %s %d %d %d %s %s %s \n", e.id, e.nom, e.d.j, e.d.m, e.d.a, e.etat, e.type, e.acces);
		}	
		fprintf(g,"%d %s %d %d %d %s %s %s \n", p.id, p.nom, p.d.j, p.d.m, p.d.a, p.etat, p.type, p.acces);
		

	}
}
fclose(f);
fclose(g);
remove("Etudiants.txt");
rename("test.txt","Etudiants.txt");
*/
supprim_etud(idg);
ajouterg (e);

}


/*------------------------vérif------------------------------*/
int verifg(char pseudo[], char mdp[])
{
int x;
FILE *f;
char ch1[50];
char ch2[50];
f=fopen("login.txt","r");
if (f==NULL);
{
while (fscanf(f,"%s %s ", ch1,ch2)!=EOF)
{
if((strcmp(ch1,pseudo)==0) && (strcmp(ch2,mdp)==0))
x=1;
else 
x=0;
}
fclose(f);
}
return x;
}

/*---------------rechercher2----------------*/
etud rechercher2(int id)
{ 

FILE *F;
etud e;
F=fopen("Etudiants.txt","r");
if(F!=NULL)
{
while(fscanf(F,"%d %s %d %d %d %s %s %s \n", &e.id, e.nom, &e.d.j, &e.d.m, &e.d.a, e.etat, e.type, e.acces)!=EOF)
{
if (e.id==id)
return e;
}
}
fclose(F);

}












