#include <iostream>
#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface() {
}

UserInterface::UserInterface(const Service& s) {
	service = s;
}

void UserInterface::showMenu() {
	cout << "---Menu---" << endl;
	cout << "1. Adauga masina" << endl;
	cout << "2. Update masina" << endl;
	cout << "3. Sterge masina" << endl;
	cout << "4. Afiseaza masini" << endl;
	cout << "0. Exit" << endl;
	cout << endl;
}

void UserInterface::addMasina() {
	char* numePosesor = NULL, * nrInmatriculare = NULL, * status = NULL;
	numePosesor = new char[20];
	nrInmatriculare = new char[20];
	status = new char[20];
	cout << "Nume posesor: ";	cin >> numePosesor;
	cout << "Numar inmatriculare: ";	cin >> nrInmatriculare;
	cout << "Status (ocupat, liber): ";	cin >> status;
	service.addMasina(numePosesor, nrInmatriculare, status);
	if (numePosesor)
		delete[] numePosesor;
	if (nrInmatriculare)
		delete[] nrInmatriculare;
	if (status)
		delete[] status;
	cout << "Masina adaugata!" << endl;
	cout << endl;
}

void UserInterface::printMasini() {
	for (int i = 0;i < service.getAll().size();i++)
		cout << service.elemAtPoz(i).getNumePosesor() << " " << service.elemAtPoz(i).getNrInmatriculare() << " " << service.elemAtPoz(i).getStatus() << endl;
	cout << endl;
}

void UserInterface::deleteMasina() {
	char* nrInmatriculare = NULL;
	nrInmatriculare = new char[20];
	cout << "Nr. de inmatriculare: ";	cin >> nrInmatriculare;
	service.delMasina(nrInmatriculare);
	if (nrInmatriculare)
		delete[] nrInmatriculare;
	cout << "Masina stearsa!" << endl;
	cout << endl;
}

void UserInterface::updateMasina() {
	char* nrInmatriculare = NULL, * newNumePosesor = NULL, * newNrInmatriculare = NULL, * newStatus = NULL;
	nrInmatriculare = new char[20];
	newNumePosesor = new char[20];
	newNrInmatriculare = new char[20];
	newStatus = new char[20];
	cout << "Nr. inmatriculare: ";	cin >> nrInmatriculare;
	cout << "Noul posesor: ";	cin >> newNumePosesor;
	cout << "Noul nr. de inmatriculare: ";	cin >> newNrInmatriculare;
	cout << "Noul status: ";	cin >> newStatus;
	service.updateMasina(nrInmatriculare, newNumePosesor, newNrInmatriculare, newStatus);
	if (nrInmatriculare)
		delete[] nrInmatriculare;
	if (newNumePosesor)
		delete[] newNumePosesor;
	if (newNrInmatriculare)
		delete[] newNrInmatriculare;
	if (newStatus)
		delete[] newStatus;
	cout << "Update realizat!" << endl;
	cout << endl;
}

void UserInterface::run() {
	bool gata = true;
	while (gata)
	{
		int op;
		showMenu();
		cout << "Optiunea aleasa: ";
		cin >> op;
		switch (op)
		{
		case 0: {gata = false; break;}
		case 1: {addMasina(); break;}
		case 2: {updateMasina(); break;}
		case 3: {deleteMasina(); break;}
		case 4: {printMasini(); break;}
		}
	}
}

UserInterface::~UserInterface() {
}
