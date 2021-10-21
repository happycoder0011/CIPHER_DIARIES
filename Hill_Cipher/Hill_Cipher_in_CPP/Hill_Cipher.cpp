/**     Author: Ajaysinh Rajput       **/

//      Hill Cipher in C++          // 


#include<iostream>
#include<math.h>
#include<vector>
using namespace std;


// Compute Co-factor of Matrix element
void GetCofactor(vector<vector<int> > Matrix,vector<vector<int> > &Minor,int p,int q,int n)
{
    int row=0,col=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=p && j!=q)
            {
                Minor[row][col++]=Matrix[i][j];
                if(col==n-1)
                {
                    col=0;
                    row++;
                }
            }
        }
    }
}

// Compute Deteminent of Matrix
int GetDeterminate(vector<vector<int> > Matrix,int n)
{
    if(n==1)
        return Matrix[0][0];

    vector<vector<int> > Minor(n,vector<int>(n,0));
    int Determinent=0;
    int s=1;
    for(int k=0;k<n;k++)
    {
        GetCofactor(Matrix,Minor,0,k,n);
        Determinent += s*Matrix[0][k]*GetDeterminate(Minor,n-1);
        s=-s;
    }
    return Determinent;
}

// To find Multiplicative Mod Inverse
int modInverse(int p, int m)
{
	for (int x = 1; x < m; x++)
		if (((p%m) * (x%m)) % m == 1)
			return x;
}


// Compute Adjoint of Matrix
vector<vector<int> > GetAdjoint(vector<vector<int> > Matrix,int n)
{
    if(n==1)
        return {{1}};

    vector<vector<int> > Adjoint(n,vector<int>(n)), Minor(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            GetCofactor(Matrix,Minor,i,j,n);
            Adjoint[j][i]=(((i+j)%2==0)?1:-1)*GetDeterminate(Minor,n-1);

            Adjoint[i][j]%=26;
            if(Adjoint[i][j]<0)
                Adjoint[i][j]+=26;
        }
    }
   
    return Adjoint;
}


// Hill Cipher Encryption
string HillCipher_encryption(string message,string key)
{
    int n = message.length();
    vector<vector<int> > messageMatrix(n,vector<int>(1)),CipherMatrix(n,vector<int>(1)),KeyMatrix(n,vector<int>(n));

    // Calculate message Matrix
    for(int i=0;i<n;i++)
        messageMatrix[i][0] = message[i]-'A';

    // Calculate Key Matrix
    int ch=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            KeyMatrix[i][j] = key[ch++]-'A';

    // Calculate Cipher Matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
            CipherMatrix[i][j]=0;
            for(int k=0;k<n;k++)
                CipherMatrix[i][j]+=KeyMatrix[i][k]*messageMatrix[k][j];
            CipherMatrix[i][j]%=26;
            if(CipherMatrix[i][j]<0)
                CipherMatrix[i][j]+=26;
        }
    }

    // Convert Cipher Matrix to Cipher Message
    string CipherMessage;
    for(int i=0;i<n;i++)
        CipherMessage.push_back(CipherMatrix[i][0]+'A');

    return CipherMessage;
}


// Hill Cipher Decryption
string HillCipher_decryption(string cipher,string key)
{
    int n = cipher.length();
    vector<vector<int> > DecryptedMatrix(n,vector<int>(1)),CipherMatrix(n,vector<int>(1)),KeyMatrix(n,vector<int>(n));

    // Calculate Cipher Matrix
    for(int i=0;i<n;i++)
        CipherMatrix[i][0] = cipher[i]-'A';

    // Calculate Key Matrix
    int ch=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            KeyMatrix[i][j] = key[ch++]-'A';

    // Get Inverse of Key Matrix
    vector<vector<int> > Adjoint(GetAdjoint(KeyMatrix,n));
    int Determinent = GetDeterminate(KeyMatrix,n);
    Determinent%=26;
    if(Determinent<0)
        Determinent+=26;
   
    vector<vector<int> > Inv_KeyMatrix(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            Inv_KeyMatrix[i][j]=(modInverse(Determinent,26)*Adjoint[i][j])%26;

    // Calculate Decrypted Matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
            DecryptedMatrix[i][j]=0;
            for(int k=0;k<n;k++)
                DecryptedMatrix[i][j]+=Inv_KeyMatrix[i][k]*CipherMatrix[k][j];
            DecryptedMatrix[i][j]%=26;
        }
    }

    // Convert Cipher Matrix to Decripted Message
    string DecryptedMessage;
    for(int i=0;i<n;i++)
        DecryptedMessage.push_back(DecryptedMatrix[i][0]+'A');

    return DecryptedMessage;

}


int main()
{
    string s,key;
    cout<<"\nEnter message: ";
    cin>>s;
    cout<<"\nEnter key: ";
    cin>>key;

    // Encryption Part
    string Cipher = HillCipher_encryption(s,key);
    cout<<"\nCipher message: "<<Cipher<<'\n';

    // Decryption Part
    string Decrypted = HillCipher_decryption(Cipher,key);
    cout<<"\nDecrypted message: "<<Decrypted<<'\n';

    return 0;

}