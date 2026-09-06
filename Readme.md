# text-encryption-and-decryption
Encrypt and decrypt text in C and C++

ENCRYPTION
-----------------
--> Have some text input as string.

    Ex--> PRATYUSH

--> Add a pointer at the end of string.

    Ex--> PRATYUSH|
    
--> Apply Burrows Wheeler Transformation.

    --> Get all possible rotations by one unit displacement.
    
        Ex--> |PRATYUSH
        
              H|PRATYUS
              
              SH|PRATYU
              
              USH|PRATY
              
              YUSH|PRAT
              
              TYUSH|PRA

              ATYUSH|PR

              RATYUSH|P
              
              PRATYUSH|

              
    --> Arrange all rotations in lexical order.
    
        Ex--> ATYUSH|PR
        
              H|PRATYUS
              
              PRATYUSH|
              
              RATYUSH|P
              
              SH|PRATYU
              
              TYUSH|PRA

              USH|PRATY

              YUSH|PRAT

              |PRATYUSH
```c              
--> String with last characters of lexicographically orderd rotations is the encrypted text.
| Sorted Index | Lexicographically Sorted Rotations | Last Character |
| 1            | A T Y U S H P R | R |
| 2            | H P R A T Y U S | S |
| 3            | P R A T Y U S H | H |
| 4            | R A T Y U S H P | P |
| 5            | S H P R A T Y U | U |
| 6            | T Y U S H P R A | A |
| 7            | U S H P R A T Y | Y |
| 8            | Y U S H P R A T | T |
```
    Ex--> RS|PUAYTH
    
--> Could save the encrpted text in file.


DECRYPTION
-----------------
--> Have encrypted text as input or from a file and arrange in a coloumn.

    Ex--> R
    
          S
          
          |
          
          P
          
          U
          
          A

          Y

          T

          H
          
--> Arrange in lexical order.

--> Add up arranged coloumn with encrypted coloumn.
```c
Ex-->   Encrypted   Arrange   Add     Arrange   Add     Arrange   Add     Arrange   Add     Arrange   Add

      ---------   -------   ------  -------   ------  -------   ------  -------   ------  -------   ------

          R          A       RA       AT       RAT     ATY       RATY    RATYU     RATYUS  RATYUSH   RATYUSH|P

          S          H       SH       H|       SH|     SH|P      SH|PR   SH|PRA    SH|PRAT SH|PRATY  SH|PRATYU

          |          P       |P       PR       |PR     |PRA      |PRAT   |PRATY    |PRATYU |PRATYUS  |PRATYUSH

          P          R       PR       RA       PRA     PRAT      PRATY   PRATYU    PRATYUS PRATYUSH  PRATYUSH|

          U          S       US       SH       USH     USH|      USH|P   USH|PR    USH|PRA  USH|PRAT  USH|PRATY

          A          T       AT       TY       ATY     ATYU      ATYUS   ATYUSH    ATYUSH| ATYUSH|P  ATYUSH|PR

          Y          U       YU       US       YUS     YUSH      YUSH|   YUSH|P    YUSH|PR YUSH|PRA  YUSH|PRAT

          T          Y       TY       YU       TYU     TYUS      TYUSH   TYUSH|    TYUSH|P TYUSH|PR  TYUSH|PRA

          H          |       H|       |P       H|P     H|PR      H|PRA   H|PRAT    H|PRATY H|PRATYU  H|PRATYUS
```
--> In last add column find string which ends with pointer.

    Ex--> PRATYUSH|

--> Could store this decrypted text in file. 
