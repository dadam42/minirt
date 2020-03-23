#include "test.h"
#define NTEST 2
#define TYPE t_vec3
#define PRINT_TYPE vec3_print
#define TESTED_FUNC t_vec3_lcomb

int main()
{
	TYPE a[] = {{1,2,3}, {-1, -1, -1}};
	TYPE b[] = {{3,2,1}, {1,1,1}};
	double l[] = {2, 3};
	TYPE e[] = {{5,6,7},{-2,-2,-2}};
	int cur_test;
	int passed;

	cur_test = 0;
	passed = 0;
	while (cur_test < NTEST)
	{
		printf("== Test %d ==\n", cur_test);
		printf("Linear combination of : %.2f, ", l[cur_test]);
		PRINT_TYPE(a[cur_test]);
		printf(" and ");
		PRINT_TYPE(b[cur_test]);
		printf("\n");
		TESTED_FUNC(l[cur_test], a[cur_test], b[cur_test], a[cur_test]);
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
