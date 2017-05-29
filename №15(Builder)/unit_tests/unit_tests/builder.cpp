#include "stdafx.h"
#include"builder.h"

string to_XML_converter::begin()
{
	return "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
}

string to_XML_converter::title_convert(string title)
{
	string res = "<title>" + title + "</title>";
	return res;
}

string to_XML_converter::author_convert(string autor)
{
	string res = "<author>" + autor + "</author>";
	return res;
}

string to_XML_converter::content_convert(string cont)
{
	string res = "<content>" + cont + "</content>";
	return res;
}

string to_XML_converter::hash_convert(string h)
{
	string res = "<hash>" + h +"</hash>";
	return res;
}


bool is_hash(string text, string res_hash)
{
	size_t res = hash<string>{}(text);
	string r_h = to_string(res);
	if (res_hash == r_h)
		return true;
	else return false;
}

text_reader::text_reader(text_converter* cvt, string file)
{
	fstream f;
	f.open(file);
	string title, author, text_, hash_;
	getline(f, title);
	getline(f, author);
	string temp;
	vector<string> t;
	while (getline(f, temp))
	{
		t.push_back(temp);
	}
	hash_ = t[t.size() - 1];
	for (int i = 0; i < t.size() - 1; i++)
		if (i != t.size() - 2)	text_ += t[i] + "\n";
		else text_ += t[i];
	if (is_hash(text_, hash_))
	{
		text = cvt->begin()+"\n";
		text += cvt->title_convert(title)+"\n";
		text += cvt->author_convert(author)+"\n";
		text += cvt->content_convert(text_)+"\n";
		text += cvt->hash_convert(hash_);
	}
	else throw runtime_error("wrong hash code!!!");
}

void text_reader::save(string file)
{
	fstream f;
	f.open(file,ios_base::out);
	f.clear();
	f << text;
	f.close();
}