# SDL2
if(USE_SYSTEM_LIBSDL2PP)
    find_package(SDL2pp REQUIRED)
else()
    set(SDL2PP_CXXSTD 11)
    set(SDL2PP_WITH_IMAGE ON)
    set(SDL2PP_WITH_MIXER ON)
    set(SDL2PP_WITH_TTF ON)
    add_subdirectory(libSDL2pp)
endif()

# tinydir
add_subdirectory(tinydir)

# UnitTest++
if(BUILD_TESTS)
    if(USE_SYSTEM_UNITTESTCPP)
        find_package(UnitTest++ REQUIRED)
    else()
        add_subdirectory(unittest-cpp)
    endif()
endif()
