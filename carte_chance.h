#ifndef CARTE_CHANCE_H
#define CARTE_CHANCE_H

#include "carte_terrain.h"

class Banque;
class Joueur;
class Jeu;
using namespace std;

class Carte_chance
{

	public:
	    Carte_chance();
	    ~Carte_chance();
	    void traiter_carte_chance( Joueur& j, Banque& banque, Jeu& jeu, int );
	    bool statusCarteLibererPrison();
        static bool carteLibererPrisonUtilisee;
};

#endif
