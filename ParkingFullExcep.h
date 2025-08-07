#pragma once
#include <stdexcept>

class ParkingFullException : public std::runtime_error {
public:
    ParkingFullException(const std::string& msg) : std::runtime_error(msg) {}
};
