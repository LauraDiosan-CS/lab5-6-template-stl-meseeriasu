#include <iostream>
#include "TestDomain.h"
#include "TestRepository.h"
#include "TestService.h"
#include "Repository.h"
#include "Service.h"
#include "UserInterface.h"

using namespace std;

int main()
{
	testMasina();
	testRepository();
	testService();
	Repository r;
	Service s(r);
	UserInterface ui(s);
	ui.run();
}