#include <stdio.h>
#include <string.h>

#define SV_Fmt "%.*s"
#define SV_Arg(s) (int)(s).count, (s).data

typedef struct {
	char *data;
	size_t count;
} String_View;

int main(void) {
	char *s1 = "Hello world";
	printf("s1 = %s\n", s1);

	String_View sv1 = {
		.data = s1,
		.count = strlen(s1)
	};
	printf("sv1 = "SV_Fmt"\n", SV_Arg(sv1));

	char s2[] = {'h','i'};
	String_View sv2 = {
		.data = s2,
		.count = 2
	};
	printf("sv2 = "SV_Fmt", count = %zu\n", SV_Arg(sv2), sv2.count);
	printf("sv2 = "SV_Fmt", count = %zu\n", SV_Arg(sv2), sv2.count);

	char s3[] = {'h','i','\0'};
	String_View sv3 = {
		.data = s3,
		.count = strlen(s3)
	};
	printf("sv3 = %s, count = %zu\n", sv3.data, sv3.count);
	printf("sv3 = "SV_Fmt", count = %zu\n", SV_Arg(sv3), sv3.count);

	return 0;
}