#include "../include/fcfs.hpp"
#include "../include/sjf.hpp"

#include <iomanip>
#include <string>

std::string scheduling_algo(int n)
{
    switch (n)
    {
    case 1:
        return "FCFS (First Come First Serve)";
    case 2:
        return "SJF (Shortest Job First)";
    case 3:
        return "SRTF (Shortest Remaining Time First)";
    case 4:
        return "RR (Round Robin)";
    case 5:
        return "Priority (Priority Scheduling)";
    default:
        return "Exit";
    }
}

void display_logo()
{
    std::string logo = R"###(  
    
.|''''|, .|'''|  '||'''|, .|'''|  
||    || ||       ||   || ||      
||    || `|'''|,  ||...|' `|'''|, 
||    ||  .   ||  ||       .   || 
`|....|'  |...|' .||       |...|' 
                                  
                                   
)###";

    std::cout << logo << std::endl;
}

void display_scheduling_algos()
{
    std::cout << "1. " << scheduling_algo(1) << std::endl;
    std::cout << "2. " << scheduling_algo(2) << std::endl;
    std::cout << "3. " << scheduling_algo(3) << std::endl;
    std::cout << "4. " << scheduling_algo(4) << std::endl;
    std::cout << "5. " << scheduling_algo(5) << std::endl;
    std::cout << "0. " << scheduling_algo(0) << std::endl;
}

int main()
{
    display_logo();
    display_scheduling_algos();

    int choice;
    std::cout << "Enter your choice of scheduler: ";
    std::cin >> choice;
    std::cout << "You have chosen " << scheduling_algo(choice) << std::endl;

    int n;
    osps::Process p[100];

    // precision for floating point numbers set to 2
    std::cout << std::setprecision(2) << std::fixed;

    std::cout << "Enter the number of processes: ";
    std::cin >> n;
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        int arrival_time, burst_time;
        std::cout << "Enter arrival time of process " << i + 1 << ": ";
        std::cin >> arrival_time;
        std::cout << "Enter burst time of process " << i + 1 << ": ";
        std::cin >> burst_time;

        std::cout << std::endl;

        // Filling array with processes
        p[i] = osps::Process(i + 1, arrival_time, burst_time, 0, 0, 0, 0, 0);
    }

    switch (choice)
    {
    case 0:
    {
        exit(0);
        break;
    }
    case 1:
    {
        FCFS fcfs(n, p);
        break;
    }
    case 2:
    {
        SJF sjf(n, p);
        break;
    }
    }

    return 0;
}