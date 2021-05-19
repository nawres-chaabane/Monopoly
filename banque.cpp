#include "banque.h"
#include "joueur.h"
#include <iostream>
using namespace std ;

        Banque :: Banque(){
	    	montant= 12000;
            nb_maisons=32;
            nb_hotels=12;
		}

		Banque :: ~Banque() {}

        int Banque :: get_nb_maisons (){
            return nb_maisons;

        }

        int Banque :: get_nb_hotels() {
            return nb_hotels;
        }
        void Banque :: set_nb_maisons(int a){  //2 setter pour modifier le nombre de maison ou de hotel disponible en cas d'une vente
            nb_maisons=a;


        }
        void Banque :: set_nb_hotels(int b){
            nb_hotels=b;
        }
        void Banque :: donner_arg(int arg,Joueur& j){
            montant= montant - arg;
            j.set_solde(j.get_solde()+arg) ;
            cout<<"Monsieur "<<j.get_nom_joueur()<<" votre solde est mise a jour a "<<j.get_solde()<<endl ;
            cout<<"Le montant de la banque est mise a jour a "<<montant<<endl;

        }
        void Banque :: recevoir_arg(int arg,Joueur& j){
            montant= montant + arg;
            j.set_solde(j.get_solde()-arg) ;
            cout<<"Monsieur "<<j.get_nom_joueur()<<" votre solde est mise a jour a "<<j.get_solde()<<endl ;
            cout<<"Le montant de la banque est mise a jour a "<<montant<<endl;
        }
