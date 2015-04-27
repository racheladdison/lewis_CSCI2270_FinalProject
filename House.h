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
    int numberInterested = 0;
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
        void displayHouses();
        house* searchHouses(int bed, int bath, int sqrfeet, std::string type, std::string neighborhood,
                          int maxPrice);
        void newHouse(int address, std::string street, int bed, int bath, int sqrfeet, std::string type, std::string neighborhood, int price);
        house* findHouse(int address, std::string street);
        void addNote(house *toBe, std::string toBeAdded);
        void printOneHouse(int address, std::string street);
        void deleteHouse(int address, std::string street);
    protected:
    private:
        house *head;
        house *tail;
};

#endif // HOUSES_H
