cmake_minimum_required (VERSION 2.6)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project (test1)

add_executable(test1 main.c)
add_executable(test2 semaphore_sample.c)
