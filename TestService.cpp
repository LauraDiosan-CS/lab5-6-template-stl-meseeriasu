#include <iostream>
#include <assert.h>
#include "Masina.h"
#include "Repository.h"
#include "Service.h"

using namespace std;

void testService() {
	Repository r;
	Service service(r);
	Masina car1("radu", "BT03RAD", "liber");
	service.addMasina("Anaa", "CJ03ANA", "ocupat");
	service.addMasina("depis", "BT14SEB", "liber");
	service.addMasina("gigi", "B130GIG", "liber");
	assert(service.getAll().size() == 3);
	service.delMasina("BT14SEB");
	assert(service.getAll().size() == 2);
	service.updateMasina("B130GIG", "radu", "BT03RAD", "liber");
	assert(service.getAll().back() == car1);
	cout << "Service tests done!" << endl;
}