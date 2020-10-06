
// y(n) = 1/2[x(n) + y(n-1)]

#define N 10

void calcul(int *X)
{
	int i, x0, y1, moy;
	int Y[N];

	y1 = X[0];
	for (i = 0; i < N; i++)
	{
		x0 = X[i];			// load
		y1 = (x0 + y1)/2;	// calc
		Y[i] = y1;			// store
	}
}


void unroll(int *X)
{
	int i, x0, x1, y0, y1, moy;
	int Y[N];
	int d = 2;
	int r = N % d;

	i = 0;
	y1 = X[i];
	for (i = 0; i < N - r; i += d)
	{
		x0 = X[i];			// load
		x1 = X[i+1];		// load
		y0 = (x0 + y1)/2;	// calc
		y1 = (x1 + y0)/2;	// calc
		Y[i] = y0;			// store
		Y[i+1] = y1;		// store
	}
	switch (r)
	{
	case 1:
	case 0:
	}
}
