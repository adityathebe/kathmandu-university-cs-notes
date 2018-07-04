function drawEllipse(cX, cY, a, b) {
	let x = 0;
	let y = b;
	let points = [];

	/* === Region 1 === */
	// Initial parameter
	let p = (b * b) - (a * a * b) + (a * a) / 4;
	while ((x * b * b) <= (y * a * a)) {
		x += 1;
		if (p < 0) {
			p += (2 * b * b * x) + (b * b);
		} else {
			y -= 1;
			p += (2 * b * b * x) - (2 * y * a * a) + (b * b);
		};
		points.push([x, y]);
	}

	/* === Region 2 === */
	// Initial Parameter
	p = ((x + 0.5) * (x + 0.5) * b * b) + ((y - 1) * (y - 1) * a * a) - (a * a * b * b)

	while (y >= 0) {
		y -= 1;
		if (p > 0) {
			p += - (2 * a * a * y) + (a * a);
		} else {
			x += 1;
			p += (2 * b * b * x) - (2 * y * a * a) + (a * a);
		};
		points.push([x, y]);
	}

	// Plot Points
	for ( let p of points ) {
		point(p[0] + cX, p[1] + cY);
		point(-p[0] + cX, p[1] + cY);
		point(p[0] + cX, -p[1] + cY);
		point(-p[0] + cX, -p[1] + cY);
	}
}

function setup() {
	createCanvas(windowWidth, windowHeight);
	background(51);

	// Move Origin to the center
	strokeWeight(2);
	translate(width / 2, height / 2);

	// Draw Ellipse
	drawEllipse(0, 0, 300, 200);

	// Grid
	textSize(10)
	strokeWeight(0.15);
	fill(50);
	for (let index = -650; index < width; index += 50) {
		// Vertical
		text(-index, 0, index)
		line(index, -height, index, height);

		// Horizontal
		text(index, index, 10);
		line(-width, index, width, index);
	}
}