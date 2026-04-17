#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> solution( vector<int> numbers , vector<int> our_score , vector<int> score_list);
int main(void){
    vector<int> numbers = {1};
    vector<int> our = {100};
    vector<int> score = {100,80,90,84,20};
    vector<string> rst =solution(numbers,our,score); 
    cout << rst[0];
    return 0;

}

vector<string> solution( vector<int> numbers , vector<int> our_score , vector<int> score_list){
    int num_student = numbers.size();
    vector<string> answer(num_student);

    for( int i=0 ; i<num_student ; i++){
        if( score_list[numbers[i]-1] == our_score[i] ){
            answer[i]="Same";
        }
        else{
            answer[i]="Different";
        }
    }
    return answer;
}