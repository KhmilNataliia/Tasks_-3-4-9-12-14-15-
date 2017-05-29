#include"builder.h"

using namespace std;

int main()
{
	to_XML_converter* cvt = new to_XML_converter();
	text_reader* read = new text_reader(cvt, "Text.txt");
	read->save("XMLFile.xml");
	return 0;
}