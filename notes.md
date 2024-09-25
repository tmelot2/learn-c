# Notes

## Interesting Things

- Pre & post increment operators in array accesses (this shit always confuses me & I never use it)
	- `a[i++]` reads `a[i]`, then increments `i`
	- `a[i--]` increments `i`, then reads `a[i]`

- `static` in array param declarations

	```c
	int sum_array(int a[static 3], int n) {
		...
	}
	```

	Hints to the compiler that the length is guaranteed to be at least 3. Allows compiler to "prefetch" elements from memory.

- Compound literal:

	```c
	total = sum_array((int []){1,2,3,4,5}, 5)l
	```
