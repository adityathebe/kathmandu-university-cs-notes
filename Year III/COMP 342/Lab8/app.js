const getHomogenousCoordinate = (x, y, z) => {
    let m = new Matrix(4, 1);
    m.data = [[x], [y], [z], [1]]
    return m;
}

const createTranslationMatrix = (tx, ty, tz) => {
    let m = new Matrix(4, 4);
    m.data = [[1, 0, 0, tx], [0, 1, 0, ty], [0, 0, 1, tz], [0, 0, 0, 1]];
    return m;
}

const createScalingMatrix = (sx, sy, sz) => {
    let m = new Matrix(4, 4);
    m.data = [[sx, 0, 0, 0], [0, sy, 0, 0], [0, 0, sz, 0], [0, 0, 0, 1]];
    return m;
}

const createReflectionMatrix = (x, y, z) => {
    let m = new Matrix(4, 4);
    m.data = [[x, 0, 0, 0], [0, y, 0, 0], [0, 0, z, 0], [0, 0, 0, 1]];
    return m;
}

let slider, factor = 0;
function setup() {
    createCanvas(windowWidth * 0.80, windowHeight * 0.80, WEBGL);
    slider = createSlider(0, 0.02, 0, 0.001);
}

function draw() {
    background(100);
    factor += slider.value();
    // rotateX(factor);
    rotateY(factor);
    // rotateZ(factor);
    normalMaterial();
    
    ambientMaterial(51);
    translate(0, 100);
    rotateX(HALF_PI);
    plane(500, 500);

    // Draw Axes
    stroke('green');
    line(0, 0, 0, width,0, 0)
    x_axis = createGraphics(400, 200);
    x_axis.fill(255);
    x_axis.textAlign(CENTER);
    x_axis.textSize(64);
    x_axis.text("X", 150, 50);

    line(0, 0, 0, 0, height, 0)
    line(0, 0, 0, 0, 0, 500)

    // Define points
    stroke(255);    
    let p1 = getHomogenousCoordinate(0, 0, 0);
    let p2 = getHomogenousCoordinate(50, 50, 75);
    line(p1.data[0][0], p1.data[1][0], p1.data[2][0], p2.data[0][0], p2.data[1][0], p2.data[2][0]);

    // Translation
    stroke("blue");
    let M_translation = createTranslationMatrix(10, 20, 30);
    let p1_ = Matrix.multiply(M_translation, p1);
    let p2_ = Matrix.multiply(M_translation, p2);
    line(p1_.data[0][0], p1_.data[1][0], p1_.data[2][0], p2_.data[0][0], p2_.data[1][0], p2_.data[2][0]);
    
    // Scaling
    stroke("yellow");
    let M_scaling = createScalingMatrix(2, 3, 4);
    p1_ = Matrix.multiply(M_scaling, p1);
    p2_ = Matrix.multiply(M_scaling, p2);
    line(p1_.data[0][0], p1_.data[1][0], p1_.data[2][0], p2_.data[0][0], p2_.data[1][0], p2_.data[2][0]);
    
    // Reflection
    stroke("red");
    let M_reflection = createReflectionMatrix(1, -1, 1);
    p1_ = Matrix.multiply(M_reflection, p1);
    p2_ = Matrix.multiply(M_reflection, p2);
    line(p1_.data[0][0], p1_.data[1][0], p1_.data[2][0], p2_.data[0][0], p2_.data[1][0], p2_.data[2][0]);
}
