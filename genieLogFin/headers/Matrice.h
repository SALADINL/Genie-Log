#pragma once
#include <iostream>
#include <vector>


struct Case{
	int 	caseLigne;
	int 	caseColonne;
	double 	caseValeur;
};

class Matrice{

	private:
	int tailleLigne;
	int tailleColonne;
	int nombreCases = 0;
	std::vector<Case> cases;

	public:
	Matrice(int ligne = 10000, int colonne = 10000);			//création d'une matrice de taille int,int
	Matrice(std::string);
	~Matrice();													//grace au vecteur n'a rien à détruire
	int TailleLigne() const;									//getter du nombre de ligne
	int TailleColonne() const;									//getter du nombre de colonne
	int NombreCases() const;
	Case& operator()(int element);								//getter du vecteur. (retourne la case i,j de la matrice).
	Case operator()(int element) const;
	void Initialisation();										//le gars va créer sa matrice. (while[choix == "oui"] -> rentre sa case avec AjouterCase).
	void Charger(std::string);									//matrice venant d'un fichier.txt
	void Sauvegarder(std::string);								//sauvegarde la matrice en LVC dans un fichier.txt
	bool AjouterCase(int,int,double);							//permet de modifier une case en particulier. (sera appelée dans initialisation)
	void ModifierCase(int,int,double);
	bool EstPresent(Case element);
	void SortCases();
	void Transposer();											//transpose la matrice
	Matrice operator=(const Matrice&);
	Matrice& operator+=(const Matrice&);
	Matrice& operator-=(const Matrice&);
};

//Matrice operator*(const Matrice&,const Matrice&);
/*int VerifToutChar(int i, std::string str, int taille);
int StringVersInt(std::string mot);
double StringVersDouble(std::string mot);
bool Init(int lig, int col, int& i, int& j, double& valeur);*/