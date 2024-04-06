# Code extra

# Encode RGB
```c
#include <stdint.h>

static int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
```

## Handle big line in the end or beginning of the map
```c
static int	check_big_line(char *line, int index)
{
	int	i;

	i = index;
	while (line[i])
	{
		if (line[i]	== '1' || line[i] == ' ')
			i++;
		else
			err_case("Invalid map (bad big line) `32'\n");
	}
	return (0);
}

/*
- Checar quando ha linhas maiores ou menores no inicio e fim da linha
 - Se a linha anterior for menor que a atual, a parte maior da linha\
atual so pode conter 1 e ' '
 - Se a linha anterior for maior que a atual, a parte maior da linha\
anterior so pode conter 1 e ' '
*/
int	handle_big_line(char **map)
{
	int	i;
	int	len_a;
	int	len_b;

	i = parse()->start_map;
	while (map[i] && i <= parse()->end_map)
	{
		len_a = ft_strlen(map[i++]);
		len_b = ft_strlen(map[i]);
		if (len_a < len_b)
			check_big_line(map[i], len_a + 1);
	}
	return (0);
}
```