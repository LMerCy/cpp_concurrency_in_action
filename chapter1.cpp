#include<iostream>
#include<thread>
void hello()
{
    std::cout<< "hello world!" << std::endl;
    return ;
}
int main(){
    std::thread t(hello);
    t.join();
}