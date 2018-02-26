#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DSU
{
	vector<int>pr;
	vector<int>rank;

	void build(int size)
	{
		pr.resize(size);
		rank.assign(size, 1);
		for (int i = 0; i < size; i++)
		{
			pr[i] = i;
		}
	}

	int get(int v)
	{
		return v == pr[v] ? pr[v] : get(pr[v]);
	}

	void glue(int a, int b)
	{
		a = get(a);
		b = get(b);

		if (rank[a] < rank[b])
		{
			swap(a, b);
		}

		pr[b] = a;
		rank[a] += rank[b];
	}

	bool check(int a, int b)
	{
		return get(a) == get(b);
	}

};

int main()
{
	DSU mydsu;
	string query;
	while (cin >> query)
	{
		int a, b;
		if (query == "RESET")
		{
			cin >> a;
			mydsu.build(a);
			cout << "RESET DONE" << endl;
		}
		if (query == "JOIN")
		{
			cin >> a >> b;
			//a--; b--;
			if (mydsu.check(a,b))
			{
				cout << "ALREADY " << a << " " << b << endl;
			}
			mydsu.glue(a, b);

		}
		if (query == "CHECK")
		{
			cin >> a >> b;
			//a--; b--;
			if (mydsu.check(a, b))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
 			}
		}
	}

	return 0;
}