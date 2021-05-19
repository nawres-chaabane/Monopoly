#include"Case.H"
#include<iostream>
using namespace std ;

    Case :: Case(int pos ,string nom, int prix )
    {
        nom_case=nom;
        prix_case = prix ;
        position_case = pos ;

    }

   int Case :: get_pos_case ()
    {
        return position_case ;
    }

    int Case :: get_prix_case ()
    {
        return prix_case ;
    }

    string Case :: get_nom_case()
    {
        return nom_case;
    }

    void Case :: set_nom_case (string ch ){
        nom_case=ch ;
    }

    void Case :: set_prix_case (int a)
    {
        prix_case=a ;
    }



