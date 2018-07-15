
#include "fdf.h"
#include <math.h>

int 	adjust_rotate(int keycode, t_param *p)
{
	double rotate;

	rotate = 0.01;
	if (keycode == 123) /*ROTATE LEFT*/
		p->r.y += fmod((p->r.y += rotate * M_PI), 2);
	else if (keycode == 124) /*ROTATE RIGHT*/
		p->r.y -= fmod((p->r.y += rotate * M_PI), 2);
	else if (keycode == 126) /*ROTATE UP*/
		p->r.x = fmod((p->r.x += rotate * M_PI), 2);
	else if (keycode == 125) /*ROTATE DOWN*/
		p->r.x = fmod((p->r.x -= rotate * M_PI), 2);
	else if (keycode == 43)	/*ROTATE AROUND Z*/
		p->r.z = fmod((p->r.z += rotate * M_PI), 2);
	else if (keycode == 47) /*ROTATE AROUND -Z*/
		p->r.z = fmod((p->r.z -= rotate * M_PI), 2);
	else if (keycode == 49) /*Stop rotation*/
	{
		p->r.x = 0;
		p->r.y = 0;
		p->r.z = 0;
	}
	else
		return (0);
	return (1);
}

int 	adjust_scale(int keycode, t_param *p)
{
	double scale;

	scale = 0.02;
	if (keycode == 116)
		p->s.z += scale;
	if (keycode == 121)
		p->s.z += scale;
	else
		return (0);
	return (1);
}

int 	adjust_trans(int keycode, t_param *p)
{
	double trans;

	trans = 0.02;
	if (keycode == 0) /*TRANS RIGHT*/
		p->t.x -= trans;
	else if (keycode == 2)/*TRANS LEFT*/
		p->t.x += trans;
	else if (keycode == 13)/*TRANS UP*/
		p->t.y += trans;
	else if (keycode == 1)/*TRANS DOWN*/
		p->t.y -= trans;
	else
		return (0);
	return (1);
}

int	key_hook(int keycode, t_param *p)
{
	// if ((adjust_rotate(keycode, p) == 1))
	// 	 ;
	// else if ((adjust_scale(keycode, p) == 1))
	// 	 ;
	// else if ((adjust_trans(keycode, p) == 1))
	// 	 ;
	if (keycode == 9)
		exit(0);
	return (0);
}