// Parkinglot/main.cpp
#include <iostream>
#include <vector>
#include <iomanip> // For std::setprecision
#include "Vehicle.h"
#include "ParkingSpot.h"
#include "VehicleType.h"
#include "ParkingSpotManagerFactory.h"
#include "EntranceGate.h"
#include "ExitGate.h"
#include "ParkingLotLogger.h"
#include "ParkingFullExcep.h" // For catching exceptions

int main() {
    std::vector<ParkingSpot> spots;
    // Setup parking spots with different prices
    // Prices are used to determine spot type
    for (int i = 1; i <= 100; ++i) {
        int price = 0;
        int floor = (i - 1) / 25 + 1;
        if (i <= 25) price = 10;       // HeavyDuty spots
        else if (i <= 50) price = 15;  // FourWheeler spots
        else if (i <= 75) price = 20;  // ThreeWheeler spots
        else price = 30;               // TwoWheeler spots
        spots.emplace_back(i, price, floor);
    }

    ParkingSpotManagerFactory factory;
    ParkingLotLogger logger;
    EntranceGate entrance(factory, logger);
    ExitGate exitGate(factory, spots);

    // --- Test Case ---
    // Correctly create a vehicle by instantiating VehicleType
    Vehicle vehicle(1234, VehicleType().HeavyDuty());
    std::cout << "Vehicle " << vehicle.vehicleno << " (" << vehicle.vehicleType << ") is approaching the gate." << std::endl;

    try {
        // 1. Find a spot
        ParkingSpot& spot = entrance.findSpot(vehicle.vehicleType, spots);
        std::cout << "Spot found! ID: " << spot.id << " on Floor " << spot.floor << std::endl;

        // 2. Generate a ticket and park
        Ticket ticket = entrance.generateTicket(vehicle, spot);

        // Simulate some time passing before exiting
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // 3. Exit the parking lot
        exitGate.removeVehicle(ticket);

        // 4. Display the log of all parked vehicles
        logger.showLog();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}