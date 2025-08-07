// Parkinglot/ParkingSpot.h
#pragma once
#include "Vehicle.h"
#include <string>

class ParkingSpot {
public:
    int id;
    bool isEmpty;
    int price; // Represents price per hour
    int floor;
    Vehicle vehicle;

    ParkingSpot() : id(0), isEmpty(true), price(0), floor(1), vehicle(0, "") {}

    ParkingSpot(int spotId, int pricePerHour, int fl = 1) :
        id(spotId), isEmpty(true), price(pricePerHour), floor(fl), vehicle(0, "") {}

    void parkVehicle(const Vehicle& v) {
        this->vehicle = v;
        isEmpty = false;
    }

    void removeVehicle() {
        isEmpty = true;
        // Reset vehicle to a default state
        vehicle = Vehicle(0, "");
    }
};