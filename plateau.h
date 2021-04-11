#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>

using namespace std ;
class 	plateau {
	_case tab[40] ;
	public:
		plateau(){
			tab[0].set_nom_case("DEPART") ;
			tab[1].set_nom_case("BOULEVARD DE BELLEVILLE") ;
			tab[1]= set_prix_case(60) ;
			tab[2]= set_nom_case(" CAISSE DE COMMUNAUTE") ;
			tab[3]= set_nom_case("RUE LECOURBE") ;
			tab[3]= set_prix_case(60) ;
			tab[4]= set_nom_case("IMPOTS SUR LE REVENU") ;
			tab[4]= set_prix_case(200) ;
			tab[5]= set_nom_case("GARE MONTPARNASSE") ;
			tab[5]= set_prix_case(200) ;
			tab[6]= set_nom_case("RUE DE VAUGIRARD") ;
			tab[6]= set_prix_case(100) ;
			tab[7]= set_nom_case("CHANCE") ;
			tab[8]= set_nom_case("RUE DE COURCELLES") ;
			tab[8]= set_prix_case(100) ;
			tab[9]= set_nom_case("AVENUE DE LA REPUBLIQUE") ;
			tab[9]= set_prix_case(120) ;
			tab[10]= set_nom_case("VISITE SIMPLE") ;
			tab[11]= set_nom_case("BOULEVARD DE LA VILLETTE") ;
			tab[11]= set_prix_case(140) ;
			tab[12]= set_nom_case("COMPAGNIE DE DISTRIBUTION DELECTRICITE") ;
			tab[12]= set_prix_case(150) ;
			tab[13]= set_nom_case("AVENUE DE NEUILLE") ;
			tab[13]= set_prix_case(140) ;
			tab[14]= set_nom_case("RUE DE PARADIS") ;
			tab[14]= set_prix_case(160) ;
			tab[15]= set_nom_case("GARE DE LYON") ;
			tab[15]= set_prix_case(200) ;
			tab[16]= set_nom_case("AVENU MOZART") ;
			tab[16]= set_prix_case(180);
			tab[17]= set_nom_case("CAISSE DE COMMUNAUTE") ;
			tab[18]= set_nom_case("BOULEVARD SAINT-MICHEL") ;
			tab[18]=set_prix_case(180) ;
			tab[19]= set_nom_case("PLACE PIGALLE") ;
			tab[19]= set_prix_case(200) ;
			tab[20]= set_nom_case("PARC GRATUIT") ;
			tab[21]= set_nom_case("AVENU MATEGION") ;
			tab[21]= set_prix_case(220) ;
			tab[22]= set_nom_case("CHANCE") ;
			tab[23]= set_nom_case("BOULEVARD MALESHERBES") ;
			tab[23]= set_prix_case(220) ;
			tab[24]= set_nom_case("AVENUE HENRI-MARTIN") ;
			tab[24]= set_prix_case(240) ;
			tab[25]= set_nom_case("GARE DU NORD") ;
			tab[25]= set_prix_case(200) ;
			tab[26]= set_nom_case("FAUBOURG SAINT-HONORE") ;
			tab[26]= set_prix_case(260) ;
			tab[27]= set_nom_case("PLACE DE LA BOURCE") ;
			tab[27]= set_prix_case(260) ;
			tab[28]= set_nom_case("COMPAGNIE DE DISTRIBUTION DES EAUX") ;
			tab[28]= set_prix_case(150) ;
			tab[29]= set_nom_case("RUE DE LAFAYETTE") ;
			tab[29]= set_prix_case(280) ;
			tab[30]= set_nom_case("EN ALLEZ PRISON") ;
			tab[31]= set_nom_case("AVENUE DE BRETEUILLE") ;
			tab[31]= set_prix_case(300) ;
			tab[32]= set_nom_case("AVENUE POCH") ;
			tab[32]= set_prix_case(300) ;
			tab[33]= set_nom_case("CAISSE DE COMMUNAUTE") ;
			tab[34]= set_nom_case("BOULEVARD DES CAPUCINES") ;
			tab[34]= set_prix_case(320) ;
			tab[35]= set_nom_case("GARRE SAINT-LAZARE") ;
			tab[35]= set_prix_case(200) ;
			tab[36]= set_nom_case("CHANCE") ;
			tab[37]= set_nom_case("AVENUE DES CHAMPS-ELYSEES") ;
			tab[37]= set_prix_case(350) ;
			tab[38]= set_nom_case("TAXE DE LUXE");
			tab[38]= set_prix_case(100) ;
			tab[39]= set_nom_case("RUE DE LA PAIX") ;
			tab[39]= set_prix_case(400) ;


			// on a définit les 40 cases du plateau selon la version choisie !







		}

	~plateau() ; // destricteur

};
#endif //PLATEAU_H
