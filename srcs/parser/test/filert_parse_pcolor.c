#include "filert_parser.h"
#include "test.h"
#define NTEST 8
#define T_TEST t_filert_pcolor
#define PRINTF	t_filert_pcolor_printf
#define EQUAL	t_filert_pcolor_equal
#include <stdio.h>

int main()
{
	char 					*test_str[NTEST] = { "\t0.3 0,0,0", "0.9 0,1,2", "0.7 42,42,42",
												"0.5 \v42\t, \v42 ,\t42", "0.01 255,255,255", "-1 2, 56, 21"
												, "1.2 0, 253, 0", "0.1 12, 12, -45"};
	t_filert_parser_com		expected_ret[NTEST] = {filert_internal, filert_internal, filert_internal, filert_internal
													, filert_internal, filert_error, filert_error, filert_error};
	t_filert_parser_com		ret;
	T_TEST					expected_parsed[NTEST] = {
										{.color = {0,0,0}, .intensity = 0.3},
										{.color = {0, 1, 2}, .intensity = 0.9},
										{.color = {42,42,42}, .intensity = 0.7},
										{.color = {42,42,42}, .intensity = 0.5},
										{.color = {255,255,255}, .intensity = 0.01}
										};
	T_TEST					parsed;
	int						cur_test;
	int						ret_passed;
	int						parsed_passed;
	int						nret_test, nparsed_test;

	ret_passed = 0;
	parsed_passed = 0;
	nret_test = 0;
	nparsed_test = 0;
	cur_test = 0;
	while (cur_test < NTEST)
	{
		nret_test++;
		printf("== TEST #%d ==\n", nret_test);
		printf("Test to parse \"%s\" as a filert_color.\n", test_str[cur_test]);		
		ret = filert_parse_color(&test_str[cur_test], &parsed);
		if (ret == expected_ret[cur_test])
		{
			printf(">> Return value ok\n");
			ret_passed++;
			if (ret == filert_internal)
			{
				nparsed_test++;
				if (EQUAL(&expected_parsed[cur_test], &parsed))
				{
					printf(">> Parsed value ok\n");
					parsed_passed++;
				}
				else
				{
					printf(">> Parsed value error\n");
					printf("Expected parsed filert_color is : \t");
					PRINTF(&expected_parsed[cur_test]);
					printf("\n");
					printf("Effective parsed filert_color is : \t");
					PRINTF(&parsed);
					printf("\n");
				}
			}
		}
		else
		{
			printf(">> Return value error\n");
			printf("Expected returned value is : \tfilert_%s\n", (expected_ret[cur_test] == filert_internal ? "internal" : "error"));
			printf("Effective returned value is : \tfilert_%s\n", (ret == filert_internal ? "internal" : "error"));
		}
		cur_test++;
	}
	printf("\nReturn test count : %d\n", nret_test);
	printf("\nReturned values passed : %d\n", ret_passed);
	printf("\nParsed test count : %d\n", nparsed_test);
	printf("\nParsed passed : %d\n", parsed_passed);
}
