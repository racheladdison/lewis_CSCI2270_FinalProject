#include <iostream>
#include "Houses.h"

using namespace std;

int main()
{
    //
    //Housing search program
    //

    Houses h;
    //Have a menu
    int quit = 0;
    while(quit != 7) {
        h.displayMenu();
        cin >> ws;
        cin >> quit;
        //Asks for what the user wants in a house
        if(quit == 1) {
            int bed = 0;
            cout << "How many bedrooms?" << endl;
            cin >> bed;
            int bath = 0;
            cout << "How many bathrooms?" << endl;
            cin >> bath;
            int sqr = 0;
            cout << "Enter square footage." << endl;
            cin >> sqr;
            string neighborhood = "";
            cout << "Which neighborhood?" << endl;
            cin >> neighborhood;
            string type = "";
            cout << "What kind of house (house, apartment, townhome)?" << endl;
            cin >> type;
            int maxPrice = 0;
            cout << "What is your maximum budget?" << endl;
            cin >> maxPrice;
            h.searchHouses(bed, bath, sqr, type, neighborhood, maxPrice);
        }

        //Adding a new listing
        if(quit == 2) {
            int address = 0;
            cout << "Enter address number." << endl;
            cin >> address;
            string street = "";
            cout << "Enter name of street." << endl;
            cin >> street;
            int bed = 0;
            cout << "Enter number of bedrooms." << endl;
            cin >> bed;
            int bath = 0;
            cout << "Enter number of bathrooms." << endl;
            cin >> bath;
            int sqr = 0;
            cout << "Enter square footage." << endl;
            cin >> sqr;
            string type = "";
            cout << "Enter type of house." << endl;
            cin >> type;
            string neighborhood = "";
            cout << "Enter neighborhood." << endl;
            cin >> neighborhood;
            int price = 0;
            cout << "Enter price." << endl;
            cin >> price;
            h.newHouse(address, street, bed, bath, sqr, type, neighborhood, price);
        }

        //Find a house if you know the address and street
        if(quit == 3) {
            int address = 0;
            cout << "Enter address." << endl;
            cin >> address;
            string street = " ";
            cout << "Enter street." << endl;
            cin >> street;
            house *ans = h.findHouse(address, street);
            h.printOneHouse(address, street);
            string answ;
            cout << "Are you interested in this house? (Yes/No)" << endl;
            cin >> answ;
            if(answ == "Yes") {
                ans->numberInterested ++;
            }
        }

        //Allows realtor to add note to house
        if(quit == 4) {
            int address = 0;
            cout << "Enter address." << endl;
            cin >> address;
            string street;
            cout << "Enter street." << endl;
            cin >> street;
            string note;
            cout << "Enter note." << endl;
            cin >> note;
            house *toBe = h.findHouse(address, street);
            h.addNote(toBe, note);
        }

        //Print all information of house
        if(quit == 5) {
            int address = 0;
            cout << "Enter address." << endl;
            cin >> address;
            string street;
            cout << "Enter street name." << endl;
            cin >> street;
            h.printOneHouse(address, street);
        }

        //Delete a house if it is sold or taken off market
        if(quit == 6) {
            int address = 0;
            cout << "Enter address to be deleted." << endl;
            cin >> address;
            string street;
            cout << "Enter street of house to be deleted." << endl;
            cin >> street;
            h.deleteHouse(address, street);
        }

        //After whichever modification is made print all houses
        h.displayHouses();
    }
    if(quit == 7) {
        cout << "Thanks for coming!" << endl;
    }

    return 0;
}
