#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *characters[][5] = {{" 0000 ", "00  00", "00  00", "00  00", " 0000 "},
								{"1111  ", "  11  ", "  11  ", "  11  ", "111111"},
								{" 2222 ", "22  22", "   22 ", "  22  ", "222222"},
								{" 3333 ", "33  33", "   333", "33  33", " 3333 "},
								{"44  44", "44  44", "444444", "    44", "    44"},
								{"555555", "55    ", "55555 ", "    55", "55555 "},
								{" 6666 ", "66    ", "66666 ", "66  66", " 6666 "},
								{"777777", "   77 ", "  77  ", " 77   ", "77    "},
								{" 8888 ", "88  88", " 8888 ", "88  88", " 8888 "},
								{" 9999 ", "99  99", " 99999", "    99", " 9999 "}};
const char *dash[5] = {"  ", "  ", "--", "  ", "  "};

void print_time(int h, int m, int s) {
	for (int i = 0; i < 5; i++) {
		printf("%s    %s    %s    %s    %s    %s    %s    %s\n",
			   characters[h / 10][i], characters[h % 10][i], dash[i],
			   characters[m / 10][i], characters[m % 10][i], dash[i],
			   characters[s / 10][i], characters[s % 10][i]);
	}
} //The job of this function is to only handle the printing correctly of the paraeters passed.

void timer(int h, int m, int s) {
	if (s >= 60) {
		m += s / 60;
		s %= 60;
	}
	if (m >= 60) {
		h += m / 60;
		m %= 60;
	}
	if (s == -1) return;
	system("clear");
	print_time(h, m, s);
	sleep(1);
	timer(h-1,m-1,s-1);
} // Pass the correct time values into the printing function and handle the mechanics of a timer.

void main(int argc, char* argv[]) {
	timer(atoi(argv[1]) / 10000, (atoi(argv[1]) % 10000) / 100, atoi(argv[1]) % 100);
	system("clear");
	printf("Completed\n");
	return;
} // main function