PROG = dgemm_ch2 dgemm_ch2_O1 dgemm_ch2_O2 dgemm_ch2_O3 dgemm_ch3 dgemm_ch3_O3 dgemm_ch4 dgemm_ch4_O3 dgemm_ch5 dgemm_ch5_O3 dgemm_ch6 dgemm_ch6_O3
all : $(PROG)

dgemm_ch2: dgemm_ch2.c
	gcc dgemm_ch2.c -o dgemm_ch2
dgemm_ch2_O1: dgemm_ch2.c
	gcc -O1 dgemm_ch2.c -o dgemm_ch2_O1
dgemm_ch2_O2: dgemm_ch2.c
	gcc -O2 dgemm_ch2.c -o dgemm_ch2_O2
dgemm_ch2_O3: dgemm_ch2.c
	gcc -O3 dgemm_ch2.c -o dgemm_ch2_O3

dgemm_ch3: dgemm_ch3.c
	gcc -mavx512f dgemm_ch3.c -o dgemm_ch3
dgemm_ch3_O3: dgemm_ch3.c
	gcc -O3 -mavx512f dgemm_ch3.c -o dgemm_ch3_O3

dgemm_ch4: dgemm_ch4.c
	gcc -mavx512f dgemm_ch4.c -o dgemm_ch4
dgemm_ch4_O3: dgemm_ch4.c
	gcc -O3 -mavx512f dgemm_ch4.c -o dgemm_ch4_O3

dgemm_ch5: dgemm_ch5.c
	gcc -mavx512f dgemm_ch5.c -o dgemm_ch5
dgemm_ch5_O3: dgemm_ch5.c
	gcc -O3 -mavx512f dgemm_ch5.c -o dgemm_ch5_O3

dgemm_ch6: dgemm_ch6.c
	gcc -fopenmp -mavx512f dgemm_ch6.c -o dgemm_ch6
dgemm_ch6_O3: dgemm_ch6.c
	gcc -O3 -fopenmp -mavx512f dgemm_ch6.c -o dgemm_ch6_O3

clean:
	/bin/rm -f $(PROG)
