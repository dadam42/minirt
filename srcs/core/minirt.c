#include "minirt.h"
#include "libft.h"
#include "bmpfile.h"
#include <math.h>
#include <unistd.h>

void	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

void	print_stdout(char *msg)
{
	write(1, msg, ft_strlen(msg));
}

int main(int argv, char **argc)
{
	t_minirt		minirt;
	t_scene_camera_iterator camera;
	static char	*default_filename = "minirt.bmp";
	char		*filename;

	if (argv < 3 || argv > 4)
	{
		if (argv <= 1)
			print_error("Missing argument.\n");
		else
			print_error("Too many arguments.\n");
		return (1);
	}
	if (ft_strncmp(argc[2], "--save", ft_strlen("--save")))
	{
		print_error("The only available option is --save.\n");
		return (1);
	}
	minirt_init(&minirt);
	minirt_load_filert(&minirt, argc[1]);
	(void)camera;
	(void)default_filename;
	(void)filename;
	{
		if (argv == 4)
			filename = argc[3];
		else
			filename = default_filename;
		scene_get_camera_iterator(&minirt.scene, &camera);
		camera.next(&camera);
		minirt.camera = camera.deref(&camera);
		minirt_save_bmpfile(&minirt, filename);
		print_stdout("Ok.\n");
	}
	minirt_release(&minirt);
	return(0);
}
