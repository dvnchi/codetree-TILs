#include <iostream>
#include <string>
#include <list>

using namespace std;

int N;
string command[10000];
int A[10000];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_front" || command[i] == "push_back") {
            cin >> A[i];
        }
    }

    // Please write your code here.
    list<int> myList;
    for(int i=0; i<N; i++){
        if(command[i] == "push_front"){
            myList.push_front(A[i]);
        }
        else if(command[i] == "push_back"){
            myList.push_back(A[i]);
        }
        else if(command[i] == "pop_front"){
            cout<<myList.front()<<endl;
            myList.pop_front();
        }
        else if(command[i] == "pop_back"){
            cout<<myList.back()<<endl;
            myList.pop_back();
        }
        else if(command[i] == "size"){
            cout<<myList.size()<<endl;
        }
        else if(command[i] == "empty"){
            cout<<myList.empty()<<endl;
        }
        else if(command[i] == "front"){
            cout<<myList.front()<<endl;
        }
        else if(command[i] == "back"){
            cout<<myList.back()<<endl;
        }
    }
    

    return 0;
}
