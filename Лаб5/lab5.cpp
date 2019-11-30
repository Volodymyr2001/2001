#include "pch.h"
#include "CDataChainSimple.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Generate(a, b)" << endl;
	int a;
	cout << "a = ";
	cin >> a;
	int b;
	cout << "b = ";
	cin >> b;

	CDataSimple First;
	First.Generate(a, b);
	cout << First.GetFullString() << endl;

	return 0;
}
