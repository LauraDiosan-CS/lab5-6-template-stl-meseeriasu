#pragma once
#include <list>
#include "Masina.h"
#include "Repository.h"

using namespace std;

class Service {
private:
	Repository repo;
public:
	Service();
	Service(const Repository&);
	void setLocuriParcare(int);
	void addMasina(const char*, const char*, const char*);
	void delMasina(const char*);
	void updateMasina(const char*, const char*, const char*, const char*);
	int addMasinaParcare(const char*);
	Masina elemAtPoz(int);
	list<Masina> getAll();
	~Service();
};