#include <iostream>
#include <fstream>

using namespace std;


Matrice operator-(const Matrice& matrice1,const Matrice& matrice2){
	if(matrice1.TailleLigne() == matrice2.TailleLigne() 
			&& matrice1.TailleColonne() == matrice2.TailleColonne()){
		Matrice res(matrice1.TailleLigne(), matrice1.TailleColonne());
		for(int i=0; i < matrice1.NombreCases(); i++){
			for(int j=0;j < matrice2.NombreCases(); j++){
				if(matrice1(i).caseLigne == matrice2(j).caseLigne && matrice1(i).caseColonne == matrice2(j).caseColonne){
					res.ModifierCase(matrice1(i).caseLigne,matrice1(i).caseColonne,matrice1(i).caseValeur - matrice2(j).caseValeur);
				}
				else{
					if(!res.EstPresent(matrice1(i)))
						res.AjouterCase(matrice1(i).caseLigne,matrice1(i).caseColonne,matrice1(i).caseValeur);
					if(!res.EstPresent(matrice2(j)))
						res.AjouterCase(matrice2(j).caseLigne,matrice2(j).caseColonne, - matrice2(j).caseValeur);
				}
			}
		}
		return res;
	}
	else{
		cerr << "Les matrices ("<<matrice1.TailleLigne() << ","
			 << matrice1.TailleColonne() << ") et ("
			 << matrice2.TailleLigne() << "," << matrice2.TailleColonne() << ")"
			 << " ne sont pas soustractives." << endl;
		return NULL;
	}
}