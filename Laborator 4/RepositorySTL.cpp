#include "RepositorySTL.h"

RepositorySTL::RepositorySTL() {
	//Constructorul
}

void RepositorySTL::addElem(Tranzactie t) {
	/*
		Adauga un element la sfarsit.
		in: t - Tranzactie
		out: -
	*/

	elem.push_back(t);
}

void RepositorySTL::delElem(Tranzactie t) {
	/*
		Cauta elementul primit ca parametru si il sterge.
		in: t - Tranzactie
		out: -
	*/
	vector<Tranzactie>::iterator it;
	it = find(elem.begin(), elem.end(), t);
	if (it != elem.end())
		elem.erase(it);
}

bool RepositorySTL::findElem(Tranzactie t) {
	/*
		Cauta elementul primit ca parametru, iar daca il gaseste returneaza true, altfel false.
		in: t - Tranzactie
		out: true daca exista, false daca nu exista
	*/
	vector<Tranzactie>::iterator it;
	it = find(elem.begin(), elem.end(), t);
	if (it != elem.end())
		return true;
	return false;
}

int RepositorySTL::dim() {
	/*
		Returneaza dimensiunea vectorului.
		in: -
		out: dimensiunea vectorului
	*/
	return elem.size();
}

Tranzactie RepositorySTL::getItemFromPos(int i) {
	/*
		Returneaza elementyl de pe pozitia primita ca parametru.
		in: i - int
		out: elementul de pe pozitia i
	*/
	return elem[i];
}

RepositorySTL::~RepositorySTL() {
	//Destructorul
}

vector<Tranzactie> RepositorySTL::getAll() {
	/*
		Returneaza toate elementele din vector.
		in: - 
		out: vectorul
	*/
	return elem;
}

Tranzactie RepositorySTL::updateElem(Tranzactie t) {
	/*
		Modifica proprietatile tranzactiei.
		in: t - Tranzactie
		out: tranzactia modificata daca aceasta exista in vector, daca nu tranzactia primita ca parametru
	*/
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getId() == t.getId()) {
			elem[i].setZiua(t.getZiua());
			elem[i].setSuma(t.getSuma());
			elem[i].setTip(t.getTip());
			elem[i].setDescriere(t.getDescriere());
			return elem[i];
		}
	}
	return t;
}