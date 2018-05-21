let math = require('mathjs');

// Parameters
const f = "2x * cos(2x) - (x+1)^2";
const a = -3;
const b = -2;

console.log(`Function: ${f} \nInterval [${a}, ${b}] \n\n`)

function evaluate(a, b, fa, fb) {
    let numerator = (a*fb) - (b*fa);
    let denominator = fb - fa;
    return (numerator / denominator).toFixed(4);
}

function solve(f, x) {
    return math.eval(f.replace(/x/g, `(${x})`));
}

let counter = 0;
function main(a, b) {
    if ( counter == 10 ) {
        return;
    }

    counter++;

    const fa = solve(f, a);
    const fb = solve(f, b);

    const x = evaluate(a, b, fa, fb);
    const fx = solve(f, x);

    console.log(`Step ${counter}: a = ${Number(a).toFixed(4)}, \t b = ${b}, \t x = ${x}, \t fx = ${fx}`)
    main(b, x)
}

main(a, b);