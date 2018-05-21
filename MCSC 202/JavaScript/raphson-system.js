let math = require('mathjs');

// Main Parameters
let x = -1.571658074549298
let y = -1.1433161490985961
let f = "(3*x*y) - 7 - (x^2)";
let g = "2*x + 2 - y";

let fx = String(math.derivative(f, 'x'));
let gx = String(math.derivative(g, 'x'));
let fy = String(math.derivative(f, 'y'));
let gy = String(math.derivative(g, 'y'));

function solve(a, b, f) {
    f = f.replace(/x/g, a);
    f = f.replace(/y/g, b);
    f = math.eval(f);
    return f;
}

function det(f, g, fy, gy) {
    return (f * gy) - (g * fy);
}

f = solve(x, y, f);
g = solve(x, y, g);
fx = solve(x, y, fx);
gx = solve(x, y, gx);
fy = solve(x, y, fy);
gy = solve(x, y, gy);

console.log("detX: ", det(f, g, fy, gy));
console.log("detY: ", det(fx, f, gx, g));
console.log("Jacobian: ", det(fx, fy, gx, gy));
console.log("x =", x - (det(f, g, fy, gy) / det(fx, fy, gx, gy) ))
console.log("y =", y - (det(fx, f, gx, g) / det(fx, fy, gx, gy) ))