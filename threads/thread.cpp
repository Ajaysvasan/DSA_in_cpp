#include<iostream>
#include<thread>
#include<map>
#include<chrono>

using namespace std::chrono_literals;

void refereshForecastMap(std::map<std::string ,int>&Map){
    while(true){
    for(auto& item:Map){
        item.second++;
        std::cout<<item.first<<" "<<item.second<<std::endl;
    }
    std::this_thread::sleep_for(2000ms);
    }
}
int main(){
    std::map<std::string , int> forecastMap = {
        {"new York",48},
        {"Mumbai" , 50},
        {"Chennai",34}
    };
    std::thread threadOne(refereshForecastMap,std::ref(forecastMap));
    threadOne.join();
    return 0;
}