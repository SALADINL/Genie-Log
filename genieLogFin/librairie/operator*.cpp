#include <iostream>
#include <fstream>
#include "../headers/Matrice.h"
#include "getValeur.cpp"
#include "EstPresent.cpp"

using namespace std;

Matrice operator*(const Matrice& matrice1,const Matrice& matrice2){
	if(matrice1.TailleColonne() == matrice2.TailleLigne()){	
		Matrice res(matrice1.TailleLigne(), matrice2.TailleColonne());
		double val;
		for(int i=0; i < matrice1.NombreCases(); i++){
			for(int j=0; j < matrice2.NombreCases(); j++){
				if(matrice1(i).caseColonne == matrice2(j).caseLigne){
					if(!EstPresent(matrice1(i).caseLigne, matrice2(j).caseColonne, res)){
						res.AjouterCase(matrice1(i).caseLigne, matrice2(j).caseColonne, matrice1(i).caseValeur * matrice2(j).caseValeur);
					}
					else{
						val = getValeur(i, j, res);
						res.ModifierCase(matrice1(i).caseLigne, matrice2(j).caseColonne, val += matrice1(i).caseValeur * matrice2(j).caseValeur);
					}
				}
			}
		}
		return res;
	}
	else{
		cerr << "Les matrices (" << matrice1.TailleLigne() << ","
				<< matrice1.TailleColonne() << ") et (" 
				<< matrice2.TailleLigne() << "," << matrice2.TailleColonne() << ")"
				<< " ne sont pas multiplicatives." << endl;
		return NULL;
	}
}