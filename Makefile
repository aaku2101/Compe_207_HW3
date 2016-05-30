target:	 64_HW3_Q1A 64_HW3_Q1B 64_HW3_Q2 64_HW3_Q3_getsockopt 64_HW3_Q3_setsockopt 64_HW3_Q4_server 64_HW3_Q4_client

64_HW3_Q1A: 64_HW3_Q1A.c
	gcc -pthread -o 64_HW3_Q1A 64_HW3_Q1A.c

64_HW3_Q1B: 64_HW3_Q1B.c
	gcc -pthread -o 64_HW3_Q1B 64_HW3_Q1B.c

64_HW3_Q2: 64_HW3_Q2.c
	gcc -pthread -o 64_HW3_Q2 64_HW3_Q2.c

64_HW3_Q3_getsockopt: 64_HW3_Q3_getsockopt.c
	gcc -o 64_HW3_Q3_getsockopt 64_HW3_Q3_getsockopt.c 

64_HW3_Q3_setsockopt: 64_HW3_Q3_setsockopt.c
	gcc -o 64_HW3_Q3_setsockopt 64_HW3_Q3_setsockopt.c

64_HW3_Q4_server: 64_HW3_Q4_server.c
	gcc -o 64_HW3_Q4_server 64_HW3_Q4_server.c

64_HW3_Q4_client: 64_HW3_Q4_client.c
	gcc -o 64_HW3_Q4_client 64_HW3_Q4_client.c


clean:
	rm -f 64_HW3_Q1A 64_HW3_Q1B 64_HW3_Q2 64_HW3_Q3_getsockopt 64_HW3_Q3_setsockopt 64_HW3_Q4_server 64_HW3_Q4_client *~
