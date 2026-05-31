#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> solution( vector<string>park , vector<string> routes );
vector<int> collisionCheck( vector<vector<bool>> map ,int h , int w , string direction, string move, vector<int> position);
int main(void){
    vector<string> park = {"SOO","OOO","OOO"};
    vector<string> routes = {"E 2","S 2","W 1"};
    vector<int> rst = solution(park,routes);
    cout << rst[0] << " , " << rst[1] <<endl;
    return 0;
}

// 1. 우선 park에 저장된것을 map에 저장하자.
// 2. 저장시에 start position은 따로 저장.
// 3. routes를 읽어서, 각각의 이동 명령에 따른 position변화를 수행.
// 4. 결과 리턴 
vector<int> solution( vector<string>park , vector<string> routes ){
    vector<vector<bool>> map;
    vector<int> position;
    int hight = park.size();
    int width = park[0].size();
    
    for( int i=0 ; i<park.size() ; i++ ){
        vector<bool> tmp; // map의 각각의 행에 삽입될 tmp
        stringstream ss(park[i]); // 행에 존재하는 map환경. 
        char ch; // 행에 존재하는 map환경에 대해서, 각 하나씩 읽기위한것.
        int j=0;
        while( ss.get(ch) ){ 
            if(ch=='S'){
                position.push_back(i);
                position.push_back(j);
                tmp.push_back(true);
            }
            else if( ch=='O'){
                tmp.push_back(true);
            }
            else if(ch=='X'){
                tmp.push_back(false);
            }
            else{
                cout<<"park case is not clear";
                return {-1};
            }
            j+=1;
        }
        map.push_back(tmp);
    }
    cout<< "start position is " << position[0] << ","<<position[1]<<endl;
    for( auto command : routes ){
        stringstream ss(command);
        string direction;
        string move;
        ss>>direction;
        ss>> move;
        position = collisionCheck( map , hight , width , direction , move , position);
        cout<< "now position is " << position[0] << ","<<position[1]<<endl;
    }

    return position;
}

// position[0]은 높이.  즉, 세로이다.
// position[1]은 폭. 즉, 가로이다.
vector<int> collisionCheck( vector<vector<bool>> map ,int h , int w , string direction, string move,  vector<int> position){
    int moveCnt = stoi(move);
    
    if ( direction=="E"){
        // 우선 맵 경계에 대한 처리
        if ( position[1] + moveCnt >= w ){
            return position;
        }
        // 여기부터는 이동구간에 장애물이 있으면 false리턴
        for( int i=1 ; i<=moveCnt ; i++){
            if ( map[position[0]][position[1]+i] == false){
                return position;
            }
        }
        // 장애물이 없었으니 true 리턴
        return {position[0],position[1]+moveCnt};
    }
    
    else if ( direction=="W"){
        // 우선 맵 경계에 대한 처리
        if ( position[1] - moveCnt < 0 ){
            return position;
        }
        // 여기부터는 이동구간에 장애물이 있으면 false리턴
        for( int i=1 ; i<=moveCnt ; i++){
            if ( map[position[0]][position[1]-i] == false){
                return position;
            }
        }
        // 장애물이 없었으니 true 리턴
        return {position[0],position[1]-moveCnt};
    }

    else if ( direction=="N"){
        // 우선 맵 경계에 대한 처리
        if ( position[0] - moveCnt < 0 ){
            return position;
        }
        // 여기부터는 이동구간에 장애물이 있으면 false리턴
        for( int i=1 ; i<=moveCnt ; i++){
            if ( map[position[0]-i][position[1]] == false){
                return position;
            }
        }
        // 장애물이 없었으니 true 리턴
        return {position[0]-moveCnt , position[1]};
    } 

    else if ( direction=="S"){
        // 우선 맵 경계에 대한 처리
        if ( position[0] + moveCnt >= h ){
            return position;
        }
        // 여기부터는 이동구간에 장애물이 있으면 false리턴
        for( int i=1 ; i<=moveCnt ; i++){
            if ( map[position[0]+i][position[1]] == false){
                return position;
            }
        }
        // 장애물이 없었으니 true 리턴
        return {position[0]+moveCnt , position[1]};
    } 
    else{
        cout<<"error";
        return position;
    }
}