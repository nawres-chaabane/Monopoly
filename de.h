#ifndef DE_H
#define DE_H
#include <iostream>


using namespace std ;

class De {
	int val_de_1 ;
	int val_de_2 ;
	int countDouble;

	public :
	De() : val_de_1(0), val_de_2(0), countDouble(0) {}
	~De(){}
	bool newDeRandomValue();
	bool obtenir_double () ;
	bool lancer_premiere_fois() ;
	int relancer() ;
	int somme() ;
    int get_countDouble();
    void set_countDouble(int a);

	private :
	bool lancer() ; /*on va l'utiliser dans la méthode relancer */



};
#endif // DE_H
