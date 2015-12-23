#include <stdio.h>
#include <comedilib.h>

#define N 150

main()
{
	comedi_t *fd;
	lsampl_t data[N];
	int i, r = 33;
	int subdev = 0, channel = 0, range = 0;

	fd = comedi_open("/dev/comedi0");
	printf("%x\n", fd);
	
	r = comedi_data_read_n(fd,subdev,channel,range,AREF_GROUND, data, N);
	printf("r = %d\n", r);
	for(i = 0; i < N; i++)
		printf("%d\n", data[i]);

}
