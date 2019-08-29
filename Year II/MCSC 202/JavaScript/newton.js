let math = require('mathjs');

// Parameters
const f = "x^3 - x - 1";
const a = 1;
const Rounder = 5

console.log(`Function: ${f} \nInital Guess: ${a}\n\n`)

function evaluate(a, fa, ffa) {
    let x1 = a - (fa / ffa);
    return x1.toFixed(Rounder)
}

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
    const ffa = solve(String(math.derivative(f, 'x')), a);
    const b = evaluate(a, fa, ffa);

    console.log(`Step ${counter}: a = ${Number(b).toFixed(Rounder)}`)
    main(Number(b))
}

main(a);