cmake_minimum_required(VERSION 2.8)
set(SOURCE_FILES src/lib/nss_debug.h src/lib/nss_debug.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

#debug
project(nss_debug)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} src/lib/${PROJECT_NAME}_hosts.c)
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 2)
install(TARGETS ${PROJECT_NAME} DESTINATION lib/)

#last
project(nss_last)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} src/lib/${PROJECT_NAME}_hosts.c)
target_compile_definitions(${PROJECT_NAME} PRIVATE LAST)
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 2)
install(TARGETS ${PROJECT_NAME} DESTINATION lib/)
