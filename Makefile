OBJS := primes.o

primes: $(OBJS)
	$(CC) -o $@ $^ -lm

.o:.c
	$(CC) -o $@ -c $^

clean:
	rm -f $(OBJS) primes
