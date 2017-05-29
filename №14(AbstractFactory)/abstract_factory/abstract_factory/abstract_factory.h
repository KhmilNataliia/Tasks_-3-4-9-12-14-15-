#include <string>
#include <vector>

using namespace std;

enum lang { ENG, UKR, ITL };

class sound_language
{
public:
	virtual string get_language() = 0;
	virtual lang get_type() = 0;
};

class english_sound :public sound_language
{
public:
	string get_language();
	lang get_type();
};

class ukr_sound :public sound_language
{
public:
	string get_language();
	lang get_type();
};

class italian_sound :public sound_language
{
public:
	string get_language();
	lang get_type();
};

class subtitles_language
{
public:
	virtual string get_language() = 0;
	virtual lang get_type() = 0;
};

class english_subs :public subtitles_language
{
public:
	string get_language();
	lang get_type();
};

class ukr_subs :public subtitles_language
{
public:
	string get_language();
	lang get_type();
};

class italian_subs :public subtitles_language
{
public:
	string get_language();
	lang get_type();
};

class film
{
	sound_language* sound;
	subtitles_language* subs;
	string name;
public:
	film(string name_);
	void set_sound(sound_language* s);
	void set_subs(subtitles_language* s);
	string get_description();
	lang get_sub_lang();
	lang get_sound_lang();
};

class abs_factory
{
public:
	virtual sound_language* init_sounds() = 0;
	virtual subtitles_language* init_subs() = 0;
};

class english_factory:public abs_factory
{
public:
	sound_language* init_sounds();
	subtitles_language* init_subs();
};

class ukr_factory :public abs_factory
{
public:
	sound_language* init_sounds();
	subtitles_language* init_subs();
};

class italian_factory :public abs_factory
{
public:
	sound_language* init_sounds();
	subtitles_language* init_subs();
};

class film_store
{
	vector<film*> films;
	film* create(string name, abs_factory* factory);
public:
	void add_film(string name, abs_factory* factory);
	vector<film*> show_films_by_cryteria(lang ln);
	vector<film*> get_all_films();
};