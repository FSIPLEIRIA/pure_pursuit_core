cmake_minimum_required(VERSION 3.25)
project(pure_pursuit_core)

set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)
#print GTest if not found
if(NOT GTest_FOUND)
	message(FATAL_ERROR "GTest not found")
endif()
#add_subdirectory(lib/googletest)

find_package(lart_common REQUIRED)

include_directories(include ${GTEST_INCLUDE_DIRS})

add_library(pure_pursuit_core SHARED src/PathTracker.cpp src/Math.cpp)
target_link_libraries(pure_pursuit_core lart_common)

add_executable(test test/PathTrackingTests.cpp test/PathTrackingTests.cpp test/MathTests.cpp)
target_link_libraries(test pure_pursuit_core ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

install(TARGETS pure_pursuit_core LIBRARY DESTINATION /usr/lib/path_tracker)
install(DIRECTORY include/path_tracker DESTINATION /usr/include)
install(FILES pure_pursuit_coreConfig.cmake DESTINATION /usr/lib/path_tracker)
