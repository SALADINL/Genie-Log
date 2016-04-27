#include <iostream>
#include "librairie/librairie.cpp"

using namespace std;

int main(){
/*
	Matrice A(5,4);
	cout << A; cout << endl;
	A.AjouterCase(1,2,3.4);
	A.AjouterCase(3,2,5.6);
	cout << A; cout << endl;
	Matrice B(10,10);
//	B.Initialisation();
	B.Charger("matricedeuxdeux.txt");
	cout << B; cout << endl;
	B.Transposer();
	B.Sauvegarder("lel.txt");
	cout << B; cout << endl;

*/
/*	Matrice A;
	A.AjouterCase(1,1,5.2);
	A.AjouterCase(0,1,3.4);
	cout << A;
	cout << endl;

	Matrice B;
	B.AjouterCase(1,0,4.1);
	cout << B;
	cout << endl;

	Matrice C;
	C = A * B;
	cout << C;
	cout << endl << endl << endl << endl << endl;
*/
/*
	Matrice D(2,2);
	D.AjouterCase(0,0,2);
	D.AjouterCase(0,1,3);
	D.AjouterCase(1,0,1);
	D.AjouterCase(1,1,4);
	Matrice E(2,3);
	E.AjouterCase(0,0,0);
	E.AjouterCase(0,1,1);
	E.AjouterCase(1,0,2);
	E.AjouterCase(1,1,5.2);
	Matrice F(2,2);
	F = D - E;
	cout << F; cout << endl;
	D -= E ;
	cout << D;
*/

/*	Matrice A(3,3);
	A.AjouterCase(1,0,3.4);
	//A.AjouterCase(3,4,3.6);
	A.AjouterCase(1,1,5.2);
	cout << A; cout << endl;

	Matrice B(3,3);
	//B.AjouterCase(3,5,4.9);
	B.AjouterCase(1,1,4.1);
	//B.AjouterCase(3,4,3.8);
	cout << B; cout << endl;

	Matrice C(3,3);
	C = A * B;
	cout << C; cout << endl;

	A+=B;
	cout << A; cout << endl;

*/
	Matrice A(3,3);
	A.Initialisation();
	cout << A; cout << endl;
	Matrice B(3,3);
	B.Charger("matricedeuxdeux.txt");
	cout << B; cout << endl;
	Matrice C(3,3);

	C = A + B;
	cout << C; cout << endl;

/*
	Matrice C(3,3);
	C.Charger("matricedeuxdeux.txt");
	C.AjouterCase(0,0,13);
	cout << C; cout << endl;

	Matrice D(3,3);
	D.Charger("matricedeuxdeux.txt");
	D.AjouterCase(2,1,24);
	cout << D; cout << endl;

	Matrice A(3,3);

	A = C + D;
	cout << A; cout << endl;

	C += D;
	cout << C; cout << endl;
*/

return 0;
}
