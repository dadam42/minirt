#include "test.h"
#define NTEST 2
#define TEST_NAME "TESTING t_vec3_add\n"
#define TYPE t_vec3
#define PRINT_TYPE vec3_print
#define TESTED_FUNC t_vec3_add

int main()
{
	TYPE a[] = {{1,2,3}, {-1, -1, -1}};
	TYPE b[] = {{3,2,1}, {1,1,1}};
	TYPE e[] = {{4,4,4},{0,0,0}};
	int cur_test;
	int passed;

	cur_test = 0;
	passed = 0;
	while (cur_test < NTEST)
	{
		printf(TEST_NAME);
		printf("== Test %d ==\n", cur_test);
		printf("Adding ");
		PRINT_TYPE(a[cur_test]);
		printf(" and ");
		PRINT_TYPE(b[cur_test]);
		printf("\n");
		TESTED_FUNC(a[cur_test], b[cur_test], a[cur_test]);
		if (!vec3_equal(a[cur_test], e[cur_test]))
		{
			printf("Test failed : \n");
			printf("Expected : ");
			PRINT_TYPE(e[cur_test]);
			printf("\nGot :");
			PRINT_TYPE(a[cur_test]);
		}
		else
		{
			printf("Test passed.\n");
			passed++;
		}
		cur_test++;
	}
	if (passed == cur_test)
		printf("== TEST PASSED ==\n");
	else
	{
		printf("== TEST ABSTRACT ==\n");
		printf("Passed : \t%d\n", passed);
		printf("Tested : \t%d\n", cur_test);
		printf("===================\n");
	}
	return (0);
}
