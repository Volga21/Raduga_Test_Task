#include <iostream>


unsigned int reverse(unsigned int value){
    int i=1;
    unsigned int result=0;
    while(value!=0){
        i=i&value;
        result=result|i;
        value=value>>1;
        i=1;
        result = result << 1;
    }
    result=result >>1;
    return result;
}


int main(){
    unsigned int p=6;
    std::cout<<reverse(p);
    return 0;
}