#pragma once

#include "RepositorySTL.h"
#include <vector>

class Service {
private:
	RepositorySTL& repository;
public:
	Service(RepositorySTL& repository);
	void addTranzactie(int id, int ziua, int suma, char* tip, char* descriere);
	void delTranzactie(int id);
	Tranzactie updateTranzactie(int id, int ziua, int suma, char* tip, char* descriere);
	vector<Tranzactie> getAll();
	~Service();
};