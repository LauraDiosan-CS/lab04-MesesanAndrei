#include "Tranzactie.h"
#include <string.h>

Tranzactie::Tranzactie() {
	ziua = 0;
	suma = 0;
	tip = NULL;
	descriere = NULL;
}

Tranzactie::Tranzactie(int ziua, int suma, const char* tip, const char* descriere) {
	this->ziua = ziua;
	this->suma = suma;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->descriere = new char[strlen(descriere) + 1];
	strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
}

Tranzactie::Tranzactie(const Tranzactie& t) {
	this->ziua = t.ziua;
	this->suma = t.suma;
	this->tip = new char[strlen(t.tip) + 1];
	strcpy_s(this->tip, strlen(t.tip) + 1, t.tip);
	this->descriere = new char[strlen(t.descriere) + 1];
	strcpy_s(this->descriere, strlen(t.descriere) + 1, t.descriere);
}

int Tranzactie::getZiua() {
	return ziua;
}

void Tranzactie::setZiua(int z) {
	ziua = z;
}

int Tranzactie::getSuma() {
	return suma;
}

void Tranzactie::setSuma(int s) {
	suma = s;
}

char* Tranzactie::getTip() {
	return tip;
}

void Tranzactie::setTip(char* t) {
	if (tip)
		delete[]tip;
	tip = new char[strlen(t) + 1];
	strcpy_s(tip, strlen(t) + 1, t);
}

char* Tranzactie::getDescriere() {
	return descriere;
}

void Tranzactie::setDescriere(char* d) {
	if (descriere)
		delete[]descriere;
	descriere = new char[strlen(d) + 1];
	strcpy_s(descriere, strlen(d) + 1, d);
}

Tranzactie::~Tranzactie() {
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
	if (this == &t)
		return *this;
	if (tip)
		delete[]tip;
	if (descriere)
		delete[]descriere;
	ziua = t.ziua;
	suma = t.suma;
	tip = new char[strlen(t.tip) + 1];
	strcpy_s(tip, strlen(t.tip) + 1, t.tip);
	descriere = new char[strlen(t.descriere) + 1];
	strcpy_s(descriere, strlen(t.descriere) + 1, t.descriere);
	return *this;
}

bool Tranzactie::operator==(const Tranzactie& t) {
	return (ziua == t.ziua) and (suma == t.suma) and (strcmp(tip, t.tip) == 0) and (strcmp(descriere, t.descriere) == 0);
}