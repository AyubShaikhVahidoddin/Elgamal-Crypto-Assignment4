# Elgamal-Crypto-Assignment4
Elgamal Implementation




M.Tech Computer Science Information security.
Cryptography Basic.(CS6530)
Assignment-4. ( C language Program for implementation of ElGamal algorithm for encryption and decryption. )
Roll Number -  CS21M515
Name – Ayub Shaikh.
Batch Year-2021
Faculty : Honorable Pandu Rangan Sir
TA : Honorable Venkatakrishnan Sutharsan Sir 








Program Solution and Explanations:-
I Have did the above example by using the C program file name is Elgamal_encryption_decryption.c  
And .exe name is Elgamal_encryption_decryption.exe is shared in the Github  and also the program is shared.
Also PDF doc. Explanation_Assignment_4_Elgamal_encryption_decryption_RollNum_CS21M515.PDF is uploaded in GIT please verfiy.

Below are the screen shots of the C programm executed . 

![Elgmal](https://user-images.githubusercontent.com/94394753/143781606-5ac170ec-dddf-4993-be51-7e5b65394891.png)


![image](https://user-images.githubusercontent.com/94394753/143781489-c838e22b-980b-4b8a-a604-b3eafa788719.png)



![image](https://user-images.githubusercontent.com/94394753/143781495-0bc95c21-b577-4751-bd18-632c0e9ad075.png)

![image](https://user-images.githubusercontent.com/94394753/143781498-70a5cabb-82c1-4d78-b82a-d1f92d43504c.png)

![image](https://user-images.githubusercontent.com/94394753/143781502-47b4a0b5-af78-4cf0-81c9-525fa3f785df.png)

**ElGamal algorithm for encryption and decryption Explanations  and Program Logical Steps Explanations  :-** 

![image](https://user-images.githubusercontent.com/94394753/143781511-fca870fc-9b8f-4ebf-9d5e-9cef1e26690d.png)

![image](https://user-images.githubusercontent.com/94394753/143781515-21b279f3-b091-4b5f-b272-d6eedec6bafb.png)

![image](https://user-images.githubusercontent.com/94394753/143781517-9bf529b6-ab0e-43bf-ba9a-d7996acaa9e6.png)



Program Logical Steps:-


 * *
 *  Program Logic
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

Note: b * a^(-x) mod p = m * y^k * g^(-xk) = m * g^(xk) * g^(-xk) = m

**THANK You So Muc Sir …. **
