#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int siz = priorities.size();
    vector<int> order(siz);
    vector<int> temp = priorities;
    sort(temp.begin(), temp.end(),greater<>());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    int next = temp.size();
    
    auto iter = priorities.begin();
    auto tmpiter = iter;

    int num = 1;
    for(int j=0;j<next;j++){
        iter = tmpiter;
        for(int i=0;i<siz;i++){
            if(*(iter) == temp[j]){
                tmpiter = iter;
                order[iter-priorities.begin()] = num++;
                if(order[location]!=0) return order[location];
            }
            iter++;
            if(iter==priorities.end()) 
                iter = priorities.begin();
        }
    }
}

int main(void) {
    cout<<solution({ 2,1,3,2 }, 2);
    return 0;
}
