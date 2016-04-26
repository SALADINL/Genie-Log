#include <iostream>
#include <fstream>

using namespace std;
ostream& operator<<(std::ostream& flux, const Matrice& matrice){
	int taille = matrice.NombreCases();
	if(taille == 0)
		flux << "Votre matrice est complétement creuse." << endl;
	else{
		for(int i=0; i < taille; i++){
			flux << "matrice[" << matrice(i).caseLigne << "]["
				 << matrice(i).caseColonne << "] = "
				 << matrice(i).caseValeur << endl;
		}
	}
}