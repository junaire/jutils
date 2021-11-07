configure_file(CMakeLists.txt.in abseil/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/abseil )
if(result)
  message(FATAL_ERROR "CMake step for abseil failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/abseil )
if(result)
  message(FATAL_ERROR "Build step for abseil failed: ${result}")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/abseil-src
                 ${CMAKE_CURRENT_BINARY_DIR}/abseil-build)

