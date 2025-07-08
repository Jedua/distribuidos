CC = gcc
CFLAGS = -I. -I/usr/include/tirpc
LIBS = -ltirpc

all: generated uber_server uber_client

uber_server: uber_server.c uber_svc.c uber_xdr.c uber.h
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

uber_client: uber_client.c uber_clnt.c uber_xdr.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) -lm

generated:
	rm -f uber.h uber_clnt.c uber_svc.c uber_xdr.c
	rpcgen -M -C -l -o uber_clnt.c uber.x
	rpcgen -M -h -o uber.h uber.x
	rpcgen -M -c -o uber_xdr.c uber.x
	rpcgen -M -m -o uber_svc.c uber.x

clean:
	rm -f *.o uber_server uber_client uber_clnt.c uber_svc.c uber_xdr.c uber.h
