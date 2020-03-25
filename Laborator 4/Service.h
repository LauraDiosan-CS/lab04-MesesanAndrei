#pragma once

#include "RepositorySTL.h"
#include <vector>

class Service {
private:
	RepositorySTL& repository;
public:
	Service(RepositorySTL& repository);
	void addTranzactie(int ziua, int suma, char* tip, char* descriere);
	void delTranzactie(int ziua, int suma, char* tip, char* descriere);
	Tranzactie updateTranzactie(int ziua_veche, int suma_veche, char* tip_vechi, char* descriere_veche, int ziua, int suma, char* tip, char* descriere);
	vector<Tranzactie> getAll();
	~Service();
};