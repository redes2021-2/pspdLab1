/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "sortv.h"
#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAXN 2000

void sortv_prog_1(char *host)
{
	CLIENT *clnt;
	funcreturn *result_1;
	numbers sort_1_arg;

#ifndef DEBUG
	clnt = clnt_create(host, SORTV_PROG, SORTV_VERS, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
#endif /* DEBUG */

	srand(time(NULL));
	// long sort1_arg.v[MAXN];
	for (int j = 0; j < 250; j++)
	{
		for (size_t i = 0; i < MAXN; i++)
		{
			long aux = (j * 2000 + i - (rand() % 500001) / 2);
			sort_1_arg.a[i] = aux * aux;
			sort_1_arg.a[i] = sqrt(sort_1_arg.a[i]);
		}

		result_1 = sort_1(&sort_1_arg, clnt);
		if (result_1 == (void *)NULL)
		{
			clnt_perror(clnt, "call failed");
		}
	}
	printf("Min:%d ---- Max:%d\n", result_1->b, result_1->a);
#ifndef DEBUG
	clnt_destroy(clnt);
#endif /* DEBUG */
}

int main(int argc, char *argv[])
{
	char *host;

	if (argc < 2)
	{
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];
	sortv_prog_1(host);
	exit(0);
}
