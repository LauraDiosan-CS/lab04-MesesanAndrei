#pragma once

class Tranzactie {
private:
	int ziua;
	int suma;
	char* tip;
	char* descriere;
public:
	Tranzactie();
	Tranzactie(int, int, const char*, const char*);
	Tranzactie(const Tranzactie&);
	Tranzactie& operator=(const Tranzactie&);
	int getZiua();
	int getSuma();
	char* getTip();
	char* getDescriere();
	void setZiua(int);
	void setSuma(int);
	void setTip(char*);
	void setDescriere(char*);
	bool operator==(const Tranzactie&);
	~Tranzactie();
};