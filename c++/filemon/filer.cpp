
#include "filer.h"

Filer::Filer(const std::string& filePath) : Thread(){
    m_rwStream.open(filePath, std::ios::out);
    if(!m_rwStream.is_open()){
        throw FileNotFoundException("File can't be opened " + filePath);
    }
}

int Filer::getLineIndex() {
       std::srand(std::time(0));
    int random_number = std::rand() % 10 - 6;
    if (random_number < 0) {
        random_number +=6;
    }

    return random_number;
    
}

void Filer::worker() {
    while(true) {
        int lineIndex = getLineIndex();
        std::string line = FILE_CONTENT[lineIndex] + "\n";
        m_rwStream.write(line.c_str(), line.size());
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}