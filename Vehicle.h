// Parkinglot/Vehicle.h
#pragma once
#include <string>

class Vehicle {
public:
    int vehicleno;
    std::string vehicleType;

    // Constructor to initialize vehicle properties
    Vehicle(int vn, const std::string& vt) : vehicleno(vn), vehicleType(vt) {}
};