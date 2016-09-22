#ifdef WIN
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>

int main() {
	int v = GetVersion() & 65535;
	float versao = (v % 256) + (v / 256) / 100.;

	printf("%f", versao);

	//system("pause");
	return (0);
}
