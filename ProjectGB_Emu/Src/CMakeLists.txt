

file (GLOB sources CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/Src/*.c")

file (GLOB headers CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/Includes/*.h")

add_library(Emulator STATIC ${sources} ${headers})

target_include_directories(Emulator PUBLIC ${PROJECT_SOURCE_DIR}/include )


if (WIN32)
  target_include_directories(Emulator PUBLIC "${PROJECT_SOURCE_DIR}/../windows_deps/sdl2/include" )
  target_include_directories(Emulator PUBLIC ${PROJECT_SOURCE_DIR}/../windows_deps/sdl2_ttf/include )
else()
  target_include_directories(Emulator PUBLIC ${SDL2_INCLUDE_DIR})
  target_link_libraries(Emulator PUBLIC ${SDL2_LIBRARY}) 
  target_link_libraries(Emulator PUBLIC ${SDL2_TTF_LIBRARY}) 
endif()

include_directories("/usr/local/include")
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(Emulator ${SDL2_LIBRARIES})
target_link_libraries(Emulator ${SDL2_TTF_LIBRARIES})

