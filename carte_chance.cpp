#include <iostream>
#include "carte_chance.h"
#include "banque.h"
#include "joueur.h"
using namespace std ;

bool Carte_chance::carteLibererPrisonUtilisee = false;

Carte_chance::Carte_chance()
{
}

Carte_chance::~Carte_chance()
{
}

bool Carte_chance ::statusCarteLibererPrison()
{
    return carteLibererPrisonUtilisee;
}

void Carte_chance :: traiter_carte_chance(Joueur& j,Banque& banque, Jeu& jeu, int num_carte=0)
{

    switch (num_carte)
    {

    /* ces 3 cartes vous recevez amende de la banque*/
    case 0 :
      {
            cout << "Votre immeuble et votre pret rapportent vous devez toucher 150 euros"<<endl;
            banque.donner_arg(150 ,j ) ;
      }
      break;
    case 1 :
       {
            cout << "Vous avez gagné le prix de mots croises recevez 100 euros"<<endl;
            banque.donner_arg(100, j ) ;
       }
       break;
    case 2:
      {
            cout << "La banque vous verse un dividence de 50 euros"<<endl;
            banque.donner_arg(50,j ) ;
      }
      break;

    /*ces 4 cartes visitez une case et recevez 20 si eciste depart*/

    case 3:
        {
            cout << "Allez à la gare GARE DE LYON et si vous passez par la case depart recevez 200 euros"<<endl;
            if (j.getPosition()>15)
            {
                j.setPosition(15);
                banque.donner_arg(200 , j);
            }
            else
            {
                j.setPosition(15);
            }
            cout <<"Monsieur "<<j.get_nom_joueur()<<" votre nouvelle position est "<<j.getPosition()<<endl;
            jeu.handlerNewPosition(j);
        }
        break;
    case 4:
        {
            cout << "Rendez vous au BOULEVARD MALESHERBES et si vous passez par la case depart recevez 200 euros"<<endl;
            if (j.getPosition()>23)
            {
                j.setPosition(23);
                banque.donner_arg(200, j);
            }
            else
            {
                j.setPosition(23);
            }
            cout <<"Monsieur "<<j.get_nom_joueur()<<" votre nouvelle position est "<<j.getPosition()<<endl;
            jeu.handlerNewPosition(j);
        }
        break;
    case 5:
        {
            cout << "Avancez à AVENUE DE NEUILLY et si vous passez par la case depart recevez 200 euros"<<endl;
            if (j.getPosition()>13)
            {
                j.setPosition(13);
                banque.donner_arg(200 ,j);
            }
            else
            {
                j.setPosition(13);
            }
            cout <<"Monsieur "<<j.get_nom_joueur()<<" votre nouvelle position est "<<j.getPosition();
            jeu.handlerNewPosition(j);
        }
        break;
    case 6:
        {
            cout << "Avancez à AVENUE FOCH si vous passez par la case depart recevez 200 euros"<<endl;
            if (j.getPosition()>32)
            {
                j.setPosition(32);
                banque.donner_arg(200,j);
            }
            else if(j.getPosition()<32)
            {
                j.setPosition(32);
            }
            cout <<"Monsieur "<<j.get_nom_joueur()<<" votre nouvelle position est "<<j.getPosition();
            jeu.handlerNewPosition(j);
        }

        break;

    /*ces 3 cartes vous devez payez la banque une somme dc presque le meme code*/

    case 7:
        {
            cout << "Vous avez une amende pour ivresse 20 euros"<<endl;
            if(j.get_solde()>20)
                banque.recevoir_arg(20, j ) ;
            else
            {
                j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(20,banque, jeu._listJoueur);
                if (j.get_solde()>20)
                {
                    banque.recevoir_arg(20 , j ) ;
                }
                else
                {
                    cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<<endl;
                    j.loser(jeu._listJoueur);
                }
            }
        }
        break;
    case 8:
        {
            cout << "Vous avez une amende pour exes de vitesse 15 euro"<<endl;
            if(j.get_solde()>15)
                banque.recevoir_arg(15 , j ) ;
            else
            {
                j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(15,banque,jeu._listJoueur);
                if (j.get_solde()>15)
                {
                    banque.recevoir_arg(15, j ) ;
                }
                else
                {
                    cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<<endl;
                    j.loser(jeu._listJoueur);
                }
            }
        }
        break;
    case 9:
        {
            cout << "Payez pour frais de scolarite 150 euros "<<endl;
            if(j.get_solde()>150)
            {
                banque.recevoir_arg(150 , j ) ;
            }

            else
            {
                j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(150,banque, jeu._listJoueur);
                if (j.get_solde()>150)
                {
                    banque.recevoir_arg(150, j ) ;
                }
                else
                {
                    cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<<endl;
                    j.loser(jeu._listJoueur);
                }
            }
        }
        break;

    /*ces 2 cartes : si  y a des maisons ou des hotels seulement sinon tu remets la carte au dessous*/

    case 10:
        {
            cout << "vous payer pour les reparations de voirie à raison de 40 euros  par maison et 115 euros  par hotel"<<endl;
            list <Carte_terrain*> :: iterator iter ;
            int som_maison=0;
            int som_hotel=0;
            if(!j.getListPossession().empty())
            {
                for (iter=j.getListPossession().begin(); iter!=j.getListPossession().end();iter ++)
                {
                    som_maison+=(*iter)->get_nbre_maison_construit();
                    som_hotel+=(*iter)->get_nbre_hotel_construit();

                }
            }
            int som_totale=40 * som_maison+115* som_hotel;
            if(j.get_solde()>som_totale)
                banque.recevoir_arg(som_totale , j ) ;
            else
            {
                j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(som_totale,banque, jeu._listJoueur);
                if (j.get_solde()>som_totale)
                {
                    banque.recevoir_arg(som_totale , j ) ;
                }
                else
                {
                    cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<<endl;
                    j.loser(jeu._listJoueur);
                }
            }
        }
        break;
    case 11:
        {
            cout << "Faites des reparations dans toutes vos maisons et versez pour chaque maison 25 et chaque hotel 100"<<endl;
            list <Carte_terrain*> :: iterator iter ;
            int som_maison=0;
            int som_hotel=0;
            if(!j.getListPossession().empty())
            {
                for (iter=j.getListPossession().begin(); iter!=j.getListPossession().end();iter ++)
                {
                    som_maison+=(*iter)->get_nbre_maison_construit();
                    som_hotel+=(*iter)->get_nbre_hotel_construit();

                }
            }

            int som_totale=25 * som_maison+100* som_hotel;
            if(j.get_solde()>som_totale)
                banque.recevoir_arg(som_totale , j ) ;
            else
            {
                j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(som_totale,banque, jeu._listJoueur);
                if (j.get_solde()>som_totale)
                {
                    banque.recevoir_arg(som_totale , j ) ;
                }
                else
                {
                    cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<<endl;
                    j.loser(jeu._listJoueur);
                }
            }
        }
        break;
    case 12:
       {
            cout << "Allez en prison directement! ne franchissez pas la case depart ! ne collectez pas 200 euros ! "<<endl;
            if (j.se_liberer(banque, jeu._listJoueur)==true)
                    cout<<"Rassurez-vous, restez sur votre place"<<endl;
            else
            {
                j.allez_en_prison ();
            }
       }
       break;
    case 13:
        {
            cout << "Vous etes libereé de prison. Cette carte peut etre conserve jusqu'a ce qu'elle soit utilisé ou vendue"<<endl;
            j.set_carte_libere_de_prison_chance(true);
            carteLibererPrisonUtilisee = true;
        }
        break;
    case 14:
       {
            cout << "Reculez de trois cases ça sera autamatiquement"<<endl;
            if (j.getPosition()<3)
            {
                j.setPosition(40+j.getPosition()-3);
            }
            else
            {
                j.setPosition(j.getPosition()-3) ;
            }
            cout <<"Monsieur "<<j.get_nom_joueur()<<" votre nouvelle position est "<<j.getPosition()<<endl;
            jeu.handlerNewPosition(j);
       }
       break;
    case 15:
        {
            cout << "Rendez vous a AVENUE DES CHAMPS-ELYSEES ça sera autamatiquement sans reculter 200 euros meme si vous passez de la case de départ"<<endl;
            j.setPosition(37);
            cout <<"Monsieur "<<j.get_nom_joueur()<<" votre nouvelle position est "<<j.getPosition()<<endl;
            jeu.handlerNewPosition(j);
        }
        break;


    }
}

