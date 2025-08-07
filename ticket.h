// Parkinglot/ticket.h
#pragma once
#include <ctime>
#include "ParkingSpot.h"
#include "Vehicle.h"

class Ticket {
private:
    std::time_t entryTime;

public:
    ParkingSpot spot;
    Vehicle vehicle;

    Ticket(std::time_t entry, const ParkingSpot& s, const Vehicle& v)
        : entryTime(entry), spot(s), vehicle(v) {}

    // Calculates the parking fee based on duration and hourly rate
    double calculateFees(std::time_t exitTime) const {
        double durationSeconds = difftime(exitTime, entryTime);
        // Ensure minimum charge for even a short stay
        int totalMinutes = static_cast<int>(durationSeconds / 60) + 1;
        // The 'price' member in ParkingSpot is the hourly rate
        double perMinuteRate = static_cast<double>(spot.price) / 60.0;
        return perMinuteRate * totalMinutes;
    }
};