// Parkinglot/FourWheeler.h
#pragma once
#include "ParkingSpotMan.h"

class FourWheelerManager : public ParkingSpotMan {
public:
    FourWheelerManager(std::vector<ParkingSpot>& s) : ParkingSpotMan(s) {}

    // Override to find a spot for a four-wheeler (price 15)
    ParkingSpot& findParkingSpace() override {
        for (auto& spot : spots) { // Use a reference
            if (spot.isEmpty && spot.price == 15) {
                return spot;
            }
        }
        throw ParkingFullException("No empty four-wheeler spot available");
    }
};