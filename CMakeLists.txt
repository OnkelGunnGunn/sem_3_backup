cmake_minimum_required(VERSION 3.16)

project(protocol VERSION 1.0 LANGUAGES CXX)

# Brug C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Sender
add_executable(protocol_tx
    src/sender.cpp
)

# Receiver
add_executable(protocol_rx
    src/reciever.cpp
)

# Include mappe
target_include_directories(protocol_tx PRIVATE include)
target_include_directories(protocol_rx PRIVATE include)

# OpenCV
find_package(OpenCV REQUIRED)

target_link_libraries(protocol_tx PRIVATE ${OpenCV_LIBS})
target_link_libraries(protocol_rx PRIVATE ${OpenCV_LIBS})

# Warnings
if(MSVC)
    target_compile_options(protocol_tx PRIVATE /W4)
    target_compile_options(protocol_rx PRIVATE /W4)
else()
    target_compile_options(protocol_tx PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(protocol_rx PRIVATE -Wall -Wextra -Wpedantic)
endif()