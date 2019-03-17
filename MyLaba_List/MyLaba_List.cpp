#include "stdafx.h"
#include "List.h"

using namespace std;

int main()
{
	Node *first = NULL;

	for (int i = 0; i < 6; i++)
	{
		add(&first, rand() % 10 + -2);
	}
	cout << "List: "; print(first);
	cout << "Length = " << length(first) << '\n';
	cout << "list[5] = " << value(first, 5) << '\n';
	cout << "deleting list[3]..." << endl;
	remove(&first, 3);
	cout << "List: "; print(first);

	system("pause");
	return 0;
}

