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

	char buf1[5], buf2[10];
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


		int rsize = syscall(286, fd, iov, 2, 0, RWF_NOWAIT);
		//int rsize = preadv2(fd, iov, 2, 0, RWF_NOWAIT);
	printf("read size=%d\n", rsize);	

		printf("preadv:%s\n", buf1);
		printf("\r\n");
		printf("preadv:%s\n", buf2);

		close(fd);

	}
	return 0;
}
