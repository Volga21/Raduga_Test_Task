#include<iostream>

template <typename T>
class SmartPointer{
    public:
        SmartPointer(T * p=nullptr):pointer(p),count(nullptr){
            if(p!=nullptr){
                count= new size_t(1);
            }
        }
        SmartPointer(const SmartPointer & sm_pointer):pointer(sm_pointer.getPtr()){
            count = sm_pointer.getCount();
            if(count!=nullptr){
                ++*count;
            }
        }
        T* getPtr()const{
            return pointer;
        }
        size_t* getCount()const{
            return count;
        }
        ~SmartPointer(){
            if(--*count==0){
                delete count;
                delete pointer;
            }
        }
    private:
        T * pointer;
        size_t * count;
};
int main(){
    {
        SmartPointer p1{new size_t(21)};
        std::cout<<(*p1.getCount())<<" "<<(*p1.getPtr())<<std::endl;
        {
            SmartPointer p2{p1};
            std::cout<<(*p2.getCount())<<" "<<(*p2.getPtr())<<std::endl;
        }   
        std::cout<<(*p1.getCount())<<" "<<(*p1.getPtr())<<std::endl;
    }
    return 0;
}