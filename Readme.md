# text-encryption-and-decryption
Encrypt and decrypt text in C

ENCRYPTION
-----------------
--> Have some text input as string.

    Ex--> Pratyush

--> Add a pointer at the end of string.

    Ex--> Pratyush|
    
--> Apply Burrows Wheeler Transformation.

    --> Get all possible rotations by one unit displacement.
    
        Ex--> |Pratyush
        
              U|Pratyush
              
              HU|Pratyush
              
              SHU|Pratyush
              
              ISHU|Pratyush
              
              Pratyush|
              
    --> Arrange all rotations in lexical order.
    
        Ex--> HU|Pratyush
        
              ISHU|Pratyush
              
              Pratyush|
              
              SHU|Pratyush
              
              U|Pratyush
              
              |Pratyush
              
--> String with last characters of lexicographically orderd rotations is the encrypted text.

    Ex--> SR|IHU
    
--> Could save the encrpted text in file.


DECRYPTION
-----------------
--> Have encrypted text as input or from a file and arrange in a coloumn.

    Ex--> S
    
          R
          
          |
          
          I
          
          H
          
          U
          
--> Arrange in lexical order.

--> Add up arranged coloumn with encrypted coloumn.

--> To get all possible rotations repeat previous two steps.

Ex--> Encrypted  Arrange   Add     Arrange   Add     Arrange   Add     Arrange   Add     Arrange   Add

      ---------  -------   ------  -------   ------  -------   ------  -------   ------  -------   ------
      
          S      H         SH      HU        SHU      HU|      SHU|    HU|R      SHU|R   HU|RI     SHU|RI
          
          R      I         RI      IS        RIS      ISH      Pratyush    ISHU      Pratyush   ISHU|     Pratyush|
          
          |      R         |R      RI        |RI      RIS      |Pratyush    Pratyush      |Pratyush   Pratyush     |Pratyush
          
          I      S         IS      SH        ISH      SHU      ISHU    SHU|      ISHU|   SHU|R     ISHU|R
          
          H      U         HU      U|        HU|      U~R      HU|R    U|RI      HU|RI   U|RIS     HU|RIS
          
          U      |         U|      |R        U|R      |RI      U|RI    |RIS      U|RIS   |Pratyush     U|Pratyush
          
--> In last add coloumn find string which ends with pointer.

    Ex--> Pratyush|
    
--> Could store this decrypted text in file.