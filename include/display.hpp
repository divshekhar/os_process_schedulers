#pragma once

#include <iostream>
#include "process.hpp"

namespace osps
{
    class Display
    {
        int n;
        osps::Process *p;

    public:
        Display(int n, osps::Process *p) : n(n), p(p) {}

        ~Display() {}

        void display_gantt_chart(){};

        void display_solution()
        {
            std::cout << std::endl;
            std::cout << "#P\t"
                      << "AT\t"
                      << "BT\t"
                      << "ST\t"
                      << "CT\t"
                      << "TAT\t"
                      << "WT\t"
                      << "RT\t"
                      << "\n"
                      << std::endl;

            for (int i = 0; i < n; i++)
            {
                std::cout << p[i].get_pid() << "\t"
                          << p[i].get_arrival_time() << "\t"
                          << p[i].get_burst_time() << "\t"
                          << p[i].get_start_time() << "\t"
                          << p[i].get_completion_time() << "\t"
                          << p[i].get_turnaround_time() << "\t"
                          << p[i].get_waiting_time() << "\t"
                          << p[i].get_response_time() << "\t"
                          << "\n"
                          << std::endl;
            }
        };
    };
};