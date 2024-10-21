#include <vector>
#include <string>
#include <iostream>

template<typename T>
class StatColumn {
    private:
        std::string columnHeader;
        std::vector<T> records;  
    public:
        StatColumn(std::string& columnHeader, std::vector<T>& records){
            this->columnHeader = columnHeader;
            this->records = records;
        }
        void addRecord(T record){
            this->records.push_back(record);
        }
        const auto getRecords() -> decltype(records){
            return records;
        }
};

int main(){
    std::string h1 = "Weight";
    std::vector<float> v1{};
    StatColumn<float> s1{h1, v1};
    s1.addRecord(114.1);
    s1.addRecord(115.2);
    std::vector<float> v2 = s1.getRecords();
    for(int i = 0; i < v2.size(); i++){
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
