// Parkinglot/factory.h
#pragma once
#include "TwoWheelerMan.h"
#include "FourWheeler.h"
#include "ThreeWheeler.h"
#include "HeavyDuty.h"
#include "VehicleType.h"
#include "ParkingSpotMan.h" // Include base class
#include <string>
#include <vector>
#include <stdexcept>

class ParkingSpotManagerFactory {
public:
    // Creates and returns the correct manager based on vehicle type
    ParkingSpotMan* getManager(const std::string& type, std::vector<ParkingSpot>& spots) {
        VehicleType vType; // Create an instance to call methods
        if (type == vType.TwoWheeler())
            return new TwoWheelerManager(spots);
        else if (type == vType.FourWheeler())
            return new FourWheelerManager(spots);
        else if (type == vType.ThreeWheeler())
            return new ThreeWheelerManager(spots);
        else if (type == vType.HeavyDuty())
            return new HeavyDutyManager(spots);
        else
            throw std::invalid_argument("Invalid vehicle type specified");
    }
};