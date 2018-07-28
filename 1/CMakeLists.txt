cmake_minimum_required(VERSION 3.6)

file(GLOB sourceFiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc)
foreach(oneSourceFile ${sourceFiles})
    string(REPLACE ".cc" "" execName ${oneSourceFile})
    add_executable(${execName} ${oneSourceFile})
endforeach(oneSourceFile ${sourceFiles})

target_link_libraries(118_PascalsTriangle printer)
target_link_libraries(119_PascalsTriangleII printer)

target_link_libraries(135_Candy printer matlab)
