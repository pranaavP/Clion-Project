cmake_minimum_required(VERSION 4.0)
project(C__Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(C__Project main.cpp
        Marble.cpp
        Marble.h
        MarbleRacingGame.cpp
        MarbleRacingGame.h
        Player.cpp
        Player.h
        FinishLine.cpp
        FinishLine.h
        BettingMethod.cpp
        BettingMethod.h)
