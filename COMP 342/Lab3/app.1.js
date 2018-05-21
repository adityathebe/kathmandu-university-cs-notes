// In General: p += A && p+= A - B
// Slope < 1 : p += 2dy && p+= 2dy - 2dx : A = 2dy B = 2dx
// Slope > 1 : p += 2dx && p+= 2dx - 2dy : A = 2dx B = 2dy

function draw_line(x1, y1, x2, y2) {
	let x = x1, y = y1;
	let dy = y2 - y1;
	let dx = x2 - x1;
	let slope = abs (dy / dx);
	textSize(40);
	text(`Slope: ${slope.toFixed(2)}`, width * 0.80, height * 0.14);

	// Parameters
	let paramA = paramB = 0
	if (slope < 1) {
		paramA = 2 * dy;
		paramB = 2 * dx;
	} else {
		paramA = 2 * dx;
		paramB = 2 * dy;
	}

	// Initial Decision Parameter
	let p = paramA - (paramB / 2);
	ellipse(x, y, 5, 5);
	point(x, y);
	for (let i = 0; i < Math.abs(paramB / 2); i++) {
		if (p < 0) {
			p += paramA;
			if (slope <= 1) x += 1;
			else y += 1;
		} else {
			p += paramA - paramB;
			x += 1, y += 1;
		}
		point(x, y);
	}
	ellipse(x, y, 10, 10);
	ellipse(x, y, 5, 5);
}

function setup() {
	createCanvas(windowWidth, windowHeight);
	background("#ebebeb");
	strokeWeight(2);
	draw_line(50, 450, 400, 300);

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