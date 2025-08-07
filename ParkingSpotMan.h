// Parkinglot/ParkingSpotMan.h
#pragma once
#include <vector>
#include <string>
#include "Vehicle.h"
#include "ParkingFullExcep.h"
#include "ParkingSpot.h"

// Abstract base class for managing parking spots of a specific type
class ParkingSpotMan {
public:
    std::vector<ParkingSpot>& spots;

    ParkingSpotMan(std::vector<ParkingSpot>& s) : spots(s) {}

    // Pure virtual function to be implemented by derived classes
    virtual ParkingSpot& findParkingSpace() = 0;

    void removeVehicle(const Vehicle& vehicle) {
        for (auto& spot : spots) {
            // Check if the spot is occupied by the correct vehicle
            if (!spot.isEmpty && spot.vehicle.vehicleno == vehicle.vehicleno) {
                spot.removeVehicle();
                break; // Exit loop once vehicle is found and removed
            }
        }
    }

    virtual ~ParkingSpotMan() = default; // Virtual destructor for base class
};