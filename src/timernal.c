#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct study_time {
	int hours;
	int minutes;
	int seconds;
};

struct break_time {
	int hours;
	int minutes;
	int seconds;
};

char mode;

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
	if (mode == 'b') {
			printf("\t\t\t\tBREAK\n\n");
		} else {
			printf("\t\t\t\tSTUDY\n\n");
		}
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
	if ((s == -1) && ((m > 0) || (h > 0))) {
		if (m > 0) {
			s = 59;
			m--;
		} else {
			m = 59;
			s = 59;
			h--;
		}
	}
	if (s == -1) {
		return;
	}
	
	system("clear");
	print_time(h, m, s);
	sleep(1);
	timer(h,m,s-1);
} // Pass the correct time values into the printing function and handle the mechanics of a timer.

void pomodoro(struct study_time study_length, struct break_time break_length, int num_sessions) {
	while (num_sessions > 0) {
		mode = 's';
		timer(study_length.hours, study_length.minutes, study_length.seconds);
		num_sessions--;
		if (num_sessions == 0) {
			break;
		}
		mode = 'b';
		timer(break_length.hours, break_length.minutes, break_length.seconds);

	}
}

void main(int argc, char* argv[]) {
	struct study_time s_time = {atoi(argv[1]) / 10000, (atoi(argv[1]) % 10000) / 100, atoi(argv[1]) % 100};
	if ((argv[2] != NULL) && (argv[3] != NULL)) {
		int sessions = atoi(argv[3]);
		struct break_time b_time = {atoi(argv[2]) / 10000, (atoi(argv[2]) % 10000) / 100, atoi(argv[2]) % 100};
		pomodoro(s_time, b_time, sessions);
	} else {
		timer(s_time.hours, s_time.minutes, s_time.seconds);
	}
	system("clear");
	system("spd-say completed");
	printf("Completed\a\n");
	return;
} // main function
