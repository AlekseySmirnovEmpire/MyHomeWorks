#include "support.h"
#include <iostream>
#include <cpr/cpr.h>

int main()
{
	cpr::Response req = cpr::Get(cpr::Url("https://httpbin.org/html"), cpr::Header({{"Accept", "text/html"}}));

	unsigned int hBegin = req.text.find("<h1>") + 4;
	unsigned int hEnd = req.text.find("</h1>");

	std::cout << req.text.substr(hBegin, hEnd - hBegin) << std::endl;
}
