#include "filert_parser.h"
#include "test.h"
#include <stdio.h>

int main()
{
	char 					*test_str[16] = {"0", "00", "001", "-0"
											, "-01", "1234", " \t0", "-\t0"
											, "-\t123", "2147483647", "-2147483648", "002147483647"
											, "\v-\t2147483648", "-.", ".", ""};
	t_filert_parser_com		expected_ret[16] = { filert_internal, filert_internal,filert_internal,filert_internal,
												 filert_internal, filert_internal,filert_internal,filert_internal,
												  filert_internal, filert_internal,filert_internal,filert_internal,
												   filert_internal, filert_error,filert_error,filert_error	};
	t_filert_parser_com		ret;
	int						expected_parsed[16] = { 1,0,1,0,-1,1234,0,0,-123,2147483647,-2147483648,2147483647,-2147483648,0,0,0
													};
	int						parsed;
	int						cur_test;
	int						ret_passed;
	int						parsed_passed;
	int						ntest;

	ret_passed = 0;
	parsed_passed = 0;
	ntest = 0;
	cur_test = 0;
	while (cur_test < 16)
	{
		ntest++;
		printf("== TEST #%d ==\n", ntest);
		printf("Test to parse \"%s\" as an int.\n", test_str[cur_test]);		
		ret = filert_parse_int(&test_str[cur_test], &parsed);
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
			printf("Expected parsed int is : \t%d\n", expected_parsed[cur_test]);
			printf("Effective parsed int is : \t%d\n", parsed);
		}
		cur_test++;
	}
	printf("\nTest count : %d\n", ntest);
	printf("\nReturned values passed : %d\n", ret_passed);
	printf("\nParsed passed : %d\n", parsed_passed);
}
