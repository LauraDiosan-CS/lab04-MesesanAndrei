#include "Teste.h"
#include "Tranzactie.h"
#include "RepositorySTL.h"
#include "Service.h"
#include <assert.h>
#include <string.h>
using namespace std;

void testDomain() {
	Tranzactie tr1;
	assert(tr1.getZiua() == 0);
	assert(tr1.getSuma() == 0);
	assert(tr1.getTip() == NULL);
	assert(tr1.getDescriere() == NULL);

	Tranzactie tr2(2, 10, "da", "amenda");
	assert(tr2.getZiua() == 2);
	assert(tr2.getSuma() == 10);
	assert(strcmp(tr2.getTip(), "da") == 0);
	assert(strcmp(tr2.getDescriere(), "amenda")==0);

	tr2.setZiua(20);
	assert(tr2.getZiua() == 20);

	tr2.setSuma(100);
	assert(tr2.getSuma() == 100);

	char* p = new char[3];
	strcpy_s(p, 3, "in");
	tr2.setTip(p);
	assert(strcmp(tr2.getTip(), "in")==0);

	char* a = new char[8];
	strcpy_s(a, 8, "mancare");
	tr2.setDescriere(a);
	assert(strcmp(tr2.getDescriere(), "mancare") == 0);

	Tranzactie t(tr2);
	assert(t.getZiua() == tr2.getZiua());
	assert(t.getSuma() == tr2.getSuma());
	assert(strcmp(t.getTip(), tr2.getTip()) == 0);
	assert(strcmp(t.getDescriere(), tr2.getDescriere()) == 0);

	Tranzactie tr3(3, 10, "da", "amenda");
	t = tr3;
	assert(t == tr3);
	t = t;
	assert(t == t);
}

void testRepository() {
	Tranzactie t1(1, 1, "out", "amenda");
	Tranzactie t2(2, 2, "in", "salar");
	Tranzactie t3(3, 3, "out", "cumparaturi");
	Tranzactie t4(4, 4, "in", "imprumut");
	Tranzactie t_neexistent(1, 1, "out", "amenda");
	RepositorySTL rep;

	rep.addElem(t1);
	rep.addElem(t2);
	rep.addElem(t3);
	rep.addElem(t4);

	assert(rep.getItemFromPos(0) == t1);
	assert(rep.getItemFromPos(1) == t2);

	assert(rep.getAll().size() == 4);

	assert(rep.findElem(t2) == true);
	Tranzactie t5(5, 5, "out", "datorie");
	assert(rep.findElem(t5) == false);
	
	assert(rep.dim() == 4);

	rep.delElem(t3);
	assert(rep.findElem(t3) == false);
	assert(rep.dim() == 3);

	char* p = new char[3];
	strcpy_s(p, 3, "in");
	char* q = new char[6];
	strcpy_s(q, 6, "salar");
	Tranzactie t1_nou = rep.updateElem(t1, 10, 10, p, q);

	assert(strcmp(t1_nou.getTip(), "in") == 0);
	assert(strcmp(t1_nou.getDescriere(), "salar") == 0);

	t1_nou = rep.updateElem(t_neexistent, 10, 10, p, q);
	assert(t1_nou == t_neexistent);
}

void testService() {
	RepositorySTL rep;
	Service service(rep);
	assert(service.getAll().size() == 0);

	Tranzactie t1(1, 1, "out", "amenda");
	Tranzactie t2(2, 2, "in", "salar");
	Tranzactie t3;
	Tranzactie t4(4, 4, "in", "imprumut");
	Tranzactie t_neexistent(1, 1, "out", "amenda");

	service.addTranzactie(t1.getZiua(), t1.getSuma(), t1.getTip(), t1.getDescriere());
	service.addTranzactie(t2.getZiua(), t2.getSuma(), t2.getTip(), t2.getDescriere());

	assert(service.getAll().size() == 2);

	char* p = new char[4];
	strcpy_s(p, 4, "out");
	char* q = new char[8];
	strcpy_s(q, 8, "facturi");
	t3 = service.updateTranzactie(t2.getZiua(), t2.getSuma(), t2.getTip(), t2.getDescriere(), 20, 20, p, q);
	assert(t3.getZiua() == 20);
	assert(t3.getSuma() == 20);
	assert(strcmp(t3.getTip(), "out") == 0);
	assert(strcmp(t3.getDescriere(), "facturi") == 0);

	service.delTranzactie(20, 20, p, q);
	assert(service.getAll().size() == 1);
}