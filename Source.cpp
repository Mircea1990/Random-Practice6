#include "biblioteca.h"
#include "raft.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int vector [5] = { 41,20,3,47,51 };
	biblioteca b1(vector, 5, "20000 leghe sub mari", "Roman", 1920);

	biblioteca* b2 = new biblioteca(vector, 5, "Maitrei", "Roman", 1964);

	biblioteca* b3(b2);

	biblioteca b4;
	b4 = b1;

	int vector2 [] = { 4,5,48,75,5,3 };
	biblioteca b5(vector2, 6, "Cartea Junglei", "Povestire", 1894);

	cout << "Operatorul bool" << endl;
	bool b = operator!(b1);
	cout << b << endl;

	cout << "Numarul de carti" << endl;
	cout << b2->getNrCarti() << endl;
	
	++b1;
	cout << "Numarul de carti preincrementare" << endl;
	cout << b1.getNrCarti() << endl;

	cout << "Numarul de carti postincrementare" << endl;
	b4++;
	cout << b4.getNrCarti() << endl;

	cout << "An publicare"<< endl;
	cout << b4.getAnPublicare() << endl;
	b4.setAnPublicare(1980);
	b4 + 10;
	cout << b4.getAnPublicare() << endl;


	/*int VectorCarti [] = { 10,20,30,40,50,60 };
	b5.setCarti(VectorCarti, 6);
	int* carti = b4.getCarti();
	cout << *carti << endl;*/


	cout << b1.getId() << endl;
	cout << b3->getId() << endl;

	cout << "Medie carti" << endl;
	
	biblioteca biblio [] = { b1, b5 };
	cout<< biblioteca::medieCarti(biblio, 2)<<endl;


}


