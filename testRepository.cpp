#include "Repository.h"
#include "TestRepository.h"
#include <assert.h>
#include <iostream>

using namespace std;

void testRepository() {
	Masina car1("Anaa", "CJ03ANA", "ocupat");
	Repository repo;
	repo.addElem(car1);
	list<Masina> rez = repo.getAll();
	cout << rez.size();
	assert(rez.size() == 1);
	cout << "Repository tests done!";
}