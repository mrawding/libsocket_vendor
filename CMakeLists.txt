cmake_minimum_required(VERSION 3.5)
project(libsocket_vendor)


find_package(ament_cmake REQUIRED)


execute_process(COMMAND unzip -o ${CMAKE_CURRENT_SOURCE_DIR}/libsocket-master.zip
  -d ${CMAKE_CURRENT_BINARY_DIR})

  include(ExternalProject)
  ExternalProject_Add(libsocket
    PREFIX libsocket
    URL ${CMAKE_CURRENT_SOURCE_DIR}/libsocket-master.zip
    CMAKE_ARGS
      -DBUILD_SHARED_LIBS=ON
      -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
    )

file(GLOB SOCKET_LIBS "${CMAKE_INSTALL_PREFIX}/lib/*.so")

ament_export_include_directories(${CMAKE_INSTALL_PREFIX}/include)
ament_export_libraries(${SOCKET_LIBS})
ament_package()