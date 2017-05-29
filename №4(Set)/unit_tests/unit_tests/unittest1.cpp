#include "stdafx.h"
#include "CppUnitTest.h"

#include"catch.hpp"
#include"wide_set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{		
	TEST_CASE("add_char_list")
	{
		Set<char>* s = new Set<char>(new set_list_adapter<char>());
		s->add('n');
		REQUIRE(s->in_set('n') == true);
	};
	TEST_CASE("add_int_list")
	{
		Set<int>* s = new Set<int>(new set_list_adapter<int>());
		s->add(13);
		REQUIRE(s->in_set(13) == true);
	};
	TEST_CASE("add_char_list_er")
	{
		Set<char>* s = new Set<char>(new set_list_adapter<char>());
		s->add('n');
		REQUIRE(s->add('n') == false);
	};
	TEST_CASE("add_int_list_er")
	{
		Set<int>* s = new Set<int>(new set_list_adapter<int>());
		s->add(13);
		REQUIRE(s->add(13) == false);
	};
	TEST_CASE("del_char_list")
	{
		Set<char>* s = new Set<char>(new set_list_adapter<char>());
		s->add('n');
		s->del('n');
		REQUIRE(s->in_set('n') == false);
	}
	TEST_CASE("del_int_list")
	{
		Set<int>* s = new Set<int>(new set_list_adapter<int>());
		s->add(13);
		s->del(13);
		REQUIRE(s->in_set(13) == false);
	}
	TEST_CASE("del_char_list_er")
	{
		Set<char>* s = new Set<char>(new set_list_adapter<char>());
		s->add('n');
		REQUIRE(s->del('f') == false);
	}
	TEST_CASE("del_int_list_er")
	{
		Set<int>* s = new Set<int>(new set_list_adapter<int>());
		s->add(13);
		REQUIRE(s->del(11) == false);
	}
	TEST_CASE("size")
	{
		Set<int>* s = new Set<int>(new set_list_adapter<int>());
		s->add(13);
		s->add(3);
		s->add(7);
		REQUIRE(s->size() == 3);
	}

	/////////////////

	TEST_CASE("add_char_vec")
	{
		Set<char>* s = new Set<char>(new set_vector_adapter<char>());
		s->add('n');
		REQUIRE(s->in_set('n') == true);
	};
	TEST_CASE("add_int_vector")
	{
		Set<int>* s = new Set<int>(new set_vector_adapter<int>());
		s->add(13);
		REQUIRE(s->in_set(13) == true);
	};
	TEST_CASE("add_char_vector_er")
	{
		Set<char>* s = new Set<char>(new set_vector_adapter<char>());
		s->add('n');
		REQUIRE(s->add('n') == false);
	};
	TEST_CASE("add_int_vector_er")
	{
		Set<int>* s = new Set<int>(new set_vector_adapter<int>());
		s->add(13);
		REQUIRE(s->add(13) == false);
	};
	TEST_CASE("del_char_vector")
	{
		Set<char>* s = new Set<char>(new set_vector_adapter<char>());
		s->add('n');
		s->del('n');
		REQUIRE(s->in_set('n') == false);
	}
	TEST_CASE("del_int_vector")
	{
		Set<int>* s = new Set<int>(new set_vector_adapter<int>());
		s->add(13);
		s->del(13);
		REQUIRE(s->in_set(13) == false);
	}
	TEST_CASE("del_char_vector_er")
	{
		Set<char>* s = new Set<char>(new set_vector_adapter<char>());
		s->add('n');
		REQUIRE(s->del('f') == false);
	}
	TEST_CASE("del_int_vector_er")
	{
		Set<int>* s = new Set<int>(new set_vector_adapter<int>());
		s->add(13);
		REQUIRE(s->del(11) == false);
	}
	TEST_CASE("size_vector")
	{
		Set<int>* s = new Set<int>(new set_vector_adapter<int>());
		s->add(13);
		s->add(3);
		s->add(7);
		REQUIRE(s->size() == 3);
	}
}