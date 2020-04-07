#include "Repository.h"
#include "TestRepository.h"
#include <assert.h>
#include <iostream>

using namespace std;

void testRepository() {
	Masina car1("Anaa", "CJ03ANA", "ocupat"), car2("depis", "BT14SEB", "liber"), car3("gigi", "B130GIG", "liber"), car4("Becali", "B13GIG", "ocupat");
	Repository repo;
	repo.addElem(car1);
	repo.addElem(car2);
	list<Masina> rez = repo.getAll();
	assert(rez.size() == 2);
	repo.delElem(car2);
	assert(repo.size() == 1);
	repo.addElem(car3);
	assert(repo.findElem(car3) == 1);
	repo.updateElem(car3, "Becali", "B13GIG", "ocupat");
	assert(repo.findElem(car4) == 1);
	assert(repo.elemAtPoz(1) == car4);
	cout << "Repository tests done!" << endl;
}