#ifndef BANQUE_H
#define BANQUE_H
#include <iostream>
#include "JOUEUR.H"
using namespace std ;


class banque
{

    private:
        int montant, nb_hotels, nb_maisons ;

    public:
        banque(){ 
		montant= 12000;
        nb_maisons= 32;
        nb_hotels=12;
		}


        ~banque(){}
        int get_nb_maisons (){
            return nb_maisons;

        }
        int get_nb_hotels() {
            return nb_hotels;
        }
        void set_nb_maisons(int a){  //2 setter pour modifier le nombre de maison ou de hotel disponible en cas d'une vente 
            nb_maisons-=a;


        }
        void set_nb_hotels(int b){
            nb_hotels-=b;


        }
        int donner_arg(int arg,joueur j){ 
            montant= montant - arg;
            j.solde+=arg;
            return (montant);

        }
        int recevoir_arg(int arg,joueur j){
            montant= montant + arg;
            j.solde-=arg;
            return (montant);

        }

};

#endif // BANQUE_H
