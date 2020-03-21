#include "filert_parser.h"
#include "test.h"
#define NTEST 9
#include <stdio.h>

int main()
{
	char 					*test_str[NTEST] = { "0.", "-0.", "-.0"
											, " -\t0", "0.5", "-0.5", "12.3"
											, "-", "-."};
	t_filert_parser_com		expected_ret[NTEST] = {filert_internal,filert_internal,filert_internal,
												 filert_internal, filert_internal,filert_internal,filert_internal,
												 filert_error,filert_error	};
	t_filert_parser_com		ret;
	float					expected_parsed[NTEST] = { 0, 0, 0, 0, 0.5, -0.5, 12.3, 0, 0};
	float					parsed;
	int						cur_test;
	int						ret_passed;
	int						parsed_passed;
	int						ntest;

	ret_passed = 0;
	parsed_passed = 0;
	ntest = 0;
	cur_test = 0;
	while (cur_test < NTEST)
	{
		ntest++;
		printf("== TEST #%d ==\n", ntest);
		printf("Test to parse \"%s\" as a float.\n", test_str[cur_test]);		
		ret = filert_parse_float(&test_str[cur_test], &parsed);
		if (ret == expected_ret[cur_test])
		{
			printf(">> Return value ok\n");
			ret_passed++;
		}
		else
		{
			printf(">> Return value error\n");
			printf("Expected returned value is : \tfilert_%s\n", (expected_ret[cur_test] == filert_internal ? "internal" : "error"));
			printf("Effective returned value is : \tfilert_%s\n", (ret == filert_internal ? "internal" : "error"));
		}
		if (parsed == expected_parsed[cur_test])
		{
			printf(">> Parsed value ok\n");
			parsed_passed++;
		}
		else
		{
			printf(">> Parsed value error\n");
			printf("Expected parsed float is : \t%f\n", expected_parsed[cur_test]);
			printf("Effective parsed float is : \t%f\n", parsed);
		}
		cur_test++;
	}
	printf("\nTest count : %d\n", ntest);
	printf("\nReturned values passed : %d\n", ret_passed);
	printf("\nParsed passed : %d\n", parsed_passed);
}
