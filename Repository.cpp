#include "Repository.h"

using namespace std;

Repository::Repository() {
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
	list<Masina>::iterator it=elem.begin();
	for (int i = 0;i < elem.size();i++)
	{
		if (i == j)
			return *it;
		advance(it, 1);
	}
}

Repository::~Repository() {
}