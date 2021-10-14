function modInverse(a, m) {
    // validate inputs
    [a, m] = [Number(a), Number(m)]
    if (Number.isNaN(a) || Number.isNaN(m)) {
      return NaN // invalid input
    }
    a = (a % m + m) % m
    if (!a || m < 2) {
      return NaN // invalid input
    }
    // find the gcd
    const s = []
    let b = m
    while(b) {
      [a, b] = [b, a % b]
      s.push({a, b})
    }
    if (a !== 1) {
      return NaN // inverse does not exists
    }
    // find the inverse
    let x = 1
    let y = 0
    for(let i = s.length - 2; i >= 0; --i) {
      [x, y] = [y,  x - y * Math.floor(s[i].a / s[i].b)]
    }
    return (y % m + m) % m
}
  
  
var affineCipher = function(text,a,b,method){
     let citext = "";
     let alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     let alpha_index= 0;
     let inverse =0;
  
     if(method === "Encode"){
        for (let i = 0; i < text.length; i++){
          for (let u =0; u < alpha.length; u++){
            if(text[i] === alpha[u]){
                alpha_index = u;
                citext += alpha[(((a * alpha_index) + b) % 26)];
  
            }else if (text[i] === alpha[u].toLowerCase()) {
               alpha_index = u;
               citext += alpha[(((a * alpha_index) + b) % 26)].toLowerCase();
  
            }else if (text[i] == " ") {
               citext += " ";
               i++;
            }
          }
        }
      return citext;
     }
     else{
  
       for (let i = 0; i < text.length; i++){
         for (let u =0; u < alpha.length; u++){
           if(text[i] === alpha[u]){
               alpha_index = u;
               citext += alpha[(((modInverse(a ,26) * (alpha_index - b)) % 26) < 0)? (26 - Math.abs((modInverse(a ,26) * (alpha_index - b)) % 26)): (((modInverse(a ,26) * (alpha_index - b)) % 26))];
           }
           else if (text[i] === alpha[u].toLowerCase()) {
              alpha_index = u;
              citext += alpha[(((modInverse(a ,26) * (alpha_index - b)) % 26) < 0)? (26 - Math.abs((modInverse(a ,26) * (alpha_index - b)) % 26)): (((modInverse(a ,26) * (alpha_index - b)) % 26))].toLowerCase();
  
           }else if (text[i] == " ") {
              citext += " ";
              i++;
           }
         }
       }
      return citext;
     }
  }

//INPUT FORMAT CAN BE CHECKED BELOW
//console.log(affineCipher("dCodeAffine",3,1,"Encode"));