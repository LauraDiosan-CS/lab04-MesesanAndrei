#include "Tranzactie.h"
#include <string.h>

Tranzactie::Tranzactie() {
	//Constructorul implicit
	id = 0;
	ziua = 0;
	suma = 0;
	tip = new char[0];
	descriere = new char[0];
}

Tranzactie::Tranzactie(int id, int ziua, int suma, const char* tip, const char* descriere) {
	/*
		Constructorul general.
		in: id - int
			ziua - int
			suma - int
			tip - const char*
			descriere - const char*
		out: -
	*/
	this->id = id;
	this->ziua = ziua;
	this->suma = suma;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->descriere = new char[strlen(descriere) + 1];
	strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
}

Tranzactie::Tranzactie(const Tranzactie& t) {
	/*
		Constructorul de copiere.
		in: t - Tranzactie
		out: -
	*/
	this->id = t.id;
	this->ziua = t.ziua;
	this->suma = t.suma;
	this->tip = new char[strlen(t.tip) + 1];
	strcpy_s(this->tip, strlen(t.tip) + 1, t.tip);
	this->descriere = new char[strlen(t.descriere) + 1];
	strcpy_s(this->descriere, strlen(t.descriere) + 1, t.descriere);
}

int Tranzactie::getZiua() {
	/*
		Returneaza ziua.
		in: -
		out: ziua
	*/
	return ziua;
}

void Tranzactie::setZiua(int z) {
	/*
		Modifica ziua.
		in: z - int
		out: -
	*/
	ziua = z;
}

int Tranzactie::getSuma() {
	/*
		Returneaza suma.
		in: -
		out: suma
	*/
	return suma;
}

void Tranzactie::setSuma(int s) {
	/*
		Modifica suma.
		in: s - int
		out: -
	*/
	suma = s;
}

char* Tranzactie::getTip() {
	/*
		Returneaza tipul.
		in: -
		out: tip
	*/
	return tip;
}

void Tranzactie::setTip(char* t) {
	/*
		Modifica tipul.
		in: t - char*
		out: -
	*/
	if (tip)
		delete[]tip;
	tip = new char[strlen(t) + 1];
	strcpy_s(tip, strlen(t) + 1, t);
}

char* Tranzactie::getDescriere() {
	/*
		Returneaza descrierea.
		in: -
		out: descriere
	*/
	return descriere;
}

void Tranzactie::setId(int id){
	/*
		Modifica id-ul.
		in: id - int
		out: -
	*/
	this->id = id;
}

void Tranzactie::setDescriere(char* d) {
	/*
		Modifica descrierea.
		in: d - char*
		out: -
	*/
	if (descriere)
		delete[]descriere;
	descriere = new char[strlen(d) + 1];
	strcpy_s(descriere, strlen(d) + 1, d);
}

Tranzactie::~Tranzactie() {
	//Destructorul
	if (tip)
		delete[]tip;
	if (descriere)
		delete[]descriere;
	tip = NULL;
	descriere = NULL;
	ziua = -1;
	suma = -1;
}

Tranzactie& Tranzactie::operator=(const Tranzactie& t) {
	/*
		Operator de atribuire.
		in: t - Tranzactie
		out: continutul indicat de this
	*/
	if (this == &t)
		return *this;
	if (tip)
		delete[]tip;
	if (descriere)
		delete[]descriere;
	id = t.id;
	ziua = t.ziua;
	suma = t.suma;
	tip = new char[strlen(t.tip) + 1];
	strcpy_s(tip, strlen(t.tip) + 1, t.tip);
	descriere = new char[strlen(t.descriere) + 1];
	strcpy_s(descriere, strlen(t.descriere) + 1, t.descriere);
	return *this;
}

int Tranzactie::getId(){
	/*
		Returneaza id-ul.
		in: -
		out: id
	*/
	return this->id;
}

bool Tranzactie::operator==(const Tranzactie& t) {
	/*
		Operatorul de egalitate.
		in: t - Tranzactie
		out: true daca este adevarat, false daca nu
	*/
	return this->id == t.id;
}