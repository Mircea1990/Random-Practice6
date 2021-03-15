#pragma once
#include<iostream>
using namespace std;

class raft
{
private:
	const int idRaft;
	int nrRafturi;
	int capaciateCarti;
	static int contor;
public:
	raft():idRaft(++contor)
	{
		nrRafturi = 0;
		capaciateCarti = 0;
	}

	raft(int nrRafturi, int capacitateCarti) :idRaft(++contor)
	{
		if(nrRafturi > 0)
		{
			this->nrRafturi = nrRafturi;
		}
		else
		{
			nrRafturi = 0;
		}
		if(capaciateCarti > 0)
		{
			this->capaciateCarti = capaciateCarti;
		}
		else
		{
			capaciateCarti = 0;
		}
	}

	int getNrRafturi()
	{
		return nrRafturi;
	}
	void setNrRafturi(int nr)
	{
		if(nr > 0)
		{
			this->nrRafturi = nr;
		}
	}

	int getCapacitateCarti()
	{
		return capaciateCarti;
	}
	void setCapacitateRafturi(int capacitate)
	{
		if(capacitate > 0)
		{
			this->capaciateCarti = capacitate;
		}
	}

};

int raft::contor = 0;