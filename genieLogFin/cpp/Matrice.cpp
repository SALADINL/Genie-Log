#pragma once
#include <iostream>
#include <fstream>
#include "../headers/Matrice.h"
#include "../librairie/Init.cpp"

using namespace std;

Matrice::Matrice(int ligne, int colonne)
: tailleLigne{ligne}, tailleColonne{colonne}
{
	this->cases.resize(nombreCases);
}

Matrice::Matrice(string nom){
	tailleLigne = 10000;
	tailleColonne = 10000;
	Charger(nom);
}

Matrice::~Matrice(){

}

int Matrice::TailleLigne() const{
	return this->tailleLigne;
}

int Matrice::TailleColonne() const{
	return this->tailleColonne;
}

int Matrice::NombreCases() const{
	return this->nombreCases;
}

Case& Matrice::operator()(int element){
	return this->cases[element];
}

Case Matrice::operator()(int element) const{
	return this->cases[element];
}


void Matrice::Initialisation(){
	int 	i,j;
	double 	val;

	while(Init(tailleLigne,tailleColonne,i,j,val))
		AjouterCase(i,j,val);
}


bool Matrice::AjouterCase(int ligne, int colonne, double valeur){
	bool test = false;
	for(int i=0; i < nombreCases; i++){
		if(cases[i].caseLigne == ligne && cases[i].caseColonne == colonne)
			test = true;
	}
	if(ligne < tailleLigne && colonne < tailleColonne && !test){
		vector<Case> tmpCases(nombreCases+1);
		for(int i=0; i < nombreCases; i++)
			tmpCases[i] = cases[i];
		tmpCases[nombreCases].caseLigne = ligne;
		tmpCases[nombreCases].caseColonne = colonne;
		tmpCases[nombreCases].caseValeur = valeur;
		cases = tmpCases;
		nombreCases++;
		return true;
	}
	else{
		cerr << "AjouterCase impossible en : ("<<ligne<<","<<colonne<<")"<<endl;
		return false;
	}
}

void Matrice::ModifierCase(int ligne, int colonne, double valeur){
	for(int i=0; i < nombreCases; i++)
		if(cases[i].caseLigne == ligne && cases[i].caseColonne == colonne)
			cases[i].caseValeur = valeur;
}


bool Matrice::EstPresent(Case element){
	for(int i=0; i < nombreCases; i++)
		if(cases[i].caseLigne == element.caseLigne && cases[i].caseColonne == element.caseColonne)
			return true;
	return false;
}

void Matrice::SortCases(){
	bool change = true;
	while(change){
		change = false;
		for(int i=0; i < nombreCases-1; i++){
			if(cases[i].caseLigne + cases[i].caseColonne
					 > cases[i+1].caseLigne + cases[i+1].caseColonne){
				Case sauvegarde = cases[i];
				cases[i] = cases[i+1];
				cases[i+1] = sauvegarde;
				change = true;
			}
			else if(cases[i].caseLigne + cases[i].caseColonne
					 == cases[i+1].caseLigne + cases[i+1].caseColonne){
				if(cases[i].caseLigne > cases[i+1].caseLigne){
					Case sauvegarde = cases[i];
					cases[i] = cases[i+1];
					cases[i+1] = sauvegarde;
					change = true;
				}
			}
		}
	}
}

void Matrice::Charger(string nom){
	ifstream fich("SAUV/"+nom, ios::in);
	if(fich){
		string 	ligne;
		double 	lig,colonne,valeur;

		while(getline(fich,ligne)){
			int 	compteur = 0;
			for(int i=0; i < 3; i++){
				string tmp;
				while(ligne[compteur] != '\0'){
					if(ligne[compteur] == ' ' || ligne[compteur] == '\t'){
						compteur++;
						break;
					}
					tmp += ligne[compteur];
					compteur++;
				}
				if(i == 0)
					lig = stod(tmp);
				else if(i == 1)
					colonne = stod(tmp);
				else if(i == 2)
					valeur = stod(tmp);
			}
			if(!AjouterCase(lig,colonne,valeur)){
				cerr << "Votre matrice n'est pas assez grande pour"
					 << " charger ce fichier !" << endl;
				return;
			}
		}
	}
	else
		cerr << "Aucun fichier de ce nom." << endl;
}

void Matrice::Sauvegarder(string nom){		//Ils peuvent mettre le repertoire souhaité
	ofstream fich("SAUV/"+nom, ios::out);
	if(fich){
		for(int i=0; i < nombreCases; i++){
			fich << cases[i].caseLigne << " " << cases[i].caseColonne << " " 
				 << cases[i].caseValeur << endl;
		}
	}
	else
		cerr << "Sauvegarde impossible." << endl;
}

void Matrice::Transposer(){
	for(int i=0; i < nombreCases; i++){
		int sauvegarde;
		sauvegarde = cases[i].caseLigne;
		cases[i].caseLigne = cases[i].caseColonne;
		cases[i].caseColonne = sauvegarde;
	}
}

Matrice Matrice::operator=(const Matrice& matrice){
	if(tailleLigne == matrice.TailleLigne() 
			&& tailleColonne == matrice.TailleColonne()){
		nombreCases = matrice.NombreCases();
		cases.resize(nombreCases);
		for(int i=0; i < nombreCases; i++)
			cases[i] = matrice(i);
		this->SortCases();
		return *this;
	}
	else{
		cerr << "Egalité impossible entre les matrices : (" 
			 << tailleLigne << "," << tailleColonne << ") et ("
			 << matrice.TailleLigne() << "," << matrice.TailleColonne() << ")"
			 << endl;
		return NULL;
	}
}

Matrice& Matrice::operator+=(const Matrice& matrice){
	if(tailleLigne == matrice.TailleLigne() 
			&& tailleColonne == matrice.TailleColonne()){
		for(int i=0; i < nombreCases; i++){
			for(int j=0;j < matrice.NombreCases(); j++){
				if(cases[i].caseLigne == matrice(j).caseLigne && cases[i].caseColonne == matrice(j).caseColonne){
					this->ModifierCase(cases[i].caseLigne,cases[i].caseColonne,cases[i].caseValeur + matrice(j).caseValeur);
				}
			}
		}
		for(int j=0;j < matrice.NombreCases(); j++)
			if(!this->EstPresent(matrice(j)))
				this->AjouterCase(matrice(j).caseLigne,matrice(j).caseColonne,matrice(j).caseValeur);
		this->SortCases();
		return *this;
	}
	else{
		cerr << "Les matrices ("<< tailleLigne << ","
			 << tailleColonne << ") et ("
			 << matrice.TailleLigne() << "," << matrice.TailleColonne() << ")"
			 << " ne sont pas additionnables." << endl;
	}
}

Matrice& Matrice::operator-=(const Matrice& matrice){
	if(tailleLigne == matrice.TailleLigne() 
			&& tailleColonne == matrice.TailleColonne()){
		for(int i=0; i < nombreCases; i++){
			for(int j=0;j < matrice.NombreCases(); j++){
				if(cases[i].caseLigne == matrice(j).caseLigne && cases[i].caseColonne == matrice(j).caseColonne){
					this->ModifierCase(cases[i].caseLigne,cases[i].caseColonne,cases[i].caseValeur - matrice(j).caseValeur);
				}
			}
		}
		for(int j=0;j < matrice.NombreCases(); j++)
			if(!this->EstPresent(matrice(j)))
				this->AjouterCase(matrice(j).caseLigne,matrice(j).caseColonne, - matrice(j).caseValeur);
		this->SortCases();
		return *this;
	}
	else{
		cerr << "Les matrices ("<< tailleLigne << ","
			 << tailleColonne << ") et ("
			 << matrice.TailleLigne() << "," << matrice.TailleColonne() << ")"
			 << " ne sont pas soustractives." << endl;
	}
}