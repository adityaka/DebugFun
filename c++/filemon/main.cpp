#include "common.h"
#include "filer.h"
#include "filemon.h"



int main(int argc, char **argv) {
    
    auto t1 = std::thread(Filer("monitored_file"));
    auto t2 = std::thread(Filemon("monitored_file"));

    t1.join();
    t2.join();

    return 0;

}

