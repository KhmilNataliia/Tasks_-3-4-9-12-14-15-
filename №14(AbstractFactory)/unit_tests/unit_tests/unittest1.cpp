#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "abstract_factory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{		
	TEST_CASE("eng_film")
	{
		english_factory* f=new english_factory();
		film_store* st = new film_store();
		st->add_film("some", f);
		vector<film*> res = st->show_films_by_cryteria(ENG);
		string ac = res[0]->get_description();
		REQUIRE(ac == "some with sounds in english and english subtitles");
	};


	TEST_CASE("ukr_film")
	{
		ukr_factory* f = new ukr_factory();
		film_store* st = new film_store();
		st->add_film("some", f);
		vector<film*> res = st->show_films_by_cryteria(UKR);
		string ac = res[0]->get_description();
		REQUIRE(ac == "some with sounds in ukranian and ukranian subtitles");
	};

	TEST_CASE("itl_film")
	{
		italian_factory* f = new italian_factory();
		film_store* st = new film_store();
		st->add_film("some", f);
		vector<film*> res = st->show_films_by_cryteria(ITL);
		string ac = res[0]->get_description();
		REQUIRE(ac == "some with sounds in italian and italian subtitles");
	};

	TEST_CASE("all_film")
	{
		italian_factory* fi = new italian_factory();
		ukr_factory* fu = new ukr_factory();
		english_factory* fe = new english_factory();
		film_store* st = new film_store();
		st->add_film("some", fe);
		st->add_film("some", fu);
		st->add_film("some", fi);
		vector<film*> res = st->get_all_films();
		string ac = res[0]->get_description();
		REQUIRE(ac == "some with sounds in english and english subtitles");
		string ac1 = res[1]->get_description();
		REQUIRE(ac1 == "some with sounds in ukranian and ukranian subtitles");
		string ac2 = res[2]->get_description();
		REQUIRE(ac2 == "some with sounds in italian and italian subtitles");
	};

	TEST_CASE("eng_subs")
	{
		english_subs* s = new english_subs();
		lang res = s->get_type();
		REQUIRE(res==ENG);
	};

	TEST_CASE("ukr_subs")
	{
		ukr_subs* s = new ukr_subs();
		lang res = s->get_type();
		REQUIRE(res == UKR);
	};

	TEST_CASE("itl_subs")
	{
		italian_subs* s = new italian_subs();
		lang res = s->get_type();
		REQUIRE(res == ITL);
	};

	TEST_CASE("itl_film_subs")
	{
		italian_factory* f = new italian_factory();
		film_store* st = new film_store();
		st->add_film("some", f);
		vector<film*> res = st->show_films_by_cryteria(ITL);
		lang ac = res[0]->get_sub_lang();
		REQUIRE(ac == ITL);
	};

}