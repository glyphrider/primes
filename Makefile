OBJS := primes.o

primes: $(OBJS)
	$(CC) -o $@ $^

.o:.c
	$(CC) -o $@ -c $^

clean:
	rm -f $(OBJS)
