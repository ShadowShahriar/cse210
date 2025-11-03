#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m, n;
	cout << "Enter the no. of processes: ";
	cin >> n;
	cout << "Enter the no. of resources: ";
	cin >> m;

	vector<vector<int>> maxNeed(n, vector<int>(m));
	vector<vector<int>> alloc(n, vector<int>(m));
	vector<vector<int>> need(n, vector<int>(m));
	vector<int> avail(m);
	vector<int> total(m);
	vector<int> finish(n, 0);
	vector<int> safeSequence;

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Process " << i + 1 << endl;
		for (int j = 0; j < m; j++)
		{
			cout << "Maximum value for resource " << j + 1 << ": ";
			cin >> maxNeed[i][j];
		}
		for (int j = 0; j < m; j++)
		{
			cout << "Allocated from resource " << j + 1 << ": ";
			cin >> alloc[i][j];
		}
	}

	cout << endl;
	for (int j = 0; j < m; j++)
	{
		cout << "Enter total value of resource " << j + 1 << ": ";
		cin >> total[j];
	}

	for (int k = 0; k < m; k++)
	{
		int totAlloc = 0;
		for (int l = 0; l < n; l++)
			totAlloc += alloc[l][k];
		avail[k] = total[k] - totAlloc;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			need[i][j] = maxNeed[i][j] - alloc[i][j];

	cout << endl;

	int count = 0;
	while (count < n)
	{
		int found = 0;
		for (int i = 0; i < n; i++)
		{
			if (!finish[i])
			{
				int canFinish = 1;
				for (int j = 0; j < m; j++)
				{
					if (need[i][j] > avail[j])
					{
						canFinish = 0;
						break;
					}
				}

				if (canFinish)
				{
					for (int k = 0; k < m; k++)
						avail[k] += alloc[i][k];
					safeSequence.push_back(i);
					finish[i] = 1;
					found = 1;
					count++;
				}
			}
		}

		if (!found)
		{
			cout << "The system is not in a safe state.";
			return 0;
		}
	}

	cout << "The system is currently in safe state and ";
	cout << "< ";
	for (int i = 0, z = safeSequence.size(); i < z; i++)
		cout << "P" << safeSequence[i] + 1 << " ";
	cout << "> is the safe sequence.\n";
}