function setup() {
    let cnv = createCanvas(800, 480);
    cnv.parent('sketch-holder');
    frameRate(60);
    textSize(20);
    pendulum = new Pendulum(mass1, mass2, length1, length2);
}

function draw() {
    background(51);
    fill(255);
    
    let yGraph = map(pendulum.ac1, min, max, 0, height);
    let potential_energy = (pendulum.m1 * pendulum.g * ( width - pendulum.y1)) + (pendulum.m2 * pendulum.g * ( width - pendulum.y2 ));
    let kinetic_energy = (0.5 * pendulum.m1 * pendulum.v1 * pendulum.v1) + (0.5 * pendulum.m2 * pendulum.v2 * pendulum.v2);
    let total_energy = potential_energy + kinetic_energy;

    text("Total Energy " + total_energy.toFixed(6), 40, 90);
    ellipse(20, yGraph  , 10, 10);
    translate(width / 2, 100);
    pendulum.update();
    pendulum.display();
}
