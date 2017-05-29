#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "Lists.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{		
	TEST_CASE("simple_list")
	{
		List* list = new List('N');
		char r = list->head_();
		REQUIRE(r == 'N');
	};

	TEST_CASE("simple_list2")
	{
		List* list = new List('N');
		list->cons('a');
		list->pop();
		char r = list->head_();
		REQUIRE(r == 'a');
	};

	TEST_CASE("simple_list_exep")
	{
		List* list = new List('N');
		list->pop();
		REQUIRE_THROWS(list->head_());
	};

	TEST_CASE("simple_list_iterate")
	{
		List* list = new List('a');
		list->cons('b');
		list->cons('c');
		auto l = list->iterate();
		l.next();
		char r = l.get();
		REQUIRE(r == 'b');
	}

	TEST_CASE("simple_list_iterate2")
	{
		List* list = new List('a');
		auto l = list->iterate();
		l.next();
		REQUIRE(l.end()==true);
	}

	TEST_CASE("bad_list_ex")
	{
		List::BadListException ex;
		string res = ex.what();
		REQUIRE(res == "Bad List Exception!");
	}

	/////cyclic////////

	TEST_CASE("cyclic_list")
	{
		CyclicList* list = new CyclicList('N');
		char r = list->head_();
		REQUIRE(r == 'N');
	};

	TEST_CASE("cyclic_list2")
	{
		CyclicList* list = new CyclicList('N');
		list->cons('a');
		list->cons('b');
		list->cons('c');
		list->pop();
		char r = list->head_();
		REQUIRE(r == 'a');
	};

	TEST_CASE("cyclic_list_exep")
	{
		CyclicList* list = new CyclicList('N');
		list->pop();
		REQUIRE_THROWS(list->head_());
	};

	TEST_CASE("cyclic_list_iterate")
	{
		CyclicList* list = new CyclicList('a');
		list->cons('b');
		list->cons('c');
		list->cons('d');
		auto l = list->iterate();
		l.next();
		char r = l.get();
		REQUIRE(r == 'b');
	}

	TEST_CASE("cyclic_list_iterate2")
	{
		CyclicList* list = new CyclicList('a');
		list->pop();
		auto l = list->iterate();
		REQUIRE(l.end() == true);
	}

	TEST_CASE("cyclic_bad_list_ex")
	{
		CyclicList::BadListException ex;
		string res = ex.what();
		REQUIRE(res == "Bad List Exception!");
	}

	/////double_sided////////

	TEST_CASE("double_sided_list")
	{
		DoubleSidedList* list = new DoubleSidedList('N');
		char r = list->head_();
		REQUIRE(r == 'N');
	};

	TEST_CASE("double_sided_list2")
	{
		DoubleSidedList* list = new DoubleSidedList('N');
		list->cons('a');
		list->cons('b');
		list->cons('c');
		list->pop();
		char r = list->head_();
		REQUIRE(r == 'a');
	};

	TEST_CASE("double_sided_list_exep")
	{
		DoubleSidedList* list = new DoubleSidedList('N');
		list->pop();
		REQUIRE_THROWS(list->head_());
	};

	TEST_CASE("double_sided_list_iterate")
	{
		DoubleSidedList* list = new DoubleSidedList('a');
		list->cons('b');
		list->cons('c');
		list->cons('d');
		auto l = list->iterate();
		l.next();
		char r = l.get();
		REQUIRE(r == 'b');
	}

	TEST_CASE("double_sided_list_iterate2")
	{
		DoubleSidedList* list = new DoubleSidedList('a');
		list->pop();
		auto l = list->iterate();
		REQUIRE(l.end() == true);
	}

	TEST_CASE("double_sided_bad_list_ex")
	{
		DoubleSidedList::BadListException ex;
		string res = ex.what();
		REQUIRE(res == "Bad List Exception!");
	}

	/////cyclic_double_sided////////

	TEST_CASE("cyclic_double_sided_list")
	{
		CyclicDoubleSidedList* list = new CyclicDoubleSidedList('N');
		char r = list->head_();
		REQUIRE(r == 'N');
	};

	TEST_CASE("cyclic_double_sided_list2")
	{
		CyclicDoubleSidedList* list = new CyclicDoubleSidedList('N');
		list->cons('a');
		list->cons('b');
		list->cons('c');
		list->pop();
		char r = list->head_();
		REQUIRE(r == 'a');
	};

	TEST_CASE("cyclic_double_sided_list_exep")
	{
		CyclicDoubleSidedList* list = new CyclicDoubleSidedList('N');
		list->pop();
		REQUIRE_THROWS(list->head_());
	};

	TEST_CASE("cyclic_double_sided_list_iterate")
	{
		CyclicDoubleSidedList* list = new CyclicDoubleSidedList('a');
		list->cons('b');
		list->cons('c');
		list->cons('d');
		auto l = list->iterate();
		l.next();
		char r = l.get();
		REQUIRE(r == 'b');
	}

	TEST_CASE("cyclic_double_sided_list_iterate2")
	{
		CyclicDoubleSidedList* list = new CyclicDoubleSidedList('a');
		list->pop();
		auto l = list->iterate();
		REQUIRE(l.end() == true);
	}

	TEST_CASE("cyclic_double_sided_bad_list_ex")
	{
		CyclicDoubleSidedList::BadListException ex;
		string res = ex.what();
		REQUIRE(res == "Bad List Exception!");
	}
}