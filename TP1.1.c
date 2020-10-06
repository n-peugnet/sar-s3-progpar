
// y(n) = x(n) + x(n-1) + x(n-2)

#define N 10

void calcul(int *T)
{
	int i, x0, x1, x2, sum;
	int Y[N];

	x1 = x2 = T[0];
	for (i = 0; i < N; i++)
	{
		x0 = T[i];			// load
		sum = x0 + x1 + x2; // calc
		Y[i] = sum;			// store
		x2 = x1;			// RR
		x1 = x0;			// RR
	}
}

void unroll(int *T)
{
	int i, x0, x1, x2, sum;
	int Y[N];
	int d = 3;
	int r = N % d;

	i = 0;
	x2 = x1 = T[i];
	for (i = 0; i < N - r; i += d)
	{
		x0 = T[i];			// load
		sum = x0 + x1 + x2; // calc
		Y[i] = sum;			// store
		x2 = T[i + 1];		// load
		sum = x2 + x0 + x1; // calc
		Y[i + 1] = sum;		// store
		x1 = T[i + 2];		// load
		sum = x1 + x2 + x0; // calc
		Y[i + 2] = sum;		// store
	}
	switch (r)
	{
	case 2:
		x0 = T[i++];
		Y[i] = x0 + x1 + x2;
	case 1:
		x1 = T[i++];
		Y[i] = x2 + x0 + x1;
	case 0:
	}
}
