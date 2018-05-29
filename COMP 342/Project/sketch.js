let pendulum = null;

function setup() {
    createCanvas(800, 480);
    frameRate(60);
    textSize(20);
    pendulum = new Pendulum(0.5, 0.5, 0.5, 0.5);
}

let max = 0;
let min = 0;
function draw() {
    background(51);
    fill(255);
    if ( pendulum.ac1 > max ) {
        max = pendulum.ac1;
    }
    
    if ( pendulum.ac1 < min) {
        min = pendulum.ac1;
    }
    
    let yGraph = map(pendulum.ac1, min, max, 0, height);
    let potential_energy = (pendulum.m1 * pendulum.g * ( width - pendulum.y1)) + (pendulum.m2 * pendulum.g * ( width - pendulum.y2 ));
    let kinetic_energy = (0.5 * pendulum.m1 * pendulum.v1 * pendulum.v1) + (0.5 * pendulum.m2 * pendulum.v2 * pendulum.v2);
    let total_energy = potential_energy + kinetic_energy;

    text(`Max Acceleration: ${max}`, 40, 30);
    text(`Min Acceleration: ${min}`, 40, 60);
    text("Total Energy " + total_energy.toFixed(6), 40, 90);
    ellipse(20, yGraph  , 10, 10);
    translate(width / 2, 100);
    pendulum.update();
    pendulum.display();
    // noLoop();
}
