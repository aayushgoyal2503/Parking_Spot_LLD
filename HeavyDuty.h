// Parkinglot/HeavyDuty.h
#pragma once
#include "ParkingSpotMan.h"

class HeavyDutyManager : public ParkingSpotMan {
public:
    HeavyDutyManager(std::vector<ParkingSpot>& s) : ParkingSpotMan(s) {}

    // Override to find a spot for a heavy-duty vehicle (price 10)
    ParkingSpot& findParkingSpace() override {
        for (auto& spot : spots) { // Use a reference to modify the actual spot
            if (spot.isEmpty && spot.price == 10) {
                return spot;
            }
        }
        throw ParkingFullException("No empty heavy-duty spot available");
    }
};