project(Filemon)
add_executable(filemon main.cpp filer.cpp filemon.cpp)
target_link_libraries(filemon pthread)