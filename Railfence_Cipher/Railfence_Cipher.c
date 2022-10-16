#include<stdio.h>

void encrypt()
{
    int key;
    char plainText[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", plainText);
    printf("Enter the key: ");
    scanf("%d",&key);

    int n = strlen(plainText);
    char rail[key][n];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<key; j++)
            rail[j][i] = '_';
    
    int row = 0;
    _Bool dir = 0;
    for(int col=0; col<n; col++)
    {
        if(row == 0 || row == key-1)
            dir = !dir;
        rail[row][col] = plainText[col];
        dir?row++:row--;
    }

    printf("Encrypted message: ");

    for(int i=0; i<key; i++)
        for(int j=0; j<n; j++)
            if(rail[i][j] != '_')
                printf("%c", rail[i][j]);
    printf("\n\n");
}

void decrypt()
{
    int key;
    char cipherText[100];
    printf("Enter the message to be decrypted: ");
    scanf("%s", cipherText);
    printf("Enter the key: ");
    scanf("%d",&key);

    int n = strlen(cipherText);
    char rail[key][n];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<key; j++)
            rail[j][i] = '_';
    
    int row = 0;
    _Bool dir = 0;
    for(int col=0; col<n; col++)
    {
        if(row == 0 || row == key-1)
            dir = !dir;
        rail[row][col] = '*';
        dir?row++:row--;
    }

    int index = 0;
    for(int i=0; i<key; i++)
        for(int j=0; j<n; j++)
            if(rail[i][j] == '*' && index<n)
                rail[i][j] = cipherText[index++];

    printf("Decrypted message: ");

    row = 0;
    dir = 0;
    for(int col=0; col<n; col++)
    {
        if(row == 0 || row == key-1)
            dir = !dir;
        printf("%c", rail[row][col]);
        dir?row++:row--;
    }

    printf("\n\n");
}

int main()
{
    int opt;

    printf("\n**********************RAIL FENCE TRANSPOSITION CIPHER**********************\n\n");

    while(1)
    {
        printf("Press 1 for encryption, 2 for decryption, 3 for exit - \n");
        scanf("%d",&opt);

        switch (opt)
        {
            case 1:
                encrypt();
                break;
            case 2:
                decrypt();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid option, try again!\n\n");
        }
    }

    return 0;
}