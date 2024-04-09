set(TEST_SRC
	# test_GraphicsContext.cpp
	test_Color.cpp
	test_Piece.cpp
	test_Transition.cpp
	test_Well.cpp
	test_WellTSpin.cpp
	test_Well_TGM.cpp

	# TestUtils.cpp
	main.cpp
)

set(TEST_H
	# TestUtils.h
)


if(USE_SYSTEM_LIBSDL2PP)
    find_package(UnitTest++ REQUIRED)
endif()

add_executable(openblok_test ${TEST_SRC} ${TEST_H})

target_link_libraries(openblok_test UnitTest++)
target_link_libraries(openblok_test module_system)
target_link_libraries(openblok_test module_game)

include(EnableWarnings)
include(RequireCxx11)
enable_warnings(openblok_test)
require_cxx11_or_higher(openblok_test)

add_test(NAME UnitTests COMMAND openblok_test)
enable_testing()
