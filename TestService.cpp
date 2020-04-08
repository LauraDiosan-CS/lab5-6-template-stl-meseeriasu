#include <iostream>
#include <assert.h>
#include "Masina.h"
#include "Repository.h"
#include "Service.h"

using namespace std;

void testService() {
	int op;
	Repository r;
	Service service(r);
	service.setLocuriParcare(3);
	Masina car1("radu", "BT03RAD", "liber");
	assert(service.addMasina("Anaa", "CJ03ANA", "liber") == 0);
	op = service.addMasina("depis", "BT14SEB", "liber");
	op = service.addMasina("gigi", "B130GIG", "liber");
	assert(service.getAll().size() == 3);
	service.delMasina("BT14SEB");
	assert(service.getAll().size() == 2);
	service.updateMasina("B130GIG", "radu", "BT03RAD", "liber");
	assert(service.getAll().back() == car1);
	assert(service.addMasina("depis", "BT03RAD", "liber") == 2);
	assert(service.addMasina("laur", "BT09AUR", "ocupat") == 3);
	op = service.addMasina("ana", "B03UIJ", "liber");
	assert(service.addMasina("laur", "BT09AUR", "liber") == 1);
	cout << "Service tests done!" << endl;
}