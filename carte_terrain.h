#ifndef CARTE_TERRAIN_H
#define CARTE_TERRAIN_H

#include <string>
#include <iostream>

#include "case.h"

class Banque;
class Joueur;
using namespace std ;

class Carte_terrain : public Case {

	private :
        string couleur ;
        int nbre_maison_construit ;
        int prix_maison ;
        int prix_hotel ;
        int nbre_hotel_construit ;
        int taux_hypotheque ;
        int prix_a_payer_avec_0_maison ;      // 6 attributs qui caractérisent l'amende à payer si un etranger se place sur ma carte !
        int prix_a_payer_avec_1_maison ;
        int prix_a_payer_avec_2_maison ;
        int prix_a_payer_avec_3_maison ;
        int prix_a_payer_avec_4_maison ;
        int prix_a_payer_avec_1_hotel ;
        bool est_hypotheque ;
        bool est_gare;
        bool est_compagnie;

	public :
        Carte_terrain ( int pos =0 ,string nom ="", int prix=0 ,string col ="" ,int nmc=0,int pm=0 , int nhc=0, int ph=0 ,
                       int h=0,int a=0 ,int b=0,int c=0 ,int d=0 , int e=0 , int f=0 ,bool eg=false ,bool ec=false);


        ~Carte_terrain();

        //Carte_terrain(const Carte_terrain&);


        bool get_est_hypotheque () const ;

       	void set_est_hypotheque (bool) ;

       	bool get_est_gare()   ;

        bool get_est_compagnie()   ;

        int get_prix_a_payer_avec_0_maison() const;

        int get_prix_a_payer_avec_1_maison() const;

        int get_prix_a_payer_avec_2_maison() const;

        int get_prix_a_payer_avec_3_maison() const;

        int get_prix_a_payer_avec_4_maison() const;

        int get_prix_a_payer_avec_1_hotel() const;

        int get_nbre_maison_construit() const;

        int get_nbre_hotel_construit() const ;

        int get_taux_hypotheque()const;   //get_taux_hypotheque

        int get_prix_maison() const;

        int get_prix_hotel() const;

        string get_couleur() const;

        int get_ce_qeu_faut_payer(Joueur&) ;

        void construire_maison( Joueur & , Banque& );

        void construire_hotel (Joueur &, Banque& banque) ;

        bool avoir_toute_la_plage_colore(Joueur &  ,string );


};
#endif //CARTE_TERRAIN_H
