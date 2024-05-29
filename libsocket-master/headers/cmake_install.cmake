# Install script for directory: /home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/fuck")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libsocket" TYPE FILE FILES
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./unixdgram.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./exception.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./inetclientdgram.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./libinetsocket.h"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./unixserverstream.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./dgramclient.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./streamclient.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./inetserverstream.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./unixclientdgram.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./socket.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./inetbase.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./inetserverdgram.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./unixclientstream.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./libunixsocket.h"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./select.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./inetclientstream.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./unixbase.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./unixserverdgram.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./inetdgram.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./dgramoverstream.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./framing.hpp"
    "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers/./epoll.hpp"
    )
endif()

