set(cpps main.cpp test_catch.cpp)
set(hpps catch.hpp RingBuffer.hpp)

#add_library(ringbuffer RingBuffer.hpp)
add_executable(testcatch ${cpps} ${hpps})
#target_link_libraries(testcatch ringbuffer)
set_property(TARGET testcatch PROPERTY CXX_STANDARD 11)
set_property(TARGET testcatch PROPERTY CXX_STANDARD_REQUIRED ON)