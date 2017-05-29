#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CASE("add")
	{
		LF_queue *LFQ = new LF_queue();
		LFQ->add(6);
		REQUIRE(LFQ->Tail.load(memory_order_relaxed)->dat == 6);
	};

	TEST_CASE("dummy")
	{
		LF_queue *LFQ = new LF_queue();
		LFQ->add(6);
		REQUIRE(LFQ->Head.load(memory_order_relaxed)->dat == 0);
	};

	TEST_CASE("del")
	{
		LF_queue *LFQ = new LF_queue();
		LFQ->add(6);
		REQUIRE(LFQ->del()== 6);
	};

	TEST_CASE("del3")
	{
		LF_queue *LFQ = new LF_queue();
		REQUIRE(LFQ->del() == 1);
	};

	TEST_CASE("del2")
	{
		LF_queue *LFQ = new LF_queue();
		LFQ->add(6);
		LFQ->add(7);
		LFQ->del();
		REQUIRE(LFQ->Head.load(memory_order_relaxed)->next.load(memory_order_relaxed)->dat == 7);
	};
}