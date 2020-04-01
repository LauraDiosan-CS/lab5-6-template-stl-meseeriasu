#include "Repository.h"

Repository::Repository() {

}

void Repository::addElem(const Masina m) {
	elem.push_back(m);
}

list<Masina> Repository::getAll() {
	return elem;
}

Repository::~Repository() {
}