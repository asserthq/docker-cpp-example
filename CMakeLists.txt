cmake_minimum_required(VERSION 3.2)
project(example)

# используем C++17
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# используем Boost.Program_options
# дабы не переусложнять, в качестве статической библиотеки
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})

# исполняемый файл нашего приложения
add_executable(example src/main.cpp src/hw.h)
target_link_libraries(example ${Boost_LIBRARIES})

# включаем CTest
enable_testing()

# в качестве фреймворка для тестирования используем GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# исполняемый файл тестов
add_executable(example_test test/test.cpp src/hw.h)
target_include_directories(example_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(example_test ${GTEST_LIBRARIES} pthread)

# добавим этот файл в тестовый набор CTest
add_test(NAME ExampleTest COMMAND example_test)