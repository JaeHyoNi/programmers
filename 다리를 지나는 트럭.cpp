#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //다리에 한번 올라오면 무조건 weight-1초 후에는 내려간다
    //따라서 올라가는 숫자만 정하면 된다
    auto iter = truck_weights.begin();
    int now_weight=*iter;
    int recent_end=bridge_length;
    queue<pair<int,int>> out;
    out.push({*iter,bridge_length+1});
    printf("%d out:%d\n",*iter,bridge_length+1);
    iter++;
    while(iter!=truck_weights.end()){
    
        //printf("*iter = %d iter = %d end() = %d \n",*iter,iter,truck_weights.end());
        //다음 숫자가 들어올 수 있는 경우
        if(now_weight + *iter <= weight){
            printf("[*] %d in:%d out:%d\n",*iter,out.back().second+1-bridge_length,out.back().second+1);
            out.push({*iter,out.back().second+1});
            if(out.front().second+bridge_length <= out.back().second){
                now_weight-=out.front().first;
                out.pop();
            }
            now_weight+=*iter;
            iter++;
        }
        //다음 숫자가 들어올 수 없는 경우
        else{
            //하나를 빼면 들어올 수 있는 경우
            if(now_weight - out.front().first + *iter <= weight){
                out.push({*iter,out.front().second+bridge_length});
                printf("%d in:%d out:%d\n",*iter,out.front().second,out.front().second+bridge_length);
                now_weight = now_weight-out.front().first + *iter;
                iter++;
                out.pop();
            }
            //하나를 빼도 들어올 수 없는 경우
            else{
                now_weight -= out.front().first;
                out.pop();
            }
        }
    }
    cout<<out.back().second;
    return answer;
}

int main(void){
    solution(5,5,{2, 2, 2, 2, 1, 1, 1, 1, 1});
    return 0;
}
