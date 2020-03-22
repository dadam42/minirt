#include "filert_parser.h"
#include "test.h"
#define NTEST 9
#define ENTEST 1
#define T_TEST t_filert_parsed_obj
#define TESTED_FUNCTION filert_parse
#define PRINTF	t_filert_parse_printf
#define EQUAL	t_filert_parse_equal
#include <stdio.h>

int main()
{
	char 					*test_str[NTEST] = {
							"pl 0.5,1,-2. -0.2,0.42, -0  8,16,48",
							"tr 0.1,-0.12,0.123 -1.9,-1.7,2 1,2,3 5,8,10",
							"sq 0.3, 2.5, -3.4  0.231, -.98, 0.25 12 0,1,2",
							"cy 0.25, 3.21, -0.213 0.2, -0.3, 1 12.1 21.1 50, 100, 150",
							"sp 0.25, -.23, 3.14159 6.28 0,10,20",
							"R 500 400",
							"A 0.3 127, 154, 124 ",
							"c -12.1, 0, .25 -0.5, 0.21, -.54 78.2",
							"l 20, 1, 4 0.3 121, 214, 231",
							};
	t_filert_parser_com		expected_ret[NTEST] = {filert_plane, filert_triangle, filert_square, filert_cylinder, filert_sphere, filert_resolution, filert_ambiant_light, filert_camera, filert_light, };
	t_filert_parser_com		ret;
	T_TEST					expected_parsed[NTEST] = {
										{.plane = {.insertion={0.5,1,-2}, .orth={-0.2,0.42,-0}, .color={8,16,48}}},
										{.triangle = {.vertex={{0.1,-0.12,0.123},{-1.9,-1.7,2},{1,2,3}},.color={5,8,10}}},
										{.square = {.center = {0.3, 2.5, -3.4}, .orth = {0.231, -0.98, 0.25}, .size = 12, .color = {0,1,2}}},
										{.cylinder = {.insertion = {0.25,3.21, -0.213}, .direction = {0.2, -0.3, 1}, .diameter = 12.1, .height = 21.1, .color = {50, 100, 150}}},
										{.sphere = {.center = {0.25, -0.23, 3.14159}, .diameter = 6.28, .color = {0, 10, 20}}},
										{.resolution = {.x = 500, .y = 400}},
										{.ambiant_light = {.color = {127, 154, 124}, .intensity = 0.3}},
										{.camera = {.position = {-12.1, 0, 0.25}, .direction = {-0.5, 0.21, -0.54}, .fov = 78.2}},
										{.light = {.position = {20, 1, 4}, .pcolor = {.color = {121, 214, 231}, .intensity = 0.3}}}
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
	while (cur_test < ENTEST)
	{
		nret_test++;
		printf("== TEST #%d ==\n", nret_test);
		printf("Test to parse \"%s\" as a filert_parsed_obj.\n", test_str[cur_test]);		
		ret = TESTED_FUNCTION(&test_str[cur_test], &parsed);
		if (ret == expected_ret[cur_test])
		{
			printf(">> Return value ok\n");
			ret_passed++;
			if (ret != filert_error)
			{
				nparsed_test++;
				if (EQUAL(ret, &expected_parsed[cur_test], &parsed))
				{
					printf(">> Parsed value ok\n");
					parsed_passed++;
				}
				else
				{
					printf(">> Parsed value error\n");
					printf("Expected parsed filert_color is : \t");
					PRINTF(ret, &expected_parsed[cur_test]);
					printf("\n");
					printf("Effective parsed filert_color is : \t");
					PRINTF(ret, &parsed);
					printf("\n");
				}
			}
		}
		else
		{
			printf(">> Return value error\n");
			printf("Expected returned value is : \tfilert_");
			t_filert_com_printf(expected_ret[cur_test]);
			printf("\n");
			printf("Effective returned value is : \tfilert_");
			t_filert_com_printf(ret);
			printf("\n");
		}
		cur_test++;
	}
	printf("\nReturn test count : %d\n", nret_test);
	printf("\nReturned values passed : %d\n", ret_passed);
	printf("\nParsed test count : %d\n", nparsed_test);
	printf("\nParsed passed : %d\n", parsed_passed);
}
