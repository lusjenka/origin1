#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include "List.h"

TEST_CASE("Check Empty", "[empty]") {
	List object;
	object.PushFront(10);
	REQUIRE(object.Empty() == false);
	object.PopFront();
	REQUIRE(object.Empty() == true);

}
TEST_CASE("Check Size", "[size]") {
	List object;
	object.PushFront(10);
	REQUIRE(object.Size() == 1);
	object.PopFront();
	REQUIRE(object.Size() == 0);
	object.PushFront(10);
	object.PushFront(20);
	object.PushBack(30);
	REQUIRE(object.Size() == 3);
}
TEST_CASE("Check Clear", "[clear]") {
	List object;
	object.PushFront(10);
	object.Clear();
	REQUIRE(object.Size() == 0);
		
}
