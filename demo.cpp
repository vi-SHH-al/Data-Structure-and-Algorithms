#include <iostream>
#include <queue>
using namespace std;

// define a struct to store process information
struct Process
{
    int pid;          // process ID
    int arrival_time; // arrival time of process
    int burst_time;   // burst time of process
};

int main()
{
    int n; // number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    // create a queue to store the processes
    queue<Process> q;

    // get process information from user
    for (int i = 0; i < n; i++)
    {
        int pid, arrival_time, burst_time;
        cout << "Enter process " << i + 1 << "id, arrival_time, burst_time";
        cin >> pid >> arrival_time >> burst_time;

        // create a process struct and add it to the queue
        Process p = {pid, arrival_time, burst_time};
        q.push(p);
    }

    // execute the processes in the order they arrived
    cout << "\nPid  Arrival time     Burst Time      Waiting time     Turna around time     Complete time\n";
    int current_time = 0;
    while (!q.empty())
    {
        Process p = q.front();
        q.pop();

        // wait for the process to arrive if necessary
        if (current_time < p.arrival_time)
        {
            current_time = p.arrival_time;
        }

        // execute the process
        current_time += p.burst_time;
        int turn_around = current_time - p.arrival_time;
        int waiting_time = turn_around - p.burst_time;

        cout << " " << p.pid << "      " << p.arrival_time << "               " << p.burst_time << "                  " << waiting_time << "                  " << turn_around << "                   " << current_time << endl;
    }

    return 0;
}