#include <iostream>
#include <fstream>

using namespace std;

int StringVersInt(string mot){
	int cpt=0;
	while(mot[cpt] != '\0'){
		if(mot[cpt] < '0' || mot[cpt] > '9')
			return -1;
		cpt++;
	}
	return stoi(mot);
}