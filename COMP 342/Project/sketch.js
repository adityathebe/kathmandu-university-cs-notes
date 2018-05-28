let pendulum = null;

function setup() {
    createCanvas(800, 480);
    frameRate(60);
    pendulum = new Pendulum(2, [0.05, 0.05], 100 );
}

function draw() {
    translate(width / 2, 40);
    background(51);
    pendulum.update();
    pendulum.display();
}
