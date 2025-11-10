#include <iostream>
#include <vector>
using namespace std;

void input(int &k, vector<int> *arr)
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int l;
		cin >> l;
		arr->push_back(l);
	}
}

void firstfit(vector<int> partitions, vector<int> processes)
{
	int sum = 0;
	int n = partitions.size();
	int m = processes.size();

	cout << endl;
	cout << "First Fit" << endl;

	vector<int> partition_taken(n, 0);
	for (int i = 0; i < m; i++)
	{
		int allocated = 0;
		for (int j = 0; j < n; j++)
			if (!partition_taken[j] && processes[i] <= partitions[j])
			{
				partition_taken[j] = 1;
				allocated = 1;
				sum += partitions[j] - processes[i];
				cout << "P" << i + 1 << " -> " << j + 1 << " " << endl;
				break;
			}
		if (!allocated)
			cout << "P" << i + 1 << " -> N/A" << endl;
	}

	cout << endl;
	cout << "Total Internal Fragmentation: " << sum << endl;
}

void bestfit(vector<int> partitions, vector<int> processes)
{
	int sum = 0;
	int n = partitions.size();
	int m = processes.size();

	cout << endl;
	cout << "Best Fit" << endl;

	vector<int> partition_taken(n, 0);

	for (int i = 0; i < m; i++)
	{
		int best_index = -1;

		for (int j = 0; j < n; j++)
			if (!partition_taken[j] && processes[i] <= partitions[j])
				if (best_index == -1 || partitions[j] < partitions[best_index])
					best_index = j;

		if (best_index != -1)
		{
			cout << "P" << i + 1 << " -> " << best_index + 1 << endl;
			partition_taken[best_index] = 1;
			sum += partitions[best_index] - processes[i];
		}
		else
			cout << "P" << i + 1 << " -> N/A" << endl;
	}

	cout << endl;
	cout << "Total Internal Fragmentation: " << sum << endl;
}

void worstfit(vector<int> partitions, vector<int> processes)
{
	int sum = 0;
	int n = partitions.size();
	int m = processes.size();

	cout << endl;
	cout << "Worst Fit" << endl;

	vector<int> partition_taken(n, 0);

	for (int i = 0; i < m; i++)
	{
		int best_index = -1;

		for (int j = 0; j < n; j++)
			if (!partition_taken[j] && processes[i] <= partitions[j])
				if (best_index == -1 || partitions[j] > partitions[best_index])
					best_index = j;

		if (best_index != -1)
		{
			cout << "P" << i + 1 << " -> " << best_index + 1 << endl;
			partition_taken[best_index] = 1;
			sum += partitions[best_index] - processes[i];
		}
		else
			cout << "P" << i + 1 << " -> N/A" << endl;
	}

	cout << endl;
	cout << "Total Internal Fragmentation: " << sum << endl;
}

/*
=== Test Input ===
4
100 500 200 300
5
212 417 112 426 50
*/

int main()
{
	int m, n;
	vector<int> partition_sizes;
	vector<int> process_sizes;

	input(n, &partition_sizes);
	input(m, &process_sizes);

	firstfit(partition_sizes, process_sizes);
	bestfit(partition_sizes, process_sizes);
	worstfit(partition_sizes, process_sizes);

	return 0;
}