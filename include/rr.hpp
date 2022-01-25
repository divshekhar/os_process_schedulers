#pragma once

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#include "process.hpp"
#include "scheduling_algorithm.hpp"
#include "scheduling_units.hpp"
#include "display.hpp"

class RR : public osps::SchedulingAlgorithm, osps::SchedulingUnits, public osps::Display
{
    int n;
    osps::Process *p;

public:
    RR(int n, osps::Process *p)
        : Display(n, p), n(n), p(p)
    {
        solve();
        display_solution();
        display_scheduling_units();
    };

    ~RR(){};

    // overriding the pure virtual function solve() in SchedulingAlgorithm
    void solve();
};