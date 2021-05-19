#ifndef CASE_H
#define CASE_H
#include <iostream>

using namespace std ;

class Case
{

	protected :
		int position_case ;
		string nom_case ; // pour les 40 cases du plateau
		int prix_case ;

	public :
		Case(int pos =0 ,string nom = "AucunNom", int prix=0 );

		int get_pos_case() ;

		int get_prix_case() ;

        string get_nom_case() ;

		void set_prix_case(int) ;

		void set_nom_case (string  ) ;

};

#endif
