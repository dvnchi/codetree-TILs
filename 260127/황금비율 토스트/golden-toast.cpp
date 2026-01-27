#include <iostream>
#include <list>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    
    list<char> bread;
    
    for(int i=0; i<n; i++){ // 식빵 배열 채우기
        char a;
        cin>>a;
        bread.push_back(a);
    }

    list<char>::iterator it = bread.end();

    for(int i=0; i<m; i++){ // 암호 명령어 입력 받기
        char command;
        cin>>command;

        if(command == 'L'){
            if(it != bread.begin()){
                it--;
            }
        }
        else if(command == 'R'){
            if(it != bread.end()){
                it++;
            }
        }
        else if(command == 'D'){
            if(it != bread.end()){
                it = bread.erase(it);
            }
        }
        else if(command == 'P'){
            char s;
            cin>>s;
            bread.insert(it,s);
        }
    }

    for(it = bread.begin(); it != bread.end(); it++){
        cout<< *it;
    }

    return 0;
}