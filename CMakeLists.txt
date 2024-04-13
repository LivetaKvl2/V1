cmake_minimum_required(VERSION 3.12)

project("V1")

add_executable(strategy1_deque
    1STRATEGIJA/Deque/testavimas.cpp
    1STRATEGIJA/Deque/studentai.cpp
    1STRATEGIJA/Deque/studentai.h
)
set_property(TARGET strategy1_deque PROPERTY CXX_STANDARD 20)

add_executable(strategy1_vector
    1STRATEGIJA/Vectors/testavimas.cpp
    1STRATEGIJA/Vectors/studentai.cpp
    1STRATEGIJA/Vectors/studentai.h
)
set_property(TARGET strategy1_vector PROPERTY CXX_STANDARD 20)

add_executable(strategy1_list
    1STRATEGIJA/List/testavimas.cpp
    1STRATEGIJA/List/studentai.cpp
    1STRATEGIJA/List/studentai.h
)
set_property(TARGET strategy1_list PROPERTY CXX_STANDARD 20)

add_executable(strategy2_deque
    2STRATEGIJA/Deque/testavimas.cpp
    2STRATEGIJA/Deque/studentai.cpp
    2STRATEGIJA/Deque/studentai.h
)
set_property(TARGET strategy2_deque PROPERTY CXX_STANDARD 20)

add_executable(strategy2_vector
    2STRATEGIJA/Vectors/testavimas.cpp
    2STRATEGIJA/Vectors/studentai.cpp
    2STRATEGIJA/Vectors/studentai.h
)
set_property(TARGET strategy2_vector PROPERTY CXX_STANDARD 20)

add_executable(strategy2_list
    2STRATEGIJA/List/testavimas.cpp
    2STRATEGIJA/List/studentai.cpp
    2STRATEGIJA/List/studentai.h
)
set_property(TARGET strategy2_list PROPERTY CXX_STANDARD 20)

add_executable(strategy3_deque
    3STRATEGIJA/Deque/testavimas.cpp
    3STRATEGIJA/Deque/studentai.cpp
    3STRATEGIJA/Deque/studentai.h
)
set_property(TARGET strategy3_deque PROPERTY CXX_STANDARD 20)

add_executable(strategy3_vector
    3STRATEGIJA/Vectors/testavimas.cpp
    3STRATEGIJA/Vectors/studentai.cpp
    3STRATEGIJA/Vectors/studentai.h
)
set_property(TARGET strategy3_vector PROPERTY CXX_STANDARD 20)

add_executable(strategy3_list
    3STRATEGIJA/List/testavimas.cpp
    3STRATEGIJA/List/studentai.cpp
    3STRATEGIJA/List/studentai.h
)
set_property(TARGET strategy3_list PROPERTY CXX_STANDARD 20)
