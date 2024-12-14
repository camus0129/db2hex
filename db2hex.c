#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// db=20log(hex/pow(2,23));
// hex = pow(10,(db/20))*pow(2,23);
void db2hex(double db, unsigned char *value)
{
	db = db / 20;
	db = pow(10.0, db);
	long res = (db * pow(2.0, 23.0) + 0.5); // up to int value
	printf("0x%08lx\n", res);
	value[0] = res >> 24;
	value[1] = (res >> 16) & 0x00FF;
	value[2] = (res >> 8) & 0x0000FF;
	value[3] = res & 0x000000FF;
}

void show_help(void)
{
	printf("Usage:\n");
	printf("db2hex db\n");
}
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		show_help();
		return 0;
	}
	double db = (double)strtol(argv[1], NULL, 10);
	unsigned char value[4] = {0};
	db2hex(db, value);
	printf("res = 0x%02x,0x%02x,0x%02x,0x%02x\n", value[0], value[1], value[2], value[3]);
	return 0;
}
