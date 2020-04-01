#pragma once
#include <list>
#include "Masina.h"

using namespace std;

class Repository {
	private:
		list<Masina> elem;
	public:
		Repository();
		void addElem(const Masina);
		list<Masina> getAll();
		~Repository();
};
