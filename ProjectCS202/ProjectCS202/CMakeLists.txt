# CMakeList.txt : CMake project for ProjectCS202, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
file(GLOB srcfile "*.cpp" "*.hpp")
# Add source to this project's executable.
add_executable (ProjectCS202 "ProjectCS202.cpp" "ProjectCS202.h")
target_link_libraries(ProjectCS202 sfml-graphics 
                                      sfml-main 
                                      sfml-window 
                                      sfml-system
                                      sfml-audio)
# TODO: Add tests and install targets if needed.
