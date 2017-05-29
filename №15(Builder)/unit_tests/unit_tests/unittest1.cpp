#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "builder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{		
	TEST_CASE("title")
	{
		to_XML_converter* cvt = new to_XML_converter();
		string res = cvt->title_convert("article");
		REQUIRE(res == "<title>article</title>");
	};
	TEST_CASE("author")
	{
		to_XML_converter* cvt = new to_XML_converter();
		string res = cvt->author_convert("article");
		REQUIRE(res == "<author>article</author>");
	};
	TEST_CASE("content")
	{
		to_XML_converter* cvt = new to_XML_converter();
		string res = cvt->content_convert("article");
		REQUIRE(res == "<content>article</content>");
	};
	TEST_CASE("hash")
	{
		to_XML_converter* cvt = new to_XML_converter();
		string res = cvt->hash_convert("1234556");
		REQUIRE(res == "<hash>1234556</hash>");
	};
	TEST_CASE("beg")
	{
		to_XML_converter* cvt = new to_XML_converter();
		string res = cvt->begin();
		REQUIRE(res == "<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	};
	TEST_CASE("is_hash")
	{
		bool res = is_hash("Last year we visited their concert.", "4022608372");
		REQUIRE(res == true);
	}
	TEST_CASE("!is_hash")
	{
		bool res = is_hash("Last year we visited their concert.", "402260836345");
		REQUIRE(res == false);
	}
}