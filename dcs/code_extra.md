# Code extra

# MAP IN INT MATRIX
```c
typedef enum e_map
{
	FLOOR,
	WALL,
	N,
	S,
	W,
	E,
	SPACES,
}				t_map;

static int	put_field(char field)
{
	if (field == '1')
		return (WALL);
	else if (field == '0')
		return (FLOOR);
	else if (field == ' ')
		return (SPACES);
	else if (field == 'N')
		return (N);
	else if (field == 'S')
		return (S);
	else if (field == 'W')
		return (W);
	else if (field == 'E')
		return (E);
	return (-1);
}

int	**get_int_map(void)
{
	int	i;
	int	j;
	int	**map;

	i = 0;
	map = ft_calloc(parse()->map_height + 1, sizeof(int *));
	while (i <= parse()->map_height)
	{
		j = 0;
		map[i] = ft_calloc(parse()->map_width + 1, sizeof(int *));
		while (j < (int)ft_strlen(parse()->map[i]))
		{
			map[i][j] = put_field(parse()->map[i][j]);
			j++;
		}
		j = parse()->map_width;
		while (map[i][j] == 0)
			map[i][j--] = SPACES;
		i++;
	}
	return (map);
}

void	print_int_map(int **map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= parse()->map_height)
	{
		j = -1;
		while (++j <= parse()->map_width)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
		i++;
	}
}

void	free_map(int **map)
{
	int	i;

	i = 0;
	while (i <= parse()->map_height)
		free(map[i++]);
	free(map);
}
```

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

## Set mouse put block
```c
/**
 * For use on Lib mlx
 * mlx_hook(cube.win_ptr, 4, (1L << 2), (void *)mouse_click, &cube.img);
*/
int	mouse_click(int button, int x, int y, t_image *img)
{
	img->mouse_button = button;
	set_grid_cell(img, x, y);
	return (1);
}

void	set_grid_cell(t_image *img, int x, int y)
{
	t_vt_d	map_pos;
	// (void)img;
	// Converting pixel coordinates into tab coordinates
	map_pos.x = x / TILE_SIZE;
	map_pos.y = y / TILE_SIZE;

	printf("x: %d, y: %d\n\n", map_pos.x, map_pos.y);

	// Checking out of range coordinates
	if (map_pos.x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;

	// Changing cell value according to mouse button
	if (img->mouse_button == MOUSE_LEFT_BUTTON)
		map()->map[map_pos.y][map_pos.x] = '1';
	else if (img->mouse_button == MOUSE_RIGHT_BUTTON)
		map()->map[map_pos.y][map_pos.x] = '0';
}
```