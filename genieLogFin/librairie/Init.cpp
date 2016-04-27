#include <iostream>
#include <fstream>
#include "VerifToutChar.cpp"
#include "StringVersDouble.cpp"

using namespace std;

bool Init(int lig, int col, int& i, int& j, double& valeur){
	string	choix, ligne, colonne, val;

	cout << "Voulez vous modifier une case de votre matrice ? o/n" << endl;
	cin >> choix;
	while(choix != "n" && choix != "o"){
		cout << "Entrez un choix valide ! o/n" << endl;
		cin >> choix;
	}
	if(choix == "o"){
		cout << "Entrez la ligne : " << endl;
		cin >> ligne;
		i = VerifToutChar(i,ligne,lig);
		cout << "Entrez la colonne : " << endl;
		cin >> colonne;
		j = VerifToutChar(j,colonne,col);
		cout << "Entrez la valeur : " << endl;
		cin >> val;
		valeur = stod(val);
		if(valeur == 0){
			cout << "Entrez une valeur de type double : " << endl;
			cin >> val;
			valeur = stod(val);
		}
		return true;
	}
	else
		return false;
}