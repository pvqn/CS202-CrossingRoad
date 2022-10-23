# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

include(FetchContent)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY    https://github.com/SFML/SFML.git
    GIT_TAG 2f11710abc5aa478503a7ff3f9e654bd2078ebab
)

set(BUILD_SHARED_LIBS OFF)

set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_DOC OFF)

set(SFML_BUILD_NETWORK OFF)

set(SFML_BUILD_AUDIO ON)
set(SFML_BUILD_GRAPHICS ON)
set(SFML_BUILD_WINDOW ON)

FetchContent_MakeAvailable(sfml)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


project ("ProjectCS202")

# Include sub-projects.
add_subdirectory ("ProjectCS202")


# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
