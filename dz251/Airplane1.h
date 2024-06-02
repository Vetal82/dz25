//#pragma once
//#ifndef AIRPORT_H
//#define AIRPORT_H
//
//#include <iostream>
//#include <cstring>
//#include <list>
//
//
//class Airplane {
//public:
//    int flight_number;
//    char direction[100];
//    int current_passengers;
//    int max_passengers;
//
//    Airplane(int flight_number, const char* direction, int max_passengers)
//        : flight_number(flight_number), max_passengers(max_passengers), current_passengers(0) {
//        strncpy_s(this->direction, direction, sizeof(this->direction) - 1);
//        this->direction[sizeof(this->direction) - 1] = '\0';
//    }
//
//    bool operator==(const Airplane& other) const {
//        return flight_number == other.flight_number;
//    }
//
//    bool operator!=(const Airplane& other) const {
//        return !(*this == other);
//    }
//
//    Airplane& operator++() {
//        if (current_passengers < max_passengers) {
//            current_passengers++;
//        }
//        return *this;
//    }
//
//    Airplane operator++(int) {
//        Airplane tmp(*this);
//        operator++();
//        return tmp;
//    }
//
//    Airplane& operator--() {
//        if (current_passengers > 0) {
//            current_passengers--;
//        }
//        return *this;
//    }
//
//    Airplane operator--(int) {
//        Airplane tmp(*this);
//        operator--();
//        return tmp;
//    }
//
//    bool operator>(const Airplane& other) const {
//        return max_passengers > other.max_passengers;
//    }
//
//    bool operator>=(const Airplane& other) const {
//        return max_passengers >= other.max_passengers;
//    }
//
//    bool operator<(const Airplane& other) const {
//        return max_passengers < other.max_passengers;
//    }
//
//    bool operator<=(const Airplane& other) const {
//        return max_passengers <= other.max_passengers;
//    }
//
//    friend std::ostream& operator<<(std::ostream& os, const Airplane& airplane) {
//        os << "Flight number: " << airplane.flight_number
//            << ", Direction: " << airplane.direction
//            << ", Current passengers: " << airplane.current_passengers
//            << ", Max passengers: " << airplane.max_passengers;
//        return os;
//    }
//};
//
//class Airport {
//public:
//    std::list<Airplane> schedule;
//
//    void add(Airplane&& airplane) {
//        schedule.push_back(std::move(airplane));
//    }
//
//    void remove(const Airplane& airplane) {
//        schedule.remove(airplane);
//    }
//
//    Airplane* find(int flight_number) {
//        for (Airplane& airplane : schedule) {
//            if (airplane.flight_number == flight_number) {
//                return &airplane;
//            }
//        }
//        return nullptr;
//    }
//
//    void sort() {
//        schedule.sort([](const Airplane& a, const Airplane& b) {
//            return a.max_passengers < b.max_passengers;
//            });
//    }
//
//    void boarding(Airplane& airplane, int passengers) {
//        if (passengers <= airplane.max_passengers - airplane.current_passengers) {
//            airplane.current_passengers += passengers;
//        }
//        else {
//            std::cout << "Not enough seats." << std::endl;
//        }
//    }
//
//    void disembarkation(Airplane& airplane, int passengers) {
//        if (passengers <= airplane.current_passengers) {
//            airplane.current_passengers -= passengers;
//        }
//        else {
//            std::cout << "Not enough passengers." << std::endl;
//        }
//    }
//};
//
//#endif // AIRPORT_H
