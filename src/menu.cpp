#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

struct MenuItem{
    int id;
    std::string description;
};

const std::vector<MenuItem> MENU_ITEMS{
    {1, "Add Record"},
    {2, "Display Current Records"},
    {3, "Display Record Values"},
    {0, "Exit the Program"}
};

bool id_in_menu(std::vector<MenuItem> menuItems, int id){
    bool found = std::any_of(menuItems.begin(), menuItems.end(), [id](MenuItem item) { return id == item.id; });
    return found;
};

void print_menu_options(std::vector<MenuItem> menuItems)
{
    for (MenuItem item : menuItems)
    {
        std::cout << item.id << ": " << item.description << std::endl;
    }
    std::cout << std::endl;
};

int get_menu_option(std::vector<MenuItem> menuItems = MENU_ITEMS)
{
    int userInput;
    print_menu_options(menuItems);

    std::cin >> userInput;
    while( !(std::cin.good() &&  id_in_menu(menuItems, userInput)) )
{
        std::cout << "Error: Invalid Console input. Please enter a valid number that is present in the menu." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // stop ignoring characters past the first newline encountered.
        print_menu_options(menuItems);
        std::cin >> userInput;
    }

    std::cout << "Valid entry accepted: " << userInput << std::endl;
    return userInput;
}