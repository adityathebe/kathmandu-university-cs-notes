function setup() {
    // Initialize Canvas
    let canvas = createCanvas(windowWidth, windowHeight);

    // Roofs
    quad(100, 100, 500, 100, 550, 200, 150, 200);
    triangle(100, 100, 150, 200, 50, 200)

    // Walls
    fill('blue')
    rect(150, 200, 400, 300)
    fill('green')
    rect(50, 200, 100, 300)

    // Doors
    fill('brown')    
    rect(75, 300, 50, 200)

    // Windows
    let window_width = 50
    let window_height = 35
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < 5; j++) {
            rect((j * window_width) + 250, (i * window_height) + 250, window_width, window_height)
        }
    }

    // Display Resolution
    textSize(25)
    text(`Resolution: ${windowWidth} * ${windowHeight}`, 100, 50 )

}