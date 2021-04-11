#ifndef DE_H
#define DE_H
#include <iostream>

using namespace std;
class de {
	int val_de_1 ;
	int val_de_2 ;
	static bool depart ;
	public :
	de() {
	 	srand(time(NULL));
	 	val_de_1=rand() %6 +1 ;
	 	val_de_2=rand() %6 +1 ;
	 	cout << val_de_1 << ":" << val_de_2 ;
	}
	~de();

	friend void joueur ::  se_deplacer ( int pos_actuelle , int somme_deux_de ) ;

	bool obtenir_double (){
		return (val_de_1 == val_de_2);
		//depart=true ;
	}

	int lancer_premiere_fois(joueur j) {
		if (obtenir_double()){
			return val_de_1 + val_de_2 ;
			cout <<" c'est parti monieur " << j.nom<< " commençons !" ;
		}

		else cout<< "vous avez besoin d'un double pour partir !" ;
	}

	/*void aller_en_prison(){
		joueur se place dans le prison et attend les permissions qui lui permettent de se libérer
	}*/

	int lancer(joueur j ){
		de d;
		cout << d.val_de_1 << ":" << d.val_de_2 ;
		return d.val_de_1 + d.val_de_2 ;
	}
	int relancer(joueur j ){
		int i=0 ;
		while ((obtenir_double()) || (i<3)){
			de d; i++ ;
			cout << val_de_1 << ":" << val_de_2 ;
		    return d.lancer();
		}
		if (i == 2) {
			cout << "aller_en_prison()" ;
			j.allez_en_prison() ;
		}


	}



};
#endif // DE_H
