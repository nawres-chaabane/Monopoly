#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include "case.h"
#include"carte_terrain.h"

using namespace std ;

class Plateau
{
    private:
        Case listeCase[40] ;

	public:

    Plateau() ;

	~Plateau() ;

	int getType(int);

	Case* get_listeCase() ;

	//Case listeCase[40] ;

};
#endif
