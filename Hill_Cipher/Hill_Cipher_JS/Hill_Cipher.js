/**     Author: Ajaysinh Rajput        **/

//      Hill Cipher in JavaScript         // 



// Make 2D Array
function Make2D(row,col)
{
    var arr = new Array(row);
    for(var i=0;i<row;i++)
    {
        arr[i] = new Array(col);
    }
    return arr;
}


// Compute Co-factor of Matrix element
function GetCofactor (Matrix, p, q, n)
{

    var Minor = Make2D(n,n);
    var row=0,col=0;
    for(var i=0;i<n;i++)
    {
        for(var j=0;j<n;j++)
        {
            if(i!=p && j!=q)
            {
                Minor[row][col]=Matrix[i][j];
                col=col+1;
                if(col==n-1)
                {
                    col=0;
                    row++;
                }
            }
        }
    }
    return Minor;

}


// Compute Deteminent of Matrix
function GetDeterminate(Matrix, n)
{
    if(n==1)
    {
        return Matrix[0][0];
    }

    var Minor;
    var Determinent=0;
    var s=1;
    for(var k=0;k<n;k++)
    {
        Minor = GetCofactor(Matrix,0,k,n);
        Determinent = Determinent + s*Matrix[0][k]*GetDeterminate(Minor,n-1);
        s=-s;
    }
    return Determinent;
}


// To find Multiplicative Mod Inverse
function modInverse(p, m)
{
	for (var x = 1; x < m; x++)
    {
		if (((p%m) * (x%m)) % m == 1)
        {
			return x;
        }
    }
}


// Compute Adjoint of Matrix
function GetAdjoint (Matrix, n)
{
    if(n==1)
    {
        return [1];
    }

    var Adjoint = Make2D(n,n)
    var Minor = Make2D(n,n);
    for(var i=0;i<n;i++)
    {
        for(var j=0;j<n;j++)
        {
            Minor = GetCofactor(Matrix,i,j,n);
            Adjoint[j][i]=(((i+j)%2==0)?1:-1)*GetDeterminate(Minor,n-1);

            Adjoint[i][j]%=26;
            if(Adjoint[i][j]<0)
            {
                Adjoint[i][j]+=26;
            }
        }
    }
   
    return Adjoint;
}


// Hill Cipher Encryption
function HillCipher_encryption(message,key)
{
    var n = message.length;
    var messageMatrix = Make2D(n,1);
    var CipherMatrix = Make2D(n,1);
    var KeyMatrix = Make2D(n,n);
    //console.log(message[0]);
    // Calculate message Matrix
    for(var i=0;i<n;i++)
    {
        messageMatrix[i][0] = (message[i]).charCodeAt(0) % 65;
    }
    //console.log(messageMatrix);

    // Calculate Key Matrix
    var ch=0;
    for(var i=0;i<n;i++)
    {
        for(var j=0;j<n;j++)
        {
            KeyMatrix[i][j] = (key[ch++]).charCodeAt(0) % 65;
        }
    }
    
    // Calculate Cipher Matrix
    for(var i=0;i<n;i++)
    {
        for(var j=0;j<1;j++)
        {
            CipherMatrix[i][j]=0;
            for(var k=0;k<n;k++)
            {
                CipherMatrix[i][j] += KeyMatrix[i][k]*messageMatrix[k][j];//,console.log(KeyMatrix[i][k],"*",messageMatrix[k][0]);;
            }
            CipherMatrix[i][j] = CipherMatrix[i][j]%26;
            if(CipherMatrix[i][j]<0)
                CipherMatrix[i][j]+=26;
        }
    }
    
    // Convert Cipher Matrix to Cipher Message
    var CipherMessage = "";
    for(var i=0;i<n;i++)
    {
        CipherMessage += String.fromCharCode(CipherMatrix[i][0]+65);
    }

    return CipherMessage;

}


// Hill Cipher Decryption
function HillCipher_decryption(cipher, key)
{
    var n = cipher.length;
    var DecryptedMatrix = Make2D(n,1);
    var CipherMatrix = Make2D(n,1);
    var KeyMatrix = Make2D(n,n);

    // Calculate Cipher Matrix
    for(var i=0;i<n;i++)
    {
        CipherMatrix[i][0] = (cipher[i]).charCodeAt(0) % 65;
    }

    // Calculate Key Matrix
    var ch=0;
    for(var i=0;i<n;i++)
    {
        for(var j=0;j<n;j++)
        {
            KeyMatrix[i][j] = (key[ch++]).charCodeAt(0) % 65;
        }
    }

    // Get Inverse of Key Matrix
    var Adjoint = GetAdjoint(KeyMatrix,n);
    var Determinent = GetDeterminate(KeyMatrix,n);
    Determinent%=26;
    if(Determinent<0)
    {
        Determinent+=26;
    }
   
    var Inv_KeyMatrix = Make2D(n,n);
    for(var i=0;i<n;i++)
    {
        for(var j=0;j<n;j++)
        {
            Inv_KeyMatrix[i][j]=(modInverse(Determinent,26)*Adjoint[i][j])%26;
        }
    }

    // Calculate Decrypted Matrix
    for(var i=0;i<n;i++)
    {
        for(var j=0;j<1;j++)
        {
            DecryptedMatrix[i][j]=0;
            for(var k=0;k<n;k++)
            {
                DecryptedMatrix[i][j]+=Inv_KeyMatrix[i][k]*CipherMatrix[k][j];
            }
            DecryptedMatrix[i][j]%=26;
        }
    }

    // Convert Cipher Matrix to Decripted Message
    var DecryptedMessage="";
    for(var i=0;i<n;i++)
    {
        DecryptedMessage += String.fromCharCode(DecryptedMatrix[i][0]+65);
    }

    return DecryptedMessage;

}


//----------------x-------------------//

// Input Part
var message = "ACT";
var key = "GYBNQKURP";

//----------------x-------------------//

console.log("\nMessage : ",message);
console.log("Key     : ",key);

// Encryption Part
var Cipher = HillCipher_encryption(message,key);
console.log("\nCipher message    : ",Cipher);

// Decryption Part
var Decrypted = HillCipher_decryption(Cipher,key);
console.log("Decrypted message : ",Decrypted);
