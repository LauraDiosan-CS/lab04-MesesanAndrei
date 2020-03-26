#pragma once
#include "Tranzactie.h"
#include <vector>

using namespace std;

class RepositorySTL {
private:
	vector<Tranzactie> elem;

public:
	RepositorySTL();
	void addElem(Tranzactie);
	bool findElem(Tranzactie);
	void delElem(Tranzactie);
	Tranzactie updateElem(Tranzactie);
	Tranzactie getItemFromPos(int);
	vector<Tranzactie> getAll();
	int dim();
	~RepositorySTL();
};