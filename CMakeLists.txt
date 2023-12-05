cmake_minimum_required(VERSION 3.5)
project(WinProj)

set(ClassesDir src/classes/)
set(Classes
        ${ClassesDir}workQueue/workQueue.cpp
        ${ClassesDir}factory/factory.cpp
        ${ClassesDir}stringSortingQueue/stringSortingQueue.cpp

)

add_executable(lab4 src/main.cpp ${Classes})
set_property(TARGET lab4 PROPERTY CXX_STANDARD 26)

target_include_directories(lab4 PUBLIC ${ClassesDir})