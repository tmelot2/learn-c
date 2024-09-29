# Notes

## Interesting Things

- Pre & post increment operators in array accesses (this shit always confuses me & I never use it)
	- `a[i++]` reads `a[i]`, then increments `i`
	- `a[++i]` increments `i`, then reads `a[i]`

- `static` in array param declarations

	```c
	int sum_array(int a[static 3], int n) {
		...
	}
	```

	Hints to the compiler that the length is guaranteed to be at least 3. Allows compiler to "prefetch" elements from memory.

- `static int i` = static storage duration, still locally scoped but it will remain in memory

- Compound literal:

	```c
	total = sum_array((int []){1,2,3,4,5}, 5)l
	```

- `const` pointers: Indicates that a pointer value won't be modified by the function.
- Annoying usages:
	```c
	*p++ or *(p++) 	Value of expression is *p before inc; inc p later
	(*p)++ 			Value of expression is *p before inc, inc *p later
	*++p or *(++p) 	Inc p first, value of expression is *p after inc
	++*p or ++(*p) 	Inc *p first, value of expression is *p after inc
	```
