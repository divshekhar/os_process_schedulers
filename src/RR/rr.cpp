#include "../../include/rr.hpp"

void RR::solve()
{

    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int burst_remaining[100];
    int idx;

    int tq;
    std::cout << "Enter time quantum: ";
    std::cin >> tq;

    for (int i = 0; i < n; i++)
    {
        burst_remaining[i] = p[i].get_burst_time();
    }

    std::sort(p, p + n, osps::Process::compareArrival);

    std::queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;

    while (completed != n)
    {
        idx = q.front();
        q.pop();

        if (burst_remaining[idx] == p[idx].get_burst_time())
        {
            p[idx].set_start_time(std::max(current_time, p[idx].get_arrival_time()));
            total_idle_time += p[idx].get_start_time() - current_time;
            current_time = p[idx].get_start_time();
        }

        if (burst_remaining[idx] - tq > 0)
        {
            burst_remaining[idx] -= tq;
            current_time += tq;
        }
        else
        {
            current_time += burst_remaining[idx];
            burst_remaining[idx] = 0;
            completed++;

            p[idx].set_completion_time(current_time);
            p[idx].set_turnaround_time(p[idx].get_completion_time() - p[idx].get_arrival_time());
            p[idx].set_waiting_time(p[idx].get_turnaround_time() - p[idx].get_burst_time());
            p[idx].set_response_time(p[idx].get_start_time() - p[idx].get_arrival_time());

            total_turnaround_time += p[idx].get_turnaround_time();
            total_waiting_time += p[idx].get_waiting_time();
            total_response_time += p[idx].get_response_time();
        }

        for (int i = 1; i < n; i++)
        {
            if (burst_remaining[i] > 0 && p[i].get_arrival_time() <= current_time && mark[i] == 0)
            {
                q.push(i);
                mark[i] = 1;
            }
        }
        if (burst_remaining[idx] > 0)
        {
            q.push(idx);
        }

        if (q.empty())
        {
            for (int i = 1; i < n; i++)
            {
                if (burst_remaining[i] > 0)
                {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }

    set_avg_turnaround_time((float)total_turnaround_time / n);
    set_avg_waiting_time((float)total_waiting_time / n);
    set_avg_response_time((float)total_response_time / n);
    set_cpu_utilisation(((p[n - 1].get_completion_time() - total_idle_time) / (float)p[n - 1].get_completion_time()) * 100);
    throughput = float(n) / (p[n - 1].get_completion_time() - p[0].get_arrival_time());
    set_throughput(throughput);

    std::sort(p, p + n, osps::Process::compareID);
}