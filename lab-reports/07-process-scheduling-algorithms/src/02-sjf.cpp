#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct process
{
	int process_id = 0;
	int arrival_time = 0;
	int burst_time = 0;
	int completion_time = 0;
	int turn_around_time = 0;
	int waiting_time = 0;
	bool completed = 0;
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

	cout << "Enter the number of processes: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		processes.push_back({i + 1});
		processes[i].completed = false;
	}

	cout << endl;
	cout << "Enter the CPU times" << endl;
	for (int i = 0; i < n; i++)
		cin >> processes[i].burst_time;

	cout << endl;
	cout << "Enter the arrival times" << endl;
	for (int i = 0; i < n; i++)
		cin >> processes[i].arrival_time;

	sort(processes.begin(), processes.end(), sortByArrival);

	int timer = 0;
	int completed_processes = 0;
	float sum_wt = 0;
	float sum_tat = 0;

	while (completed_processes < n)
	{
		int min_job_index = -1;
		int min_bt = INT_MAX;

		for (int i = 0; i < n; ++i)
		{
			if (processes[i].arrival_time <= timer && !processes[i].completed)
			{
				if (processes[i].burst_time < min_bt)
				{
					min_bt = processes[i].burst_time;
					min_job_index = i;
				}
			}
		}

		if (min_job_index != -1)
		{
			process &curr_process = processes[min_job_index];
			curr_process.completion_time = timer + curr_process.burst_time;
			curr_process.turn_around_time = curr_process.completion_time - curr_process.arrival_time;
			curr_process.waiting_time = curr_process.turn_around_time - curr_process.burst_time;

			timer = curr_process.completion_time;
			curr_process.completed = true;
			completed_processes++;
		}
		else
			timer++;
	}

	sort(processes.begin(), processes.end(), sortByID);

	for (int i = 0; i < n; i++)
	{
		cout << "Process " << processes[i].process_id << ": ";
		cout << "Waiting Time: " << processes[i].waiting_time << " \t| ";
		cout << "Turnaround Time: " << processes[i].turn_around_time << endl;

		sum_wt += processes[i].waiting_time;
		sum_tat += processes[i].turn_around_time;
	}

	float avg_wt = 0.0;
	float avg_tat = 0.0;
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