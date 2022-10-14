#include <iostream>
using namespace std;
int main()
{
	int i, j, n = 3, g, k = 0, d, s;
	double** a;
	a = new double* [n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	double* b;
	b = new double[n];
	double* x;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (j % 3 == 0) /*Таким образом, каждое 4 введеное число будет свободным членом*/
				cin >> g;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
			if (j % 3 == 0)
				cout << g << "\t";
		}
	}
	for (k = 1; k <= n; k++) 
	{
		for (j = k + 1; j <= n; j++)
		{
			d = a[j][k] / a[k][k]; 
			for (i = k; i <= n; i++)
			{
				a[j][i] = a[j][i] - d * a[k][i]; 
			}
			b[j] = b[j] - d * b[k]; 
		}
	}
	for (k = n; k >= 1; k--)
	{
		d = 0;
		for (j = k + 1; j <= n; j++)
		{
			s = a[k][j] * x[j]; 
			d = d + s; 
		}
		x[k] = (b[k] - d) / a[k][k]; 
	}
	for (i = 1; i <= n; i++)
	{
		cout << i << x[i] << " " << endl;
	}
}