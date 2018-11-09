

int valid(char **b)
{
	int i, j, k, v, bitmap[3][9] = {};
	for (i=0; i<9; i++)
		for (j=0; j<9; j++) {
			k = i/3*3+j/3;
			v = (int)b[i][j];
			if (v != '.') {
				int mask = 1 << v;
				if ((bitmap[0][i] & mask) || \
					(bitmap[1][j] & mask) || \
					(bitmap[2][k] & mask))
					return 0;
				bitmap[0][i] |= 1<<v;
				bitmap[1][j] |= 1<<v;
				bitmap[2][k] |= 1<<v;
			}
		}
	return 1;
}

int main(void)
{
	return 0;
}
