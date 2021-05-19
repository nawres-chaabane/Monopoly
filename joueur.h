#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <list>
#include <vector>
#include <iostream>

#include "carte_chance.h"
#include "carte_communaute.h"
#include "carte_terrain.h"
#include "de.h"
#include "banque.h"
#include "jeu.h"
#include "plateau.h"

using namespace std ;

class Joueur {
    string nom_joueur ;
    int position_joueur ;
    int nbre_possession_carte ;
	list<Carte_terrain*> list_possession ;
	int solde ;
	int nbr_tour_en_prison;
    bool a_commence ;       //pour savoir est ce que le joueur a commencer à jouer
	bool avoir_carte_libre_prison_chance;
	bool avoir_carte_libre_prison_communite;
	/*les deux attributs static sont nécessaires pour souligner le fait que chaque joueur qui tire une
	carte de chance ou de communauté il doit la disposer sous les autres*/

	public :
		Joueur(string ch ="sans nom" );

		~Joueur();

		int get_solde() ;

		void set_solde(int ) ;

		string get_nom_joueur() ;

		bool get_a_commence() const ;

		void set_a_commence(bool);

		int getPosition() const ;

		void setPosition(int ) ;

		list<Carte_terrain*> getListPossession() const;

		bool isCarteOwner ( list <Carte_terrain*>& l, int pos)  ;

		bool isCarteOwnedByOtherPlayer (Joueur* j, vector <Joueur>& listJoueur, list <Carte_terrain*>& l, int pos, std::string nom);

		void acheter_carte_de_la_banque(Carte_terrain &cr ,Banque & banque);  //elle à été pointeur pour la carte terrain

		void acheter_carte_du_joueur(Carte_terrain& cr, Joueur& j, int prix_demande);

		void vendre_carte_au_joueur(Carte_terrain &cr, Joueur j) ;

		void se_deplacer ( De& , Banque & banque) ;

		void tirer_carte_chance (Carte_chance& carte, Banque& banque, Jeu& jeu) ;

		void tirer_carte_communaute (Carte_communaute& cr, Carte_chance& cc, Banque& banque, Jeu& jeu) ;

		void donner_argent(Joueur& j , int somme) ;

		void recevoir_argent(Joueur& j , int somme)	;

		void allez_en_prison () ;

		int get_nbre_possession_carte();

		bool est_en_prison();

		int get_nbre_maison_du_joueur_plage(string col) ;

		void hypothequer(Carte_terrain&,Banque &) ;

		void recuperer_carte_hypotheque(Carte_terrain& cr,Banque& b);

		void loser(vector <Joueur>& listJoueur);

		bool se_liberer(Banque& banque, vector <Joueur>& listJoueur);

		void traitement_si_solde_superieur_a_la_somme_apayer_au_joueur(Joueur & j ,int som_a_payer, Plateau plateau);

		void traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(int som_a_payer ,Banque &_banque, vector <Joueur>& listJoueur);

		int get_nbr_tour_en_prison();

		void set_nbr_tour_en_prison(int);

		bool avoir_carte_libere_de_prison();

		void set_carte_libere_de_prison_chance(bool val);

		void set_carte_libere_de_prison_communite(bool val);

        bool possede_carte_libere_de_prison_chance();

        bool possede_carte_libere_de_prison_communite();

        void traitement_si_je_suis_sur_ma_gare(Carte_terrain &);

        void acheter_toute_la_plage_de_couleur(Carte_terrain& cr, Joueur& j,int prix_demande);

        static int nbre_tir_carte_chance ;

        static int nbre_tir_carte_communaute ;


};
#endif
