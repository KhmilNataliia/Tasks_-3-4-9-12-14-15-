#include "stdafx.h"
#include"abstract_factory.h"

string english_sound::get_language()
{
	return "sounds in english";
}

string ukr_sound::get_language()
{
	return "sounds in ukranian";
}

string italian_sound::get_language()
{
	return "sounds in italian";
}

string english_subs::get_language()
{
	return "english subtitles";
}

string ukr_subs::get_language()
{
	return "ukranian subtitles";
}

lang english_sound::get_type()
{
	return ENG;
}

lang ukr_sound::get_type()
{
	return UKR;
}

lang italian_sound::get_type()
{
	return ITL;
}

lang english_subs::get_type()
{
	return ENG;
}

lang ukr_subs::get_type()
{
	return UKR;
}

lang italian_subs::get_type()
{
	return ITL;
}

string italian_subs::get_language()
{
	return "italian subtitles";
}

film::film(string name_)
{
	name = name_;
}

void film::set_sound(sound_language* s)
{
	sound = s;
}

void film::set_subs(subtitles_language* s)
{
	subs = s;
}

string film::get_description()
{
	string res = name + " with " + sound->get_language() + " and " + subs->get_language();
	return res;
}

sound_language* english_factory::init_sounds()
{
	english_sound* ln = new english_sound();
	return ln;
}

subtitles_language* english_factory::init_subs()
{
	english_subs* sb = new english_subs();
	return sb;
}

sound_language* ukr_factory::init_sounds()
{
	ukr_sound* ln = new ukr_sound();
	return ln;
}

subtitles_language* ukr_factory::init_subs()
{
	ukr_subs* sb = new ukr_subs();
	return sb;
}

sound_language* italian_factory::init_sounds()
{
	italian_sound* ln = new italian_sound();
	return ln;
}

subtitles_language* italian_factory::init_subs()
{
	italian_subs* sb = new italian_subs();
	return sb;
}

film* film_store::create(string name, abs_factory* factory)
{
	film* f = new film(name);
	f->set_sound(factory->init_sounds());
	f->set_subs(factory->init_subs());
	return f;
}

lang film::get_sound_lang()
{
	return sound->get_type();
}

lang film::get_sub_lang()
{
	return subs->get_type();
}

void film_store::add_film(string name, abs_factory* factory)
{
	film* f = create(name, factory);
	films.push_back(f);
}

vector<film*> film_store::show_films_by_cryteria(lang ln)
{
	vector<film*> res;
	for (int i = 0; i < films.size(); i++)
	{
		if (films[i]->get_sound_lang() == ln)
			res.push_back(films[i]);
	}
	return res;
}

vector<film*> film_store::get_all_films()
{
	return films;
}