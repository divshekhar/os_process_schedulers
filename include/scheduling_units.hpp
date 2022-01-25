#pragma once

namespace osps
{
    class SchedulingUnits
    {
    private:
        float avg_turnaround_time;
        float avg_waiting_time;
        float avg_response_time;
        float cpu_utilisation;
        float throughput;

    public:
        // constructor
        SchedulingUnits()
        {
            avg_turnaround_time = 0;
            avg_waiting_time = 0;
            avg_response_time = 0;
            cpu_utilisation = 0;
            throughput = 0;
        }

        // destructor
        ~SchedulingUnits() {}

        // getters
        float get_avg_turnaround_time() { return avg_turnaround_time; }
        float get_avg_waiting_time() { return avg_waiting_time; }
        float get_avg_response_time() { return avg_response_time; }
        float get_cpu_utilisation() { return cpu_utilisation; }
        float get_throughput() { return throughput; }

        // setters
        void set_avg_turnaround_time(float avg_turnaround_time)
        {
            this->avg_turnaround_time = avg_turnaround_time;
        }

        void set_avg_waiting_time(float avg_waiting_time)
        {
            this->avg_waiting_time = avg_waiting_time;
        }

        void set_avg_response_time(float avg_response_time)
        {
            this->avg_response_time = avg_response_time;
        }

        void set_cpu_utilisation(float cpu_utilisation)
        {
            this->cpu_utilisation = cpu_utilisation;
        }

        void set_throughput(float throughput)
        {
            this->throughput = throughput;
        }

        void display_scheduling_units()
        {
            std::cout << "Average Turnaround Time = " << get_avg_turnaround_time() << std::endl;
            std::cout << "Average Waiting Time = " << get_avg_waiting_time() << std::endl;
            std::cout << "Average Response Time = " << get_avg_response_time() << std::endl;
            std::cout << "CPU Utilization = " << get_cpu_utilisation() << "%" << std::endl;
            std::cout << "Throughput = " << get_throughput() << " process/unit time" << std::endl;
        }
    };
} // namespace osps