# 🅿️ Parking Lot System in C++

A modular, object-oriented *Parking Lot Management System* built in C++. Designed with a clean architecture using modern C++ principles, this system supports:

- Multiple vehicle types: Two-Wheeler, Three-Wheeler, Four-Wheeler, Heavy-Duty
- Dynamic pricing based on time (per-minute rate)
- Entry and Exit flow with ticketing and fee calculation
- Polymorphic Manager classes and Factory Pattern for flexibility

---

## 🚗 Vehicle Support

| Vehicle Type   | Price/Hour | Manager Class             |
|----------------|------------|----------------------------|
| TwoWheeler     | ₹10/hr     | TwoWheelerManager         |
| ThreeWheeler   | ₹15/hr     | ThreeWheelerManager       |
| FourWheeler    | ₹20/hr     | FourWheelerManager        |
| HeavyDuty      | ₹30/hr     | HeavyDutyManager          |

---

## 📁 Project Structure


parking_lot_cpp/
├── VehicleType.h            # Constants for vehicle types
├── Vehicle.h / .cpp         # Vehicle class
├── ParkingSpot.h / .cpp     # ParkingSpot class
├── Exception.h              # Custom exceptions
├── ParkingSpotManager.h     # Abstract + derived managers
├── Factory.h / .cpp         # Manager factory
├── Ticket.h / .cpp          # Ticket with fee logic
├── Logger.h / .cpp          # Logging system
├── EntranceGate.h / .cpp    # Entry gate logic
├── ExitGate.h / .cpp        # Exit gate logic
├── main.cpp                 # Program entry point


---

## 🔁 Core Workflow

1. *main.cpp*
   - Initializes 100 parking spots
   - Creates a Vehicle
   - Handles entry with EntranceGate
   - Handles exit using ExitGate
   - Calculates fee based on duration

2. *Ticketing*
   - Time of entry recorded
   - On exit, calculates parked minutes
   - Applies fee: price_per_hour / 60 * total_minutes

3. *Logging*
   - Tickets are logged using Logger

---

## 🧠 Design Principles

- *Factory Pattern*: Dynamically returns correct Manager
- *Inheritance/Polymorphism*: Vehicle-specific managers override behavior
- *Separation of Concerns*: Each module handles only its own logic

---

## 🧪 Sample Output

bash
$ ./parking_lot
Vehicle 567 parked at Spot 12 on Floor 1
Total fee for vehicle 567: ₹20.0
Vehicle 567 parked at spot 12 at time 1699900000.00


---

## 🛠 Requirements

- C++17 or higher
- Standard Library only (no external dependencies)
- g++ / clang++ compiler

---

## 📄 License

This project is open-source and intended for learning, demonstration, and interview prep.

---

## 🙋‍♂️ Author

*Made with ❤️, Aayush*

> If you liked this project, don’t forget to ⭐ the repo and share love 💌
