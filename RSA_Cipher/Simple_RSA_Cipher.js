function mod( m, n )
{           
    return m - n*Math.floor(m/n)
}
function PowerMod(x,p,N)
    // Compute x^p mod N
    {
        var A = 1
        var m = p
        var t = x

        while( m > 0 )
        {
            k = Math.floor( m/2 )
            r = m - 2*k
            if( r == 1 )
                A = mod( A*t, N )
            t = mod( t*t, N )
            m = k
        }           
        return A
    }


function encrypt_text(text, pq, public_key) {
    var char_int;
    var char_int_mod;
    const output_array = []
    for (let e = 0; e < text.length; e++) {
        if (text[e] == text[e].toUpperCase()){
            char_int = text[e].charCodeAt(0) - 64;
        }
        else {
            char_int = text[e].charCodeAt(0) - 96;
        }
        char_int_mod = PowerMod(char_int, public_key, pq);
        output_array.push(char_int_mod);
    }
    return output_array;
}


function decrypt_text(text, pq, private_key) {
    var char_int;
    var char_int_mod;
    let output_array = ""
    for (let e = 0; e < text.length; e++) {
        char_int_mod = PowerMod(text[e], private_key, pq);
        
        char_int = char_int_mod + 64;
        output_array += String.fromCharCode(char_int);
    }
    return output_array;
}

var e = 17
var p = 11
var q = 7
var d = 53

var encrypted_text = encrypt_text("HelloWorld", p*q, e)
console.log(encrypted_text)
var decrypted_text = decrypt_text(encrypted_text, p*q, d)
console.log(decrypted_text)