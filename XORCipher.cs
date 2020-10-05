// XOR Cipher implementation in C#
// Function gets string to encrypt/decrypt and returns encrypted/decrypted string.
// OUTPUT:
// Enter the message: FINE
// Enter the key: less
// Encrypted message:  *,=6
//


using System;

public class XORCipher
{
    public static void Main(string[] args)
    {
        Console.Write("Enter the message: ");
        string message = Console.ReadLine();
        Console.Write("Enter the key: ");
        string key = Console.ReadLine();
        Console.WriteLine($"Encrypted message: {Encrypt(message, key)}");
    }

    public static string Encrypt(string text, string key)
    {
        char[] textBytes = text.ToCharArray();
        char[] keyBytes = key.ToCharArray();
        char[] encrypted = new char[textBytes.Length];

        for (int i = 0; i < textBytes.Length; i++)
        {
            encrypted[i] = (char)(textBytes[i] ^ keyBytes[i % keyBytes.Length]);
        }

        return new string(encrypted);
    }
}