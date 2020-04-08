#pragma once
#include <list>
#include "Masina.h"

using namespace std;

class Repository {
private:
	list <Masina> elem;
	char** parcare;
	int locuriParcare, statusLocuri;
public:
	Repository();
	void setLocuriParcare(int);
	int getLocuriParcare();
	void addElem(Masina);
	void updateElem(Masina, const char*, const char*, const char*);
	int findElem(Masina);
	void delElem(Masina);
	Masina elemAtPoz(int);
	int size();
	int intrareParcare(const char*);
	list <Masina> getAll();
	~Repository();
};