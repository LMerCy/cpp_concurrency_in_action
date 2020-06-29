#include<iostream>
#include<thread>
class backgroudtask
{
public:
    void operator()() const {
        std::cout << "hello world!" << std::endl;
    }
};

struct func{
    int & i;
    func(int &_i):i(_i){}
    void operator()(){
        for(unsigned int j=0;j<10000;j++){
            std:: cout << --i << std::endl;
        }
    }
};

class thread_guard{
    std::thread& t;
public:
    explicit thread_guard(std::thread& _t): t(_t){}
    ~thread_guard(){
        if(t.joinable())
        {
            t.join();
        }
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};
int main(){
    int local_stat = 100;
    func bg(local_stat);
    std::thread my_thread(bg);
    thread_guard tg(my_thread);
}