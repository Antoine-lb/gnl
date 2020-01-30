
#include "get_next_line.h"
#include <stdio.h>

size_t ft_strlcat(char *dst,
				  const char *src, size_t dstsize)
{
	size_t i;
	size_t sizedst;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i] && i < dstsize)
		i++;
	sizedst = i;
	while (src[i - sizedst] && i < dstsize - 1)
	{
		dst[i] = src[i - sizedst];
		i++;
	}
	if (sizedst < dstsize)
		dst[i] = '\0';
	return (sizedst + ft_strlen(src));
}

void test(char *str)
{
	int i = 0;
	char dst[50];
	char folder[50] = "tests/";
	char tag[100] = "\n\n=== ";
	char extention[] = ".txt";
	char sep[] = " ===\n";
	int fd;
	char *line;

	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';

	ft_strlcat(folder, dst, 50);
	ft_strlcat(folder, extention, 50);
	ft_strlcat(tag, dst, 50);
	ft_strlcat(tag, sep, 50);
	printf("%s", tag);
	fd = open(folder, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n----\n", line);
	free(line);
}

// int main(int ac, char **av)
int main()
{
	int fd;
	char *line;

	// int ret;
	// if (!ac)
	// 	return (-1);
	// fd = open(av[1], O_RDONLY);
	// while ((ret = get_next_line(fd, &line)) > 0)
	// {
	// 	printf("%d: %s\n", ret, line);
	// 	free(line);
	// }
	// get_next_line(fd, &line);
	// printf("%d: %s\n", ret, line);
	// free(line);

	// test("bible");

	test("1_till_4");
	test("1_to_4");
	test("1_to_4n");
	test("1");
	test("1n");
	test("3");
	test("5");
	test("5n");
	test("8");
	test("9");
	test("10_char_with_n");
	test("10_char");
	test("10");
	test("11");
	test("12");
	test("empty");
	test("just_new_line_2");
	test("just_new_line_3");
	test("just_new_line_4");
	test("just_new_line");
	test("multiple_new_lines");
	test("myfile");
	test("no_new_line");
	test("with_new_line");

	{
		printf("\n\n=== 3.txt ===\n");
		fd = open("tests/3.txt", O_RDONLY);
		int res = get_next_line(fd, &line);
		printf("res = %d line = %s\n\n", res, line);
		free(line);
		res = get_next_line(fd, &line);
		printf("res = %d line = %s\n\n", res, line);
		free(line);
		res = get_next_line(fd, &line);
		printf("res = %d line = %s\n\n", res, line);
		free(line);
		res = get_next_line(fd, &line);
		printf("res = %d line = %s\n\n", res, line);
		free(line);
	}

	{
		printf("\n\n=== abc.txt ===\n");
		fd = open("tests/abc.txt", O_RDONLY);
		int res = get_next_line(fd, &line);
		printf("lib res = 0\n");
		printf("ft_ res = %d\n", res);
		printf("lib line = abc\n");
		printf("ft_ line = %s\n\n", line);
		free(line);
		res = get_next_line(fd, &line);
		printf("lib res = 0\n");
		printf("ft_ res = %d\n", res);
		printf("lib line = \n");
		printf("ft_ line = %s\n\n", line);
		free(line);
	}

	{
		printf("\n\n=== abcn.txt ===\n");
		fd = open("tests/abcn.txt", O_RDONLY);
		int res = get_next_line(fd, &line);
		free(line);
		printf("lib res = 1\n");
		printf("ft_ res = %d\n", res);
		printf("lib line = abc\n");
		printf("ft_ line = %s\n\n", line);
		res = get_next_line(fd, &line);
		free(line);
		printf("lib res = 0\n");
		printf("ft_ res = %d\n", res);
		printf("lib line = \n");
		printf("ft_ line = %s\n\n", line);
	}

	{
		printf("\n\n=== just_new_line_2.txt ===\n");
		fd = open("tests/just_new_line_2.txt", O_RDONLY);
		int res = get_next_line(fd, &line);
		printf("lib res = 1\n");
		printf("ft_ res = %d\n", res);
		printf("lib line = \n");
		printf("ft_ line = %s\n\n", line);
		free(line);
		res = get_next_line(fd, &line);
		printf("lib res = 1\n");
		printf("ft_ res = %d\n", res);
		printf("lib line = \n");
		printf("ft_ line = %s\n\n", line);
		free(line);
		res = get_next_line(fd, &line);
		printf("lib res = 0\n");
		printf("ft_ res = %d\n", res);
		printf("lib line = \n");
		printf("ft_ line = %s\n\n", line);
		free(line);
	}

	{
		printf("\n\n=== empty.txt ===\n");
		fd = open("tests/empty.txt", O_RDONLY);
		int res = get_next_line(fd, &line);
		printf("lib res = 0\n");
		printf("ft_ res = %d\n", res);
		printf("lib line = \n");
		printf("ft_ line = %s\n\n", line);
		free(line);
	}

	while (1)
		;
	return (0);
}