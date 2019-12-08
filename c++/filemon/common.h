
#ifndef FILEMON_COMMON_H 
#define FILEMON_COMMON_H

#include<exception>
#include<fstream>
#include<iostream>
#include<string>
#include<thread>
#include<vector>
#include <cstdio> 
#include <ctime>
#include <chrono>

class Thread {
    public: 
    virtual void worker() = 0; 
    void operator() () {
        worker();
    }
};


class FileNotFoundException : std::exception {
    public:
    FileNotFoundException(const std::string &msg) :std::exception(){
        this->msg = msg; 
    }

    const char* what()   {
        return const_cast<char*>(msg.c_str());
        
    }

    private:
    std::string msg;
};



#endif