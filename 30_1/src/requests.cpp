#include "clear.h"
#include "header.h"
#include "wait.h"
#include <iostream>
#include <cpr/cpr.h>

void getRequest() {

	cpr::Response req = cpr::Get(cpr::Url("https://httpbin.org/get"));

	std::cout << req.text << std::endl;
}

void postRequest() {

	cpr::Response req = cpr::Post(cpr::Url("https://httpbin.org/post"));

	std::cout << req.text << std::endl;
}

void putRequest() {

	cpr::Response req = cpr::Put(cpr::Url("https://httpbin.org/put"));

	std::cout << req.text << std::endl;
}

void deleteRequest() {

	cpr::Response req = cpr::Delete(cpr::Url("https://httpbin.org/delete"));

	std::cout << req.text << std::endl;
}

void patchRequest() {

	cpr::Response req = cpr::Patch(cpr::Url("https://httpbin.org/patch"));

	std::cout << req.text << std::endl;
}



void doRequest(const int& reqNumber) {

	switch (reqNumber)
	{
	case GET:
		getRequest();
		break;

	case POST:
		postRequest();
		break;

	case PUT:
		break;

	case eDELETE:
		break;

	case PATCH:
		break;

	case EXIT:
		break;

	default:
		std::cout << "Wrong input! Try again!";
		break;
	}

	wait();

	clear();
}