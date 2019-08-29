let math = require('mathjs');

// Parameters
const f = "( 2 * x^3 + 1 )/( 3* x^2 - 1)";
const a = 1;   // Initial Guess

console.log(`Function: ${f} \nInitial Guess: ${a} \n\n`)

function solve(f, x) {
    return math.eval(f.replace(/x/g, `(${x})`));
}

let counter = 0;
function main(a) {
    if ( counter == 10 ) {
        return;
    }

    counter++;

    const fa = solve(f, a);
    console.log(`${counter}: x = ${Number(fa).toFixed(4)}`);

    main(fa);
}

main(a);