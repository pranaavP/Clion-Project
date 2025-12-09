cmake_minimum_required(VERSION 4.0)

project(Clion-Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Clion_Project
        main.cpp
        Marble.cpp
        MarbleRacingGame.cpp
        Player.cpp
        FinishLine.cpp
        BettingMethod.cpp
)
