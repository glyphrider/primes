OBJS := primes.o

primes: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -f $(OBJS) primes
