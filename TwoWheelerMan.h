// Parkinglot/TwoWheelerMan.h
#pragma once
#include "ParkingSpotMan.h"

class TwoWheelerManager : public ParkingSpotMan {
public:
    TwoWheelerManager(std::vector<ParkingSpot>& s) : ParkingSpotMan(s) {}

    // Override to find a spot for a two-wheeler (price 30)
    ParkingSpot& findParkingSpace() override {
        for (auto& spot : spots) { // Use a reference
            if (spot.isEmpty && spot.price == 30) {
                return spot;
            }
        }
        throw ParkingFullException("No empty two-wheeler spot available");
    }
};