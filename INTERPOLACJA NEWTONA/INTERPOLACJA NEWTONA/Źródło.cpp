#include <iostream>
using namespace std;

#define size 20

int main()
{
	int n, i, j;
	double x[size], y[size], a, result = 0, mult;

	cout << "Ile punktow: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Podaj x[" << i << "] = ";
		cin >> x[i];
		cout << "Podaj y[" << i << "] = ";
		cin >> y[i];
	}
	cout << "\nWprowadz wartosc do interpolacji: ";
	cin >> a;

	for (j = 0; j < n - 1; j++)
	{
		for (i = n - 1; i>j; i--)
			y[i] = (y[i] - y[i - 1]) / (x[i] - x[i - j - 1]);
	}

	for (i = 0; i < n; i++)
	{
		mult = 1;
		for (j = 0; j < i; j++)
			mult *= (a - x[j]);

		mult *= y[j];
		result += mult;
	}

	cout << "Wynik: " << result << endl;
	system("pause");
	return 0;
}