#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include "menu.cpp"
#include "statistics.cpp"

const std::vector<MenuItem> MENU_ITEMS{
    {1, "Add Stat Column"},
    {2, "Add Records to Existing Columns"},
    {3, "Display Current Stat Columns"},
    {4, "Display Current Records"},
    {0, "Exit the Program"}
};

template<typename T>
std::vector<StatColumn<T>> add_column(std::vector<StatColumn<T>> records, int recordSize);

template<typename T>
std::vector<StatColumn<T>> add_record(std::vector<StatColumn<T>> records);

template<typename T>
void print_column_headers(std::vector<StatColumn<T>> records);

template<typename T>
void print_columns(std::vector<StatColumn<T>> records);

int main(){
    std::vector<StatColumn<int>> records;
    bool exitOption;
    int recordSize = 0;

    do{
        int input = get_menu_option(MENU_ITEMS);
        switch(input){
            case 1:
                records = add_column(records, recordSize);
                break;
            case 2:
                records = add_record(records);
                recordSize++;
                break;
            case 3:
                print_column_headers(records);
                break;
            case 4:
                print_columns(records);
                break;
            default:
                exitOption = 1;
        }
        std::cout << std::endl;
    }while(!exitOption);
    std::cout << "Exited program. Goodbye" << std::endl; 
    return 0;
}

template<typename T>
std::vector<StatColumn<T>> add_column(std::vector<StatColumn<T>> records, int recordSize){
    std::string recordName;
    T recordValue;
    std::cout << "Please enter record name: ";
    std::cin >> recordName;
    std::vector<T> v(recordSize, 0 );
    StatColumn<T> record{recordName, v};
    records.push_back(record);
    return records;
}

template<typename T>
std::vector<StatColumn<T>> add_record(std::vector<StatColumn<T>> records){
    T recordValue;
    for(StatColumn<T> &record: records){
        std::cout << "Enter value for " << record.getHeader() << ": ";
        std::cout << "Please enter record value: ";
        std::cin >> recordValue;
        while(std::cin.bad()){
            std::cout << "Invalid input. Please enter record value: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> recordValue;
        }
        record.addRecord(recordValue);
    }
    return records;
}

template<typename T>
void print_column_headers(std::vector<StatColumn<T>> records){
    for(int i = 0; i < records.size(); i++){
        std::cout << "Record " << i+1 << " Name: " << records[i].getHeader() << std::endl;
    }
    return;
}

template<typename T>
void print_columns(std::vector<StatColumn<T>> records){
    for(int i = 0; i < records.size(); i++){
        std::vector<T> record_values = records[i].getRecords();
        std::cout << records[i].getHeader() << ": " << std::endl;
        if(record_values.size() == 0){
            std::cout << "\t" << "No Entries" << std::endl;
        }
        else{
            for(int i = 0; i < record_values.size(); i++){
                std::cout << "\t" << i+1 << ": " << record_values[i] << std::endl;
            }
        }
    }
    return;
}



