// Parkinglot/VehicleType.h
#pragma once
#include <string>

class VehicleType {
public:
    std::string TwoWheeler() { return "TwoWheeler"; }
    std::string FourWheeler() { return "FourWheeler"; }
    std::string HeavyDuty() { return "HeavyDuty"; }
    std::string ThreeWheeler() { return "ThreeWheeler"; }
};