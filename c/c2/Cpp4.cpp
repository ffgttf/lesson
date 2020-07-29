#include <stdio.h>

int main()
{ 
	int a, b, c, first_sub, second_sub, third_sub, forth_sub, fifth_sub, sixth_sub, seventh_sub, eighth_sub;
	printf("Enter a 24-hour time: ");
	scanf("%2d:%2d", &a, &b);

    c = a * 60 + b;
	first_sub = 531;
	second_sub = 631;
	third_sub = 723;
	forth_sub = 803;
	fifth_sub = 892;
	sixth_sub = 1042;
	seventh_sub = 1222;
	eighth_sub = 1529;

	if (c <= first_sub)
		printf("Closest departure time is 8:00,arriving at 10:16.\n");
	else if (c > first_sub && c <= second_sub)
		printf("Closest departure time is 9:43,arriving at 11:52.\n");
	else if (c > second_sub && c <= third_sub)
		printf("Closest departure time is 11:19,arriving at 1:31.\n");
	else if (c > third_sub && c <= forth_sub)
		printf("Closest departure time is 12:47,arriving at 3:00.\n");
	else if (c > forth_sub && c <= fifth_sub)
		printf("Closest departure time is 2:00,arriving at 4:08.\n");
	else if (c > fifth_sub && c <= sixth_sub)
		printf("Closest departure time is 3:45,arriving at 5:55.\n");
	else if (c > sixth_sub && c <= seventh_sub)
		printf("Closest departure time is 7:00,arriving at 9:20.\n");
	else if (c > seventh_sub && c <= eighth_sub)
		printf("Closest departure time is 9:45,arriving at 11:58.\n");

	return 0;
}






