#pragma once
#include <list>
#include "Masina.h"

using namespace std;

class Repository {
	private:
		list <Masina> elem;
	public:
		Repository();
		void addElem(Masina);
		void updateElem(Masina, const char*, const char*, const char*);
		int findElem(Masina);
		void delElem(Masina);
		Masina elemAtPoz(int);
		int size();
		list <Masina> getAll();
		~Repository();
};
