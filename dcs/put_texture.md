# Texture algorithms

## TEST II
```c
int	file_xpm_to_image(t_cube *cube, t_image *text[4])
{
	t_textures	i;

	textures_path(cube);
	i = TEXT_NO;
	while (i <= TEXT_EA)
	{
		text[i]->mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
		cube->textures[i], &text[i]->width, &text[i]->height);
		if (!text[i]->mlx_img)
			image_error(cube);
		text[i]->addr = mlx_get_data_addr(text[i]->mlx_img, &text[i]->bpp, \
						&text[i]->line_len, &text[i]->endian);
		i++;
	}
	return (0);
}
```

## TEST I
```c
void	get_image(t_cube *cube)
{
	tex()->path_no = file_to_image(cube, parse()->path_no);
	// cube->tex_no.img.mlx_img = tex()->path_no;
	tex()->path_so = file_to_image(cube, parse()->path_so);
	tex()->path_we = file_to_image(cube, parse()->path_we);
	tex()->path_ea = file_to_image(cube, parse()->path_ea);
}
void	*file_to_image(t_cube *cube, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(cube->mlx_ptr, path, &width, &height);
	if (!img)
		image_error(cube);
	else
		printf("IMAGE: %p\n", img);
	return (img);
}

void	image_to_window(t_cube *cube, void *img, int x, int y)
{
	mlx_put_image_to_window
	(
		cube->mlx_ptr,
		cube->win_ptr,
		img,
		x * TILE_SIZE,
		y * TILE_SIZE
	);
}
```

## TEST 0
```c
void	ft_load_texture(void *mlx, t_texture *texture)
{
	texture->img.addr = mlx_get_data_addr(texture->img.mlx_img,
			&texture->img.bpp,
			&texture->img.line_len,
			&texture->img.endian);
}

void ft_init_textures(t_cube *cube)
{
	char *path_no;
	char *path_so;
	char *path_we;
	char *path_ea;

	path_no = "../../textures/walls/w3d_e.xpm";
	path_so = "../../textures/walls/w3d_n.xpm";
	path_we = "../../textures/walls/w3d_s.xpm";
	path_ea = "../../textures/walls/w3d_w.xpm";

	ft_load_texture(cube->mlx_ptr, &cube->tex_no, path_no);
	ft_load_texture(cube->mlx_ptr, &cube->tex_so, path_so);
	ft_load_texture(cube->mlx_ptr, &cube->tex_we, path_we);
	ft_load_texture(cube->mlx_ptr, &cube->tex_ea, path_ea);
}
```