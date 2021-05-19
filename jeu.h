#ifndef _JEU_H
#define _JEU_H
#include <iostream>
#include"carte_chance.h"
#include"carte_communaute.h"
#include <vector>
#include"banque.h"
#include"carte_terrain.h"
#include"case.h"
#include "joueur.h"
#include "plateau.h"
#include "de.h"
using namespace std;

class Jeu
{
	public:
		Jeu(vector<Joueur> listJoueur);
		~Jeu();
		void lancerJeu();
		void handlerNewPosition(Joueur& m);

        vector <Joueur> _listJoueur;
	protected:
	private:
        Plateau _plateau;
		De d;
		Banque _banque;
		Carte_communaute _carteCommunaute;
        Carte_chance _carteChance;
};
#endif
