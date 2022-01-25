#pragma once

namespace osps
{
    class Process
    {
    private:
        int pid;
        int arrival_time;
        int burst_time;
        int start_time;
        int completion_time;
        int turnaround_time;
        int waiting_time;
        int response_time;
        int priority;

    public:
        Process()
        {
            pid = 0;
            arrival_time = 0;
            burst_time = 0;
            start_time = 0;
            completion_time = 0;
            turnaround_time = 0;
            waiting_time = 0;
            response_time = 0;
            priority = 0;
        }

        Process(int pid, int arrival_time, int burst_time, int start_time, int completion_time,
                int turnaround_time, int waiting_time, int response_time, int priority)
        {
            this->pid = pid;
            this->arrival_time = arrival_time;
            this->burst_time = burst_time;
            this->start_time = start_time;
            this->completion_time = completion_time;
            this->turnaround_time = turnaround_time;
            this->waiting_time = waiting_time;
            this->response_time = response_time;
            this->priority = priority;
        }

        ~Process() {}

        // Getters
        int get_pid() { return pid; }
        int get_arrival_time() { return arrival_time; }
        int get_burst_time() { return burst_time; }
        int get_start_time() { return start_time; }
        int get_completion_time() { return completion_time; }
        int get_turnaround_time() { return turnaround_time; }
        int get_waiting_time() { return waiting_time; }
        int get_response_time() { return response_time; }
        int get_priority() { return priority; }

        // Setters
        void set_pid(int pid) { this->pid = pid; }
        void set_arrival_time(int arrival_time) { this->arrival_time = arrival_time; }
        void set_burst_time(int burst_time) { this->burst_time = burst_time; }
        void set_start_time(int start_time) { this->start_time = start_time; }
        void set_completion_time(int completion_time) { this->completion_time = completion_time; }
        void set_turnaround_time(int turnaround_time) { this->turnaround_time = turnaround_time; }
        void set_waiting_time(int waiting_time) { this->waiting_time = waiting_time; }
        void set_response_time(int response_time) { this->response_time = response_time; }
        void set_priority(int priority) { this->priority = priority; }

        static bool compareArrival(Process p1, Process p2)
        {
            return p1.get_arrival_time() < p2.get_arrival_time();
        }

        static bool compareID(Process p1, Process p2)
        {
            return p1.get_pid() < p2.get_pid();
        }
    };
}
