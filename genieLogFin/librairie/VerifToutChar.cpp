#include <iostream>
#include <fstream>
#include "StringVersInt.cpp"

using namespace std;
int VerifToutChar(int i, string str, int taille){
	i = StringVersInt(str);
	while(i == -1 || i < 0 || i > taille-1){
		cout<<"Veuillez entrer un chiffre valide."<<endl;
		cin>>str;
		i = StringVersInt(str);
	}
return i;
}