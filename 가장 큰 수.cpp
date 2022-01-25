#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(int a,int b){
    string a1 = to_string(a),b1 = to_string(b);
    string t1 = a1+b1,t2 = b1+a1;
    if(stoi(t1)>stoi(t2)) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),compare);
    bool pass=true;
    for(auto K:numbers){answer += to_string(K);if(K!=0)   pass = false;}
    if(pass) return "0";
    else return answer;
}

int main(void){
    cout<<compare(1000,999)<<endl;
    cout<<solution({0,0,0});
}
