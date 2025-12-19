
#include <iostream>
#include <conio.h>
#include <windows.h>

int count = 0;


int main()
{
	while (true)
	{
		count++;
		Sleep(1000);
		std::cout << "счет: " << count << std::endl;
	}
	return 0;
}