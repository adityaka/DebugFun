#include "common.h"

#ifndef FILEMON_FILER_H 
#define FILEMON_FILER_H
const std::vector<std::string> FILE_CONTENT = {
    "Quick brown fox jumped over the dog",
    "Quick brown dog jumped over the duck",
    "Quick brown duck jumped over the pig",
    "Quick brown pig jumped over the hen",
    "Quick brown hen jumped over the log",
    "Quick brown log stayed on the ground"
};



class Filer : public Thread {
    public:
    Filer(const std::string& filePath="monitored_file");
    virtual void worker() override;
    
    private:
    int getLineIndex();
    std::fstream m_rwStream;
};
#endif