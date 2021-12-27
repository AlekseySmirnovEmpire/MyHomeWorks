#include "support.h"
#include "request.h"
#include <iostream>
#include <string>
#include <map>
#include <cpr/cpr.h>

void doGetRequest(const std::map<std::string, std::string>& map) {
	
	std::string arguments = "?";

	for (auto it = map.begin(); it != map.end(); ++it) {

		arguments += it->first + '=' + it->second + '&';
	}

	arguments.resize(arguments.length() - 1);

	std::string urlAdress = "https://httpbin.org/get" + arguments;

	cpr::Response req = cpr::Get(cpr::Url(urlAdress));

	std::cout << req.text << std::endl;
}

void doPostRequest(const std::map<std::string, std::string>& map) {

	std::string arguments = "";

	for (auto it = map.begin(); it != map.end(); ++it) {

		arguments += it->first + ' ' + it->second + ' ';	
	}

	arguments.resize(arguments.length() - 1);

	cpr::Response req = cpr::Post(cpr::Url("https://httpbin.org/post"),
		cpr::Payload{ {"Arguments", arguments.c_str()} });

	std::cout << req.text << std::endl;
}

void getParametrs(const std::string& userInput, std::string& name, std::string& something) {

	name = userInput.substr(0, userInput.find(' '));

	something = userInput.substr(userInput.find(' ') + 1, userInput.length() - userInput.find(' '));
}

void doRequests() {

	std::string userInput;

	bool isEnd = false;

	std::map<std::string, std::string> reqs;

	do {

		std::cout << "Input your arguments (name value): ";
		std::getline(std::cin, userInput);

		clear();

		if (userInput.length() > 0) {

			std::string name, value;

			getParametrs(userInput, name, value);

			if (name == "post" || name == "get") {

				name == "post" ? doPostRequest(reqs) : doGetRequest(reqs);
				isEnd = true;
			}				
			else {

				reqs.emplace(name, value);
				clear();
			}
		}
		else {

			std::cout << "Input something!" << std::endl;
		}

	} while (!isEnd);
}