#pragma once

namespace osps
{
    class SchedulingAlgorithm
    {
    public:
        SchedulingAlgorithm() {}
        virtual ~SchedulingAlgorithm() {}
        virtual void solve() = 0;
    };
};