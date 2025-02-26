C++ Flight Management System

A comprehensive flight management system developed in C++ for handling flight companies, crew members, planes, and flight operations.

Features

✅ Manage flights, planes, and crew members efficiently.

✈️ Assign crew members and planes to flights.

🚀 Supports both regular and cargo planes.

🛠️ Robust exception handling.

💾 File persistence for data storage.

Installation & Compilation

Prerequisites

A C++ compiler (G++ or MSVC)

A terminal or IDE that supports C++ development

Compilation (Using g++)

g++ -o flight_management main.cpp CFlightCompany.cpp CFlight.cpp CFlightInfo.cpp \
    CPlane.cpp CCargo.cpp CCrewMember.cpp CHost.cpp CPilot.cpp CAddress.cpp \
    PlaneCrewFactorycpp.cpp -std=c++11

Running the Program

After compiling, execute the program:

./flight_management

Usage

1. Load or Create a Flight Company

When you run the program, it attempts to load data from Delta.txt.If the file is missing, it prompts the user to enter flight company details manually.

2. Add a New Plane

CPlane newPlane(150, "Boeing 737");
flightCompany.AddPlane(newPlane);

3. Assign a Crew Member to a Flight

CPilot pilot("John Doe", true, nullptr, 5000);
flightCompany.AddCrewMember(pilot);

4. Take Off a Flight

bool success = flightCompany.TakeOff(flightNumber);
if (success) {
    cout << "Flight took off successfully!" << endl;
} else {
    cout << "Failed to take off." << endl;
}

File Structure

📦 Flight Management System
┣ 📜 main.cpp                 # Main program entry point
┣ 📜 CFlightCompany.cpp        # Manages the flight company operations
┣ 📜 CFlight.cpp               # Handles flights and operations
┣ 📜 CFlightInfo.cpp           # Stores flight details (destination, time, distance)
┣ 📜 CPlane.cpp                # Represents a plane
┣ 📜 CCargo.cpp                # Subclass of CPlane, representing a cargo plane
┣ 📜 CCrewMember.cpp           # Base class for crew members (hosts and pilots)
┣ 📜 CHost.cpp                 # Subclass of CCrewMember, representing flight attendants
┣ 📜 CPilot.cpp                # Subclass of CCrewMember, representing pilots
┣ 📜 CAddress.cpp              # Stores address information
┣ 📜 PlaneCrewFactorycpp.cpp   # Factory for creating planes, flights, and crew members
┣ 📜 FlightCompException.h     # Custom exception handling
┣ 📜 Delta.txt                 # Sample data file
┗ 📜 README.md                 # Project documentation (this file)

Future Improvements

🖥️ Implement a GUI for better usability.

🗄️ Store flight data in a database instead of text files.

✅ Add unit tests for better code reliability.

🌍 Extend support for international flights with different time zones.

License

This project was developed for educational purposes and is open-source.

Author

Developed by Ricardo as part of a C++ course project.

