#ifndef CARTE_COMMUNAUTE_H
#define CARTE_COMMUNAUTE_H
#include "banque.h"
class Joueur;

using namespace std;

class Carte_communaute
{
private:
public:
    Carte_communaute();
    ~Carte_communaute();
    void traiter_carte_communaute(Joueur& ,Banque & ,int ,Carte_chance &,Jeu &jeu );
    bool statusCarteLibererPrison();
    static bool carteLibererPrisonUtilisee;
};

#endif
