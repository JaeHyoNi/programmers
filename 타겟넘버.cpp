#include <iostream>
#include <vector>
#include <cstring>
using namespace std;




int answer = 0,sizenum = 0,targett = 0;
vector<int> temp;
void dfs( int sum, int now){
    if (now == sizenum){
        if (sum == targett) answer++;
        return;
    }
    printf("target = %d , sum = %d , now = %d\n",targett,sum,now);
    dfs(sum + temp[now], now+1);
    dfs(sum - temp[now], now+1);
}


int solution(vector<int> numbers, int target) {
    temp = numbers;
    targett = target;
    sizenum = numbers.size();
    dfs(0,0);
    return answer;
}




int main(void){
    vector<int> temp;
    
    cout<< solution({1,1,1,1,1},3);
}
