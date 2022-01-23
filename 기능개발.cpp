#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int siz = progresses.size();
    vector<bool> done(siz);
    int iter = 0,ans = 0;
    while(1){
        for(int i=0;i<siz;i++){
            ans = 0;
            progresses[i]+=speeds[i];
            if(progresses[i]>=100){
                done[i] = true; 
            }
        }
        while(done[iter] == true){
            ans++;
            iter++;
        }
        if(ans!=0) answer.push_back(ans);
        if(iter == siz) break;
    }
    return answer;
}

int main(){
    for (auto K:solution({95, 90, 99, 99, 80, 99},{1, 1, 1, 1, 1, 1})){
        cout<<K<<" ";
    }
}
