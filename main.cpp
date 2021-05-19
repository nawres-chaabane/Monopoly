#include "jeu.h"
#include "joueur.h"
#include "de.h"
#include <vector>
using namespace std ;

int main(int argc, char *argv[])
{
	int nbPlayer = 0;
	cout << "Bienvenu, entrer le nombre des joueurs s'il vous plait "<<endl;
	cin >> nbPlayer;
	vector<Joueur> listJoueur;
	for (int i = 0; i< nbPlayer; ++i)
	{
		string joueurName;
        if(i==0)
            cout <<endl<<endl<< "Entrer le nom du "<< (i+1) << " er joueur "<<endl;
        else
        {
            cout <<endl<<endl<< "Entrer le nom du "<< (i+1) << " eme joueur "<<endl;
        }
		cin >> joueurName;
		listJoueur.push_back(Joueur(joueurName));
	}

    Jeu game(listJoueur);

    game.lancerJeu();

}
