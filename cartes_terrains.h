#ifndef DE_H
#define DE_H
#include <iostream>

using namespace std;

class carte_terrain (){    // elle ne comporte pas les 4 cases des coins , les chances , les communautés .
	int position ;
	string nom_terrain ;
	int prix_terrain ;
	string couleur ;
	int prix_maison ;
	int nbre_maison ;
	int prix_hotel ;
	int nbre_hotel ;
	string notez_bien ;
	int taux_hypothéqué ;
	int position ;

	public :
	 carte_terrain(string nm = "" ,int a=0 , string st ="" , int b=0 , int c=0 , int d=0 , int e =0 , string nt ="" , int f=0 , int g =0) {
	 nom_terrain =nm ;
	 prix_terrain=a ;
	 couleur =st ;
	 prix_maison=b ;
	 nbre_maison =c;     //nombre de maisons maximale qu'on peut construire qui est généralement 4
	 prix_hotel =d;
	 nbre_hotel=e ;      //nombre de hotel maximale qu'on peut construire qui est généralement 1
	 notez_bien = nt ;
	 taux_hypothéqué=f ;
	 int position =g;
	}


	~carte_terrain();


	int get_prix_maison(){
		return prix_maison ;
	}


	int get_prix_hotel(){
		return prix_hotel ;
	}


	void construire_maison(int a, joueur j) {
		if (a <= nbre_maison ) {
			cout<< "vous devez payer : " << prix_maison * a ;
			j.nbre_maison_du_joueur ++ ;
			j.solde-= prix_maison ;
		}

		if (a==nbre_maison)
		cout<<"vous pouvez maintenant construire un hotel" ;
	}

	//friend void carte_terrain :: construire_hotel () ; il faut la mettre dans la classe joueur

	void construire_hotel (joueur j ){

		if (nbre_maison_du_joueur==nbre_maison) {    // !!! get_nbre_maison_du_joueur() est une methode de la classe joueur donc il faut la déclarer comme friend
		cout<<"vous devez payer :"<< prix_hotel ;
		j.nbre_hotel_du_joueur ++ ;
		j.solde-=prix_hotel ;
		}
		else
		cout<< " vous devez finir dabord de construire vos " << nbre_maison << "maison !! " ;
	}

	void hypothéquer(joueur j) {
		if ((j.nbre_maison_du_joueur ==0 ) && (j.nbre_hotel_du_joueur ==0 ) && (j.solde))
			cout << " vous venez de hypthétiquer votre possession à cause de votre faillite , vous recevrez : " << taux_hypothéqué ;
			j.solde+=taux_hypothéqué ;

	}


};
#endif //CARTE_TERRAIN_H
