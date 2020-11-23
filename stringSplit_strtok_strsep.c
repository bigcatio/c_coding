#include <stdio.h>
#include <string.h>

#define STRING_FOR_TESTING "{0x1,0x2}, {{{{{{{{{{{{0x3,0x4}, {0x5,0x6},{0x7,0x8},{0x9,0x10},{0x11,0x12},{0x13,0x14},"
int main()
{
	char input[] = STRING_FOR_TESTING;
	char input_tok[] = STRING_FOR_TESTING;
	char input_sep[] = STRING_FOR_TESTING;
	char *token;
	char *pCur;

	printf("origin input: %s, size:%lu\n", input, sizeof(input));

	printf("************ strtok start ************\n");
	printf("input_tok=%p\n", input_tok);

	token = strtok(input_tok, "{");
	while (token != NULL)
	{
		printf("strtok:%s -- token=%p\n", token, token);
		token = strtok(NULL, "{");
	}

	printf("now input: %85s, size:%lu\n", input_tok, sizeof(input_tok));

	printf("************ strtok  end  ************\n");

	printf("************ strsep start ************\n");

	pCur = input_sep;
	printf("input_sep=%p\n", input_sep);

	token = strsep(&pCur, "{");
	while (token != NULL)
	{
		printf("strsep:%s-- token=%p  pCur=%p\n", token, token, pCur);
		token = strsep(&pCur, "{");
	}

	printf("now input: %85s, size:%lu\n", input_sep, sizeof(input_sep));

	printf("************ strsep  end  ************\n");

	return 0;
}
