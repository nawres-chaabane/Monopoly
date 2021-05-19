#include "de.h"
#include <iostream>
#include <ctime>
using namespace std ;

	int De::somme()
	{
		return (val_de_1 + val_de_2);
	}


	void De::set_countDouble(int a)
	{
	    countDouble=a;
	}
	int De::get_countDouble()
	{
	    return countDouble ;
	}

	bool De :: obtenir_double (){
		return (val_de_1 == val_de_2);

	}

	bool De::newDeRandomValue()      // si joueur a un double on a true et il ya incrementation de countDouble si nn CountDouble est initialisée à 0 !!
	{                                 // l'appel à cette methode signifie avoir deux nouvelles valeurs pour le dé
		srand(time(NULL));
	 	val_de_1=rand() %6 +1 ;
	 	val_de_2=rand() %6 +1 ;
	 	if (obtenir_double()){
	 		++countDouble;
	 		return true;
	 	}
	 	countDouble = 0;
	 	return false;
	}

	bool De ::  lancer_premiere_fois()
	{
		countDouble = 0;

		if (newDeRandomValue()){
			cout <<"C'est parti monsieur commencons !"<<endl ;
			cout << "de = "<< val_de_1 << ":" << val_de_2<<endl ;
			return true ;
		}
		else
		{
			cout<< "Vous avez besoin d'un double pour partir :( !"<<endl ;
			return false;
		}
	}



	bool De ::  lancer()
	{
		bool ret = newDeRandomValue();
		cout << "de = "<< val_de_1 << ":" << val_de_2<<endl ;     /*on va l'utiliser dans la méthode relancer */
		return ret ;
	}



	int De ::  relancer()
	{
		bool retValue = lancer();
		if(countDouble == 3)
		{
			cout << "Aller_en_prison"<<endl ;
			return 2;	// 2 c'est à dire aller en prison
		}

		if(retValue)
		{
			cout<<"Vous avez un double "<<val_de_1<<":"<<val_de_2<<endl ;
			return 1;    // il a un double
		}

		cout<<"Vous vous deplacez ,ca sera automatiquement"<<endl;                  //vous avez "<<val_de_1<<":"<<val_de_2<<endl ;
		return 0; // pas d'un double un simple déplacement

	}





