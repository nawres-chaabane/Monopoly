#include <iostream>
#include <ctime>
#include <vector>
#include <list>

using namespace std ;



class De {
	int val_de_1 ;
	int val_de_2 ;
	int countDouble;

	public :
	De() : val_de_1(0), val_de_2(0), countDouble(0) {}
	~De(){}
	bool newDeRandomValue();
	bool obtenir_double () ;
	bool lancer_premiere_fois() ;
	int relancer() ;
	int somme() ;
    int get_countDouble();
    void set_countDouble(int a);

	private :
	bool lancer() ; /*on va l'utiliser dans la méthode relancer */



};

int De::somme()
	{
		return (val_de_1 + val_de_2);
	}


	void De::set_countDouble(int a)
	{
	    countDouble=a;
	}
	int De::get_countDouble()
	{
	    return countDouble ;
	}

	bool De :: obtenir_double (){
		return (val_de_1 == val_de_2);

	}

	bool De::newDeRandomValue()      // si joueur a un double on a true et il ya incrementation de countDouble si nn CountDouble est initialisée à 0 !!
	{                                 // l'appel à cette methode signifie avoir deux nouvelles valeurs pour le dé
		srand(time(NULL));
	 	val_de_1=rand() %6 +1 ;
	 	val_de_2=rand() %6 +1 ;

	 	if (obtenir_double()){
	 		++countDouble;
	 		return true;
	 	}
	 	countDouble = 0;
	 	return false;
	}

	bool De ::  lancer_premiere_fois()
	{
		countDouble = 0;

		if (newDeRandomValue()){
			cout <<"C'est parti monsieur commencons !"<<endl ;
			cout << "de = "<< val_de_1 << ":" << val_de_2<<endl ;
			return true ;
		}
		else
		{
			cout<< "Vous avez besoin d'un double pour partir :( !"<<endl ;
			return false;
		}
	}



	bool De ::  lancer()
	{
		bool ret = newDeRandomValue();
		cout << "de = "<< val_de_1 << ":" << val_de_2<<endl ;     /*on va l'utiliser dans la méthode relancer */
		return ret ;
	}



	int De ::  relancer()
	{
		bool retValue = lancer();
		if(countDouble == 3)
		{
			cout << "Aller_en_prison"<<endl ;
			return 2;	// 2 c'est à dire aller en prison
		}

		if(retValue)
		{
			cout<<"Vous avez un double "<<val_de_1<<":"<<val_de_2<<endl ;
			return 1;    // il a un double
		}

		cout<<"Vous vous deplacez ,ca sera automatiquement"<<endl;                  //vous avez "<<val_de_1<<":"<<val_de_2<<endl ;
		return 0; // pas d'un double un simple déplacement

	}



class Carte_chance;
class Carte_terrain;
class Banque;
class Carte_communaute;
class Banque;
class Jeu;
class Case;
class Plateau;
class Joueur;


class Case
{

	protected :
		int position_case ;
		string nom_case ; // pour les 40 cases du plateau
		int prix_case ;

	public :
		Case(int pos =0 ,string nom = "AucunNom", int prix=0 );

		int get_pos_case() ;

		int get_prix_case() ;

        string get_nom_case() ;

		void set_prix_case(int) ;

		void set_nom_case (string  ) ;


		virtual bool get_est_hypotheque () const {}

       	virtual void set_est_hypotheque (bool) {}

       	virtual bool get_est_gare()   {}

        virtual bool get_est_compagnie()   {}

        virtual int get_prix_a_payer_avec_0_maison() const{}

        virtual int get_prix_a_payer_avec_1_maison() const{}

        virtual int get_prix_a_payer_avec_2_maison() const{}

        virtual int get_prix_a_payer_avec_3_maison() const{}

        virtual int get_prix_a_payer_avec_4_maison() const{}

        virtual int get_prix_a_payer_avec_1_hotel() const{}

        virtual int get_nbre_maison_construit() const{}

        virtual int get_nbre_hotel_construit() const {}

        virtual int get_taux_hypotheque()const{}  //get_taux_hypotheque

        virtual int get_prix_maison() const{}

        virtual int get_prix_hotel() const{}

        virtual string get_couleur() const{}

        virtual int get_ce_qeu_faut_payer(Joueur&) {}

        virtual void construire_maison( Joueur & , Banque& ){}

        virtual void construire_hotel (Joueur &, Banque& banque) {}

        virtual bool avoir_toute_la_plage_colore(Joueur &  ,string ){}

};

class Carte_terrain : public Case {

	private :
        string couleur ;
        int nbre_maison_construit ;
        int prix_maison ;
        int prix_hotel ;
        int nbre_hotel_construit ;
        int taux_hypotheque ;
        int prix_a_payer_avec_0_maison ;      // 6 attributs qui caractérisent l'amende à payer si un etranger se place sur ma carte !
        int prix_a_payer_avec_1_maison ;
        int prix_a_payer_avec_2_maison ;
        int prix_a_payer_avec_3_maison ;
        int prix_a_payer_avec_4_maison ;
        int prix_a_payer_avec_1_hotel ;
        bool est_hypotheque ;
        bool est_gare;
        bool est_compagnie;

	public :
        Carte_terrain ( int pos =0 ,string nom ="", int prix=0 ,string col ="" ,int nmc=0,int pm=0 , int nhc=0, int ph=0 ,
                       int h=0,int a=0 ,int b=0,int c=0 ,int d=0 , int e=0 , int f=0 ,bool eg=false ,bool ec=false,bool eh=false);


        ~Carte_terrain();

        //Carte_terrain(const Carte_terrain&);


        bool get_est_hypotheque () const ;

       	void set_est_hypotheque (bool) ;

       	bool get_est_gare()   ;

        bool get_est_compagnie()   ;

        int get_prix_a_payer_avec_0_maison() const;

        int get_prix_a_payer_avec_1_maison() const;

        int get_prix_a_payer_avec_2_maison() const;

        int get_prix_a_payer_avec_3_maison() const;

        int get_prix_a_payer_avec_4_maison() const;

        int get_prix_a_payer_avec_1_hotel() const;

        int get_nbre_maison_construit() const;

        int get_nbre_hotel_construit() const ;

        int get_taux_hypotheque()const;   //get_taux_hypotheque

        int get_prix_maison() const;

        int get_prix_hotel() const;

        string get_couleur() const;

        int get_ce_qeu_faut_payer(Joueur&) ;

        void construire_maison( Joueur & , Banque& );

        void construire_hotel (Joueur &, Banque& banque) ;

        bool avoir_toute_la_plage_colore(Joueur &  ,string );




        int get_pos_case() ;

		int get_prix_case() ;

        string get_nom_case() ;


};
class Plateau
{
    private:
        Case *listeCase[40] ;

	public:

    Plateau() ;

	~Plateau() ;

	int getType(int);

	Case** get_listeCase() ;

	//Case listeCase[40] ;

};

class Banque
{

    private:
        int montant;
        int nb_hotels;
        int nb_maisons ;

    public:
        Banque() ;

        ~Banque() ;

        int get_nb_maisons () ;

        int get_nb_hotels() ;

        void set_nb_maisons(int a) ;

        void set_nb_hotels(int b) ;

        void donner_arg(int arg,Joueur& j) ;

        void recevoir_arg(int arg,Joueur& j) ;


};
class Carte_chance
{

	public:
	    Carte_chance();
	    ~Carte_chance();
	    void traiter_carte_chance( Joueur& j, Banque& banque, Jeu& jeu, int );
	    bool statusCarteLibererPrison();
        static bool carteLibererPrisonUtilisee;
};
class Carte_communaute
{
private:
public:
    Carte_communaute();
    ~Carte_communaute();
    void traiter_carte_communaute(Joueur& ,Banque & ,int ,Carte_chance &,Jeu &jeu );
    bool statusCarteLibererPrison();
    static bool carteLibererPrisonUtilisee;
};

class Joueur {
    string nom_joueur ;
    int position_joueur ;
    int nbre_possession_carte ;
	list<Carte_terrain*> list_possession ;
	int solde ;
	int nbr_tour_en_prison;
    bool a_commence ;       //pour savoir est ce que le joueur a commencer à jouer
	bool avoir_carte_libre_prison_chance;
	bool avoir_carte_libre_prison_communite;
	/*les deux attributs static sont nécessaires pour souligner le fait que chaque joueur qui tire une
	carte de chance ou de communauté il doit la disposer sous les autres*/

	public :
		Joueur(string ch ="sans nom" );

		~Joueur();

		int get_solde() ;

		void set_solde(int ) ;

		string get_nom_joueur() ;

		bool get_a_commence() const ;

		void set_a_commence(bool);

		int getPosition() const ;

		void setPosition(int ) ;

		list<Carte_terrain*> getListPossession() const;

		bool isCarteOwner ( )  ;

		bool isCarteOwnedByOtherPlayer (Joueur& j, vector <Joueur>& listJoueur, list <Carte_terrain*>& l, int pos, std::string nom);

		void acheter_carte_de_la_banque(Carte_terrain &cr ,Banque & banque);  //elle à été pointeur pour la carte terrain

		void acheter_carte_du_joueur(Carte_terrain& cr, Joueur& j, int prix_demande);

		void vendre_carte_au_joueur(Carte_terrain &cr, Joueur j) ;

		void se_deplacer ( De& , Banque & banque) ;

		void tirer_carte_chance (Carte_chance& carte, Banque& banque, Jeu& jeu) ;

		void tirer_carte_communaute (Carte_communaute& cr, Carte_chance& cc, Banque& banque, Jeu& jeu) ;

		void donner_argent(Joueur& j , int somme) ;

		void recevoir_argent(Joueur& j , int somme)	;

		void allez_en_prison () ;

		int get_nbre_possession_carte();

		bool est_en_prison();

		int get_nbre_maison_du_joueur_plage(string col) ;

		void hypothequer(Carte_terrain&,Banque &) ;

		void recuperer_carte_hypotheque(Carte_terrain& cr,Banque& b);

		void loser(vector <Joueur>& listJoueur);

		bool se_liberer(Banque& banque, vector <Joueur>& listJoueur);

		void traitement_si_solde_superieur_a_la_somme_apayer_au_joueur(Joueur & j ,int som_a_payer, Plateau plateau);

		void traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(int som_a_payer ,Banque &_banque, vector <Joueur>& listJoueur);

		int get_nbr_tour_en_prison();

		void set_nbr_tour_en_prison(int);

		bool avoir_carte_libere_de_prison();

		void set_carte_libere_de_prison_chance(bool val);

		void set_carte_libere_de_prison_communite(bool val);

        bool possede_carte_libere_de_prison_chance();

        bool possede_carte_libere_de_prison_communite();

        void traitement_si_je_suis_sur_ma_gare(Carte_terrain &);

        void acheter_toute_la_plage_de_couleur(Carte_terrain& cr, Joueur& j,int prix_demande);

        static int nbre_tir_carte_chance ;

        static int nbre_tir_carte_communaute ;


};
class Jeu
{
	public:
		Jeu(vector<Joueur> listJoueur);
		~Jeu();
		void lancerJeu();
		void handlerNewPosition(Joueur& m);

        vector <Joueur> _listJoueur;
	protected:
	private:
        Plateau _plateau;
		De d;
		Banque _banque;
		Carte_communaute _carteCommunaute;
        Carte_chance _carteChance;
};


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

		bool Joueur::isCarteOwner( )
		{
		    list <Carte_terrain*>:: iterator it;
		    if(!list_possession.empty())
            {
                for (it= list_possession.begin() ; it != list_possession.end(); it++)
                {
                    if ((*it)->get_pos_case()== position_joueur)

                    {
                        return true;
                    }
                }
            }

			return false;
		}


		bool Joueur::isCarteOwnedByOtherPlayer (Joueur& otherPlayer, vector <Joueur>& listJoueur, list <Carte_terrain*>& l, int pos, std::string nom)
		{
               vector <Joueur>:: iterator iter ;
               //otherPlayer = nullptr;

				for (iter=listJoueur.begin() ; iter!= listJoueur.end() ;iter++)
				{
				    if(((*iter).get_nom_joueur() != nom_joueur ))
                    {
                        list <Carte_terrain*>:: iterator it ;
                        list<Carte_terrain*> poss = iter->getListPossession();
                        if(!poss.empty())
                        {
                            for (it = poss.begin() ; it!= poss.end(); it++)
                            {
                                if ( (*it)->get_pos_case()== pos )
                                {
                                    cout <<iter->get_nom_joueur()<<endl;
                                    otherPlayer = (*iter); //std::pointer_from(iter);
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
		    cout <<"Cette carte terrain appartient a une plage de couleur ou il y a des maisons construites Voulez-vous achetez toutes la plage a "<< prix_demande<<"?"<<endl;
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
                cout <<"L_operation nest pas effectuee a cause d_un refus ou manque de solde de "<<nom_joueur<<endl;
		}


        void Joueur :: acheter_carte_du_joueur(Carte_terrain &cr, Joueur &j,int prix_demande )   //dans le cas normal mais si otherPlayer n'a pas de maison ou hotel construit
		{
            cout <<" Voulez-vous achetez la carte a :"<< prix_demande<<"?"<<endl;
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
                cout <<"L_operation nest pas effectuee a cause d_un refus ou manque de solde de "<<nom_joueur<<endl;
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

	    void Joueur :: donner_argent(Joueur &j , int somme){
	        if(&j==nullptr)

            // dans le cas d'une tombé sur une possession d'un autre Joueur
			j.solde+=somme ;
			solde-=somme ;
			cout<<"Monsieur "<<nom_joueur <<" vous avez donne une somme de :"<<somme<<" a monsieur " <<j.nom_joueur<<endl ;
			cout<<"Le nouveau solde de " << nom_joueur << " est " << solde << endl;
			cout<<"Le nouveau solde de " << j.nom_joueur << " est " << j.solde << endl;
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
            cout << "Est ce que vous voulez acheter la carte terrain si l_autre joueur accepte ?"<<endl;
            string x ;
            cin >> x ;
            if (((x=="oui") || (x=="OUI"))&& j.get_nbre_maison_du_joueur_plage( (plateau.get_listeCase()[j.getPosition()])->get_couleur())==0)
            {
                 cout << j.nom_joueur <<" vous accepter de vendre cette carte ? "<<endl;;
                 string y ;
                 int prix ;
                 cin >>y ;
                 cout << "donner le montant desire "<< endl;
                 cin >>prix ;
                 if((y=="oui" || y=="OUI") && prix >  plateau.get_listeCase()[position_joueur]->get_prix_case())
                 {
                    cout << this->nom_joueur<<", Est ce que vous acceptez d_acheter cette carte a ce prix :"<<prix<<endl; ;
                    string z ;
                    cin >>z ;
                    if((z=="oui") || (z=="OUI"))
                    {
                        acheter_carte_du_joueur(*(Carte_terrain*)((plateau.get_listeCase()[getPosition()])),j,prix);
                    }
                    else
                        this->donner_argent(j,som_a_payer);
                 }
            }
            else  // non ou NON c'est à dire le joueur courant juste pay ce qu'il doit payer au joueur qui possède la carte
            {
                donner_argent(j,som_a_payer);
            }
		}


         void Joueur::traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(int som_a_payer , Banque& banque, vector <Joueur>& listJoueur)
            {
                cout<<get_nom_joueur()<<"Vous etes oblige d'hpothequer ou bien vendre quelques une de vos possessions , vous ecriverez a chaque fois pour chaque carte vendre ou hypotheque jusqu_a atteindre la somme "<<endl ;

                while(solde<=som_a_payer && nbre_possession_carte!=0 )
                {
                    list <Carte_terrain*> ::iterator it ;
                    for(it= list_possession.begin();it!=list_possession.end();it++)
                    {
                        cout<<"Voulez-vous hypothequez ou vendez cette carte"<<(*it)->get_nom_case() <<" ?"<<endl;
                        string x ; cin>>x;
                        if(x=="hypotheque")
                        {
                                hypothequer(*(*it),banque);
                        }
                        else if(x=="vendre")
                        {
                            //bool carte_vendu=false;
                            cout<<"Un tour de table va etre lieu pour vendre "<<(*it)->get_nom_case()<<endl;
                            cout<<nom_joueur<<"Donnez le prix désiré pour vendre la carte "<<(*it)->get_nom_case()<<endl;
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
                                    cout<<nom_joueur<<"Attention il ya des maisons sur la plage de couleur "<<(*it)->get_couleur()<<". Validez par oui et donnez le prix désiré pour toute la plage si c'est le cas d'une acceptation "<<endl;
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
                    cout<<"Quelle chance! vous pouvez vous en sortir automatiquement!"<<endl;
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
                        cout<<(*iter).nom_joueur<<"voulez vous vendre votre carte a "<<nom_joueur<<"?"<<endl;
                        string rep;
                        cin>>rep;
                        if(((rep=="oui") || (rep=="OUI")) )
                        {
                            cout<<"Entrez le prix que vous proposez"<<endl;
                            int pr;
                            cin>>pr;
                            if(solde>pr)
                            {
                                cout<<nom_joueur<<"Ce prix vous semble-t-il convenable?"<<endl;
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





        Banque :: Banque(){
	    	montant= 12000;
            nb_maisons=32;
            nb_hotels=12;
		}

		Banque :: ~Banque() {}

        int Banque :: get_nb_maisons (){
            return nb_maisons;

        }

        int Banque :: get_nb_hotels() {
            return nb_hotels;
        }
        void Banque :: set_nb_maisons(int a){  //2 setter pour modifier le nombre de maison ou de hotel disponible en cas d'une vente
            nb_maisons=a;


        }
        void Banque :: set_nb_hotels(int b){
            nb_hotels=b;
        }
        void Banque :: donner_arg(int arg,Joueur& j){
            montant= montant - arg;
            j.set_solde(j.get_solde()+arg) ;
            cout<<"Monsieur "<<j.get_nom_joueur()<<" votre solde est mise a jour a "<<j.get_solde()<<endl ;
            cout<<"Le montant de la banque est mise a jour a "<<montant<<endl;

        }
        void Banque :: recevoir_arg(int arg,Joueur& j){
            montant= montant + arg;
            j.set_solde(j.get_solde()-arg) ;
            cout<<"Monsieur "<<j.get_nom_joueur()<<" votre solde est mise a jour a "<<j.get_solde()<<endl ;
            cout<<"Le montant de la banque est mise a jour a "<<montant<<endl;
        }



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




    Carte_terrain ::Carte_terrain ( int pos ,string nom, int prix ,string col ,int nmc,int pm , int nhc, int ph,
                                   int h,int a ,int b,int c ,int d , int e , int f ,bool eg ,bool ec,bool eh): Case(pos , nom , prix)
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
         est_hypotheque=eh ;
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
			cout<<"vous pouvez maintenant construire un hotel" <<endl;
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
                  //  if (avoir_toute_la_plage_colore(j ,couleur ))   //j joueur qui joue maintenant
                    //{
                    //    return (2*prix_a_payer_avec_0_maison);   // c'est une remarque sur chaque carte terrain
                    //}
                   // else
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

 int Carte_terrain :: get_pos_case ()
    {
        return position_case ;
    }

    int Carte_terrain :: get_prix_case ()
    {
        return prix_case ;
    }

    string Carte_terrain :: get_nom_case()
    {
        return nom_case;
    }

Plateau::Plateau() :listeCase(
    {
        new Case (0,"Depart",0),
        new Carte_terrain(1,"Boulevard de Belleville",60,"Marron",0,50,0,50,30,2,10,30,90,160,250,false,false,false),
        new Case (2,"Caisse de communaute",0),
        new Carte_terrain(3,"Rue Lecourbe",60,"Marron",0,50,0,50,30,2,10,30,90,160,250,false,false,false),
        new Case (4,"Impots sur le revenu",200),
        new Carte_terrain (5," Gare Montparnasse",200,"noir",0,0,0,0,100,25,0,0,0,0,0,true,false,false),
        new Carte_terrain (6,"Rue de vaugirard",100,"bleu",0,50,0,50,50,6,30,90,270,400,550,false,false,false),
        new Case (7,"Caisse de chance",0),
        new Carte_terrain (8,"Rue de courcelles",100,"bleu",0,50,0,50,50,6,30,90,270,400,550,false,false,false),
        new Carte_terrain (9,"Avenue de la republique",120,"bleu",0,50,0,50,50,6,30,90,270,400,550,false,false,false),
        new Case (10,"Visite simple en prison",0),
        new Carte_terrain (11,"Rue de la villette",140,"rose",0,100,0,100,70,10,50,150,450,625,750,false,false,false),
        new Carte_terrain (12,"Compagne de distribution d'electrecite",150,"blanc",0,0,0,0,75,0,0,0,0,0,0,false,true,false),
        new Carte_terrain (13,"Rue de la Neuilly",140,"rose",0,100,0,100,70,10,50,150,450,625,750,false,false,false),
        new Carte_terrain (14,"Rue de la Paradis",160,"rose",0,100,0,100,80,12,60,180,500,700,900,false,false,false),
        new Carte_terrain (15,"Gare de lyon",200,"noir",0,0,0,0,100,25,0,0,0,0,0,true,false,false),
        new Carte_terrain (16,"Avenue Mozart",180,"orange",0,100,0,100,90,14,70,200,550,750,950,false,false,false),
        new Case(17,"Caisse communaute",0),
        new Carte_terrain (18,"Boulevard Saint-Michel",180,"orange",0,100,0,100,90,14,70,200,550,750,950,false,false,false),
        new Carte_terrain (19,"Place Pigalle",200,"orange",0,100,0,100,100,16,80,220,600,800,1000,false,false,false),
        new Case (20,"Parc Gratuit",0),
        new Carte_terrain (21,"Avenue Matignon",220, "rouge",0,150,0,150,110,18,90,250,700,875,1050,false,false,false),
        new Case (22,"Caisse de chance",0),
        new Carte_terrain(23,"Boulevard Malesherbes",220,"rouge",0,150,0,150,110,18,90,250,700,875,1050,false,false,false),
        new Carte_terrain(24,"Avenue Henri-Martin",240,"rouge",0,150,0,150,120,20,100,300,750,925,1100,false,false,false),
        new Carte_terrain (25,"Gare du nord",200,"noir",0,0,0,0,100,25,0,0,0,0,0,true,false,false),
        new Carte_terrain(26,"Faubourg Saint-Honore",260,"jaune",0,150,0,150,130,22,110,330,800,975,1150,false,false,false),
        new Carte_terrain(27,"Place de la bourse",260,"jaune",0,150,0,150,130,22,110,330,800,975,1150,false,false,false),
        new Carte_terrain (28,"Compagnie de distribution des eaux",150,"blanc",0,0,0,0,75,0,0,0,0,0,0,false,true,false),
        new Carte_terrain(29,"Rue de La fayette",280,"jaune",0,150,0,150,140,24,120,360,850,1025,1200,false,false,false),
        new Case (30,"Allez en prison",0),
        new Carte_terrain(31,"Avenue de Breteuil",300,"vert",0,200,0,200,150,26,130,390,900,1100,1275,false,false,false),
        new Carte_terrain(32,"Avenue Foch",300,"vert",4,200,1,200,150,26,130,390,900,1100,1275,false,false,false),
        new Case ( 33,"Caisse de communaute",0),
        new Carte_terrain(34,"Boulevard des capucines",320,"vert",0,200,0,200,160,28,150,450,1000,1200,1400,false,false,false),
        new Carte_terrain ( 35,"Gare saint-lazare",200,"noir",0,0,0,0,100,25,0,0,0,0,0,true,false,false),
        new Case (36,"Caisse de chance",0),
        new Carte_terrain(37,"Avenue des champs elysees",350,"bleu fonce",0,200,0,200,175,35,175,500,1100,1300,1500,false,false,false),
        new Case (38,"Taxe de luxe",100),
        new Carte_terrain(39,"Rue de la paix",350,"bleu fonce",0,200,0,200,200,50,200,600,1400,1600,2000,false,false,false)
    })
{}

Plateau::~Plateau()
{
    //delete[] listeCase;
}

Case** Plateau :: get_listeCase()
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
			cout << "Vous etes sur la case de depart , lorsque vous passerez la prochaine vous recevrez 200 euros automatiquement"<<endl ;
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
			cout << "Vous etes sur une carte terrain cest "<<(_plateau.get_listeCase()[j.getPosition()])->get_nom_case()<<endl ;
            //Joueur& otherPlayer = nullptr;
            Joueur otherPlayer;
            list<Carte_terrain*> l=j.getListPossession();

            if(j.isCarteOwner())
            {
                cout <<"Assurez vous , vous etes sur votre propre case " << endl;
            	if((_plateau.get_listeCase()[j.getPosition()])->get_est_hypotheque ()==false)
            	{
	                if((_plateau.get_listeCase()[j.getPosition()])->get_est_gare()==false
                    && (_plateau.get_listeCase()[j.getPosition()])->get_est_compagnie()==false)
                    {
                        string x ;
                        do
                        {
                            cout <<"Est ce que vous voulez construire un maison ? Validez par oui ou non " << endl;
                            cin >> x ;
                            if ((x=="oui") || (x=="OUI"))
                            {
                                 (_plateau.get_listeCase()[j.getPosition()])->construire_maison( j ,_banque) ;
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
                                 (_plateau.get_listeCase()[j.getPosition()])->construire_hotel( j ,_banque) ;
                            }

                        }
                        while ((x!="oui") && (x!="OUI") && (x!="non") && (x!="NON"));
                    }
                    else if ((_plateau.get_listeCase()[j.getPosition()])->get_est_gare()==true)
                    {
                        cout <<"Vous etes sur votre gare"<<_plateau.get_listeCase()[j.getPosition()]->get_nom_case() << endl;
                        j.traitement_si_je_suis_sur_ma_gare(*(Carte_terrain*)(_plateau.get_listeCase()[j.getPosition()]));
                    }
                    else
                    {
                        cout <<"Vous etes sur votre compagnie "<<_plateau.get_listeCase()[j.getPosition()]->get_nom_case() << endl;
                    }
	           	}
	           	else
	           	{
	           		cout<<"Votre carte est hypothequee mais vous la récuperez immédiatement si votre solde est compatible !"<< endl;
	           		j.recuperer_carte_hypotheque(*(Carte_terrain*)(_plateau.get_listeCase()[j.getPosition()]),_banque) ;
				}
			}


            else if (j.isCarteOwnedByOtherPlayer(otherPlayer, _listJoueur, l, j.getPosition(),j.get_nom_joueur()))
            {
                cout <<"Vous etes sur une carte terrain de autre joueur"<<endl ;
            	if ((_plateau.get_listeCase()[j.getPosition()])->get_est_hypotheque ()==false)
           		{
                        Case* ca = (_plateau.get_listeCase()[j.getPosition()]);
		                int som_a_payer=ca->get_ce_qeu_faut_payer(otherPlayer);

		                //si j'ai le solde necessaire pour payer le dette

		                if (j.get_solde()>som_a_payer)
		                {
                            j.traitement_si_solde_superieur_a_la_somme_apayer_au_joueur(otherPlayer ,som_a_payer, _plateau);
						}

		                //si solde inf ou meme egale a la som_a_payer puisque lorsque elle sera egale il ne peut pas continuer à jouer avec solde egale à 0

		                else if ((j.get_solde()<=som_a_payer))
		                {
                            j.traitement_si_solde_inferieur_ou_egale_a_la_somme_apayer_au_joueur_ou_banque(som_a_payer ,_banque, _listJoueur);
                            if (j.get_solde()>som_a_payer)
                            {
                                j.donner_argent(otherPlayer,som_a_payer);
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
                             j.acheter_carte_de_la_banque( *(Carte_terrain*)(_plateau.get_listeCase()[j.getPosition()]),_banque) ;
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
int main(int argc, char *argv[])
{
	int nbPlayer = 0;
    while(nbPlayer <=1)
    {
        cout << "Bienvenu, entrer le nombre des joueurs s'il vous plait strictement superieur a 1 "<<endl;
        cin >> nbPlayer;
    }
	vector<Joueur> listJoueur;
	for (int i = 0; i< nbPlayer; ++i)
	{
		string joueurName;
        if(i==0)
            cout <<endl<<endl<< "Entrer le nom du "<< (i+1) << " er joueur "<<endl;
        else
        {
            cout <<endl<<endl<< "Entrer le nom du "<< (i+1) << " eme joueur "<<endl;
        }
		cin >> joueurName;
		listJoueur.push_back(Joueur(joueurName));
	}

    Jeu game(listJoueur);

    game.lancerJeu();

}

