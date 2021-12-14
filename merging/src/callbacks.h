#include <gtk/gtk.h>


void
on_button_gestionfoyer_accueil_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gestionstock_acceuil_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_nutritionniste_accueil_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gestioncapteur_accueil_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_inscription_accueil_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_to_accueil_de_connexion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_authentification_jesser_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_jesser_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimercapteur_dhia_clicked
                                        (GtkButton      *button,
                                        gpointer         user_data);

void
on_button_retourto_accueil_from_capteur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_connexion_alterne_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_temp_dhia_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_fum__e_dhia_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_infrarouge_dhia_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajoutcapt_interface_dhia_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_confirmer_supprission_capteur_dhia_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_annuler_nouha_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_valider_nouha_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Bienvenue_stock_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_nouha_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_nouha_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_ajout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_supp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_cherch_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_affichier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_affichunique_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajout_capteur_dhia_clicked   (GtkButton       *button,
                                        gpointer         user_data);


void
on_button_modifiercapteur_dhia_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_cherchercapteur_dhia_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_affichiercapteur_dhia_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier1_noctis_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutton_modifinfra_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif_fumee_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif_temp_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_authentification0_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_incription0_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_actualiser_affichage_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_accueil_affichage_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_verifmodif_noctis_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_ajout_capt_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_acc_modif_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_connexion_alterne_enter      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_connexion_alterne_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_tache2_dhia_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_confirm_alarme_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_dhia_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_search_dhia_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_fumer_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mouvement_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_tout_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_refresh_alarmes_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_alarmes_clicked              (GtkButton       *button,
                                        gpointer         user_data);



//////////jesser//////////



void
on_button5_trouver_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button4_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button3_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttontechnicien_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonnutrionniste_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonagentfoyer_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonagentrestaurant_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonetudiant_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button6_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_retourner_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button9_retourner_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_nombre_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_retourner_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_calculer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton6tech_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton7nut_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton8foyer_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton9resto_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton10etud_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1modifierm_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2retournerm_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_recherche_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_retournerrecher_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_checkbutton1_afich_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1j_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_button1_sidentifier_clicked         (GtkButton       *button,
                                        gpointer         user_data);
//////////////end jesser////////////

/*------------------------gaston--------------------*/


/*-------- bouton interface principale--------------*/
void
on_button1_agent_ajout_gas_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_agent_modifier_gas_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button3_agent_supprimer_gas_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_afficher_gas_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_agent_rechercher_gas_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_agent_actu_gas_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

/*-------- bouton confirmer--------------*/
void
on_button_supprimer_confirmer_gas_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_confirmer_ajout_gas_clicked  (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modif_confirmer_gas_clicked  (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_rechercher_confirmer_gas_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_id_a_modif_gas_clicked       (GtkButton       *button,
                                        gpointer         user_data);





/*--------bouton retourner--------------*/
void
on_button_retourner_supprimer_gas_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data);
void
on_button_retourner_ajout_gas_clicked  (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modif_retourner_gas_clicked  (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_retourner_afficher_gas_clicked
                                        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button_rech_retourner_gas_clicked   (GtkButton       *objet_graphique,
                                        gpointer         user_data);

/*-------- treeview--------------*/

void
on_treeview1_gas_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_treeview2_gas_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);



//////////////////////////////////////////////////////////////////////////
/*-------- radio button --------------*/
/*-------- radio ajout--------------*/
void
on_radiobutton_ajout_nonpaye_gas_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ajout_paye_gas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_radiobutton1_gas_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gb_radiobutton2_gas_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
/*-------- radio modif--------------*/


void
on_radiobutton_modif_paye_gas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif_nonpaye_gas_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif_avec_gas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif_sans_gas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_rech_affich_gas_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_check_rech_gas_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
/*---------------------------end gaston-------------------------*/



void
on_button_login_ghassen_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button15_suppr_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajout_menu_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_meilleur_menu_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button16_modifr_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_actualisermenu_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_meilleur_plat_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button19_retour_espace_admin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_authentification_nutritionnist_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_confajout_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_affajout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_annuler_ajout_menu_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button20_recherchermenu_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button21_confirmer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retourner_modif_menu_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_annulersuppmenu_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_suppmenu_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_annuler_meilleur_menu_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_trouver_meilleur_plat_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retourner_meilleur_plat_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton6_calcium_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_lipides_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4_glucides_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton7_fer_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton5_proteines_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton8_vitamines_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview1r_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_radiobutton1_ptdej_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_dej_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_diner_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_trouve_meilleur_menu_clicked (GtkButton       *button,
                                        gpointer         user_data);




/*------------------------nouhe-------------*/



void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_button111_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button222_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button333_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button444_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button555_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button666_clicked                   (GtkButton       *button,
                                        gpointer         user_data);


void
on_authnouhaa_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_button1111_clicked                  (GtkButton       *button,
                                        gpointer         user_data);



void
on_button2222_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3333_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4444_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5555_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6666_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2222_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1n_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_radiobutton1n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bienvenue_n_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_n_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_ajout_bienvenue_n_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_modif_bienvenue_n_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_modification_n_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_n_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_supp_bienvenue_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherche_n_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_rech_bienvenue_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2n_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_affichage0_bienvenue_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_b_principal_n_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_a_pricipal_n_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_jesser_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_dashboard_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Nouha_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ghassen_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Dhia_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_rima_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_dashboard_dhia_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_dshboard_jesser_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_dashboard_rima_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_dashboard_nouha_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_page1_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_R_D_D_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_R_D_J_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_R_D_R_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_R_D_N_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_R_D_G_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button66666666666_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7777777777_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_gas_ret_princip_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_meilleur_menu_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_meilleur_plat_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_dashnouha_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6667_clicked                  (GtkButton       *button,
                                        gpointer         user_data);
