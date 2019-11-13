set(OPENBLOK_VERSION_MAJOR "0")
set(OPENBLOK_VERSION_MINOR "8")
set(OPENBLOK_VERSION_PATCH "1")
set(OPENBLOK_VERSION_EXTRA "")

find_package(Git)
if(GIT_FOUND AND EXISTS "${CMAKE_SOURCE_DIR}/.git/")
    execute_process(COMMAND
        "${GIT_EXECUTABLE}" describe --always --dirty
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE GIT_HASH
        RESULT_VARIABLE GIT_COMMAND_RESULT
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET)
    if(GIT_COMMAND_RESULT EQUAL 0)
        set(OPENBLOK_VERSION_EXTRA "+${GIT_HASH}")
    endif()
endif()
