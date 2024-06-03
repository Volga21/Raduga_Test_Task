#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
//вход N-кол-во автоматов 
//К - покупателей и их время работы 

//


int queueTime(int N,std::queue<int> customers){
    size_t time=0;
    std::vector<size_t> busy_terminals(N);
    if(customers.size()<=N){
        size_t max=0;
        while(!customers.empty()){
            if(customers.front()>max){
                max=customers.front();
            }
            customers.pop();
            }
            return max;
    }
    //пускаем первых N людей к терминалам
    for(size_t i=0;i<N;i++){
        busy_terminals[i]=customers.front();
        customers.pop();
    }
    size_t min;
    int count = customers.size();
    //пока все люди не прошли выполняем
    while(count>0){

        min=*std::min_element(begin(busy_terminals),end(busy_terminals));//находим человека с наименьшим временем, он уйдет первым
        time+=min;
        for(size_t i=0;i<N;i++){
            busy_terminals[i]-=min;//вычитаем наименьшее время у всех 
        }
        for(size_t i=0;i<busy_terminals.size();i++){
            if(busy_terminals[i]==0){
                busy_terminals[i]=customers.front();//заменяем людей
                customers.pop();
                count--;
                if(count==0){
                    break;
                }
            }
        }
    }
    time+=*std::max_element(begin(busy_terminals),end(busy_terminals));//добавляем время самого долгого 
    return time;
}

int main(){
    size_t N,K;
    std::cin>>N>>K;
    size_t time;
    std::queue<int> q;
    for(size_t i=0;i<K;i++){
        std::cin>>time;
        q.push(time);
    }
    std::cout<<queueTime(N,q);
    return 0;
}