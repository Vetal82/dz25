//#include "Airplane1.h"
//
//
//
//int main() {
//    Airport airport;
//
//    Airplane airplane1(1, "Kyiv-London", 200);
//    Airplane airplane2(2, "Kyiv-Paris", 150);
//    Airplane airplane3(3, "Kyiv-Warshaw", 250);
//
//    airport.add(std::move(airplane1));
//    airport.add(std::move(airplane2));
//    airport.add(std::move(airplane3));
//
//    Airplane* airplane = airport.find(2);
//    if (airplane) {
//        std::cout << "Found airplane with flight number 2." << std::endl;
//    }
//
//    airport.sort();
//
//    Airplane* airplane_to_board = airport.find(1);
//    if (airplane_to_board) {
//        airport.boarding(*airplane_to_board, 100);
//    }
//
//    Airplane* airplane_to_disembark = airport.find(2);
//    if (airplane_to_disembark) {
//        airport.disembarkation(*airplane_to_disembark, 50);
//    }
//
//    return 0;
//}
//
