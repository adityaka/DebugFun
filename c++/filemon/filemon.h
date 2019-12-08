#include"common.h"

#ifndef FILEMON_FILEMON_H
#define FILEMON_FILEMON_H

class Filemon : public Thread{
    public:
    Filemon(const std::string filePath="monitored_file");

    virtual void worker() override;

    private:
    const std::string m_filePath;
    std::fstream m_rwStream;
};

#endif