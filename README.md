# ✈️ Flight Reservation System

A **console-based Flight Reservation System** written in **C**.  
This was my **second-year project** while learning about **Data Structures and Algorithms (DSA)**.  
The program simulates a simple airline booking system, where users can search flights, book/cancel seats, and view reservations.  

It uses **linked lists** to manage flight data and reservations — a practical application of DSA concepts.  

---

## 🚀 Features

- **View Flights**  
  See a list of all available flights, including:
  - Plane number  
  - Origin & Destination  
  - Departure & Arrival times  
  - Ticket Price  

- **Filter Flights**  
  Search flights by **origin** or **destination**.

- **Book Seats**  
  - Select a flight and book available seats.  
  - The system shows a **visual seating layout** (booked seats marked as `X`).  

- **Cancel Reservations**  
  Cancel a previously booked seat by entering its number.  

- **Check Reservations**  
  View all **passenger details** and their reserved seat info for a specific flight.  

- **Data Persistence**  
  Flight details are loaded from a **`Flight-details`** text file, making schedule updates simple without recompiling.  

---

## 📂 File Setup

The file `Flight-details` must contain flight information in this format:  

`[from] [to] [depart_hour]:[depart_min][AM/PM] [arrive_hour]:[arrive_min][AM/PM] [price]`

### Example content for `Flight-details`:
- `NewDelhi Mumbai 10:00AM 12:30PM 5000`  
- `Mumbai Bengaluru 08:30AM 10:45AM 4500`  

---

## 🛠️ How to Compile & Run

### **Prerequisites**
- A C compiler (e.g., GCC).  
- A text file named `Flight-details` in the same directory as `main.c`.  

### **Steps**
1. Save the C source code as `main.c`.  
2. Create a text file named `Flight-details` and add flight data (as shown above).  
3. Compile the program:  
   ```bash
   gcc main.c -o flight_system
