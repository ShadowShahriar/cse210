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
	int remaining_time = 0;
};

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
		processes.push_back({i + 1});

	cout << endl;
	cout << "Enter the CPU times" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> processes[i].burst_time;
		processes[i].remaining_time = processes[i].burst_time;
	}

	cout << endl;
	cout << "Enter the arrival times" << endl;
	for (int i = 0; i < n; i++)
		cin >> processes[i].arrival_time;

	int timer = 0;
	int completed_processes = 0;
	int shortest_job_index = -1;
	int min_remaining_time = INT_MAX;
	bool process_running = false;

	while (completed_processes < n)
	{
		min_remaining_time = INT_MAX;
		shortest_job_index = -1;
		process_running = false;

		for (int i = 0; i < n; ++i)
			if (processes[i].arrival_time <= timer && processes[i].remaining_time > 0)
			{
				if (processes[i].remaining_time < min_remaining_time)
				{
					min_remaining_time = processes[i].remaining_time;
					shortest_job_index = i;
					process_running = true;
				}
			}

		if (!process_running)
		{
			timer++;
			continue;
		}

		process &curr_process = processes[shortest_job_index];
		curr_process.remaining_time--;
		timer++;

		if (curr_process.remaining_time == 0)
		{
			completed_processes++;
			curr_process.completion_time = timer;
			curr_process.turn_around_time = curr_process.completion_time - curr_process.arrival_time;
			curr_process.waiting_time = curr_process.turn_around_time - curr_process.burst_time;
		}
	}

	sort(processes.begin(), processes.end(), sortByID);

	float sum_wt = 0.0;
	float sum_tat = 0.0;
	float avg_wt = 0.0;
	float avg_tat = 0.0;

	cout << endl;
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