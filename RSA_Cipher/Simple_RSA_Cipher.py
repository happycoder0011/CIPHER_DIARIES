def encrypt_text(text, pq, public_key):
    output_array=[]
    for e in text:
        if(e.isupper()):
            output_array.append(int((((ord(e)-64) ** public_key)%pq)))
        else:
            output_array.append(int((((ord(e)-96) ** public_key)%pq))) 
    return output_array

def decrypt_array(encrypt_array, pq, private_key):
    output_text=""
    for e in encrypt_array:
        output_text += chr(int(((e ** private_key)%pq)+96))
    return output_text

e = 17   # gcd(e,(p-1)(q-1))=1
p = 11   # Need to be prime number
q = 7    # Need to be prime number
d = 53   # d*e congruence to 1(mod(p-1(q-1))

encrypt_array = encrypt_text('HelloWorld',p*q,e)   
print(encrypt_array)
decrypt_text = decrypt_array(encrypt_array,p*q,d)
print(decrypt_text)