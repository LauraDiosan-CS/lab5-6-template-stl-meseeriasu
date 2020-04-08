#include "Repository.h"

using namespace std;

Repository::Repository() {
	locuriParcare = 0;
	statusLocuri = 0;
	parcare = new char* [10];
	for (int count = 0; count < 10; ++count)
		parcare[count] = new char[10];
}

void Repository::setLocuriParcare(int n) {
	locuriParcare = n;
}

int Repository::getLocuriParcare() {
	return locuriParcare;
}

void Repository::addElem(Masina m) {
	elem.push_back(m);
}

list<Masina> Repository::getAll() {
	return elem;
}

void Repository::delElem(Masina m) {
	list<Masina>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end())
		elem.erase(it);
}

int Repository::findElem(Masina m) {
	list<Masina>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end()) {
		return distance(elem.begin(), it);
	}
	return -1;
}

void Repository::updateElem(Masina m, const char* numePosesor, const char* nrInmatriculare, const char* status) {
	list<Masina>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end()) {
		(*it).setNumePosesor(numePosesor);
		(*it).setNrInmatriculare(nrInmatriculare);
		(*it).setStatus(status);
	}
}

int Repository::size() {
	return elem.size();
}

Masina Repository::elemAtPoz(int j) {
	list<Masina>::iterator it = elem.begin();
	for (int i = 0;i < elem.size();i++)
	{
		if (i == j)
			return *it;
		advance(it, 1);
	}
}

int Repository::intrareParcare(const char* nrImatriculare) {
	for (int i = 0;i < locuriParcare;i++)
		if (strcmp(parcare[i], nrImatriculare) == 0)
			return 1;
	if (statusLocuri == locuriParcare)
		return 2;
	bool masinaRepository = false;
	for (int i = 0;i < size();i++)
	{
		Masina m;
		m = elemAtPoz(i);
		if (strcmp(m.getNrInmatriculare(), nrImatriculare) == 0)
		{
			masinaRepository = true;
			break;
		}
	}
	if (masinaRepository == false)
		return 3;
	strcpy_s(parcare[statusLocuri], strlen(nrImatriculare) + 1, nrImatriculare);
	statusLocuri++;
	return 0;
}

Repository::~Repository() {
	for (int count = 0; count < 10; ++count)
		delete[] parcare[count];
	delete[] parcare;
}