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







