Flight Reservation System ✈️
This was my second-year project while I was starting to learn about Data Structures and Algorithms (DSA). It's a simple, console-based Flight Reservation System written in C. The program allows a user to interact with a flight database to book and manage seat reservations. It uses linked lists to manage flight data and seat reservations, providing a practical application of DSA concepts.

Features ✨
View Flights: See a list of all available flights, including their plane number, origin, destination, departure and arrival times, and price.

Filter Flights: Easily search for flights by their origin or destination.

Book Seats: Choose a flight and book available seats. The program displays a visual representation of the plane's seating layout, showing which seats are taken with an 'X'.

Cancel Reservations: Cancel a previously booked seat by entering its number.

Check Reservations: View a detailed list of all passengers and their seat information for a specific flight.

Data Persistence: Flight details are loaded from a text file named Flight-details, making it easy to update flight schedules without recompiling the code.

How to Compile and Run 🚀
Prerequisites
A C compiler (like GCC).

A text file named Flight-details must be in the same directory as the source code.

Flight-details File Format
The format for each line in the Flight-details file is as follows:

[from] [to] [depart_hour]:[depart_min][depart_meri] [reach_hour]:[reach_min][reach_meri] [price]
Example Flight-details:

NewDelhi Mumbai 10:00AM 12:30PM 5000
Mumbai Bengaluru 08:30AM 10:45AM 4500
Steps
Save the Code: Save the provided C code as main.c.

Create Data File: Create the Flight-details file in the same directory.

Compile: Open your terminal and compile the code using a C compiler.

Bash

gcc main.c -o flight_system
Run: Execute the compiled program.

Bash

./flight_system
Project Insights & Learning 📚
This project was a fantastic exercise in using linked lists to manage dynamic data. Each flight is a node in a main linked list, and each flight itself contains a separate linked list to manage its seat reservations. This structure allowed for flexible addition and removal of both flights and individual seats without a fixed array size.

It was an early step in understanding how data structures can be applied to solve real-world problems. I hope this code can be a useful reference for anyone starting their own DSA journey!
