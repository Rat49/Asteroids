cmake_minimum_required(VERSION 3.6)

project(Asteroids)

set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

set(CMAKE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/Source)
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/Bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(ENGINE_DIR ${CMAKE_SOURCE_DIR}/Engine)
set(GAME_DIR ${CMAKE_SOURCE_DIR}/Game)
set(SFML_DIR ${PROJECT_SOURCE_DIR}/../SFML)
set(SFML_INCLUDE_DIR ${SFML_DIR}/include)
set(SFML_LIBRARY_DIR ${SFML_DIR}/lib)

set(ENGINE_LIB Engine)
set(GAME_EXEC Game)

file(GLOB ENGINE_SOURCES "${ENGINE_DIR}/*.cpp")
file(GLOB ENGINE_HEADERS "${ENGINE_DIR}/*.h")
file(GLOB GAME_SOURCES "${GAME_DIR}/*.cpp")
file(GLOB GAME_HEADERS "${GAME_DIR}/*.h")

add_library(${ENGINE_LIB} SHARED ${ENGINE_SOURCES} ${ENGINE_HEADERS})
add_executable(${GAME_EXEC} ${GAME_SOURCES} ${GAME_HEADERS})

target_include_directories(${ENGINE_LIB}
        PRIVATE ${ENGINE_DIR}
        PRIVATE ${SFML_INCLUDE_DIR})

target_include_directories(${GAME_EXEC}
        PRIVATE ${GAME_DIR}
        PRIVATE ${ENGINE_DIR}
        PRIVATE ${SFML_INCLUDE_DIR})

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    set_target_properties(${ENGINE_LIB} PROPERTIES SUFFIX "-d.so")
    set_target_properties(${GAME_EXEC} PROPERTIES SUFFIX "-d")
    target_compile_definitions(${ENGINE_LIB}
            PRIVATE _DEBUG
            PRIVATE _LINUX
            PRIVATE ENGINE_LIB)
    target_compile_definitions(${GAME_EXEC}
            PRIVATE _DEBUG
            PRIVATE _LINUX
            PRIVATE SFML_STATIC)
    set(SFML_WINDOW_LIB ${SFML_LIBRARY_DIR}/libsfml-window-d.so.2.5)
    set(SFML_SYSTEM_LIB ${SFML_LIBRARY_DIR}/libsfml-system-d.so.2.5)
    set(SFML_GRAPHICS_LIB ${SFML_LIBRARY_DIR}/libsfml-graphics-d.so.2.5)
    set(SFML_AUDIO_LIB ${SFML_LIBRARY_DIR}/libsfml-audio-d.so.2.5)
    set(SFML_NETWORK_LIB ${SFML_LIBRARY_DIR}/libsfml-network-d.so.2.5)
else()
    set_target_properties(${ENGINE_LIB} PROPERTIES SUFFIX ".so")
    target_compile_definitions(${ENGINE_LIB}
            PRIVATE NDEBUG
            PRIVATE _LINUX
            PRIVATE ENGINE_LIB)
    target_compile_definitions(${GAME_EXEC}
            PRIVATE NDEBUG
            PRIVATE _LINUX
            PRIVATE SFML_STATIC)
    set(SFML_WINDOW_LIB ${SFML_LIBRARY_DIR}/libsfml-window.so.2.5)
    set(SFML_SYSTEM_LIB ${SFML_LIBRARY_DIR}/libsfml-system.so.2.5)
    set(SFML_GRAPHICS_LIB ${SFML_LIBRARY_DIR}/libsfml-graphics.so.2.5)
    set(SFML_AUDIO_LIB ${SFML_LIBRARY_DIR}/libsfml-audio.so.2.5)
    set(SFML_NETWORK_LIB ${SFML_LIBRARY_DIR}/libsfml-network.so.2.5)
endif()

target_link_libraries(${GAME_EXEC}
        PRIVATE ${ENGINE_LIB}
        PRIVATE ${SFML_WINDOW_LIB}
        PRIVATE ${SFML_SYSTEM_LIB}
        PRIVATE ${SFML_GRAPHICS_LIB}
        PRIVATE ${SFML_AUDIO_LIB}
        PRIVATE ${SFML_NETWORK_LIB})

add_custom_command(TARGET ${GAME_EXEC} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_WINDOW_LIB} ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_SYSTEM_LIB} ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_GRAPHICS_LIB} ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_NETWORK_LIB} ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_AUDIO_LIB} ${CMAKE_BINARY_DIR})