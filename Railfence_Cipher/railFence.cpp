#include<bits/stdc++.h>
using namespace std;

pair< string , int > getInput()
{
    string inputStr;
    int key;

    cout << "Enter the key: ";
    cin >> key;

    cout << "Enter the text: ";
    cin.ignore();
    getline(cin, inputStr);

    return make_pair(inputStr, key);
}

string encryption(string plainText, int key)
{
    int numOfCols = plainText.length();
    char matrix[key][numOfCols];

    for(int i=0; i<key; i++)
        for(int j=0; j<numOfCols; j++)
            matrix[i][j] = '_';

    int i=0;
    bool moveDown = true;
    for(int colNum = 0; colNum < numOfCols; colNum++){
        matrix[i][colNum] = plainText[colNum];
        if(moveDown){
            if(i+1 == key){
                i--;
                moveDown = !moveDown;
            }
            else
                i++;
        }
        else {
            if(i-1 == -1){
                i++;
                moveDown = !moveDown;
            }
            else
                i--;
        }
    }

    string cipherText;
    for(int i=0; i<key; i++){
        for(int j=0; j<numOfCols; j++){
            if(matrix[i][j] != '_')
                cipherText.push_back(matrix[i][j]);
        }
    }

    return cipherText;
}

string decryption(string cipherText, int key)
{
    int numOfCols = cipherText.length();
    char matrix[key][numOfCols];

    for(int i=0; i<key; i++)
        for(int j=0; j<numOfCols; j++)
            matrix[i][j] = '_';


    int i=0;
    bool moveDown = true;
    for(int colNum = 0; colNum < numOfCols; colNum++){
        matrix[i][colNum] = '*';
        if(moveDown){
            if(i+1 == key){
                i--;
                moveDown = !moveDown;
            }
            else
                i++;
        }
        else {
            if(i-1 == -1){
                i++;
                moveDown = !moveDown;
            }
            else
                i--;
        }
    }

    int ptr = 0;
    for(int i=0; i<key; i++)
        for(int j=0; j<numOfCols; j++)
            if(matrix[i][j] == '*' && ptr < numOfCols)
                matrix[i][j] = cipherText[ptr++];

    string plainText;
    i=0;
    moveDown = true;
    for(int colNum = 0; colNum < numOfCols; colNum++){
        plainText.push_back(matrix[i][colNum]);
        if(moveDown){
            if(i+1 == key){
                i--;
                moveDown = !moveDown;
            }
            else
                i++;
        }
        else {
            if(i-1 == -1){
                i++;
                moveDown = !moveDown;
            }
            else
                i--;
        }
    }

    return plainText;
}

int main()
{
    int choice;
    bool isRunning = true;

    cout << "**********************RAIL FENCE TRANSPOSITION CIPHER**********************\n";

    while(isRunning){
        cout << "Choose one of the below:\n";
        cout << "1.Encryption\n";
        cout << "2.Decryption\n";
        cout << "3.QUIT\n";

        cin >> choice;

        switch(choice)
        {
            case 1:
                    {
                        cout << "***************ENCRYPTION***************\n";
                        pair< string, int > inputs = getInput();
                        string cipherText = encryption(inputs.first, inputs.second);
                        cout << "The cipherText is: \n";
                        cout << cipherText << endl;
                        cout << "***************************************\n";
                        break;
                    }

            case 2:
                    {
                        cout << "***************ENCRYPTION***************\n";
                        pair< string, int > inputs = getInput();
                        string plainText = decryption(inputs.first, inputs.second);
                        cout << "The plainText is: \n";
                        cout << plainText << endl;
                        cout << "***************************************\n";
                        break;
                    }

            case 3:
                    isRunning = false;
                    break;

            default:
                    cout << "No such option available\n";
                    break;
        }
    }
}
