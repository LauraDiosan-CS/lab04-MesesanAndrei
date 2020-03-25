#include "Service.h"

using namespace std;

Service::Service(RepositorySTL& repository): repository{repository}
{

}

void Service::addTranzactie(int ziua, int suma, char* tip, char* descriere) {
	Tranzactie noua_tranzactie(ziua, suma, tip, descriere);
	repository.addElem(noua_tranzactie);
}

void Service::delTranzactie(int ziua, int suma, char* tip, char* descriere) {
	Tranzactie stergere_tranzactie(ziua, suma, tip, descriere);
	repository.delElem(stergere_tranzactie);
}

Tranzactie Service::updateTranzactie(int ziua_veche, int suma_veche, char* tip_vechi, char* descriere_veche, int ziua, int suma, char* tip, char* descriere){
	Tranzactie modifica_tranzactie(ziua_veche, suma_veche, tip_vechi, descriere_veche);
	return repository.updateElem(modifica_tranzactie, ziua, suma, tip, descriere);
}

vector<Tranzactie> Service::getAll() {
	return repository.getAll();
}

Service::~Service() {

}