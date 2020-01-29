cmake_minimum_required(VERSION 3.5) 

project(blackjack LANGUAGES CXX VERSION 1.0.0)


set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

set(CMAKE_CXX_STANDARD 17)

set(WORKSPACE_DIR "/home/musabbir/workspace/blackjack")
set(SRC_FILE ${WORKSPACE_DIR}/main.cpp)

get_filename_component(SOURCE_NAME ${SRC_FILE} NAME_WE)
set(EXE_NAME "${SOURCE_NAME}.bin")

add_executable(${EXE_NAME} 
               ${SRC_FILE}
	       ${WORKSPACE_DIR}/Card.cpp
       	       ${WORKSPACE_DIR}/Player.cpp
	       ${WORKSPACE_DIR}/CardDeck.cpp
      	       ${WORKSPACE_DIR}/Game.cpp)
