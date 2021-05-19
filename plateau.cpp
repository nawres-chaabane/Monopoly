#include"plateau.h"
#include<iostream>
#include<string>
using namespace std ;

Plateau::Plateau() :listeCase(
    {
        Case (0,"Depart",0),
        Carte_terrain(1,"Boulevard de Belleville",60,"Marron",0,50,0,50,30,2,10,30,90,160,250),
        Case (2,"Caisse de communaute",0),
        Carte_terrain(3,"Rue Lecourbe",60,"Marron",0,50,0,50,30,2,10,30,90,160,250),
        Case (4,"Impots sur le revenu",200),
        Carte_terrain (5," Gare Montparnasse",200,"noir",0,0,0,0,100,25,0,0,0,0,0,true),
        Carte_terrain (6,"Rue de vaugirard",100,"bleu",0,50,0,50,50,6,30,90,270,400,550),
        Case (7,"Caisse de chance",0),
        Carte_terrain (8,"Rue de courcelles",100,"bleu",0,50,0,50,50,6,30,90,270,400,550),
        Carte_terrain (9,"Avenue de la republique",120,"bleu",0,50,0,50,50,6,30,90,270,400,550),
        Case (10,"Visite simple en prison",0),
        Carte_terrain (11,"Rue de la villette",140,"rose",0,100,0,100,70,10,50,150,450,625,750),
        Carte_terrain (12,"Compagne de distribution d'electrecite",150,"blanc",0,0,0,0,75,0,0,0,0,0,0,false,true),
        Carte_terrain (13,"Rue de la Neuilly",140,"rose",0,100,0,100,70,10,50,150,450,625,750),
        Carte_terrain (14,"Rue de la Paradis",160,"rose",0,100,0,100,80,12,60,180,500,700,900),
        Carte_terrain (15,"Gare de lyon",200,"noir",0,0,0,0,100,25,0,0,0,0,0,true),
        Carte_terrain (16,"Avenue Mozart",180,"orange",0,100,0,100,90,14,70,200,550,750,950),
        Case(17,"Caisse communaute",0),
        Carte_terrain (18,"Boulevard Saint-Michel",180,"orange",0,100,0,100,90,14,70,200,550,750,950),
        Carte_terrain (19,"Place Pigalle",200,"orange",0,100,0,100,100,16,80,220,600,800,1000),
        Case (20,"Parc Gratuit",0),
        Carte_terrain (21,"Avenue Matignon",220, "rouge",0,150,0,150,110,18,90,250,700,875,1050),
        Case (22,"Caisse de chance",0),
        Carte_terrain(23,"Boulevard Malesherbes",220,"rouge",0,150,0,150,110,18,90,250,700,875,1050),
        Carte_terrain(24,"Avenue Henri-Martin",240,"rouge",0,150,0,150,120,20,100,300,750,925,1100),
        Carte_terrain (25,"Gare du nord",200,"noir",0,0,0,0,100,25,0,0,0,0,0,true),
        Carte_terrain(26,"Faubourg Saint-Honore",260,"jaune",0,150,0,150,130,22,110,330,800,975,1150),
        Carte_terrain(27,"Place de la bourse",260,"jaune",0,150,0,150,130,22,110,330,800,975,1150),
        Carte_terrain (28,"Compagnie de distribution des eaux",150,"blanc",0,0,0,0,75,0,0,0,0,0,0,false,true),
        Carte_terrain(29,"Rue de La fayette",280,"jaune",0,150,0,150,140,24,120,360,850,1025,1200),
        Case (30,"Allez en prison",0),
        Carte_terrain(31,"Avenue de Breteuil",300,"vert",0,200,0,200,150,26,130,390,900,1100,1275),
        Carte_terrain(32,"Avenue Foch",300,"vert",4,200,1,200,150,26,130,390,900,1100,1275),
        Case ( 33,"Caisse de communaute",0),
        Carte_terrain(34,"Boulevard des capucines",320,"vert",0,200,0,200,160,28,150,450,1000,1200,1400),
        Carte_terrain ( 35,"Gare saint-lazare",200,"noir",0,0,0,0,100,25,0,0,0,0,0,true),
        Case (36,"Caisse de chance",0),
        Carte_terrain(37,"Avenue des champs elysees",350,"bleu fonce",0,200,0,200,175,35,175,500,1100,1300,1500),
        Case (38,"Taxe de luxe",100),
        Carte_terrain(39,"Rue de la paix",350,"bleu fonce",0,200,0,200,200,50,200,600,1400,1600,2000)
    })
{}

Plateau::~Plateau()
{
}

Case* Plateau :: get_listeCase()
{
    return listeCase ;
}

int Plateau ::getType(int pos)
{
    switch (pos)
    {
        case 0 :
            return 0 ; // case depart

        case 10 :
            return 1 ; // visite simple

        case 20 :
            return 2 ;  //parc gratuit

        case 30 :
            return 3 ; //allez en prison
        case 2 :
        case 17 :
        case 33 :
            return 4 ; //caisse de communaute

        case 7 :
        case 22 :
        case 36 :
            return 5 ; //caisse de chance
        case 4 :
        case 38 :
            return 6 ; // Impot sur le revenu ou Taxe de lux

        default	:
            return 7;  //carte de terrain

    }

}

