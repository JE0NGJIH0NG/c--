#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution( int storage , int usage , vector<int> change ){
    int total_usage = 0;
    for(int i=0 ; i<change.size() ; i++){
        usage = usage + usage*change[i]/100;
        total_usage+=usage;
        if(total_usage>0){
            return i;
        }
    }
    return -1;
}

int main(void){
    int storage = 5141;
    int usage = 500;
    vector<int> change;
    change.push_back(10);
    change.push_back(-10);
    change.push_back(10);
    change.push_back(-10);
    change.push_back(10);
    change.push_back(-10);
    change.push_back(10);
    change.push_back(-10);
    change.push_back(10);
    change.push_back(-10);
    cout << solution(storage,usage,change) << endl;
    return 0;
}