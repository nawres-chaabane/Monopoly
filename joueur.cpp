#include "joueur.h"
#include<string>
#include <vector>
#include<iostream>
using namespace std ;

        int Joueur ::   nbre_tir_carte_chance  =0 ;
		int Joueur ::   nbre_tir_carte_communaute  =0;

		Joueur :: Joueur(string ch ) : nom_joueur(ch) ,position_joueur(0),nbre_possession_carte(0), solde(1500), nbr_tour_en_prison(0),
                                                                                            a_commence(false), avoir_carte_libre_prison_chance(false),
                                                                                            avoir_carte_libre_prison_communite(false)
         {
         }

        Joueur ::~Joueur(){}

		int Joueur :: getPosition() const
		{
			return position_joueur;
		}

		void Joueur :: setPosition(int pos)
		{
			position_joueur=pos ;
		}

		list<Carte_terrain*> Joueur::getListPossession() const
		{
		    return list_possession;
		}

		bool Joueur::isCarteOwner( list <Carte_terrain*>& l, int pos)
		{
		    list <Carte_terrain*>:: iterator it;
		    if(!l.empty())
            {
                for (it= l.begin() ; it != l.end(); it++)
                {
                    if ((*it)->get_pos_case()== pos)
                    {
                        return true;
                    }
                }
            }

			return false;
		}


		bool Joueur::isCarteOwnedByOtherPlayer (Joueur* otherPlayer, vector <Joueur>& listJoueur, list <Carte_terrain*>& l, int pos, std::string nom)
		{
               vector <Joueur>:: iterator iter ;
               otherPlayer = nullptr;

				for (iter=listJoueur.begin() ; iter!= listJoueur.end() ;iter++)
				{
				    if(((*iter).get_nom_joueur() != nom ))
                    {
                        list <Carte_terrain*>:: iterator it ;
                        if(!l.empty())
                        {
                            for (it = l.begin() ; it!= l.end(); it++)
                            {
                                if ( (*it)->get_pos_case()== pos )
                                {
                                    otherPlayer = &(*iter); //std::pointer_from(iter);
                                    return true;
                                }
                            }
                        }
                    }

				}

				return false;
		}

		int Joueur :: get_solde()
		{
			return solde ;
		}

		void Joueur :: set_solde(int a)
		{
			solde=a;
		}

		string Joueur :: get_nom_joueur()
		{
			return nom_joueur ;
		}


        void Joueur :: acheter_carte_de_la_banque(Carte_terrain &cr , Banque& banque)
        {
			if ((solde>= cr.get_prix_case()) && (cr.get_pos_case()==position_joueur))
            {
                banque.recevoir_arg(cr.get_prix_case() , *this) ;
                list_possession.push_back(&cr) ;
                if (list_possession.size()!=0)
                {
                    list <Carte_terrain*> :: iterator it ;
                    cout <<"Ceci est une liste de vos possessions monsieur "<<nom_joueur<<" :"<<endl;
                    for(it=list_possession.begin() ; it!=list_possession.end() ; it++)
                    {
                        cout<<" -"<<(*it)->get_nom_case()<<endl;
                    }
                }
                nbre_possession_carte ++ ;
            }
        }

		void Joueur::acheter_toute_la_plage_de_couleur(Carte_terrain& cr, Joueur& j,int prix_demande)   //courant va acheter de j
		{
		    cout <<"Cette carte terrain appartient a une plage de couleur ou il y a des maisons construites Voulez-vous achetez toutes la plage a "<< prix_demande<<"?";
		    string x;
		    cin>>x;
		    if((x=="oui" || x=="OUI") && solde>prix_demande)
		    {
		        list <Carte_terrain*>:: iterator iter ;
		        j.solde+=prix_demande ;
                solde-=prix_demande;
		        for (iter=j.list_possession.begin() ; iter!=j.list_possession.end() ; iter++)
                {
                    if ((*iter)->get_couleur()==cr.get_couleur() )
                    {
                        j.list_possession.erase (iter) ;
                        j.nbre_possession_carte -- ;
                        list_possession.push_back(&cr) ;
                        nbre_possession_carte ++ ;
                    }

                }
                if (list_possession.size()!=0)
                {
                    list <Carte_terrain*> :: iterator it ;
                    cout <<"Ceci est une liste de vos possessions monsieur "<<nom_joueur<<" :"<<endl;
                    for(it=list_possession.begin() ; it!=list_possession.end() ; it++)
                    {
                        cout<<" -"<<(*it)->get_nom_case()<<endl;
                    }
                }
                if (j.list_possession.size()!=0)
                {
                    list <Carte_terrain*> :: iterator it ;
                    cout <<"Ceci est une liste de vos possessions monsieur "<<j.nom_joueur<<" :"<<endl;
                    for(it=j.list_possession.begin() ; it!=j.list_possession.end() ; it++)
                    {
                        cout<<" -"<<(*it)->get_nom_case()<<endl;
                    }
                }
		    }
		    else
                cout <<"L_operation nest pas effectuee a cause d_un refus ou manque de solde de "<<nom_joueur;
		}


        void Joueur :: acheter_carte_du_joueur(Carte_terrain &cr, Joueur &j,int prix_demande )   //dans le cas normal mais si otherPlayer n'a pas de maison ou hotel construit
		{
            cout <<" Voulez-vous achetez la carte à :"<< prix_demande<<"?";
		    string x;
		    cin>>x;
            if((x=="oui" || x=="OUI") && solde> prix_demande)
            {
                if (solde> prix_demande)
                {
                    j.solde+=prix_demande ;
                    solde-=prix_demande;
                    list_possession.push_back(&cr) ;
                    j.nbre_possession_carte -- ;
                    nbre_possession_carte ++ ;
                    list <Carte_terrain*>:: iterator iter ;
                    for ( iter=j.list_possession.begin() ; iter!=j.list_possession.end() ; iter++)
                    {
                        if ((*iter)->get_nom_case()==cr.get_nom_case() )
                        {
                            j.list_possession.erase (iter) ;
                        }
                    }
                }
                if (list_possession.size()!=0)
                {
                    list <Carte_terrain*> :: iterator it ;
                    cout <<"Ceci est une liste de vos possessions monsieur "<<nom_joueur<<" :"<<endl;
                    for(it=list_possession.begin() ; it!=list_possession.end() ; it++)
                    {
                        cout<<" -"<<(*it)->get_nom_case()<<endl;
                    }
                }
                if (j.list_possession.size()!=0)
                {
                    list <Carte_terrain*> :: iterator it ;
                    cout <<"Ceci est une liste de vos possessions monsieur "<<j.nom_joueur<<" :"<<endl;
                    for(it=j.list_possession.begin() ; it!=j.list_possession.end() ; it++)
                    {
                        cout<<" -"<<(*it)->get_nom_case()<<endl;
                    }
                }
            }
            else
                cout <<"L_operation nest pas effectuee a cause d_un refus ou manque de solde de "<<nom_joueur;
		}


		void Joueur :: se_deplacer ( De& d, Banque& banque )
		{
			position_joueur += d.somme() ;
			if (position_joueur > 39  )
			{
				position_joueur -= 40 ;
				banque.donner_arg(200,*this) ;
			}
		}

		void Joueur :: tirer_carte_chance (Carte_chance& cc, Banque& banque, Jeu& jeu)
		{
		    if(cc.statusCarteLibererPrison())
            {
                nbre_tir_carte_chance ++;
            }
			cc.traiter_carte_chance (*this ,banque, jeu, nbre_tir_carte_chance ++  ) ;
			if ( nbre_tir_carte_chance > 15 )
				{
                    nbre_tir_carte_chance = 0;    // elle est statique
				}

		}

		void Joueur :: tirer_carte_communaute (Carte_communaute& cr, Carte_chance& cc, Banque& banque, Jeu& jeu)
		{
            if(cr.statusCarteLibererPrison())
            {
                nbre_tir_carte_communaute ++;
            }
			cr.traiter_carte_communaute ( *this ,banque,nbre_tir_carte_communaute ++, cc, jeu) ;
            if (nbre_tir_carte_communaute > 15)
			{
				nbre_tir_carte_communaute = 0;
			}
		}

	    void Joueur :: donner_argent(Joueur &j , int somme){       // dans le cas d'une tombé sur une possession d'un autre Joueur
			j.solde+=somme ;
			solde-=somme ;
			cout<<"Monsieur "<<nom_joueur <<"vous avez donne une somme de :"<<somme<<" a monsieur " <<j.nom_joueur<<endl ;
		}

    	void Joueur :: recevoir_argent(Joueur &j , int somme){
			j.solde-=somme ;
			solde+=somme ;
			cout<<"Monsieur vous avez recevoir une somme de :"<<somme<<" de monsieur " <<j.nom_joueur<<endl ;
		}


		void Joueur :: allez_en_prison (){

			position_joueur=10 ;
		}

		bool Joueur::est_en_prison()
		{
		   if (10 == position_joueur)
           {
               return true;
           }
           return false;
		}
		void Joueur :: hypothequer(Carte_terrain& cr,Banque& b)
		{
			cr.set_est_hypotheque(true) ;
			b.donner_arg(cr.get_taux_hypotheque(),*this) ;

		}

		void Joueur :: recuperer_carte_hypotheque(Carte_terrain& cr,Banque& b)
		{
			cr.set_est_hypotheque(false) ;
			b.recevoir_arg(cr.get_taux_hypotheque()+0.1*cr.get_taux_hypotheque(),*this) ;

		}


		void Joueur::loser(vector <Joueur>& listJoueur)
		{
			if (list_possession.size()!=0)
			{
				list <Carte_terrain*>:: iterator iter ;
				for(iter=list_possession.begin() ; iter!=list_possession.end() ; iter++)       //question est ce ce lors de la suppression dans la boucle for le size de la liste va etre à jour ?
				{
					(*iter)->set_est_hypotheque(false);
					list_possession.erase(iter);
				}
			}
            vector <Joueur>:: iterator it ;
            for( it=listJoueur.begin() ; it!=listJoueur.end() ; it++)
            {
                if ((*it).nom_joueur==nom_joueur)
                {
                    listJoueur.erase(it);
                }
            }

		}

        int Joueur::get_nbre_possession_carte()
		{
        	return nbre_possession_carte;
		}

		bool Joueur::get_a_commence() const
		{
			return a_commence ;
		}

		void Joueur::set_a_commence(bool a)
		{
			a_commence=a;
		}

		int Joueur::get_nbre_maison_du_joueur_plage(string col)    // retourner le nombre totale de maison construit dans le meme couleur
		{
			int nbre_maison_du_joueur_plage =0 ;
			list <Carte_terrain*>:: iterator it ;
			for (it =list_possession.begin(); it !=list_possession.end(); it ++)
			{
				if ((*it)->get_couleur() == col)
				{
					nbre_maison_du_joueur_plage+=(*it)->get_nbre_maison_construit() ;
				}
			}
			return nbre_maison_du_joueur_plage ;
		}

		void Joueur::traitement_si_solde_superieur_a_la_somme_apayer_au_joueur(Joueur & j ,int som_a_payer, Plateau plateau)
		{
		    //demander est-ce-que vous voulez acheter la carte de otherPlayer si otherPlyer accepte !! sinon il pait ce quil faut payer
            cout << "Est ce que vous voulez acheter la carte terrain si l_autre joueur accepte ?";
            string x ;
            cin >> x ;
            if (((x=="oui") || (x=="OUI"))&& j.get_nbre_maison_du_joueur_plage(static_cast<Carte_terrain&>(plateau.get_listeCase()[j.getPosition()]).get_couleur())==0)
            {
                 cout << j.nom_joueur <<"vous accepter de vendre cette carte ? si oui donner le montant desire ";
                 string y ;
                 int prix ;
                 cin >>y ;
                 cin >>prix ;
                 if((y=="oui" || y=="OUI") && prix>plateau.get_listeCase()[position_joueur].get_prix_case())
                 {
                    cout << j.nom_joueur<<"Est ce que vous acceptez d_acheter cette carte a ce prix :"<<prix ;
                    string z ;
                    cin >>z ;
                    if((z=="oui") || (z=="OUI"))
                    {
                        acheter_carte_du_joueur(static_cast<Carte_terrain&>(plateau.get_listeCase()[getPosition()]),j,prix);
                    }
                    else
                        donner_argent(j,som_a_payer);
                 }
            }
            else  // non ou NON c'est à dire le joueur courant juste pay ce qu'il doit payer au joueur qui possède la carte
            {
                donner_argent(j,som_a_payer);
            }
		}


         void Joueur::traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(int som_a_payer , Banque& banque, vector <Joueur>& listJoueur)
            {
                cout<<get_nom_joueur()<<"Vous etes oblige d'hpothequer ou bien vendre quelques une de vos possessions , vous ecriverez a chaque fois pour chaque carte vendre ou hypotheque jusqu_a atteindre la somme " ;

                while(solde<=som_a_payer && nbre_possession_carte!=0 )
                {
                    list <Carte_terrain*> ::iterator it ;
                    for(it= list_possession.begin();it!=list_possession.end();it++)
                    {
                        cout<<"Voulez-vous hypothequez ou vendez cette carte"<<(*it)->get_nom_case() <<" ?";
                        string x ; cin>>x;
                        if(x=="hypotheque")
                        {
                                hypothequer(*(*it),banque);
                        }
                        else if(x=="vendre")
                        {
                            //bool carte_vendu=false;
                            cout<<"Un tour de table va etre lieu pour vendre "<<(*it)->get_nom_case();
                            cout<<nom_joueur<<"Donnez le prix désiré pour vendre la carte "<<(*it)->get_nom_case();
                            int prix; cin>>prix ;
                            vector <Joueur> ::iterator joueur ;
                            for (joueur=listJoueur.begin();joueur!=listJoueur.end();joueur++)
                            {
                                if(get_nbre_maison_du_joueur_plage((*it)->get_couleur())==0)
                                    {
                                        (*joueur).acheter_carte_du_joueur(*(*it),*this,prix);   //la validation du joueur est assurée dans la methode
                                    }
                                else
                                {
                                    cout<<nom_joueur<<"Attention il ya des maisons sur la plage de couleur "<<(*it)->get_couleur()<<". Validez par oui et donnez le prix désiré pour toute la plage si c'est le cas d'une acceptation ";
                                    string valid ; int prix2 ; cin>>valid ; cin>>prix2 ;
                                    if(valid=="oui")
                                        (*joueur).acheter_toute_la_plage_de_couleur(*(*it),*this,prix2); //la validation du joueur est assurée dans la methode
                                }
                            }
                        }
                    }
                }
            }



		bool Joueur::avoir_carte_libere_de_prison()
		{
            return (avoir_carte_libre_prison_chance || avoir_carte_libre_prison_communite);
		}

        bool Joueur::possede_carte_libere_de_prison_chance()
		{
            return (avoir_carte_libre_prison_chance);
		}

        bool Joueur::possede_carte_libere_de_prison_communite()
		{
            return (avoir_carte_libre_prison_communite);
		}

		void Joueur::set_carte_libere_de_prison_chance(bool val)
		{
		    avoir_carte_libre_prison_chance = val;
		}

		void Joueur::set_carte_libere_de_prison_communite(bool val)
		{
            avoir_carte_libre_prison_communite = val;
		}



        int Joueur:: get_nbr_tour_en_prison()
        {
            return nbr_tour_en_prison;
        }

		void Joueur::set_nbr_tour_en_prison(int nb)
		{
		    nbr_tour_en_prison=nb;
        }

        bool Joueur::se_liberer(Banque& banque, vector <Joueur>& listJoueur)
        {
                cout<<"Vous avez 3 choix pour sortir du prison!"<<endl;
                cout <<"C_est le 1 choix si vous accepter de payer la banque 50 euros"<<endl;
                if(solde>50)
                {
                    cout<<"Vous avez assez d'argent pour payer une amende de 50 euros a la banque le tour suivant acceptez vous ce choix?"<<endl;
                    string x;
                    cin>>x;
                    if ((x=="oui") || (x=="OUI"))
                    {
                        banque.recevoir_arg(50, *this);
                        cout<<"c'est bon, attendez le tour suivant pour jouer"<<endl;
                        return true;
                    }
                    else
                        cout<<"Passez au choix suivant!"<<endl;
                }
                cout <<"C_est le 2 choix d_avoir une carte qui vous libere du prison , si vous l_avait vous sortez directement "<<endl;
                if( avoir_carte_libere_de_prison() )
                {
                    if(possede_carte_libere_de_prison_chance())
                    {
                        set_carte_libere_de_prison_chance(false);
                        Carte_chance::carteLibererPrisonUtilisee = false;       //attribut statique
                    }
                    else
                    {
                        set_carte_libere_de_prison_communite(false);
                        Carte_communaute::carteLibererPrisonUtilisee = false; //attribut statique
                    }
                    cout<<"Quelle chance! vous pouvez vous en sortir automatiquement!";
                    return true ;
                }
                else
                {
                    cout <<"C_est le 3 choix d_acheter une carte si quelqun la possede et accepte de la vendre"<<endl;
                    vector <Joueur>:: iterator iter ;
                    for (iter= listJoueur.begin() ; iter!= listJoueur.end() ;iter++)
                    {
                      if((*iter).avoir_carte_libere_de_prison())
                      {
                        cout<<(*iter).nom_joueur<<"voulez vous vendre votre carte a "<<nom_joueur<<"?";
                        string rep;
                        cin>>rep;
                        if(((rep=="oui") || (rep=="OUI")) )
                        {
                            cout<<"Entrez le prix que vous proposez";
                            int pr;
                            cin>>pr;
                            if(solde>pr)
                            {
                                cout<<nom_joueur<<"Ce prix vous semble-t-il convenable?";
                                string rep1;
                                cin>>rep1;
                                if ((rep1=="oui") || (rep1=="OUI"))    //il faut que le solde soit >pr
                                {
                                    donner_argent((*iter),pr);
                                    if((*iter).possede_carte_libere_de_prison_chance())
                                    {
                                        (*iter).set_carte_libere_de_prison_chance(false);
                                        Carte_chance::carteLibererPrisonUtilisee = false;
                                    }
                                    else
                                    {
                                        (*iter).set_carte_libere_de_prison_communite(false);
                                        Carte_communaute::carteLibererPrisonUtilisee = false;
                                    }
                                    return true;
                                }
                                cout << "Prix inconvenable !"<<endl;
                            }
                            else
                            {
                                cout << "Prix superieur à votre solde !"<<endl;
                            }
                        }
                        cout << "Joueur "<< (*iter).nom_joueur << " refuse de vendre sa carte"<<endl;

                      }
                    }
                    cout <<"Dommage :( aucun des 3 choix n_est verifie pour vous liberer du prison  "<<endl;

                    return false;
                }
        }


        void Joueur :: traitement_si_je_suis_sur_ma_gare(Carte_terrain &c)
        {
            bool test=false ;
            list <Carte_terrain*> :: iterator it ;
            for (it=list_possession.begin();it!=list_possession.end() && (*it)->get_nom_case()!=c.get_nom_case();it++)
            {
                if ((*it)->get_est_gare()==true)
                {
                    test=true;
                    cout <<"Voulez-vous se déplacer vers votre  gare "<<(*it)->get_nom_case()<<"?"<<endl;
                    string x ; cin>>x ;
                    if (x=="oui" || x=="OUI")
                    {
                        setPosition((*it)->get_pos_case());
                    }
                }
            }
            if (test==false)
            {
                cout<<"Vous avez que cette gare "<<c.get_nom_case()<<" restez sur cette position"<<endl;
            }

        }







