#include "jeu.h"
#include<iostream>
#include <memory>
using namespace std ;

Jeu::Jeu(vector<Joueur> listJoueur): _listJoueur(listJoueur)
{
}

Jeu::~Jeu()
{
}

void Jeu::handlerNewPosition(Joueur& j)
{
	switch(_plateau.getType(j.getPosition()))
	{
		case 0: //depart
		{
			cout << "Vous etes sur la case de depart , lorsque vous passerez la prochaine vous recevrez 200 euros automatiquement" ;
		}
		break;

		case 1: // visite simple
		{
			cout << "Vous etes sur la case visite simple " << endl;
		}
		break;

		case 2: // parc gratuit
		{
			cout << "Vous etes sur la case parc gratuit " << endl;
		}
		break;

		case 3 : //allez en prison
		{
			cout << "Desole :( vous serez diriger vers le prison ! " << endl;
            if (j.se_liberer(_banque, _listJoueur)==true)
                cout<<"Rassurez-vous, restez sur votre place" << endl;
            else
            {
                j.allez_en_prison ();
            }

		}
		break ;

		case 4: //carte communité
		{
			cout << "Vous etes sur une case de communaute " << endl;
			j.tirer_carte_communaute(_carteCommunaute, _carteChance, _banque, *this);
		}
		break;

		case 5: //carte chance
		{
			cout << "Vous etes sur une case de chance " << endl;
			j.tirer_carte_chance (_carteChance, _banque, *this) ;

		}
		break;

		case 6 :  // Impot sur le revenu ou Taxe de lux
            {
                if(j.getPosition()==4)
                {
                    cout << "Vous etes sur la case IMPOT SUR LE REVENU , vous devez payez 200 euros"<<endl;
                    if(j.get_solde()>200)
                            _banque.recevoir_arg(200 , j ) ;
                    else
                    {
                        j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(200,_banque, _listJoueur);
                        if (j.get_solde()>200)
                        {
                            _banque.recevoir_arg(200 , j ) ;
                        }
                        else
                        {
                            cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<< endl;
                            j.loser(_listJoueur);
                        }
                    }
                }
                else
                {
                    cout << "Vous etes sur la case TAXE DE LUX, vous devez payez 100 euros"<<endl;
                    if(j.get_solde()>100)
                            _banque.recevoir_arg(100 , j ) ;
                    else
                    {
                        j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(100,_banque, _listJoueur);
                        if (j.get_solde()>100)
                        {
                            _banque.recevoir_arg(100 , j ) ;
                        }
                        else
                        {
                            cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<< endl;
                            j.loser(_listJoueur);
                        }
                    }
                }
            }
            break;

		case 7 : //carte terrain
		{
			cout << "Vous etes sur une carte terrain cest "<<(_plateau.get_listeCase()[j.getPosition()]).get_nom_case()<<endl ;
            Joueur* otherPlayer = nullptr;
            list<Carte_terrain*> l=j.getListPossession();

            if(j.isCarteOwner(l, j.getPosition()))
            {

                cout <<"Assurez vous , vous etes sur votre propre case " << endl;
            	if(static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]).get_est_hypotheque ()==false)
            	{
	                if(static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]).get_est_gare()==false
                    && static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]).get_est_compagnie()==false)
                    {
                        string x ;
                        do
                        {
                            cout <<"Est ce que vous voulez construire un maison ? Validez par oui ou non " << endl;
                            cin >> x ;
                            if ((x=="oui") || (x=="OUI"))
                            {
                                 static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]).construire_maison( j ,_banque) ;
                            }
                        }
                        while ((x!="oui") && (x!="OUI") && (x!="non") && (x!="NON"));
                        do
                        {
                            cout <<"Est ce que vous voulez construire un hotel ? Validez par oui ou non" << endl;
                            string x ;
                            cin >> x ;
                            if ((x=="oui") || (x=="OUI"))
                            {
                                 static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]).construire_hotel( j ,_banque) ;
                            }

                        }
                        while ((x!="oui") && (x!="OUI") && (x!="non") && (x!="NON"));
                    }
                    else if (static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]).get_est_gare()==true)
                    {
                        cout <<"Vous etes sur votre gare"<<_plateau.get_listeCase()[j.getPosition()].get_nom_case() << endl;
                        j.traitement_si_je_suis_sur_ma_gare(static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]));
                    }
                    else
                    {
                        cout <<"Vous etes sur votre compagnie "<<_plateau.get_listeCase()[j.getPosition()].get_nom_case() << endl;
                    }
	           	}
	           	else
	           	{
	           		cout<<"Votre carte est hypothequee mais vous la récuperez immédiatement si votre solde est compatible !"<< endl;
	           		j.recuperer_carte_hypotheque(static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]),_banque) ;
				}
			}


            else if (j.isCarteOwnedByOtherPlayer(otherPlayer, _listJoueur, l, j.getPosition(),j.get_nom_joueur()))
            {
                cout <<"Vous etes sur une carte terrain de autre joueur"<<endl ;
            	if (static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]).get_est_hypotheque ()==false)
           		{
		                int som_a_payer=static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]).get_ce_qeu_faut_payer(*otherPlayer);

		                //si j'ai le solde necessaire pour payer le dette

		                if (j.get_solde()>som_a_payer)
		                {
                            j.traitement_si_solde_superieur_a_la_somme_apayer_au_joueur(*otherPlayer ,som_a_payer, _plateau);
						}

		                //si solde inf ou meme egale a la som_a_payer puisque lorsque elle sera egale il ne peut pas continuer à jouer avec solde egale à 0

		                else if ((j.get_solde()<=som_a_payer))
		                {
                            j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(som_a_payer ,_banque, _listJoueur);
                            if (j.get_solde()>som_a_payer)
                            {
                                j.donner_argent(*otherPlayer,som_a_payer);
	                        }
	                        else
                            {
                                cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<< endl;
                                j.loser(_listJoueur);
                            }
			            }
		        }
		        else
                {
                    cout <<"Heureusement"<<j.get_nom_joueur()<<"cette carte est hypothéquee , ne payez rien , joueur suivant "<< endl ;
                }
        	}




			else    //la carte est libre
            {
                cout <<"Cette carte est libre voulez vous l'acheter ? Si oui taper oui sinon tapez non !" << endl;
                string x ;
                do
                    {
                        cin >>x ;
                        if ((x=="oui") || (x=="OUI"))
                        {
                             j.acheter_carte_de_la_banque( static_cast<Carte_terrain&>(_plateau.get_listeCase()[j.getPosition()]),_banque) ;
                        }
                    }
                while ((x!="oui") && (x!="OUI") && (x!="non") && (x!="NON"));
            }
		}
		break;
	}
}

void Jeu::lancerJeu()
{
    //#include <conio.h>
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while(_listJoueur.size() != 1) //condition d'arret du jeux
	{
	    vector <Joueur> :: iterator it;
	    int i = 0;
		for(it=_listJoueur.begin(); it!=_listJoueur.end(); it++, i++)
		{

		    if (!((*it).est_en_prison())|| (*it).get_nbr_tour_en_prison()==3)
            {
                (*it).set_nbr_tour_en_prison(0);
                if(i==0)
                    cout <<endl<<endl<< "Tour du " << i+1 << " er joueur "<<endl;
                else
                {
                    cout <<endl<<endl<< "Tour du " << i+1 << " eme joueur "<<endl;
                }
                cout << "Cliquez sur Entree pour lancer de"<<endl;
                //std::cin.ignore(INT_MAX);
                //std::cin.clear();
                system("pause");
                bool lancer_premier_fois_ok = false;
                bool joueur_non_encore_commence = (0 == (*it).getPosition()) && ((*it).get_a_commence()==false);
                if(joueur_non_encore_commence)    // le joueur n'a pas commencé c'est à dire n'a pa eu un double
			    {
                    if((lancer_premier_fois_ok = d.lancer_premiere_fois()))
                        {
                            (*it).se_deplacer(d,_banque);
                            handlerNewPosition(*it);
                            (*it).set_a_commence(true);

                        }
                    else
                        {
                            (*it).set_a_commence(false);
                            cout << "Joueur suivant"<<endl<<endl;
                        }
			    }

			    if((!joueur_non_encore_commence) || (lancer_premier_fois_ok))
                {
                    bool repeat = true;
                    while (repeat)
                    {
                        if(lancer_premier_fois_ok)
                        {
                            cout << "Vous avez deja un double. Relancer de ?"<<endl;
                            system("pause");
                        }

                        switch(d.relancer())
                        {
                            case 0: //simple
                               {
                                    (*it).se_deplacer(d,_banque);
                                    handlerNewPosition(*it);
                                    repeat = false;
                               }
                                break;
                            case 1:	//double
                                {
                                    (*it).se_deplacer(d,_banque);
                                    handlerNewPosition(*it);
                                    lancer_premier_fois_ok = false;
                                    cout << "Vous avez un double. Relancer de ?"<<endl;
                                    system("pause");
                                }
                                break;
                            case 2: //3 double consecutive
                                 {
                                     if ((*it).se_liberer(_banque, _listJoueur)==true)
                                      {
                                         cout<<"Rassurez-vous, restez sur votre place "<<endl;
                                      }
                                     else
                                      {
                                         (*it).allez_en_prison() ;
                                      }
                                      repeat = false;
                                 }
                                 break;
                            default:
                                repeat = false;
                                cout << "C'est pas votre tour il se peut"<<endl ;
                                break;
                        }
                    }

                }
		     }
		     else
            {
                    cout<<"Restez en prison ,il vous reste monsieu "<<(*it).get_nom_joueur()<< 3-(*it).get_nbr_tour_en_prison()<<endl;
                    (*it).set_nbr_tour_en_prison((*it).get_nbr_tour_en_prison()+1);
            }

             d.set_countDouble(0);
	  }

    }
}


