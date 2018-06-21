void	matrix_cpy(float source[4][4], float dest[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			dest[i][j] = source[i][j];
	}
}

void	matrix_mult(float mat1[4][4], float mat2[4][4], float dest[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			dest[i][j] = mat1[i][0]*mat2[0][j]+
						 mat1[i][1]*mat2[1][j]+
						 mat1[i][2]*mat2[2][j]+
						 mat1[i][3]*mat2[3][j];
	}
}

void	matrix_vec_mult(t_vector *source, float mat[4][4], t_vector *dest)
{
	dest->x =	source->x * mat[0][0]+
				source->y * mat[1][0]+
				source->z * mat[2][0]+
							mat[3][0];
	dest->y =	source->x * mat[0][1]+
				source->y * mat[1][1]+
				source->z * mat[2][1]+
							mat[3][1];
	dest->z =	source->x * mat[0][2]+
				source->y * mat[1][2]+
				source->z * mat[2][2]+
							mat[3][2];
}

void	matrix_identity(float mat[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				mat[i][j] = 1;
			else
				mat[i][j] = 0
			j++;
		}
		i++;
	}
}

void	matrix_translate(float mat[4][4], float tx, float ty, float tz)
{
	float tmat[4][4]
	matrix_identity(smat);
	tmat[3][0]=tx;
	tmat[3][1]=ty;
	tmat[3][2]=tz;
	matrix_mult(matrix, tmat, mat1);
	matrix_cpy(mat1, matrix);
}

void	matrix_scale(float mat1[4][4], float tx, float ty, float tz)
{
	float tmat[4][4]
	matrix_identity(smat);
	tmat[3][0]=tx;
	tmat[3][1]=ty;
	tmat[3][2]=tz;
	matrix_mult(matrix, tmat, mat1);
	matrix_cpy(mat1, matrix);
}

void matrix_rotate(float matrix[4][4],int ax,int ay,int az)
{
	float xmat[4][4];
	float ymat[4][4];
	float zmat[4][4];

	matrix_identity(xmat);
	xmat[1][1] = COS(ax);
	xmat[1][2] = SIN(ax);
	xmat[2][1] = -SIN(ax);
	xmat[2][2] = COS(ax);

	matrix_identity(ymat);
	ymat[0][0]=COS(ay);
	ymat[0][2]=-SIN(ay);
	ymat[2][0]=SIN(ay);
	ymat[2][2]=COS(ay);

	matrix_identity(zmat);
	zmat[0][0]=COS(az);
	zmat[0][1]=SIN(az);
	zmat[1][0]=-SIN(az);
	zmat[1][1]=COS(az);

	matrix_mult(matrix,ymat,mat1);
	matrix_mult(mat1,xmat,mat2);
	matrix_mult(mat2,zmat,matrix);
}