#include <iostream>
#include <fstream>

using namespace std;
double StringVersDouble(string mot){
	int cpt=0;
	while(mot[cpt] != '\0'){
		if(mot[cpt] != '.' && (mot[cpt] < '0' || mot[cpt] > '9'))
			return 0;
		cpt++;
	}
	return stod(mot);
}