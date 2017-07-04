#include "profiler.h"

#include <iomanip>

namespace utils {

BlockProfiler::BlockProfiler(const std::string& block_name) {
    start = std::chrono::steady_clock::now();
    block_name_ = block_name;
}

BlockProfiler::~BlockProfiler() {

    end = std::chrono::steady_clock::now();
    std::chrono::microseconds msec = 
        std::chrono::duration_cast<std::chrono::microseconds>(end-start);

    using float_milliseconds = std::chrono::duration<float, std::milli>;
    float_milliseconds fms = msec;
    float time_taken = fms.count();

    if(__profiles__->find(block_name_) == __profiles__->end()) {
        (*__profiles__)[block_name_] = ProfileStats();
        (*__profiles__)[block_name_].update(time_taken);
    }
    else {
        ProfileStats& pstats = (*__profiles__)[block_name_];
        pstats.update(time_taken);
    }
}

void printProfilers() {
    __ProfilesIterator__ iter = __profiles__->begin();

    int text_width = 30;
    std::cout << "\n---------------------------------------------------";
    std::cout << "---------------------------------------------------\n";
    std::cout << std::setw(text_width) << std::left << "FUNCTION"  << "\t"
              << std::setw(8) << "Num calls "  << "\t"
              << std::setw(8) << "Avg (ms) "  << "\t"
              << std::setw(8) << "Min (ms) "  << "\t"
              << std::setw(8) << "Max (ms) "  << "\t";
    std::cout << "\n---------------------------------------------------";
    std::cout << "---------------------------------------------------\n";

    while(iter != __profiles__->end()) {
        std::cout << std::setw(text_width) << std::left 
                  << iter->first.substr(0, text_width)
                  << "\t" << std::setw(8) << iter->second.num_calls
                  << "\t" << std::setw(8) << iter->second.total_time / iter->second.num_calls
                  << "\t" << std::setw(8) << iter->second.min_time
                  << "\t" << std::setw(8) << iter->second.max_time
                  << "\n";
        iter++;
    }
    std::cout << "---------------------------------------------------";
    std::cout << "---------------------------------------------------\n";
}

void printProfilersAndReset() {

    __ProfilesIterator__ iter = __profiles__->begin();

    int text_width = 30;
    std::cout << "\n---------------------------------------------------";
    std::cout << "---------------------------------------------------\n";
    std::cout << std::setw(text_width) << std::left << "FUNCTION"  << "\t"
              << std::setw(8) << "Num calls "  << "\t"
              << std::setw(8) << "Avg (ms) "  << "\t"
              << std::setw(8) << "Min (ms) "  << "\t"
              << std::setw(8) << "Max (ms) "  << "\t";
    std::cout << "\n---------------------------------------------------";
    std::cout << "---------------------------------------------------\n";

    while(iter != __profiles__->end()) {
        std::cout << std::setw(text_width) << std::left 
                  << iter->first.substr(0, text_width) 
                  << "\t" << std::setw(8) << iter->second.num_calls
                  << "\t" << std::setw(8) << iter->second.total_time / iter->second.num_calls
                  << "\t" << std::setw(8) << iter->second.min_time
                  << "\t" << std::setw(8) << iter->second.max_time
                  << "\n";
        iter->second = ProfileStats();
        iter++;
    }
    std::cout << "---------------------------------------------------";
    std::cout << "---------------------------------------------------\n";
}

void resetProfilers() {
    __ProfilesIterator__ iter = __profiles__->begin();
    while(iter != __profiles__->end()) {
        iter->second = ProfileStats();
        iter++;
    }
}

void clearProfilers() {
    __profiles__->clear();
}

}
