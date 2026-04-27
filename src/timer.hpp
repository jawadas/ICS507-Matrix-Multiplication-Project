#pragma once

#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>

class ScopedTimer {
public:
    using Clock = std::chrono::steady_clock;

    ScopedTimer() : start_(Clock::now()) {}

    std::chrono::milliseconds elapsed() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - start_);
    }

private:
    Clock::time_point start_;
};

inline std::string formatDuration(std::chrono::milliseconds duration) {
    const auto totalSeconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
    const auto hours = totalSeconds / 3600;
    const auto minutes = (totalSeconds % 3600) / 60;
    const auto seconds = totalSeconds % 60;

    std::ostringstream output;
    output << std::setfill('0') << std::setw(2) << hours << ':'
           << std::setw(2) << minutes << ':'
           << std::setw(2) << seconds;
    return output.str();
}
