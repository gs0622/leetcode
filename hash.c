

unsigned int hash(long long key)
{
	long long hash = key * 2564435761 % 4294967296;
	return (unsigned int )hash;
}


