#include "../includes/RTv1.h"
#include <stdio.h>

void	show_obj_coord(t_basic *all)
{

	printf("SPHERE\n");
	printf("centr %f, %f, %f\n", ((t_sphere*)(all->prim->content))->cntr.x, ((t_sphere*)(all->prim->content))->cntr.y, ((t_sphere*)(all->prim->content))->cntr.z);
	printf("radius %f\n", ((t_sphere*)(all->prim->content))->rds);
	printf("color %x\n", ((t_sphere*)(all->prim->content))->clr.color);
	printf("reflective %f\n", ((t_sphere*)(all->prim->content))->rfl);
	printf("specular %d\n", ((t_sphere*)(all->prim->content))->spcl);


	printf("SPHERE2\n");
	printf("centr %f, %f, %f\n", ((t_sphere*)(all->prim->next->content))->cntr.x, ((t_sphere*)(all->prim->next->content))->cntr.y, ((t_sphere*)(all->prim->next->content))->cntr.z);
	printf("radius %f\n", ((t_sphere*)(all->prim->next->content))->rds);
	printf("color %x\n", ((t_sphere*)(all->prim->next->content))->clr.color);
	printf("reflective %f\n", ((t_sphere*)(all->prim->next->content))->rfl);
	printf("specular %d\n", ((t_sphere*)(all->prim->next->content))->spcl);

	printf("SPOT\n");
	printf("intensity %f\n", ((t_spot*)(all->light->content))->intensity);
	printf("position %f, %f, %f\n", ((t_spot*)(all->light->content))->position.x, ((t_spot*)(all->light->content))->position.y, ((t_spot*)(all->light->content))->position.z);
}
