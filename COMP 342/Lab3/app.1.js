// In General: p += A && p+= A - B
// Slope < 1 : p += 2dy && p+= 2dy - 2dx : A = 2dy B = 2dx
// Slope > 1 : p += 2dx && p+= 2dx - 2dy : A = 2dx B = 2dy

function draw_line(x1, y1, x2, y2) {
	let x = x1, y = y1;
	point(x, y);

	let dy = y2 - y1;
	let dx = x2 - x1;
	let slope = dy / dx;
	if (slope > 1) {
		let p = 2 * dx - dy;

		for (let i = 0; i < dy; i++) {
			if (p < 0) {
				p = p + (2 * dx); 
			} else {
				p = p + (2 * dx) - (2 * dy); 
				x += 1;
			}
			y += 1;
			point(x, y);
		}
	} else {
		let p = 2 * dy - dx;

		for (let i = 0; i < dx; i++) {
			if (p < 0) {
				p = p + (2 * dy);
			} else {
				p = p + (2 * dy) - (2 * dx); 
				y += 1;
			}
			x += 1;
			point(x, y);
		}
	}
	text(`Slope: ${slope.toFixed(2)}`, width * 0.80, height * 0.14);
}

function setup() {
	createCanvas(windowWidth, windowHeight);
	background("#ebebeb");
	strokeWeight(2);
	textSize(40);

	draw_line(250, 100, 300, 300);

	// Grid
	stroke("green");
	textSize(10)
	strokeWeight(0.25);
	for (let index = 0; index < width; index += 50) {
		text(index, index, 10)
		line(index, 0, index, height)
		text(index, 0, index)
		line(0, index, width, index)
	}
}