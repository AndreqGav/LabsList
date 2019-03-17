#include "stdafx.h"
#include "List.h"
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	List<float> amm;

	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		float fl = 0.0, up = 0.0, down = 0.0;

		up = rand() % 9 + 1;
		down = rand() % 9 + 1;
		fl = up / down;
		amm.add(fl);

	}
	cout << "amm:";
	amm.print();
	cout << "---------------------------------------" << endl;

	cout << "fkn = amm.sorted(true)" << endl;
	List<float> fkn = amm.sorted(true);
	cout << "amm.add(0.01)" << endl;
	amm.add(0.01);
	cout << "fkn:";
	fkn.print();

	cout << "amm.sort(false)" << endl;
	amm.sort(false);
	cout << "amm:";
	amm.print();

	cout << "amm.value(100)" << amm.value(100) << endl;

	system("pause");
	return 0;
}

