#ifndef CASE_H	
#define CASE_H	
#include <iostream>

using namespace std ;

class _case {
	string nom_case ; // pour les 40 cases du plateau 
	int prix_case ; 
	public :
		_case(string nom = "" , int a =0){
			nom_case=nom;
			prix_case=a ;
			
		}
		void set_nom_case (string ch ){
			nom_case=ch ;
		}
		void set_prix_case (int a ){
			prix_case=a ;
		}
};
#endif //CASE_H
