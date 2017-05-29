#include <string>
#include <fstream>
#include <vector>
#include <functional>
#include <stdexcept>

using namespace std;


bool is_hash(string text, string res_hash);

class text_converter 
{
public:
	virtual string begin() = 0;
	virtual string title_convert(string) = 0;
	virtual string author_convert(string) = 0;
	virtual string content_convert(string) = 0;
	virtual string hash_convert(string) = 0;
};

class to_XML_converter : public text_converter {
public:
	string begin();
	string title_convert(string);
	string author_convert(string);
	string content_convert(string);
	string hash_convert(string);
};

class text_reader 
{
	string text;
public:
	text_reader(text_converter*, string);
	void save(string);
};