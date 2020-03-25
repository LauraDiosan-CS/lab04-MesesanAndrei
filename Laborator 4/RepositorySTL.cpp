#include "RepositorySTL.h"

RepositorySTL::RepositorySTL() {

}

void RepositorySTL::addElem(Tranzactie t) {
	elem.push_back(t);
}

void RepositorySTL::delElem(Tranzactie t) {
	vector<Tranzactie>::iterator it;
	it = find(elem.begin(), elem.end(), t);
	if (it != elem.end())
		elem.erase(it);
}

bool RepositorySTL::findElem(Tranzactie t) {
	vector<Tranzactie>::iterator it;
	it = find(elem.begin(), elem.end(), t);
	if (it != elem.end())
		return true;
	return false;
}

int RepositorySTL::dim() {
	return elem.size();
}

Tranzactie RepositorySTL::getItemFromPos(int i) {
	return elem[i];
}

RepositorySTL::~RepositorySTL() {

}

vector<Tranzactie> RepositorySTL::getAll() {
	return elem;
}

Tranzactie RepositorySTL::updateElem(Tranzactie t, int ziua, int suma, char* tip, char* descriere) {
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == t) {
			elem[i].setZiua(ziua);
			elem[i].setSuma(suma);
			elem[i].setTip(tip);
			elem[i].setDescriere(descriere);
			return elem[i];
		}
	}
	return t;
}