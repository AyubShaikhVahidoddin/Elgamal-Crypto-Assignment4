/*
 * Elgamal_encryption_decryption.c
 *
 *  Created on: 20-Nov-2021
 *      Author: Ayub Shaikh
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

/*
 * *
 *  Proogram Logic
 *  1) Take large prime numbers p and g (g <p, g is preferably the prime root of p)

Note: If g is a prime root of the prime number p, then g mod p, g^2 mod p, …, g^p-1 mod p are permutations from 1 to p-1

2) Randomly select an integer x (2 <= x <= (p-2), (p, g, x) is the private key)

3) Calculate y = g^x (mod p) ((p, g, y) is the public key)



2. Encryption process

1) Randomly select an integer k (2 <= k <= (p-2) and k and (p-1) are relatively prime)

2) Calculate a = g^k mod p, b = m*y^k mod p (m is the plaintext to be encrypted)

3) Ciphertext C = (a, b)



3. Decryption process

1. m = b * a^(-x) mod p

Note: b * a^(-x) mod p = m * y^k * g^(-xk) = m * g^(xk) * g^(-xk) = m*/

int e1, e2;
int p, d;
int C1, C2;

int gcd(int a, int b)
{
    int q, r1, r2, r;

    if (a > b)
    {
        r1 = a;
        r2 = b;
    }
    else {
        r1 = b;
        r2 = a;
    }

    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
    }

    return r1;
}

uint64_t randomsNumbers(uint64_t upper, uint64_t lower)

{
    uint64_t num = ( rand()%
                (upper - lower +1)) + lower;
    return num;

}

int getExponention(int bit, int n, int* y, int* a)
{
    if (bit == 1) {
        *y = (*y * (*a)) % n;
    }

    *a = (*a) * (*a) % n;
}


// Prime number check
uint64_t primeNumberCheck(uint64_t n)
{
    uint64_t i, flag = 0;
    for (i=2;i<n/2; ++i)
    {
        //condition for non-prime
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

// generate random prime numbers
uint64_t generateRandomPrimeNumbers(uint64_t upper,uint64_t lower)
{
    uint64_t p;
    uint64_t flag = 1;
    while(flag)
    {
        p = randomsNumbers(upper, lower);
        flag = primeNumberCheck(p);
    }
    return p;
}

// Euclidean GCD  to get GCD
uint64_t euclidGCDLogic(uint64_t a, uint64_t b)
{
    if (a == 0)
        return b;
    return euclidGCDLogic(b % a, a);
}

//Modular Exponentiation
uint64_t power(uint64_t  x, uint64_t y, uint64_t p)
{
    uint64_t res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

uint64_t Exponent(uint64_t bit, uint64_t n, uint64_t* y, uint64_t* a)
{
    if (bit == 1) {
        *y = (*y * (*a)) % n;
    }

    *a = (*a) * (*a) % n;
}



uint64_t t_value(uint64_t a, uint64_t m, uint64_t n)
{
    uint64_t r;
    uint64_t y = 1;

    while (m > 0)
    {
        r = m % 2;
        Exponent(r, n, &y, &a);
        m = m / 2;
    }

    return y;
}



uint64_t PrimitiveRoot(uint64_t p)
{
    uint64_t flag;
    for (uint64_t a = 2; a < p; a++)
    {
        flag = 1;
        for (uint64_t i = 1; i < p; i++)
        {
            if (t_value(a, i, p) == 1 && i < p - 1) {
                flag = 0;
            }
            else if (flag && t_value(a, i, p) == 1 && i == p - 1) {
                return a;
            }
        }
    }
}





uint64_t x_value(uint64_t p)

{
        uint64_t x_arr[sizeof(p)];

        uint64_t z_len;
        z_len = p - 2;
//                                            printf("z_len : %d",z_len);
        uint64_t arr[z_len];
        uint64_t size, i, toSearch = 3, found = 0;

        for(i=2; i<z_len; i++)
        {
            uint64_t z_val = i % p;
            // printf("Zp values : %d ", z_val);
            arr[i] = z_val;
        }

    while ((found == 0))
    {

        toSearch = randomsNumbers(p,2);


        /* Assume that element does not exists in array */
        found = 0;

        for(i=0; i<z_len; i++)
        {
            /*
            * If element is found in array then raise found flag
            * and terminate from loop.
            */
            if(arr[i] == toSearch)
            {
                found = 1;
                break;
            }
        }
    }

    return toSearch;



}



int numberTwo;
// C Main program execution
int main()

{

	     printf("--------------------------------------------------------------------\n");
	   	 printf("--------------------------------------------------------------------\n");

	     printf("---*** C language Program for implementation of ElGamal algorithm for encryption and decryption.  ***---\n");

	     printf("--------------------------------------------------------------------\n");
	     printf("-------Assignment-3 Submitted by Roll number: CS21M515 -------------\n");
	     printf("--------------------------------------------------------------------\n");
	     printf("Please Enter the number or :\n");

    uint64_t p,g,x,y;

    uint64_t m = 9867;//9677;

    uint64_t upper = 100000;
    uint64_t lower = (upper-1000);

    srand (time(0));

    p = generateRandomPrimeNumbers(upper,lower);
    g = PrimitiveRoot(p);
    x = x_value(p);



    y = power(g,x,p);






    char str[1000];
    uint64_t i=0;
    uint64_t mes[1000], c2[1000];


    printf("Please enter any plain text: ");
    //scanf("%s",str);
    gets(str);
    printf("\n\n");

    printf("ASCII of given string: ");

    while(str[i])
    {
        mes[i] = str[i];
        printf("%d",mes[i]);
        i++;
    }

    printf("\n\n");

    // Elgamal Encryption C1 = and C2 generated :

    printf("-------------------------------------------------\n");
    printf("* Elgamal Encryption=> C1 = and C2 generated *\n");

    // 1 < r < p
    uint64_t r;
    do {
        r = rand() % (p - 1) + 1;
    }
    while (euclidGCDLogic(r, p) != 1);

    uint64_t c1 = power(g, r, p);


    i = 0;
    while(mes[i])
    {
        c2[i] = mes[i] * power(y, r, p) % p;
        i++;
    }


    printf("Private Key is:\n\tx : %d\n",x);


    printf("Public Key  is : \n");
    printf("\t Generated Random prime number p : %d\n",p);
    printf("\t Primitive Root g : %d\n\n",g);

    printf("Cipher message C1 : %d \n",c1);


    printf("Cipher Message C2 : ");
    i = 0;
    while (c2[i])
    {
        printf("%d", c2[i]);
        i++;
    }

    printf("\n\n");

    //uint64_t c2 = m * power(y, r, p) % p;



    // Decryption logic code by using Elgamal Decryption .

    printf("* Decryption by using Elgamal Decryption logic.");
    printf("***********************************************\n");

    i = 0;
    while(c2[i])
    {
        uint64_t c_2 = c2[i];
        mes[i] = c_2 * power(c1, p-1-x, p) % p;
        i++;
    }

    printf("\n");

    printf("Decrypted ASCII Message : ");
    i = 0;
    while(mes[i])
    {
        printf("%d",mes[i]);
        i++;
    }



    printf("\n\n");


    printf("The Conversion of above ASCII to plain text is :=> ");
    i = 0;
    while(mes[i])
    {
        printf("%c",mes[i]);
        i++;
    }


    printf("\n\n");

    printf("Enter any number to exit:\n");
        scanf("%d", & numberTwo);


        if(numberTwo > 0){
           return 0;
        }


   // return 0;
}

int FindPri(int a, int m, int n)
{
    int r;
    int y = 1;

    while (m > 0)
    {
        r = m % 2;
        getExponention(r, n, &y, &a);
        m = m / 2;
    }

    return y;
}

int PrimitiveRootMethodTwo(int p)
{
    int flag;
    for (int a = 2; a < p; a++)
    {
        flag = 1;
        for (int i = 1; i < p; i++)
        {
            if (FindPri(a, i, p) == 1 && i < p - 1) {
                flag = 0;
            }
            else if (flag && FindPri(a, i, p) == 1 && i == p - 1) {
                return a;
            }
        }
    }
}

int KeyGenerationLogic()
{
    do {
        do
            p = rand() + 256;
        while (p % 2 == 0);

    } while (!(2, p));
    p = 107;

    e1 = 2;
    do {
        d = rand() % (p - 2) + 1;        // 1 <= d <= p-2
    } while (gcd(d, p) != 1);

    d = 67;
    e2 = FindPri(e1, d, p);
}

