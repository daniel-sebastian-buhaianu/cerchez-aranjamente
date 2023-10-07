#include <iostream>

using namespace std;

int main()
{
	int n, m;

	cout << "n = "; cin >> n;
	cout << "m = "; cin >> m;

	int f[n+1], a[m+1], i, j, gata, pot;

	for (i = 0; i <= n; i++)
	{
		f[i] = 0;
	}

	for (i = 1; i <= m; i++)
	{
		a[i] = i;
		f[i] = 1;
	}

	gata = 0;

	while (!gata)
	{
		// afisez configuratia curenta

		for (i = 1; i <= m; i++)
		{
			cout << a[i] << ' ';
		}

		cout << '\n';

		// generez urmatoarea configuratie
		
		for (i = m; i > 0; i--)
		{
			// il pot creste pe a[i]?
			pot = 0;

			for (j = a[i]+1; j <= n; j++)
			{
				if (f[j] == 0)
				{
					pot = 1;
					break;
				}
			}

			if (pot)
			{
				break;
			}
			else
			{
				f[a[i]] = 0;
			}
		}

		if (i == 0)
		{
			gata = 1; // ultima configuratie
		}
		else
		{
			f[a[i]] = 0;

			a[i] = j;
			f[a[i]] = 1;

			for (i = i+1; i <= m; i++)
			{
				for (j = 1; j <= n && f[j] == 1; j++);

				a[i] = j;
				f[a[i]] = 1;
			}
		}
	}

	return 0;
}
