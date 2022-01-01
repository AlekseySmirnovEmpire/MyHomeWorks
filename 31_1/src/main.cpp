#include "Smart_pointer.h"
#include "Clear.h"
#include "Classes.h"
#include <iostream>

int main()
{
	Smart_ptr ball = makeSharedPtr("ball");
	Smart_ptr bone = makeSharedPtr("bone");

	Dog first("Bobik", 5, ball);
	Dog second("Sharik", 5);
	Dog third = first;
	Dog fourth(second);
	Dog fifth("Keglia", 2, bone);

	bone.dataDelete();	
}
