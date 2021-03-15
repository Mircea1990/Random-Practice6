#pragma once
#include<iostream>
#include<string>
#include "raft.h"

using namespace std;

class biblioteca
{
private:
	int* carti;
	int nrCarti;
	const int id;
	char* numeCarte;
	char* categoria;
	int anPublicare;
	static string numeBiblioteca;
	static int nrId;
	raft raft;
public:

	biblioteca() :id(nrId++)
	{
		carti = nullptr;
		nrCarti = 0;
		numeCarte = nullptr;
		categoria = nullptr;
		anPublicare = 1;
		
	}

	biblioteca(int* carti, int nrCarti, const char* numeCarte, const char* categoria, int anPublicare) :id(nrId++)
	{
		if(carti != nullptr && nrCarti > 0)
		{
			this->carti = new int [nrCarti];
			for(int i = 0; i < nrCarti; i++)
			{
				this->carti [i] = carti [i];
			}
			this->nrCarti = nrCarti;
		}
		else
		{
			carti = nullptr;
			nrCarti = 0;
		}
		if(numeCarte != nullptr)
		{
			this->numeCarte = new char [strlen(numeCarte) + 1];
			strcpy_s(this->numeCarte, strlen(numeCarte) + 1, numeCarte);
		}
		if(categoria != nullptr)
		{
			this->categoria = new char [strlen(categoria) + 1];
			strcpy_s(this->categoria, strlen(categoria) + 1, categoria);
		}
		else
		{
			numeCarte = nullptr;
			categoria = nullptr;
		}
		this->anPublicare = anPublicare;
	}


	~biblioteca()
	{
		if(carti != nullptr && nrCarti > 0)
		{
			delete [] carti;
		}
		if(numeCarte != nullptr)
		{
			delete [] numeCarte;
		}
		if(categoria != nullptr)
		{
			delete [] categoria;
		}
	}

	biblioteca(const biblioteca& b) : id(++nrId)
	{
		if(b.carti != nullptr && b.nrCarti > 0)
		{
			nrCarti = b.nrCarti;
			carti = new int [b.nrCarti];
			for(int i = 0; i < b.nrCarti; i++)
			{
				carti [i] = b.carti [i];
			}
		}
		else
		{
			carti = nullptr;
			nrCarti = 0;
		}
		if(b.numeCarte != nullptr)
		{
			numeCarte = new char [strlen(b.numeCarte) + 1];
			strcpy_s(numeCarte, strlen(b.numeCarte) + 1, b.numeCarte);
		}
		else
		{
			numeCarte = nullptr;
		}
		if(b.categoria != nullptr)
		{
			categoria = new char [strlen(b.categoria) + 1];
			strcpy_s(categoria, strlen(b.categoria) + 1, b.categoria);
		}
		else
		{
			categoria = nullptr;
		}
		if(b.anPublicare > 0)
		{
			anPublicare = b.anPublicare;
		}
		else
		{
			anPublicare = 0;
		}
	}

	biblioteca& operator=(biblioteca& b)
	{
		if(carti != nullptr && nrCarti > 0)
		{
			delete [] carti;
		}
		if(numeCarte != nullptr)
		{
			delete [] numeCarte;
		}
		if(categoria != nullptr)
		{
			delete [] categoria;
		}
		if(b.carti != nullptr && b.nrCarti > 0)
		{
			nrCarti = b.nrCarti;
			carti = new int [b.nrCarti];
			for(int i = 0; i < b.nrCarti; i++)
			{
				carti [i] = b.carti [i];
			}
		}
		else
		{
			carti = nullptr;
			nrCarti = 0;
		}
		if(b.numeCarte != nullptr)
		{
			numeCarte = new char [strlen(b.numeCarte) + 1];
			strcpy_s(numeCarte, strlen(b.numeCarte) + 1, b.numeCarte);
		}
		else
		{
			numeCarte = nullptr;
		}
		if(b.categoria != nullptr)
		{
			categoria = new char [strlen(b.categoria) + 1];
			strcpy_s(categoria, strlen(b.categoria) + 1, b.categoria);
		}
		else
		{
			categoria = nullptr;
		}
		if(b.anPublicare > 0)
		{
			anPublicare = b.anPublicare;
		}
		else
		{
			anPublicare = 0;
		}
		return *this;

	}

	int getNrCarti()
	{
		return this->nrCarti;
	}
	void setNrCarti(int nrCarti)
	{
		this->nrCarti = nrCarti;
	}

	int getAnPublicare()
	{
		return anPublicare;
	}

	void setAnPublicare(int an)
	{
		if(anPublicare != 0)
		{
			anPublicare = an;
		}
	}

	int* getCarti()
	{
		if(carti != nullptr)
		{
			int* copie = new int [nrCarti];
			for(int i = 0; i < nrCarti; i++)
			{
				copie [i] = carti [i];
			}
			return copie;
		}
		else
		{
			carti = nullptr;
		}
	}

	void setCarti(int* carti, int nrCarti)
	{
		if(this->carti != nullptr)
		{
			delete [] this->carti;
		}
		if(carti != nullptr && nrCarti > 0)
		{
			this->nrCarti = nrCarti;
			this->carti = new int [nrCarti];
			for(int i = 0; i < nrCarti; i++)
			{
				this->carti [i] = carti [i];
			}
		}
		else
		{
			carti = nullptr;
			nrCarti = 0;
		}
	}

	int getId()
	{
		return id;
	}

	static float medieCarti(biblioteca* b, int nrCarti)
	{
		float suma = 0;
		float contor = 0;
		for(int i = 0; i < nrCarti; i++)
		{
			if(b [i].carti != nullptr)
			{
				for(int j = 0; j < b [i].nrCarti; j++)
				{
					suma += b [i].carti [i];
					contor++;
				}
			}
			else
			{
				b [i].carti = nullptr;
			}
		}
		return (suma > 0) ? suma / contor : 0;
	}

	friend biblioteca& operator++(biblioteca& b);
	friend biblioteca& operator++(biblioteca& b, int);
	friend biblioteca& operator+(biblioteca& b, int anPublicare);

	friend bool operator!(biblioteca& b);
};

biblioteca& operator+(biblioteca& b, int anPublicare)
{
	biblioteca copie = b;
	b.anPublicare += anPublicare;
	return copie;
}

biblioteca& operator++(biblioteca& b)
{
	if(b.nrCarti <= 20)
	{
		b.nrCarti++;
	}
	return b;
}

biblioteca& operator++(biblioteca& b, int)
{
	if(b.nrCarti > 0)
	{
		biblioteca copie = b;
		b.nrCarti++;
		return copie;
	}
}

bool operator!(biblioteca& b)
{
	return b.anPublicare < 2000;
}

string biblioteca::numeBiblioteca = "Biblioteca Nationala";
int biblioteca::nrId = 1;

