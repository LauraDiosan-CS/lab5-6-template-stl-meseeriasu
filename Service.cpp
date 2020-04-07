#include "Service.h"

Service::Service() {
}

Service::Service(const Repository& r) {
	repo = r;
}

void Service::addMasina(const char* numePosesor, const char* nrInmatriculare, const char* status) {
	Masina c(numePosesor, nrInmatriculare, status);
	repo.addElem(c);
}

list<Masina> Service::getAll() {
	return repo.getAll();
}

void Service::delMasina(const char* nrInamtriculare) {
	for (int i = 0;i < repo.size();i++)
	{
		Masina car = repo.elemAtPoz(i);
		if (strcmp(car.getNrInmatriculare(), nrInamtriculare) == 0)
		{
			repo.delElem(car); break;
		}
	}
}

void Service::updateMasina(const char* nrInmatriculare, const char* newNumePosesor, const char* newNrInmatriculare, const char* newStatus) {
	for (int i = 0;i < repo.size();i++)
	{
		Masina car = repo.elemAtPoz(i);
		if (strcmp(car.getNrInmatriculare(), nrInmatriculare) == 0)
		{
			repo.updateElem(car, newNumePosesor, newNrInmatriculare, newStatus); break;
		}
	}
}

Masina Service::elemAtPoz(int j)
{
	return repo.elemAtPoz(j);
}

Service::~Service()
{
}