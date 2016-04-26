#include <iostream>
#include <fstream>
#include "../headers/Matrice.h"

using namespace std;

bool EstPresent(int i, int j, Matrice res){
	for(int cpt=0; cpt < res.NombreCases(); cpt++){
		if(res(cpt).caseLigne == i && res(cpt).caseColonne == j){
			return true;
		}
	}
	return false;
}