// Parkinglot/EntranceGate.h
#pragma once
#include "ParkingSpotManagerFactory.h"
#include "ParkingLotLogger.h"
#include "Vehicle.h"
#include "ParkingSpot.h"
#include "Ticket.h"
#include <ctime>

class EntranceGate {
private:
    ParkingSpotManagerFactory factory;
    ParkingLotLogger& logger;

public:
    EntranceGate(ParkingSpotManagerFactory f, ParkingLotLogger& log) : factory(f), logger(log) {}

    // Finds a spot using a temporary manager, preventing memory leaks
    ParkingSpot& findSpot(const std::string& vehicleType, std::vector<ParkingSpot>& spots) {
        ParkingSpotMan* manager = factory.getManager(vehicleType, spots);
        try {
            ParkingSpot& spot = manager->findParkingSpace();
            delete manager; // IMPORTANT: Free the allocated memory
            return spot;
        } catch (...) {
            delete manager; // Ensure memory is freed even if an exception occurs
            throw; // Re-throw the exception
        }
    }

    Ticket generateTicket(const Vehicle& vehicle, ParkingSpot& spot) {
        spot.parkVehicle(vehicle);
        std::time_t entryTime = std::time(nullptr);
        Ticket ticket(entryTime, spot, vehicle);
        logger.logTicket(ticket);
        return ticket;
    }
};