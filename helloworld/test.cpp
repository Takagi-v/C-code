#include<iostream>
int main(){
    int x=3;
    int y=x+(x=x+1);
    std::cout<<y;
}
