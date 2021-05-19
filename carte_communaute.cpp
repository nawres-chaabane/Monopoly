#include <iostream>
#include "banque.h"
#include "joueur.h"
#include "jeu.h"


bool Carte_communaute::carteLibererPrisonUtilisee = false;

Carte_communaute::Carte_communaute()
{}

Carte_communaute::~Carte_communaute()
{}

bool Carte_communaute ::statusCarteLibererPrison()
{
    return carteLibererPrisonUtilisee;
}


void Carte_communaute :: traiter_carte_communaute(Joueur& j,Banque & banque ,int num_carte,Carte_chance & cc,Jeu &jeu)
{
    switch (num_carte)
    {

    /* ces 7 cartes vous recevez amende de la banque*/
    case 0 :
        {
            cout << "Les contributions vous remboursent la somme 20 euros"<<endl;
            banque.donner_arg(20 ,j ) ;
        }
        break;
    case 1 :
        {
            cout << "Erreur de la banque en votre faveur recevez 200 euros"<<endl;
            banque.donner_arg(200 ,j ) ;
        }
        break;
    case 2:
        {
            cout << "Recevez votre interet sur l'emprunt a 7% : 25"<<endl;
            banque.donner_arg(25 ,j ) ;
        }
        break;
    case 3:
        {
            cout << "Recevez votre revenu annuel 100 euros"<<endl;
            banque.donner_arg(100,j ) ;
        }
        break;
    case 4:
        {
            cout << "Vous avez gagne le 2eme prix de beaute recevez 10"<<endl;
            banque.donner_arg(10 ,j ) ;
        }
        break;
    case 5:
        {
            cout << "Vous heritez 100 euros "<<endl;
            banque.donner_arg(100  ,j ) ;
        }
        break;
    case 6:
       {
            cout << "Recevez votre revenu annuel 100 euros"<<endl;
            banque.donner_arg(100 ,j ) ;
       }
       break;

    /*ces 3 cartes vous devez payez la banque */

    case 7:
        {
            cout << "Vous devez payez la note du medecin 50"<<endl;
            if(j.get_solde()>50)
                    banque.recevoir_arg(50, j ) ;
            else
            {
                j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(50,banque, jeu._listJoueur);
                if (j.get_solde()>50)
                {
                    banque.recevoir_arg(50 , j ) ;
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
            cout << "Vous devez payez à l'hopital 100 euros"<<endl;
            if(j.get_solde()>100)
                    banque.recevoir_arg(100, j ) ;
            else
            {
                j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(100,banque, jeu._listJoueur);
                if (j.get_solde()>100)
                {
                    banque.recevoir_arg(100 , j ) ;
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
            cout << "Vous devez payez votre police d'assurace s'elevant à 50 euros "<<endl;
            if(j.get_solde()>50)
                    banque.recevoir_arg(50, j ) ;
            else
            {
                j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(50,banque, jeu._listJoueur);
                if (j.get_solde()>50)
                {
                    banque.recevoir_arg(50, j ) ;
                }
                else
                {
                    cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<<endl;
                    j.loser(jeu._listJoueur);
                }
            }
        }
        break;

    case 10:
        {
            cout << "Placez vous sur la case depart ca sera automatiquement"<<endl;
            j.setPosition(0);
            banque.donner_arg(200 ,j ) ;
        }
        break;

	case 11:
        {
            cout << "Retournez a BOULEVARD DE BELLEVILLE vous ne collectez pas 200 meme si vous passer de la case de départ"<<endl;
            j.setPosition(1);
            jeu.handlerNewPosition(j);
        }
        break;
    case 12:
    	{
            int x =0;
            cout << "Que voulez-vous Payez une amende de 10 ou bien tirez une carte de chance ?"<<endl ;
            do {
                cout << "Si vous voulez tirez une carte de chance taper 0 sinon entrer 1"<<endl ;
                cin >>x ;
             }
            while ((x==0) || (x==1)) ;
            if (x==0)
                j.tirer_carte_chance(cc, banque, jeu) ;
            else
                if(j.get_solde()>10)
                    banque.recevoir_arg(10 , j ) ;
                else
                {
                    j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(10,banque, jeu._listJoueur);
                    if (j.get_solde()>10)
                    {
                        banque.recevoir_arg(10 , j ) ;
                    }
                    else
                    {
                        cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<<endl;
                        j.loser(jeu._listJoueur);
                    }
                }
    	}
    	break;

    case 13:
        {
            cout << "C'est votre anniversaire chaque joueur doit vous donner 10"<<endl;
            for ( size_t i = 0; i < jeu._listJoueur.size(); i++)
            {
                Joueur x = jeu._listJoueur.at(i);
                if(x.get_solde()>10)
                    x.donner_argent(j , 10) ;
                else
                {
                    j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(10,banque, jeu._listJoueur);
                    if (j.get_solde()>10)
                    {
                        banque.recevoir_arg(10 , j ) ;
                    }
                    else
                    {
                        cout<<"Malheureusement "<<j.get_nom_joueur()<<" la somme collectee est insuffisante a payer le dette pourtant on a tout fait pour soutenir ." <<j.get_nom_joueur()<<"vous etes elimine du jeu "<<endl;
                        j.loser(jeu._listJoueur);
                    }
                }

            }
        }
        break;
    case 14:
        {
            cout << "Vous etes libre de prison cette carte peut etre conservé jusqu'a ce qu'elle soit utilisé ou vendue"<<endl;
            j.set_carte_libere_de_prison_communite(true);
            carteLibererPrisonUtilisee = true;
        }
        break;
    case 15:
        {
            cout << "Allez en prison directement! ne franchissez pas la case depart ! ne recevrez pas 200 euros !"<<endl;
            if (j.se_liberer(banque, jeu._listJoueur)==true)
                cout<<"rassurez-vous, restez sur votre place"<<endl;
            j.allez_en_prison ();
        }
        break;

    }
}
