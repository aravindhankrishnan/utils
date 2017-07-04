#pragma once

#include <iostream>
#include <chrono>
#include <map>
#include <memory>
#include <limits>

#define PROFILE_FUNCTION utils::BlockProfiler __function__profiler__(__FUNCTION__);
#define PROFILE_BLOCK(str) utils::BlockProfiler __block__profiler__(str);

namespace utils {

struct ProfileStats {

    float total_time;
    long num_calls;
    float min_time;
    float max_time;

    ProfileStats() {
        total_time = 0;
        num_calls = 0;
        min_time = std::numeric_limits<float>::max();
        max_time = std::numeric_limits<float>::min();
    }

    void update(float time) {
        total_time += time;
        min_time = std::min(time, min_time);
        max_time = std::max(time, max_time);
        num_calls++;
    }
};

typedef std::map<std::string, ProfileStats> __Profiles__;
typedef std::map<std::string, ProfileStats>::iterator __ProfilesIterator__;

std::unique_ptr<__Profiles__> __profiles__(new __Profiles__);

class BlockProfiler {

    public:

        BlockProfiler(const std::string& block_name);
        ~BlockProfiler();

    private:

    std::chrono::steady_clock::time_point start,
                                          end;
    std::string block_name_;
};

void printProfilers();
void printProfilersAndReset();
void resetProfilers();
void clearProfilers();

}
