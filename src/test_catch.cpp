//
// Created by Jonathan Gerber on 11/27/16.
//
#include "ringbuffer.hpp"
#include "catch.hpp"

TEST_CASE("RingBuffer") {

    RingBuffer<int> rb(4);
    REQUIRE(rb.size() == 0);

    rb.push_back(1);
    REQUIRE(rb.size() == 1);

    int val = rb.pop_front();
    REQUIRE(rb.size() == 0);
    REQUIRE(val == 1);
}