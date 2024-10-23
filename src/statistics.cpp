#include <vector>
#include <string>

template<typename T>
class StatColumn {
    public:
        std::string columnHeader;
        std::vector<T> records;  
        StatColumn(std::string& columnHeader, std::vector<T>& records){
            this->columnHeader = columnHeader;
            this->records = records;
        }
        void addRecord(float record){
            records.push_back(record);
        }
        decltype(auto) getRecords(){
            return (records);
        }
};