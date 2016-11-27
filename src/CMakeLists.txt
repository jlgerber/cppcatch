set(cpps main.cpp bdd_catch.cpp)
set(hpps catch.hpp RingBuffer.hpp)

# since RingBuffer is a template, we don't have to add it as a library
#add_library(ringbuffer RingBuffer.hpp)
add_executable(testcatch ${cpps} ${hpps})

# nore do we have to link against it.
#target_link_libraries(testcatch ringbuffer)

# I am adding c++11
set_property(TARGET testcatch PROPERTY CXX_STANDARD 11)
set_property(TARGET testcatch PROPERTY CXX_STANDARD_REQUIRED ON)