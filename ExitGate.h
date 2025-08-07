// Parkinglot/ExitGate.h
#pragma once
#include "ParkingSpotManagerFactory.h"
#include "Ticket.h"
#include <iostream>
#include <ctime>

class ExitGate {
private:
    ParkingSpotManagerFactory factory;
    std::vector<ParkingSpot>& spots;

public:
    ExitGate(ParkingSpotManagerFactory f, std::vector<ParkingSpot>& s) : factory(f), spots(s) {}

    void removeVehicle(const Ticket& ticket) {
        // Calculate and display the fee first
        double fee = ticket.calculateFees(std::time(nullptr));
        std::cout << "\nVehicle " << ticket.vehicle.vehicleno << " is exiting." << std::endl;
        std::cout << "Total Fee: Rs. " << std::fixed << std::setprecision(2) << fee << std::endl;

        // Use the factory to get a manager to handle vehicle removal
        ParkingSpotMan* manager = factory.getManager(ticket.vehicle.vehicleType, spots);
        if (manager) {
            manager->removeVehicle(ticket.vehicle);
            std::cout << "Vehicle removed from Spot " << ticket.spot.id << ". Thank you!" << std::endl;
            delete manager; // Free the manager's memory
        }
    }
};