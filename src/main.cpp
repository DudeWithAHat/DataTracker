#include <vector>
#include <string>
#include <iostream>

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

int main(){
    std::string h1 = "Weight";
    std::vector<float> v1{};
    StatColumn s1{h1, v1};
    s1.addRecord(114.1);
    s1.addRecord(115.2);
    std::vector<float>& v2 = s1.getRecords();
    v2[1] = 5.0;
    std::cout << &s1.records << std::endl;
    std::cout << &v2 << std::endl;
    auto v3 = s1.getRecords();
    for(int i = 0; i < v3.size(); i++){
        std::cout << v3[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
