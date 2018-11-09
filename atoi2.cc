#include <iostream>
#include <climits>
#include <cctype>
using namespace std;

int myatoi(string &s) {
	
}
int myatoi(const char *s)
{
	const long long INT_MAX_DIV10 = (long long)INT_MAX / 10;
	const long long INT_MIN_DIV10 = (long long)(INT_MIN / 10) * (-1);
	long long v = 0, sign = 1;
	const char *p = s;
	if (*p == '-')
		sign = -1, p += 1;
	if (*p == '+')
		p += 1;
	while (isblank(*p))
		p += 1; 
	while (*p) {
		if (!isdigit(*p))
			break;
		v = v * 10 + (*p - '0');
		if (sign == 1 && v > INT_MAX_DIV10)
			return INT_MAX;
		else if (sign == -1 && v > INT_MIN_DIV10)
			return INT_MIN;
		p += 1;
	}
	return (int)(v * sign);
no_conv:
	return 0;
}
int main(void)
{
	std::string s[] = {
		"1",
		"-1",
		"-2147483649",
		"2147483648",
		" 100",
		"-999a",
		"+2",
	};
	for (int i = 0; i < 7; i += 1) {
		std::cout << s[i] << ": ";
		std::cout << myatoi(s[i].c_str()) << endl;
	}
} 
