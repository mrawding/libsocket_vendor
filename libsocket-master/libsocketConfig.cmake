set(libsocket_INCLUDE_DIRS "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master/headers")

set(libsocket_BINARY_DIR "/home/mike/Desktop/WARDEN/radar/src/libsocket_vendor/libsocket-master")

include(${libsocket_BINARY_DIR}/libsocketTargets.cmake)

set(libsocket_LIBRARIES socket++)
