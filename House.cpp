#include "Houses.h"
#include <iostream>

Houses::Houses()
{
    //ctor
    head = new house;
    head->address = 1058;
    head->street = "virgor";
    head->bed = 1;
    head->bath = 1;
    head->sqrfeet = 1000;
    head->type = "apartment";
    head->neighborhood = "cheyenne mountain";
    head->price = 50000;
    head->previous = NULL;
    //head->next = tail; Note: defining the head->next = tail here will
    //result in a seg fault. The head->next is being set to a place in
    //memory that isnt really there yet. To fix the seg fault when quitting
    //issue I mentioned, I moved this line of code to line 33. Which sets
    //the head->next to tail which is now a defined spot in memory.

    tail = new house;
    tail->address = 277;
    tail->street = "raven mine";
    tail->bed = 5;
    tail->bath = 4;
    tail->sqrfeet = 4000;
    tail->type = "house";
    tail->neighborhood = "gold hill mesa";
    tail->price = 450000;
    tail->next = NULL;
    tail->previous = head;
    head->next = tail;
}

Houses::~Houses()
{
    //dtor
}

/*
Function prototype:
void Houses::displayHouses()

Function description:
This goes through the linked list of houses and prints all of the
addresses and street names.

Example:
Houses h;
h.displayHouses();

Precondition: A linked list of houses must already be established. These
houses must have addresses and street names.
Postcondition: A printed list will display, but nothing about the structure
changes.
*/
void Houses::displayHouses() {
    house *tracker = head;
    while(tracker->next != NULL) {
        std::cout << tracker->address << " " << tracker->street << std::endl;
        tracker = tracker->next;
    }
    std::cout << tracker->address << " " << tracker->street << std::endl;
}


/*
Function prototype:
void Houses::displayMenu()

Function description:
This displays a menu that will be used by the user to navigate through
the program set up to use these functions to navigate the list of homes.

Example:
House h;
h.displayMenu()

Precondition: The iostream library must be included.
Postcondition: The menu is printed but no change happens to the structure
of the program.
*/
void Houses::displayMenu() {
    std::cout << "1. Enter Requests" << std::endl;
    std::cout << "2. Enter New Listing" << std::endl;
    std::cout << "3. Find House by Address and Street" << std::endl;
    std::cout << "4. Add Note" << std::endl;
    std::cout << "5. Print House Details" << std::endl;
    std::cout << "6. Delete House" << std::endl;
    std::cout << "7. Quit" << std::endl;
}

/*
Function prototype:
house Houses::searchHouses(int bed, int bath, int sqrfeet, std::string type,
                           std::string neighborhood, int maxPrice)

Function description:
This searches through the linked list of houses for a house to meet the
parameters of what the user is looking for. If a house is found meeting
the criteria, it will be returned. If such a house does not exist, NULL
will be returned.

Example:
Houses h;
h.searchHouses(2, 2, 1000, apartment, bear creek, 2000)

Precondition: There must be a linked list of houses with the last house
of the list pointing to NULL. These houses should have all variables of
their structure filled out.
Postcondition: A house meeting the description is returned so the user can
see the information pertaining to the house.
*/
house* Houses::searchHouses(int bed, int bath, int sqrfeet, std::string type, std::string neighborhood, int maxPrice) {
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

/*
Function prototype:
void Houses::newHouse(int address, std::string street, int bed, int bath,
                      int sqrfeet, std::string type, std::string neighborhood,
                      int price)

Function description:
This creates a new house and adds all of the information from the input
into the house structure. It then adds the house to the end of the linked
list ensuring if there are similar houses, older additions will be found
first.

Example:
Houses h;
h.newHouse(277, "Institute", 5, 3, 4000, "house", "gold hill", 400000)

Precondition: A head and tail of a linked list of house structs established.
Variables that are being passed in are needed.
Postcondition: Memory is allocated for a new house struct. This house
is then added to the end of the linked list that already exists.
*/
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

/*
Function prototype:
house Houses::findHouse(int address, std::string street)

Function description:
This allows the user to find a house based on the address and street. If
a user has already found the house or is interested in one they have heard
of this is a more efficient way to find it without searching with all the
criteria of searchHouses. This will return a house if the house exists and
NULL if it does not exist.

Example:
Houses h;
h.findHouse(277, "Institute")

Precondition: Linked list of house structs with address and street variables
filled in.
Postcondition: A house struct is returned, but nothing in the structure of
the program is changed.
*/
house* Houses::findHouse(int address, std::string street) {
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

/*
Function prototype:
void Houses::addNote(std::string note)

Function description:
This function allows realtors to add notes to the struct of the house in
order to give details that are not variables in the struct already such
as fireplaces, porches, and yards.

Example:
Houses h;
h.addNote("Great fireplace")

Precondition: The house parameter that is in the function must already
exist.
Postconditin: The note section of that house is now updated to the note
that was passed in.
*/
void Houses::addNote(house *toBe, std::string note) {

}

/*
Function prototype:
void Houses::printOneHouse(int address, std::string street)

Function description:
This finds a house based on the address and street and prints out its
information so the user can see the details of the house.

Example:
Houses h;
h.printOneHouse(277, "Institute")

Precondition: A linked list of house structs with a head and a tail with
a next pointer that points to NULL.
Postcondition: The structure of the program will not change. The information
concerning the house will be printed.
*/
void Houses::printOneHouse(int address, std::string street) {
    house *toPrint = findHouse(address, street);
    std::cout << toPrint->address << " " << toPrint->street << std::endl;
    std::cout << "Beds: " << toPrint->bed << std::endl;
    std::cout << "Baths: " << toPrint->bath << std::endl;
    std::cout << "Square Feet: " << toPrint->sqrfeet << std::endl;
    std::cout << "Type: " << toPrint->type << std::endl;
    std::cout << "Neighborhood: " << toPrint->neighborhood << std::endl;
    std::cout << "Price: " << toPrint->price << std::endl;
    std::cout << "Number Interested: " << toPrint->numberInterested << std::endl;
}

/*
Function prototype:
void Houses::deleteHouse(int address, std::string street)

Function Description:
This deletes a house if it has been bought or if the seller no longer is
interested in selling. The realtor can use this function to take the listing
out of the linked list. If the house does not exist a statement will be
printed saying so.

Example:
Houses h;
h.deleteHouse(277, "Institute)

Precondition: A linked list with a head and a tail with a next pointer
pointing to NULL.
Postcondition: House has been deleted from the linked list and the memory
associated with the house has been freed.
*/
void Houses::deleteHouse(int address, std::string street) {
    house *tracker = head;
    while(tracker != NULL) {
        if(tracker->address == address && tracker->street == street) {
            break;
        }
        tracker = tracker->next;
    }
    if(tracker == NULL) {
        std::cout << "House not found." << std::endl;
    }
    else {
        house *temp = tracker->previous;
        temp->next = tracker->next;
        tracker->previous = temp;
        delete tracker;
    }
}
