#ifndef TESTS_HH
#define TESTS_HH

const char RESET[]  = "\x1b[0m";
const char RED[]    = "\x1b[31m";
const char GREEN[]  = "\x1b[32m";
const char YELLOW[] = "\x1b[33m";
const char BLUE[]   = "\x1b[34m";

#define TEST(test, desc) \
{ std::cout << BLUE << desc << (test ? "\x1b[32m\tOK" : "\x1b[31m\tFAIL") << RESET << std::endl; }

#define BEGIN_TESTS(unit) \
{ std::cout << YELLOW << std::endl << unit << RESET << std::endl;}

bool float_equal(double a, double b)
{
	return fabs(a - b) < 0.001;
}

#endif // TESTS_HH
