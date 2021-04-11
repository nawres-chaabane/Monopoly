ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>

using namespace std ;

class joueur {
	carte_terrain * pocession_de_carte  [] ;
	int nbre_pocession_carte ;

	string nom_joueur ;
	int nbre_maison_du_joueur ;
	int nbre_hotel_du_joueur ;
	int solde ;
	int position_joueur ;
	static int nbre_tir_carte_chance ;     // initialisation dans main        joueur ::   nbre_tir_carte_chance ; =-1 ;
	static int nbre_tir_carte_communaute ;  // initialisation dans main        joueur ::   nbre_tir_carte_communaute ; =-1 ;


	public :
		joueur(){

		}
		~joueur(){

		}

		friend int banque :: donner_arg(int , joueur) ;  // ce sont deux méthodes de la classe banque !!
		friend int banque :: recevoir_arg(int , joueur) ;

		friend class de ;

		friend class carte_terrain ;

		void acheter_carte(carte_terrain cr){

			if ((solde>= cr.prix_carte_terrain) && (cr.position==position_joueur)) {
						 		solde-=cr.prix ;
								pocession_de_carte[nbre_pocession_carte ++]=cr ;    // il faut surcharger le constructeur d'affectation dans la classe carte_terrain !!!
			}

		}

		void vendre_carte(carte_terrain cr){
			solde+=cr.prix ;
			for ( int i=0 ; i<nbre_pocession_carte ; i++)
			{
				if (pocession_carte[i]==cr )
				cr.~carte_terrain() ;
			}

			nbre_pocession_carte -- ;
		}

		void se_deplacer ( int pos_actuelle , int somme_deux_de )
		{
			position_joueur = pos_actuelle + somme_deux_de ;
			if (position_joueur > 39  )           // n'oublie pas le fait que vous prendre 200 euros mais si vous ne tirez pas une carte chance ou communauté qui est contre ceci !!
			position_joueur -= 40 ;
		}


		void tirer_carte_chance (){
			carte_chance c ;
			c.afficher_le_contenu_chance (nbre_tir_carte_chance ++ ) ;

		}

		void tirer_carte_chance (carte_communaute carte){
			carte_communaute c ;
			c.afficher_le_contenu_communaute ( nbre_tir_carte_communaute ++) ;
		}


		void donner_argent(joueur j , int somme){
			j.solde+=somme ;
			solde-=somme ;
			cout<<"monsieur vous avez donné une somme de :"<<somme<<" à monsieur " <<j.nom_joueur ;
		}


		void recevoir_argent(joueur j , int somme){												// on peut éliminer cette méthode en remarquant que c'est similaire
			j.solde-=somme ;																		// à celle d'avant en inversant les intervenants .
			solde+=somme ;
			cout<<"monsieur vous avez recevoir une somme de :"<<somme<<" de monsieur " <<j.nom_joueur ;
		}

		void allez_en_prison (){
			position=10 ;
		}




		/*il reste se déplacer pour le joueur */

		/*   pour les cartes de chances et de communautés on va utilisé switch val {
		case 0 :
		cout<< aller en prison ;


		}*/
#endif //JOUEUR_H
