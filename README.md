# OSPS

Operating System Process Schedulers

<div align="center">
<img src="./img/osps.png" width="50%">
</div>

![GitHub](https://img.shields.io/github/license/divshekhar/os_process_schedulers?style=plastic) ![GitHub top language](https://img.shields.io/github/languages/top/divshekhar/os_process_schedulers?style=plastic) ![GitHub repo size](https://img.shields.io/github/repo-size/divshekhar/os_process_schedulers?style=plastic) ![GitHub issues](https://img.shields.io/github/issues/divshekhar/os_process_schedulers?style=plastic) ![GitHub last commit](https://img.shields.io/github/last-commit/divshekhar/os_process_schedulers) ![GitHub forks](https://img.shields.io/github/forks/divshekhar/os_process_schedulers?style=social)

## Quick Start

<div align="center">
<img src="./img/homescreen.jpg" width="80%" alt="Homescreen">
</div>

### Solution

<div align="center">
<img src="./img/solution.jpg" width="80%" alt="Homescreen">
</div>

## Build

### Without Make

Use this script to build the executable file.

```bash
g++ -std=c++17 -I ./include/ src/FCFS/fcfs.cpp src/SJF/sjf.cpp src/SRTF/srtf.cpp src/RR/rr.cpp src/PS/ps.cpp src/osps.cpp -o ./bin/osps.exe
```

Run the executable file using:

```bash
./bin/osps.exe
```

### Using Make

Build the executable file using:

```bash
make build
```

Run the executable file using:

```bash
make run
```

Just use `make` to build & run the executable file.

Use `make clean` to remove the executable file.

---

|Short Form|Meaning|
|--|--|
|AT|Arrival Time of the process|
|BT|Burst Time of the process|
|ST|Start Time of the process|
|CT|Completion Time of the process|
|TAT|Turnaround Time of the process|
|WT|Waiting Time of the process|
|RT|Response Time of the process|

---

|Formulas used|
|--|
|TAT = CT - AT|
|WT = TAT - BT|
|RT = ST - AT|
