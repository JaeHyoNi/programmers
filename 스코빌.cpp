#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int , vector<int> , greater<> > scobill;
    for(auto K:scoville)    scobill.push(K);
    int a,b;
    while(1){
        a = scobill.top();
        scobill.pop();
        if(a>=K) {return answer;}
        if(scobill.empty()) return -1;
        b = scobill.top();
        scobill.pop();
        answer++;
        scobill.push(a+2*b);
    }
}

int main(void){
    cout<<solution({1, 2, 3, 9, 10, 12},7);
    return 0;
}
