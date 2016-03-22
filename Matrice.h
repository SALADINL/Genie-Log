
Deuxieme essai de mes couilles !!


#include <iostream>
#include <vector>

class Matrice{

	private:

	std::vector<std::vector<double>> matrice;					//plus facile à utiliser que double**
	int tailleLigne;
	int tailleColonne;

	public:

	Matrice(int ligne = 10000, int colonne = 10000);			//création d'une matrice de taille int,int
	~Matrice();													//grace au vecteur n'a rien à détruire
	void Initialisation();										//le gars va créer sa matrice. (while[choix == "oui"] -> rentre sa case avec Modification).
	void Charger(std::string);									//matrice venant d'un fichier.txt
	void Sauvegarder(std::string);								//sauvegarde la matrice en LVC dans un fichier.txt
	void Modification(int,int,double);							//permet de modifier une case en particulier. (sera appelée dans initialisation)
	bool OperationPossible(const Matrice&);						//M1(a,b) * M2(b,c) -> M3(a,c)  sinon return false
	void Transposer();											//transpose la matrice
/**/Matrice& operator+=(const Matrice&);
/**/Matrice& operator*=(const Matrice&);
/**/Matrice& operator-=(const Matrice&);
/**/Matrice& operator/=(const Matrice&);
	int TailleLigne() const;									//getter du nombre de ligne
	int TailleColonne() const;									//getter du nombre de colonne
	double& operator()(int ligne, int colonne);					//getter du vecteur. (retourne la case i,j de la matrice).
	double operator()(int ligne, int colonne) const;
};

bool OperationPossible(const Matrice&, const Matrice&);
/**/Matrice operator+(const Matrice&,const Matrice&);			//Dans chaque fonction faudra créer une matrice tampon pour pas modifier celles d'origine
/**/Matrice operator*(const Matrice&,const Matrice&);
/**/Matrice operator-(const Matrice&,const Matrice&);
/**/Matrice operator/(const Matrice&,const Matrice&);
std::ostream& operator<<(std::ostream& flux, const Matrice&);	//affiche une matrice. (seulement les cases pleines).
