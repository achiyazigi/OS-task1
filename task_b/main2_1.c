#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 1;
	int fork_ans;
	if ((fork_ans = fork()) == -1)
	{
		printf("fork failed\n");
	}
	else if (fork_ans == 0)
	{
		// printf("im the child\n");
		int fork_ans2;
		if ((fork_ans2 = fork()) == -1)
		{
			printf("fork failed\n");
		}
		else if (fork_ans2 == 0)
		{
			// printf("im the grandson\n");
		}

	}
	else if (fork_ans > 0)
	{
		// printf("im the father, my child id is: %d\n", fork_ans);

	}
	sleep(10);
	return 0;
}
