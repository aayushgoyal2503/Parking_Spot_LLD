// Parkinglot/ThreeWheeler.h
#pragma once
#include "ParkingSpotMan.h"

// Corrected class name from "ThreeWheelerManagaer"
class ThreeWheelerManager : public ParkingSpotMan {
public:
    ThreeWheelerManager(std::vector<ParkingSpot>& s) : ParkingSpotMan(s) {}

    // Override to find a spot for a three-wheeler (price 20)
    ParkingSpot& findParkingSpace() override {
        for (auto& spot : spots) { // Use a reference
            if (spot.isEmpty && spot.price == 20) {
                return spot;
            }
        }
        throw ParkingFullException("No empty three-wheeler spot available");
    }
};