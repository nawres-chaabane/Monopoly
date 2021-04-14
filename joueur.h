#ifndef JOUEUR_H	
#define JOUEUR_H	
#include <iostream>
#include"CARTE_TERRAIN.H"
#include"BANQUE.H"
#include<string>

using namespace std ;

class joueur {
	carte_terrain * possession_de_carte  [] ;   // il contient les possessions que possede le joueur 
	int nbre_possession_carte ;
	string nom_joueur ;
	int nbre_maison_du_joueur ;
	int nbre_hotel_du_joueur ;
	int solde ;
	int position_joueur ; 
	static int nbre_tir_carte_chance ;     // initialisation dans main        joueur ::   nbre_tir_carte_chance ; =-1 ;
	static int nbre_tir_carte_communaute ;  // initialisation dans main        joueur ::   nbre_tir_carte_communaute ; =-1 ;
	// les deux attributs static sont nécessaires pour souligner le fait que chaque joueur qui tire une carte de chance ou de communauté il doit la disposer sous les autres
	
	
	public :
		joueur(string ch ="sans nom" , int pos = 0 , int nb1=0 , int nb2=0 , int solde=1500 , nb3 =0){
			possession_de_carte = new carte_terrain[nb3];
			nom_joueur=ch ;
		}
		~joueur(){
			delete[] possession_de_carte ;
		}
		
		friend int banque :: donner_arg(int , joueur) ;  // ce sont deux méthodes de la classe banque !!
		friend int banque :: recevoir_arg(int , joueur) ; 
		
		friend class de ;    // on a définit la classe de amie avec celle de joueur car la majorité de ses méthodes nécessitent l'utilistion des attributs de la classe joueur
		
		friend class carte_terrain ;  // on a définit la classe carte-terrain amie avec celle de joueur car la majorité de ses méthodes nécessitent l'utilistion des attributs de la classe joueur
		
		void acheter_carte_de_la_banque(carte_terrain cr){

			if ((solde>= cr.prix_carte_terrain) && (cr.position==position_joueur)) {
						 		banque :: recevoir_arg(cr.prix , this) ;
								possession_de_carte[nbre_possession_carte ++]=cr ;    // il faut surcharger le constructeur d'affectation dans la classe carte_terrain !!!
			}
		 		
		}
		
		void acheter_carte_du_joueur(carte_terrain cr, joueur j){

			if ((solde>= cr.prix_carte_terrain) && (cr.position==position_joueur)) {
						 		j.solde+=cr.prix_carte_terrain ;
						 		solde-=cr.prix_carte_terrain ;
								possession_de_carte[nbre_possession_carte ++]=cr ;
								for ( int i=0 ; i<j.nbre_possession_carte ; i++)
									{
										if (j.possession_carte[i]==cr )
												cr.~carte_terrain() ;
												j.nbre_possession_carte -- ; 
												}
											}
										}
			
		
		/*void vendre_carte_de_banque(carte_terrain cr){
			banque :: donner_arg(cr.prix , this) ;
			for ( int i=0 ; i<nbre_possession_carte ; i++)
			{
				if (possession_carte[i]==cr )
				cr.~carte_terrain() ;
			}
			
			nbre_possession_carte -- ;
		}*/
		
		void vendre_carte_au_joueur(carte_terrain cr, joueur j){

			if  (cr.position==j.position_joueur){
						 		solde+=cr.prix_carte_terrain ;
						 		j.solde-=cr.prix_carte_terrain ;
								j.possession_de_carte[nbre_possession_carte ++]=cr ;
								for ( int i=0 ; i<nbre_possession_carte ; i++)
									{
										if (possession_carte[i]==cr )
												cr.~carte_terrain() ;
												nbre_possession_carte -- ; 
												}
											}
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
		
		void tirer_carte_communaute (carte_communaute carte){
			carte_communaute c ;
			c.afficher_le_contenu_communaute ( nbre_tir_carte_communaute ++) ;   /*il nous reste à implémenter les classes carte_chance et carte_comunaute on fait la methode
			afficher_le_contenu_chance et la methode afficher_le_contenu_communaute sont deux methodes de ces deux classes */
		}
		
		
		void donner_argent(joueur j , int somme){       // dans le cas d'une tombé sur une possession d'un autre joueur 
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
	
	
	// 2 méthodes qui nous renseignent sur le gagnant et les perdants seront implémentées dans la classe jeu qui à comme attribut un tableau de joueur !!
		
		
		
		/*   pour les cartes de chances et de communautés on va utilisé switch val {
		case 0 :  */
		
		                     
		
		};
#endif //JOUEUR_H		
