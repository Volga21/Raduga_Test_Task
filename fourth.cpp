#include <iostream>
#include <string>
#include <vector>

class Employer{
    public:
        explicit Employer(bool busy,std::string name):busy(busy),name(name){}
        bool accpetCall(){
            if(!busy){
                std::cout<<name<<" принял звонок"<<std::endl;
                busy=true;
                return true;
            }
             std::cout<<name<<" сейчас не может принять звонок"<<std::endl;
            return false;
        }
        void freeEmployer(){
            busy=false;
        }

    private:
        bool busy;
        std::string name;
};

class Director:public Employer{
    public:
        explicit Director(bool busy):Employer(busy,"Директор"){
        }
};

class Manager:public Employer{
    public:
        explicit Manager(bool busy):Employer(busy,"Менеджер"){
        }
};

class Operator:public Employer{
    public:
        explicit Operator(bool busy):Employer(busy,"Оператор"){
        }
};

class CallCenter{
    public:
        void dispatchCall(){
            if(!operat.accpetCall()){
                if(!manager.accpetCall()){
                    director.accpetCall();
                }
                
            }
        }
    private:
        Director director{false};
        Manager manager{false};
        Operator operat{false};
};

int main(){
    CallCenter sber;
    sber.dispatchCall();
    sber.dispatchCall();
    sber.dispatchCall();
    sber.dispatchCall();

    return 0;
}