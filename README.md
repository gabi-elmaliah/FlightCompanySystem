# **C++ Flight Management System**

A comprehensive flight management system developed in C++ for handling flight companies, crew members, planes, and flight operations.

---

## **Features**
- ✅ Manage flights, planes, and crew members efficiently.
- ✈️ Assign crew members and planes to flights.
- 🚀 Supports both regular and cargo planes.
- 🛠️ Robust exception handling.
- 💾 File persistence for data storage.

---

## **Usage**
### **1. Load or Create a Flight Company**

When you run the program, it attempts to **load data from `Delta.txt`**.  
If the file is missing, it prompts the user to **enter flight company details manually**.

### **2. Add New Plane**

```cpp
CPlane newPlane(150, "Boeing 737");
flightCompany.AddPlane(newPlane);
```

### **3. Assign a Crew Member to a Flight**

```cpp
CPilot pilot("John Doe", true, nullptr, 5000);
flightCompany.AddCrewMember(pilot)
```

### **4. Take Off a Flight**

```cpp
bool success = flightCompany.TakeOff(flightNumber);
if (success) {
    cout << "Flight took off successfully!" << endl;
} else {
    cout << "Failed to take off." << endl;
}
```

## **Classes Explanation**

### **1. CFlightCompany**  

Manages the entire flight operation, including flights, planes, and crew members.  
It provides methods to:  
- Add new planes, crew members, and flights.  
- Take off flights and manage assignments.  

### **2. CFlight**  

Represents an individual flight. It contains flight details such as:  
- Flight information  
- Assigned plane  
- Crew members  

It provides functionality to:  
- Assign planes and crew members to a flight  
- Handle the takeoff process  

### **3. CFlightInfo**  

Stores essential flight details, including:  
- Destination  
- Flight number  
- Duration  
- Distance
  
### **4. CPlane**  

Represents a general aircraft with:  
- A unique serial number  
- Name  
- Seat capacity  

### **5. CCargo (inherits from CPlane)**  

A specialized class for cargo planes, adding attributes for:  
- Maximum weight capacity  
- Maximum volume capacity  

### **6. CCrewMember**  

A base class representing a flight crew member. It stores information about:  
- Crew member’s name  
- Total air time  

### **7. CHost (inherits from CCrewMember)**  

A subclass of `CCrewMember` representing flight attendants. It includes functionality for:  
- Receiving gifts  
- Switching uniforms  

### **8. CPilot (inherits from CCrewMember)**  

A subclass of `CCrewMember` representing pilots. It supports:  
- Captain status  
- Additional methods for pilot-specific actions like logging simulator training  

### **9. CAddress**  

Handles addresses related to crew members, storing:  
- Street name  
- House number  
- City  

### **10. PlaneCrewFactory**  

A factory class responsible for:  
- Creating and managing different types of crew members  
- Generating flights dynamically  
- Managing plane assignments  

### **11. FlightCompException**  

Defines custom exceptions related to the flight management system, including:  
- Invalid inputs  
- File errors  
- Operational constraints  

  








