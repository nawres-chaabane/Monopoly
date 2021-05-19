#include <iostream>
#include <list>

#include"carte_terrain.h"
#include "joueur.h"

using namespace std ;

    Carte_terrain ::Carte_terrain ( int pos ,string nom, int prix ,string col ,int nmc,int pm , int nhc, int ph,
                                   int h,int a ,int b,int c ,int d , int e , int f ,bool eg ,bool ec): Case(pos , nom , prix)
         {
         couleur =col ;
         nbre_maison_construit =nmc;
         prix_maison=pm ;
         nbre_hotel_construit=nhc;
         prix_hotel =ph;
         taux_hypotheque=h ;
         prix_a_payer_avec_0_maison =a;
         prix_a_payer_avec_1_maison =b;
         prix_a_payer_avec_2_maison =c;
         prix_a_payer_avec_3_maison =d;
         prix_a_payer_avec_4_maison =e;
         prix_a_payer_avec_1_hotel =f ;
         est_gare=eg ;
         est_compagnie=ec;
         est_hypotheque=false ;
        }

    Carte_terrain ::~Carte_terrain(){}

    bool Carte_terrain :: get_est_gare()
    {
        return est_gare;
    }

    bool Carte_terrain :: get_est_compagnie()
    {
        return est_compagnie;
    }

	int Carte_terrain :: get_taux_hypotheque() const
	{
		return taux_hypotheque ;
	}



	string Carte_terrain :: get_couleur() const
	{
		return couleur ;
	}

	void Carte_terrain:: set_est_hypotheque (bool a)
	{
		 est_hypotheque=a ;
	}

	int Carte_terrain :: get_prix_maison() const
	{
		return prix_maison ;
	}

	int Carte_terrain :: get_prix_hotel() const
	{
		return prix_hotel ;
	}

	int Carte_terrain :: get_nbre_maison_construit() const
	{
	    return nbre_maison_construit ;
	}

    int Carte_terrain :: get_nbre_hotel_construit() const
    {
        return nbre_hotel_construit ;
    }


    int Carte_terrain :: get_prix_a_payer_avec_0_maison() const
    {
        return prix_a_payer_avec_0_maison ;
    }

    int Carte_terrain :: get_prix_a_payer_avec_1_maison() const
    {
        return prix_a_payer_avec_1_maison ;
    }

    int Carte_terrain :: get_prix_a_payer_avec_2_maison() const
    {
        return prix_a_payer_avec_2_maison ;
    }

    int Carte_terrain :: get_prix_a_payer_avec_3_maison() const
    {
        return prix_a_payer_avec_3_maison ;
    }

    int Carte_terrain :: get_prix_a_payer_avec_4_maison() const
    {
        return prix_a_payer_avec_4_maison ;
    }

    int Carte_terrain :: get_prix_a_payer_avec_1_hotel() const
    {
        return prix_a_payer_avec_1_hotel ;
    }

	bool Carte_terrain :: avoir_toute_la_plage_colore(Joueur & j ,string col )    // verifier si le joueur possede tous les terrains de meme couleur
	{
		int compte_meme_col =0 ;
		list <Carte_terrain*>:: iterator it ;
		if(!j.getListPossession().empty())
        {
            for (it =j.getListPossession().begin() ; it !=j.getListPossession().end(); it++)
            {
                if ((*it)->couleur == col)
                {

                    compte_meme_col++ ;
                }
            }
        }


		if ((compte_meme_col==3) || ((compte_meme_col==2) && (col =="Marron"||col=="bleu fonce")))
		{
			return true ;
		}
        return false;
	}


	void Carte_terrain :: construire_maison( Joueur &j , Banque& banque)
	{
		bool test1=false ;    //si les cartes tesrrain de meme couleur possede le meme nombre de maison construit elle sera true
		if (nbre_maison_construit <4)
		{
			if(avoir_toute_la_plage_colore(j,couleur))          //joueur a toute la plage
		    {
				list <Carte_terrain*>:: iterator it ;

				if(!j.getListPossession().empty())
                {
                    for (it =j.getListPossession().begin() ; it !=j.getListPossession().end(); it++)
                    {
                        if ((*it)->couleur == couleur)
                        {
                            if ((*it)->nbre_maison_construit == nbre_maison_construit)
                            {
                                 test1 =true ;
                            }

                            else
                            {
                                cout<< "Il faut avoir le meme nbre de maison construits par case"<<endl ;
                                test1=false ;
                                break ;    //verifier
                            }
                        }
                    }
                }
                if((nbre_maison_construit ==0) || test1)
                {
                        nbre_maison_construit ++ ;
                        banque.recevoir_arg(prix_maison, j) ;
                        banque.set_nb_maisons(banque.get_nb_maisons()-1);
                }
			 }

		}

		else  // vous atteind 4 maison par carte !
		{
			cout<<"vous pouvez maintenant construire un hotel" ;
		}
	}



	void Carte_terrain :: construire_hotel (Joueur &j ,Banque& banque)
	{
		if ((nbre_maison_construit ==4) && (nbre_hotel_construit==0))
		{
			nbre_hotel_construit ++ ;
			banque.recevoir_arg(prix_hotel, j) ;
			banque.set_nb_hotels(banque.get_nb_hotels()-1);
		}
		else if (nbre_hotel_construit!=0)
		{
			cout << "Vous ne pouvez construire qu'un seul hotel !"<<endl ;
		}
		else if(nbre_maison_construit !=4)
        {
            cout << "Vous ne pouvez construire un hotel que si vous atteignez 4 maisons construites !"<<endl ;
        }
	}


	int Carte_terrain :: get_ce_qeu_faut_payer(Joueur & j)
	{
	    if(est_compagnie==false && est_gare==false)
        {
            switch (nbre_maison_construit)
            {
                case 0:
                    if (avoir_toute_la_plage_colore(j ,couleur ))   //j joueur qui joue maintenant
                    {
                        return (2*prix_a_payer_avec_0_maison);   // c'est une remarque sur chaque carte terrain
                    }
                    else
                        return  prix_a_payer_avec_0_maison  ;
                case 1 :
                    return prix_a_payer_avec_1_maison ;
                case 2 :
                    return prix_a_payer_avec_2_maison ;
                case 3 :
                    return prix_a_payer_avec_3_maison ;
                case 4 :
                    return prix_a_payer_avec_4_maison ;
                default :
                    return prix_a_payer_avec_1_hotel ;      // si non pour tout ce qui précede donc il a construit un hotel
            }
        }
        else if (est_gare==true)
        {
            int nbre_gare=1 ;
            list <Carte_terrain*> :: iterator it ;
            if(!j.getListPossession().empty())
            {
                for (it=j.getListPossession().begin();it!=j.getListPossession().end() && (*it)->get_nom_case()!=get_nom_case();it++)
                {
                    if ((*it)->get_est_gare()==true)
                    {
                        nbre_gare++;
                    }
                }
            }

            return nbre_gare*25 ;
        }
        else
        {
            int nbre_compagnie=1 ;
            list <Carte_terrain*> :: iterator it ;
            if(!j.getListPossession().empty())
            {
                for (it=j.getListPossession().begin();it!=j.getListPossession().end() && (*it)->get_nom_case()!=get_nom_case();it++)
                {
                    if ((*it)->get_est_compagnie()==true)
                    {
                        nbre_compagnie++;
                    }
                }
            }

            if(nbre_compagnie==1)
            {
                return 28 ;
            }
            else
            {
                return 70;
            }
        }
	}

	bool Carte_terrain::get_est_hypotheque () const
	{
	    return est_hypotheque;
	}

