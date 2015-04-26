#ifndef HOUSES_H
#define HOUSES_H
#include <iostream>

struct house {
    int address;
    std::string street;
    int bed;
    int bath;
    int sqrfeet;
    std::string type;
    std::string neighborhood;
    int price;
    int numberInterested;
    std::string notes;
    house *next;
    house *previous;
};

class Houses
{
    public:
        Houses();
        virtual ~Houses();
        void displayMenu();
        house searchHouses(int bed, int bath, int sqrfeet, std::string type, std::string neighborhood,
                          int maxPrice);
        void newHouse(int address, std::string street, int bed, int bath, int sqrfeet, std::string type, std::string neighborhood, int price);
        house findHouse(int address, std::string street);
        void addNote(std::string toBeAdded);
        void printOneHouse(int address, std::string street);
        void deleteHouse(int address, std::string street);
    protected:
    private:
        house *head;
        house *tail;
        void displayHouses();
};

#endif // HOUSES_H
