#include <iostream>
#include <vector>

using namespace std;

int N;
string command[10000];
int num[10000];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command[i];
        if (command[i] == "push_back" || command[i] == "get") {
            cin >> num[i];
        }
    }

    // Please write your code here.
    vector<int> v;
    for(int i=0; i<N; i++){
        if(command[i] == "push_back"){
            v.push_back(num[i]);
        }
        else if(command[i] == "pop_back"){
            v.pop_back();
        }
        else if(command[i] == "get"){
           cout<<v[num[i]-1]<<endl;
        }
        else if(command[i] == "size"){
            cout<<v.size()<<endl;
        }

    }

    return 0;
}
