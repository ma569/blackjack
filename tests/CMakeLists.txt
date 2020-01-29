cmake_minimum_required(VERSION 3.5) 

project(blackjack LANGUAGES CXX VERSION 1.0.0)


set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

set(CMAKE_CXX_STANDARD 17)

set(WORKSPACE_DIR "/home/musabbir/workspace/blackjack")
set(TEST_DIR "/home/musabbir/workspace/blackjack/tests")
set(SRC_FILE ${TEST_DIR}/Player_test.cpp)

get_filename_component(SOURCE_NAME ${SRC_FILE} NAME_WE)
set(EXE_NAME "${SOURCE_NAME}.bin")


# include(GoogleTest)
# enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${EXE_NAME} 
               ${SRC_FILE}
       	       ${WORKSPACE_DIR}/Card.cpp
       	       ${WORKSPACE_DIR}/Player.cpp)


add_executable(Game_test.bin 
               Game_test.cpp
       	       ${WORKSPACE_DIR}/Card.cpp
       	       ${WORKSPACE_DIR}/CardDeck.cpp	       
       	       ${WORKSPACE_DIR}/Player.cpp
       	       ${WORKSPACE_DIR}/Game.cpp)

target_link_libraries(${EXE_NAME} ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(Game_test.bin ${GTEST_BOTH_LIBRARIES} pthread)
