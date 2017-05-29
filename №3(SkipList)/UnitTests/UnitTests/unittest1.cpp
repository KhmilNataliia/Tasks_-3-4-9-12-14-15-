#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "skiplist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CASE("insert")
	{
		int res[8];
		skiplist list;
			list.insert(1);
			list.insert(7);
			list.insert(3);
			list.insert(7);
			list.insert(4);
			list.insert(2);
			list.insert(5);
			list.insert(6);
			list.help_();
		res[0] = list.get_help();
		res[1] = list.get_help();
		res[2] = list.get_help();
		res[3] = list.get_help();
		res[4] = list.get_help();
		res[5] = list.get_help();
		res[6] = list.get_help();
		res[7] = list.get_help();
		REQUIRE(res[0] == 1);
		REQUIRE(res[1] == 2);
		REQUIRE(res[2] == 3);
		REQUIRE(res[3] == 4);
		REQUIRE(res[4] == 5);
		REQUIRE(res[5] == 6);
		REQUIRE(res[6] == 7);
		REQUIRE(res[7] == 7);
	}

	TEST_CASE("is_in_list")
	{
		skiplist list;
		list.insert(1);
		list.insert(7);
		list.insert(3);
		list.insert(7);
		list.insert(4);
		list.insert(2);
		list.insert(5);
		list.insert(6);
		REQUIRE(list.is_in_list(1) == true);
		REQUIRE(list.is_in_list(2) == true);
		REQUIRE(list.is_in_list(3) == true);
		REQUIRE(list.is_in_list(4) == true);
		REQUIRE(list.is_in_list(5) == true);
		REQUIRE(list.is_in_list(6) == true);
		REQUIRE(list.is_in_list(7) == true);
	}

	TEST_CASE("delete")
	{
		skiplist list;
		list.insert(1);
		list.insert(7);
		list.insert(3);
		list.insert(7);
		list.insert(4);
		list.insert(2);
		list.insert(5);
		list.insert(6);
		list.delitem(1);
		list.delitem(7);
		list.delitem(4);
		REQUIRE(list.is_in_list(1) == false);
		REQUIRE(list.is_in_list(2) == true);
		REQUIRE(list.is_in_list(3) == true);
		REQUIRE(list.is_in_list(4) == false);
		REQUIRE(list.is_in_list(5) == true);
		REQUIRE(list.is_in_list(6) == true);
		REQUIRE(list.is_in_list(7) == true);
	}
}