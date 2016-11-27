
set(cpps main.cpp bdd_catch.cpp)

set(hpps ../include/catch.hpp
        ../include/RingBuffer.hpp)

# since RingBuffer is a template, we don't have to add it as a library
#add_library(ringbuffer RingBuffer.hpp)
add_executable(testcatch ${cpps} ${hpps})

# nore do we have to link against it.
#target_link_libraries(testcatch ringbuffer)

# I am adding c++11
set_property(TARGET testcatch PROPERTY CXX_STANDARD 11)
set_property(TARGET testcatch PROPERTY CXX_STANDARD_REQUIRED ON)

#
# Because I want to install testcatch into a bin directory, I do the following
install(TARGETS testcatch
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)


add_custom_target(install_testcatch
        $(MAKE) install
        DEPENDS testcatch
        COMMENT "Installing ${PROJECT_NAME}")
