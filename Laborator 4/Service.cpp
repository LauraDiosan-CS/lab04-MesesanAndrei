#include "Service.h"

using namespace std;

Service::Service(RepositorySTL& repository): repository{repository}
{
	//Constructorul
}

void Service::addTranzactie(int id, int ziua, int suma, char* tip, char* descriere) {
	/*
		Adauga o tranzactie in repository
		in: id- int
			ziua - int
			suma - int
			tip - char*
			descriere - char*
		out: -
	*/
	Tranzactie noua_tranzactie(id, ziua, suma, tip, descriere);
	repository.addElem(noua_tranzactie);
}

void Service::delTranzactie(int id) {
	/*
		Sterge o tranzactie din repository dupa id.
		in: id - int
		out: -
	*/
	Tranzactie stergere_tranzactie = Tranzactie();
	stergere_tranzactie.setId(id);
	repository.delElem(stergere_tranzactie);
}

Tranzactie Service::updateTranzactie(int id, int ziua, int suma, char* tip, char* descriere){
	/*
		Modifica proprietatile tranzactiei.
		in: id - int
			ziua - int
			suma - int
			tip - char*
			descriere - char*
		out: un repository cu tranzactia modificata
	*/
	Tranzactie modifica_tranzactie(id, ziua, suma, tip, descriere);
	return repository.updateElem(modifica_tranzactie);
}

vector<Tranzactie> Service::getAll() {
	/*
		Returneaza toate elementele din repository.
		in: -
		out: un repository
	*/
	return repository.getAll();
}

Service::~Service() {
	//Destructorul
}