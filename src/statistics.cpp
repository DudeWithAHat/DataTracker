#include <vector>
#include <string>

template<typename T>
class StatColumn {
    private:
        std::string header;
        std::vector<T> records;  
    public:
        StatColumn(std::string header, std::vector<T> records){
            this->header = header;
            this->records = records;
        }
        //void addRecord(float record){
        //    records.push_back(record);
        //}
        std::string getHeader(){
            return header;
        }
        std::vector<T> getRecords(){
            return records;
        }
};