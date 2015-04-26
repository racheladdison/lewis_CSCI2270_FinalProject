#include "Houses.h"
#include <iostream>

Houses::Houses()
{
    //ctor
    head = new house;
    head->name = "Rico";
    head->bed = 1;
    head->bath = 1;
    head->type = "apartment";
    head->neighborhood = "cm";
    head->price = 50,000;
    head->previous = NULL;
    head->next = NULL;
}

Houses::~Houses()
{
    //dtor
}

//Displays all the addresses of the houses in the linked list
void Houses::displayHouses() {
    house *tracker = head;
    while(tracker->next != NULL) {
        std::cout << tracker->address << " " << tracker->street << std::endl;
        tracker = tracker->next;
    }
    std::cout << tracker->address << " " << tracker->street << std::endl;
}


//Function to easily display the menu of selections for the user
void Houses::displayMenu() {
    std::cout << "1. Enter Requests" << std::endl;
    std::cout << "2. Enter New Listing" << std::endl;
    std::cout << "7. Quit" << std::endl;
}

//Searches for a house that meets the requests of the user
//Returns NULL if such a house does not exist
house Houses::searchHouses(int bed, int bath, int sqrfeet, std::string type, std::string neighborhood, int maxPrice) {
    house *tracker = head;
    house *found = NULL;
    while(tracker != NULL) {
        if(tracker->bed > bed && tracker->bath > bath && tracker->sqrfeet > sqrfeet &&
            tracker->type == type && tracker->neighborhood == neighborhood && tracker->price < maxPrice) {
            found = tracker;
        }
    }
    return found;
}

//Creates a new house and adds it to the linked list of houses
void Houses::newHouse(int address, std::string street, int bed, int bath, int sqrfeet, std::string type, std::string neighborhood, int price) {
    house *newH = new house;
    newH->address = address;
    newH->street = street;
    newH->bed = bed;
    newH->bath = bath;
    newH->sqrfeet = sqrfeet;
    newH->type = type;
    newH->neighborhood = neighborhood;
    newH->price = price;
    //newH->previous = tail;
    //tail->next = newH;
    newH->next = NULL;
    //tail = newH;
    displayHouses();
}

//Allows a person to search for a certain address to access its information
house Houses::findHouse(int address, std::string street) {
    house *tracker = head;
    house *found = NULL;
    while(tracker != NULL) {
        if(tracker->address == address && tracker->street == street) {
            found = tracker;
        }
        tracker = tracker->next;
    }
    return found;
}

//Allows realtors to add notes about the home such as features(fireplaces,
//yards, porches, basements).
void Houses::addNote(std::string toBe) {

}

//Prints all information having to do with the house address
void Houses::printOneHouse(int address, std::string street) {
    house toPrint = findHouse(address, street);
    std::cout << toPrint->address << " " << toPrint->street << std::endl;
    std::cout << "Beds: " << toPrint->bed << std::endl;
    std::cout << "Baths: " << toPrint->bath << std::endl;
    std::cout << "Square Feet: " << toPrint->sqrfeet << std::endl;
    std::cout << "Type: " << toPrint->type << std::endl;
    std::cout << "Neighborhood: " << toPrint->neighborhood << std::endl;
    std::cout << "Price: " << toPrint->price << std::endl;
    std::cout << "Number Interested: " << toPrint->numberInterested << std::endl;
}
