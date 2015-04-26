#include <iostream>
#include "Houses.h"

using namespace std;

int main() {
  //
  // Housing search program
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
      string neighborhood = "";
      cout << "Which neighborhood?" << endl;
      cin >> neighborhood;
      string type = "";
      cout << "What kind of house (house, apartment, townhome)?" << endl;
      cin >> type;
      int maxPrice = 0;
      cout << "What is your maximum budget?" << endl;
      cin >> maxPrice;
      h.searchHouses(bed, bath, type, neighborhood, maxPrice);
    }
    
    //Adding a new listing
    if(quit == 2) {
      string name = "";
      cout << "Enter name of home." << endl;
      cin >> name;
      int bed = 0;
      cout << "Enter number of bedrooms." << endl;
      cin >> bed;
      int bath = 0;
      cout << "Enter number of bathrooms." << endl;
      cin >> bath;
      string type = "";
      cout << "Enter type of house." << endl;
      cin >> type;
      string neighborhood = "";
      cout << "Enter neighborhood." << endl;
      cin >> neighborhood;
      int price = 0;
      cout << "Enter price." << endl;
      cin >> price;
      h.newHouse(name, bed, bath, type, neighborhood, price);
    }
  }
  
  if(quit == 7) {
        cout << "Thanks for coming!" << endl;
    }

    return 0;
}
