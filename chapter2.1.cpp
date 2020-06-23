#include<iostream>
#include<thread>
class backgroudtask
{
public:
    void operator()() const {
        std::cout << "hello world!" << std::endl;
    }
};
int main(){
    backgroudtask bg;
    backgroudtask();
    std::thread t((backgroudtask()));
    t.join();
}