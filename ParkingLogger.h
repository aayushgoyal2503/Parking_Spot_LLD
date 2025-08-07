// Parkinglot/ParkingLotLogger.h
#pragma once
#include "ticket.h"
#include <vector>
#include <iostream>
#include <string>

class ParkingLotLogger {
private:
    // Stores a copy of each ticket generated
    std::vector<Ticket> ticketLog;

public:
    void logTicket(const Ticket& ticket) {
        ticketLog.push_back(ticket);
        std::cout << "Logger: Ticket generated for vehicle " << ticket.vehicle.vehicleno
                  << " at Spot " << ticket.spot.id << std::endl;
    }

    void showLog() {
        std::cout << "\n--- Parking Log ---" << std::endl;
        if (ticketLog.empty()) {
            std::cout << "Log is empty." << std::endl;
        }
        for (const auto& t : ticketLog) {
            std::cout << "  - Vehicle No: " << t.vehicle.vehicleno
                      << ", Type: " << t.vehicle.vehicleType
                      << ", Spot ID: " << t.spot.id << std::endl;
        }
        std::cout << "-------------------\n" << std::endl;
    }
};