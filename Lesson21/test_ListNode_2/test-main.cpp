#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include "List.h"

TEST_CASE("Check PushBack", "[PushBack]") {
	List object;
	object.PushBack(10);
	REQUIRE(object.Size() == 1);
	object.PushBack(20);
	REQUIRE(object.Size() == 2);

}
TEST_CASE("Check PushFront", "[PushFront]") {
	List object;
	object.PushFront(10);
	REQUIRE(object.Size() == 1);
	object.PushFront(20);
	REQUIRE(object.Size() == 2);

}
TEST_CASE("Check PopBack", "[PopBack]") {
	List object;
	object.PushFront(10);
	object.PopBack();
	REQUIRE(object.Size() == 0);
	object.PushFront(10);
	object.PushFront(20);
	object.PopBack();
	REQUIRE(object.Size() == 1);
	object.Clear();
	SECTION("Check empty") {
		REQUIRE_THROWS_AS(object.PopBack(), std::runtime_error);
	}

}
TEST_CASE("Check PopFront", "[PopFront]") {
	List object;
	SECTION("Check empty") {
		REQUIRE_THROWS_AS(object.PopFront(), std::runtime_error);
	}
	object.PushFront(10);
	object.PopFront();
	REQUIRE(object.Size() == 0);
	object.PushFront(10);
	object.PushFront(20);
	object.PopFront();
	REQUIRE(object.Size() == 1);
	
}