#include "stdafx.h"
#include "List.h"

using namespace std;

int main()
{
	List first;

	for (int i = 0; i < 6; i++)
	{
		first.add(rand() % 10 + -2);
	}
	cout << "List: "; first.print();
	cout << "Length = " << first.length() << '\n';
	cout << "list[5] = " << first.value(5) << '\n';
	cout << "deleting list[3]..." << endl;
	first.remove(3);
	cout << "List: "; first.print();

	system("pause");
	return 0;
}

