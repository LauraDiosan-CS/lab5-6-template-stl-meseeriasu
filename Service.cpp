#include "Service.h"

Service::Service() {
	locuriParcare = 0;
}

Service::Service(const Repository& r) {
	repo = r;
	locuriParcare = 0;
}

void Service::setLocuriParcare(int n) {
	locuriParcare = n;
}

int Service::addMasina(const char* numePosesor, const char* nrInmatriculare, const char* status) {
	if (repo.size() == locuriParcare)
		return 1;
	for (int i = 0;i < repo.size();i++)
	{
		Masina m = repo.elemAtPoz(i);
		if (strcmp(m.getNrInmatriculare(), nrInmatriculare) == 0)
			return 2;
	}
	if (strcmp(status, "ocupat") == 0)
		return 3;
	Masina c(numePosesor, nrInmatriculare, status);
	repo.addElem(c);
	return 0;
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