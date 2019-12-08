#include<iostream>
#include<thread>

class Thread {
public:
    virtual void worker() =0;

    void operator() () {
        worker();
    }
};

class HelloThread : public Thread {
    public:
    HelloThread() :Thread() {

    }

    virtual void worker() override {
        std::cout << "Hello ";
    }

};

class WorldThread : public Thread { 
    public:
    WorldThread() : Thread() {

    }

    virtual void worker() override {
        std::cout << "World";
    }


};

int main(int argc, char **argv){
    std::thread t = std::thread(HelloThread());
    std::thread t1 = std::thread(WorldThread());
    t1.join();

    t.join();
}