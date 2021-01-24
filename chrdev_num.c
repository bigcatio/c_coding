#include<stdio.h>
/* fs/char_dev.c */
#define CHRDEV_MAJOR_MAX 512
/* Marks the bottom of the first segment of free char majors */
#define CHRDEV_MAJOR_DYN_END 234
/* Marks the top and bottom of the second segment of free char majors */
#define CHRDEV_MAJOR_DYN_EXT_START 511
#define CHRDEV_MAJOR_DYN_EXT_END 384
#define CHRDEV_MAJOR_HASH_SIZE 255


static inline int major_to_index(unsigned major)
{
	return major % CHRDEV_MAJOR_HASH_SIZE;
}

int main()
{
	int i;
	for (i = 255-1; i >= CHRDEV_MAJOR_DYN_END; i--) {
		printf("chrdev num = %d\n", i);
	}
	printf("\n\n\n#######################################\n\n\n");
	for (i = CHRDEV_MAJOR_DYN_EXT_START;
	     i >= CHRDEV_MAJOR_DYN_EXT_END; i--) {
		printf("chrdev num = %d\n", major_to_index(i));
	}
	return 0;
}