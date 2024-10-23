#include <vector>
#include <string>
#include <iostream>
#include "menu.cpp"
#include "statistics.cpp"

int main(){
    int input = get_menu_option();
    std::cout << "Option Selected: " << input << std::endl;
    return 0;
}
