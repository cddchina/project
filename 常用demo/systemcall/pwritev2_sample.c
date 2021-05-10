#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <linux/fs.h>
#include <unistd.h>
#include <sys/syscall.h>
//#include </usr/src/kernels/4.19.90-17.ky10.aarch64/include/uapi/asm-generic/fcntl.h>

int main() {

	char buf1[5]={"jjjj"}, buf2[10]={"kkkkkkkkkk"};
	struct iovec iov[2];
	iov[0].iov_base = buf1;
	iov[0].iov_len = 5;
	iov[1].iov_base = buf2;
	iov[1].iov_len = 10;

	size_t fd = open("/root/test/1.txt", O_RDWR);
	if (fd) {
		printf("fd=%d\n", fd);
		char buf[100] = {0};
		//read(fd, buf, sizeof(buf));


		//int rsize = syscall(286, fd, iov, 2, 0, RWF_NOWAIT);
		int rsize = pwritev2(fd, iov, 2, 0, RWF_APPEND);
	printf("write size=%d\n", rsize);	


		close(fd);

	}
	return 0;
}
