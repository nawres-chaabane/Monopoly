#ifndef BANQUE_H
#define BANQUE_H
#include <iostream>
#include "carte_chance.h"

using namespace std ;

class Joueur;

class Banque
{

    private:
        int montant;
        int nb_hotels;
        int nb_maisons ;

    public:
        Banque() ;

        ~Banque() ;

        int get_nb_maisons () ;

        int get_nb_hotels() ;

        void set_nb_maisons(int a) ;

        void set_nb_hotels(int b) ;

        void donner_arg(int arg,Joueur& j) ;

        void recevoir_arg(int arg,Joueur& j) ;


};

#endif // BANQUE_H
