CC = gcc
CFLAGS = -I. -I/usr/include/tirpc
LIBS = -ltirpc

SERVER_OBJS = uber_server.c uber_svc.c uber_xdr.c
CLIENT_OBJS = uber_client.c uber_clnt.c uber_xdr.c

all: uber_server uber_client

uber_server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) $(LIBS)

uber_client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) $(LIBS)

clean:
	rm -f uber_server uber_client *.o
