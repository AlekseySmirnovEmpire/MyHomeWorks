#pragma once

void clear() {

#ifdef _WIN32
	system("slc");

#elif (_LINUX_)
	system("clear");

#endif 
}