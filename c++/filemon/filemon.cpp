#include "filemon.h"

Filemon::Filemon(const std::string filePath): Thread(){
    this->m_rwStream.open(filePath, std::ios::in );
    if (!this->m_rwStream.is_open()) {
        throw FileNotFoundException("Can't open file " +  filePath);
    }
}

 void Filemon::worker() {
    std::string lastLine="";
    std::string currentLastLine;
    while(!m_rwStream.eof()){
        std::getline(m_rwStream, currentLastLine, '\n');
    }
    if (currentLastLine.size() == lastLine.size()){
        if (currentLastLine == lastLine){
            std::cout << "File updated with " << currentLastLine;
            lastLine = currentLastLine;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
    
}