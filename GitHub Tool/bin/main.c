/*
git add * && git commit -m "Kommentar" && git push origin master
cc GitHub\ Tool/bin/main.c -std=c99 -g -o GitHub\ Tool/src/a.out && ./GitHub\ Tool//src/a.out
cc GitHub\ Tool/bin/main.c -std=c99 -g -o GitHub\ Tool/src/a.out && gdb ./GitHub\ Tool//src/a.out

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char commit[1024];
	char syscall[1024];
	
	printf("\nPlease set your commit for actual update: ");
	scanf("%s", &commit);
	printf("\nConnecting to GitHub and update your work...");
	strcat(syscall, "git add * && git commit -m ");
	strcat(syscall, commit);
	strcat(syscall, " && git push origin master");
	system(syscall);
	printf("\nOk.\n");

	return 0;
}