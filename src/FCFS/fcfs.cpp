#include "../../include/fcfs.hpp"

void FCFS::solve()
{
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;

    std::sort(p, p + n, osps::Process::compareArrival);

    for (int i = 0; i < n; i++)
    {
        int maxStartTime = std::max(p[i - 1].get_completion_time(), p[i].get_arrival_time());

        int start_time = (i == 0) ? p[i].get_arrival_time() : maxStartTime;

        p[i].set_start_time(start_time);
        p[i].set_completion_time(p[i].get_start_time() + p[i].get_burst_time());
        p[i].set_turnaround_time(p[i].get_completion_time() - p[i].get_arrival_time());
        p[i].set_waiting_time(p[i].get_turnaround_time() - p[i].get_burst_time());
        p[i].set_response_time(p[i].get_start_time() - p[i].get_arrival_time());

        total_turnaround_time += p[i].get_turnaround_time();
        total_waiting_time += p[i].get_waiting_time();
        total_response_time += p[i].get_response_time();
        total_idle_time += (i == 0) ? (p[i].get_arrival_time()) : (p[i].get_start_time() - p[i - 1].get_completion_time());
    }

    set_avg_turnaround_time((float)total_turnaround_time / n);
    set_avg_waiting_time((float)total_waiting_time / n);
    set_avg_response_time((float)total_response_time / n);
    set_cpu_utilisation(((p[n - 1].get_completion_time() - total_idle_time) / (float)p[n - 1].get_completion_time()) * 100);
    set_throughput(float(n) / (p[n - 1].get_completion_time() - p[0].get_arrival_time()));

    std::sort(p, p + n, osps::Process::compareID);
}
