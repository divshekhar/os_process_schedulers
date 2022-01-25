#include "../../include/ps.hpp"

void PS::solve()
{
    int choice;
    std::cout << "Choose Priority Scheduling Algorithm: " << std::endl;
    std::cout << "1. Preemptive" << std::endl;
    std::cout << "2. Non-Preemptive" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        solution(true);
        break;
    case 2:
        solution(false);
        break;
    case 0:
        exit(0);
        break;
    default:
        std::cout << "Invalid Choice" << std::endl;
        break;
    }
}

void PS::solution(bool preemptive)
{
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;

    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    // preemptive
    int burst_remaining[100];
    for (int i = 0; i < n; i++)
    {
        burst_remaining[i] = p[i].get_burst_time();
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != n)
    {
        int idx = -1;
        int mx = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].get_arrival_time() <= current_time && is_completed[i] == 0)
            {
                if (p[i].get_priority() > mx)
                {
                    mx = p[i].get_priority();
                    idx = i;
                }
                if (p[i].get_priority() == mx)
                {
                    if (p[i].get_arrival_time() < p[idx].get_arrival_time())
                    {
                        mx = p[i].get_priority();
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1)
        {
            if (preemptive == true)
            {
                if (burst_remaining[idx] == p[idx].get_burst_time())
                {
                    p[idx].set_start_time(current_time);
                    total_idle_time += p[idx].get_start_time() - prev;
                }
                burst_remaining[idx] -= 1;
                current_time++;
                prev = current_time;

                if (burst_remaining[idx] == 0)
                {
                    p[idx].set_completion_time(current_time);
                    p[idx].set_turnaround_time(p[idx].get_completion_time() - p[idx].get_arrival_time());
                    p[idx].set_waiting_time(p[idx].get_turnaround_time() - p[idx].get_burst_time());
                    p[idx].set_response_time(p[idx].get_start_time() - p[idx].get_arrival_time());

                    total_turnaround_time += p[idx].get_turnaround_time();
                    total_waiting_time += p[idx].get_waiting_time();
                    total_response_time += p[idx].get_response_time();

                    is_completed[idx] = 1;
                    completed++;
                }
            }
            else
            {
                p[idx].set_start_time(current_time);
                p[idx].set_completion_time(p[idx].get_start_time() + p[idx].get_burst_time());
                p[idx].set_turnaround_time(p[idx].get_completion_time() - p[idx].get_arrival_time());
                p[idx].set_waiting_time(p[idx].get_turnaround_time() - p[idx].get_burst_time());
                p[idx].set_response_time(p[idx].get_start_time() - p[idx].get_arrival_time());

                total_turnaround_time += p[idx].get_turnaround_time();
                total_waiting_time += p[idx].get_waiting_time();
                total_response_time += p[idx].get_response_time();
                total_idle_time += p[idx].get_start_time() - prev;

                is_completed[idx] = 1;
                completed++;
                current_time = p[idx].get_completion_time();
                prev = current_time;
            }
        }
        else
        {
            current_time++;
        }
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for (int i = 0; i < n; i++)
    {
        min_arrival_time = std::min(min_arrival_time, p[i].get_arrival_time());
        max_completion_time = std::max(max_completion_time, p[i].get_completion_time());
    }

    set_avg_turnaround_time((float)total_turnaround_time / n);
    set_avg_waiting_time((float)total_waiting_time / n);
    set_avg_response_time((float)total_response_time / n);
    set_cpu_utilisation(((max_completion_time - total_idle_time) / (float)max_completion_time) * 100);
    throughput = float(n) / (max_completion_time - min_arrival_time);
    set_throughput(throughput);
}
