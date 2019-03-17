#include "stdafx.h"
#include "List.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	List amm;

	for (int i = 0; i < 5; ++i)
		amm.add(rand() % 10 - 2);
	cout << "amm: ";
	amm.print();
	cout << "amm[1] = 3" << endl;
	cout << "amm[0] = 0" << endl;
	amm[1] = 3;
	amm[0] = 0;
	cout << "amm: ";
	amm.print();
	cout << "amm[5] = 2" << endl;
	amm[5] = 2;

	cout << "amm[4]: " << amm[4] << endl;
	cout << "amm[7]: " << amm[7] << endl;

	cout << "amm.sort(false)" << endl;
	amm.sort(false);
	cout << "amm: ";
	amm.print();

	cout << " - - - - - - - - - -" << endl;

	cout << "fkn = amm.sorted(true)";
	List fkn = amm.sorted(true);
	cout << "fkn: ";
	fkn.print();
	cout << "--------------------" << endl;
	cout << "amm: ";
	amm.print();

	system("pause");
	return 0;
}

