#include <iostream>
using namespace std;
int main(void){
    int start;
    int before;
    int after;
    cin >> start >> before >> after;

    int money = start;
    int month = 1;

    while(money<70){
        money+=before;
        month+=1;
    }
    while(money<100){
        money+=after;
        month+=1;
    }
    cout<<month<<endl;
    return 0;
}