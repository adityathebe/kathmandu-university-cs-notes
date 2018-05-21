function checkPrime(num) {
	if (num === 2)
		return false;
	else if (num % 2 === 0)
		return false;
	else {
		var k = Math.floor(Math.sqrt(num));
		var d = 1;
		while(d<k) {
			d+=2;
            if(num % d === 0)
              return false;
		}
		return true;
	}
}

function getPrime(x) {
	var count = 0, i=1;
	while(count < x-1) {
		if(checkPrime(++i))
      		count++;  
    }
    return i;
}

function main(N) {
	var x = 2, count = 1;
	var ans = [];
	while( N != 1) {
		if( N%x == 0) {
			N = N / x;
			ans.push(x);
		} else {
			count++;
			x = getPrime(count);
		}
	}
	console.log(ans);
}

main(123);