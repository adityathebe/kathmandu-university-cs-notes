const getHomogenousCoordinate = (x, y) => {
    let m = new Matrix(3, 1);
    m.data = [[x], [y], [1]]
    return m;
}

const createTranslationMatrix = (tx, ty) => {
    let m = new Matrix(3, 3);
    m.data = [[1, 0, tx], [0, 1, ty], [0, 0, 1]];
    return m;
}

const createScalingMatrix = (sx, sy) => {
    let m = new Matrix(3, 3);
    m.data = [[sx, 0, 0], [0, sy, 0], [0, 0, 1]];
    return m;
}

const createReflectionMatrix = (x_axis = -1, y_axis = -1) => {
    let m = new Matrix(3, 3);
    m.data = [[x_axis, 0, 0], [0, y_axis, 0], [0, 0, 1]];
    return m;
}

const createShearingMatrix = (shx = 0, shy = 0) => {
    let m = new Matrix(3, 3);
    m.data = [[1, shx, 0], [shy, 1, 0], [0, 0, 1]];
    return m;
}

const createRotationMatrix = (theta) => {
    let m = new Matrix(3, 3);
    m.data = [
        [Math.cos(theta), -Math.sin(theta), 0],
        [Math.sin(theta), Math.cos(theta), 0],
        [0, 0, 1]
    ]
    return m;
}

function setup() {
    createCanvas(windowWidth, windowHeight);
    background("#2ecc71");
    stroke("#2c3e50");
    strokeWeight(2);
    
    // Translate origin to center and draw axes
    line(width / 2, 0, width / 2, height);
    line(0, height / 2, width, height / 2)
    translate(width / 2, height / 2);

    // Two points of a line to transform
    stroke(255);
    let p1 = getHomogenousCoordinate(20, 80);
    let p2 = getHomogenousCoordinate(75, 120);
    line(p1.data[0][0], p1.data[1][0], p2.data[0][0], p2.data[1][0])

    // Translation (50, 40)
    stroke("#8e44ad");
    let M_translation = createTranslationMatrix(20, 40)
    let p1_translated = Matrix.multiply(M_translation, p1);
    let p2_translated = Matrix.multiply(M_translation, p2);
    line(p1_translated.data[0][0], p1_translated.data[1][0], p2_translated.data[0][0], p2_translated.data[1][0])

    // Scaling (3, 3)
    stroke("#2980b9");
    let M_scaling = createScalingMatrix(2, 2);
    let p1_scaled = Matrix.multiply(M_scaling, p1);
    let p2_scaled = Matrix.multiply(M_scaling, p2);
    line(p1_scaled.data[0][0], p1_scaled.data[1][0], p2_scaled.data[0][0], p2_scaled.data[1][0])

    // Rotation
    stroke("#f1c40f")
    let M_rotation = createRotationMatrix(PI / 2);
    let p1_rotated = Matrix.multiply(M_rotation, p1);
    let p2_rotated = Matrix.multiply(M_rotation, p2);
    line(p1_rotated.data[0][0], p1_rotated.data[1][0], p2_rotated.data[0][0], p2_rotated.data[1][0])

    // Reflection about x-axis
    stroke("#d35400")
    let M_reflection = createReflectionMatrix(1, -1);
    let p1_reflected = Matrix.multiply(M_reflection, p1);
    let p2_reflected = Matrix.multiply(M_reflection, p2);
    line(p1_reflected.data[0][0], p1_reflected.data[1][0], p2_reflected.data[0][0], p2_reflected.data[1][0])
    
    // Shearing
    stroke("#e74c3c")
    let M_sheared = createShearingMatrix(2, 1.5);
    let p1_sheared = Matrix.multiply(M_sheared, p1);
    let p2_sheared = Matrix.multiply(M_sheared, p2);
    line(p1_sheared.data[0][0], p1_sheared.data[1][0], p2_sheared.data[0][0], p2_sheared.data[1][0])
}