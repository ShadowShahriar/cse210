#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct process
{
	int process_id = 0;
	int burst_time = 0;
	int arrival_time = 0;
	int completion_time = 0;
	int waiting_time = 0;
	int turn_around_time = 0;
};

bool sortByArrival(const process &p1, const process &p2)
{
	return p1.arrival_time < p2.arrival_time;
}

bool sortByID(const process &p1, const process &p2)
{
	return p1.process_id < p2.process_id;
}

int main()
{
	int n;
	vector<process> processes = {};

	cout << "Enter the number of process: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		processes.push_back({i + 1});

	cout << endl;
	cout << "Enter the CPU times" << endl;
	for (int i = 0; i < n; i++)
		cin >> processes[i].burst_time;

	cout << endl;
	cout << "Enter the arrival times" << endl;
	for (int i = 0; i < n; i++)
		cin >> processes[i].arrival_time;

	sort(processes.begin(), processes.end(), sortByArrival);

	int time_frame = 0;
	for (int i = 0; i < n; i++)
	{
		time_frame += processes[i].burst_time;
		processes[i].turn_around_time = time_frame - processes[i].arrival_time;

		if (i == 0)
			processes[i].waiting_time = 0;
		else
			processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
	}

	sort(processes.begin(), processes.end(), sortByID);

	float avg_wt = 0.0;
	float avg_tat = 0.0;

	float sum_wt = 0.0;
	float sum_tat = 0.0;

	for (int i = 0; i < n; i++)
	{
		cout << "Process " << processes[i].process_id << ": ";
		cout << "Waiting Time: " << processes[i].waiting_time << " \t| ";
		cout << "Turnaround Time: " << processes[i].turn_around_time << endl;

		sum_wt += processes[i].waiting_time;
		sum_tat += processes[i].turn_around_time;
	}

	avg_wt = sum_wt / (float)n;
	avg_tat = sum_tat / (float)n;

	cout << endl;

	cout << "Average Waiting Time: \t\t";
	cout << fixed << setprecision(2) << avg_wt;
	cout << " time units" << endl;

	cout << "Average Turnaround Time: \t";
	cout << fixed << setprecision(2) << avg_tat;
	cout << " time units" << endl;
	return 0;
}