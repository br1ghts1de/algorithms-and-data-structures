#include <iostream>
#include <vector>
#include <algorithm>
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

struct Node
{
	long long W;
	int from, to;
	Node(long long W, int from, int to) :
		W(W),
		from(from),
		to(to)
	{}
};
bool mycmp(Node a, Node b)
{
	return a.W < b.W;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int ch = n;
	DSU mydsu;
	mydsu.build(n);
	long long ans = 0;
	vector < Node > nodes;
	for (int i = 0; i < k; i++)
	{
		int a, b; long long c;
		cin >> a >> b >> c;
		Node k1(c, a, b);
		nodes.push_back(k1);
	}
	sort(nodes.begin(), nodes.end(),mycmp);
	for (int i = 0; i < nodes.size(); i++)
	{
		if (!mydsu.check(nodes[i].from, nodes[i].to))
		{
			ch--;
			mydsu.glue(nodes[i].from, nodes[i].to);
			ans += nodes[i].W;
		}
	}

	if (ch != 1)
	{
		cout << "NON-CONNECTED" << endl;
		return 0;
	}

	cout << ans << endl;

	return 0;
}