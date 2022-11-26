cmake_minimum_required(VERSION 3.13)
project(Group_Byzantine)

set(CMAKE_CXX_STANDARD 14)

add_executable(Group_Byzantine main.cpp node.h network.cpp network.h insertValues.h)