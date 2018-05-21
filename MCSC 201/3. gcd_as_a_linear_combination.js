function cal_gcd (x,y) {
    var temp = x>y ? y : x;
    var gcd_val = 1;
    while(1) {
        if(x%temp === 0 && y%temp === 0) {
            gcd_val = temp;
            break;
        } else
            temp--;
        }
    return gcd_val;
}

function main(a, b) {
    var gcd = cal_gcd(a,b);
    var s, t=0;
    do{
        t++;
        s = (gcd-t*b)/a;
    } 
    while(s % 1 !== 0);
    console.log(gcd + " = " + s + "*" + a + " + " + t + "*" + b);
}

main(140, 250);