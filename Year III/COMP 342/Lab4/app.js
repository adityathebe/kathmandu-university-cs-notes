function drawCircle(cX, cY, r) {
	let x = 0;
	let y = r;
	let p = null;

	// Initial parameter
	if ( Number.isInteger(r)) p = (5/4) - r
	else p = 1 - r;

	while ( x <= y ) {
		x += 1;
		if ( p < 0) {
			p += 2 * x + 1;	
		} else {
			y -= 1;
			p += 2*x - 2*y + 1
		};

		// Plot pixel in all eight octants
		point(x + cX, cY + y);
		point(-x + cX, cY + y);
		point(x + cX, cY - y);
		point(-x + cX, cY - y);
		point(y + cX, cY + x);
		point(y + cX, cY + -x);
		point(-y + cX, cY + x);
		point(-y + cX, cY + -x);
	}
}

function draw_line(x1, y1, x2, y2) {
	let x = x1, y = y1;
	let stepX, stepY = 1;
	let dy = y2 - y1;
	let dx = x2 - x1;
	if (dy < 0) { dy = -dy; stepY = -1 }
	if (dx < 0) { dx = -dx; stepX = -1 }
	dy *= 2;
	dx *= 2;

	let slope = dy / dx;
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
			if (slope <= 1) x += stepX;
			else y += stepY;
		} else {
			p += paramA - paramB;
			x += stepX, y += stepY;
		}
		point(x, y);
	}
	ellipse(x, y, 10, 10);
	ellipse(x, y, 5, 5);
}

function piechart(data, cX, cY, r) {
	// Sum all => Get percentage => Radian
	let total = data.reduce((acc, val) => acc + val);
	let angles = data.map((d) => ( d * 2 * PI) / ( total));
	let prev_angle = 0;
	angles.forEach((d, index) => {
		let x = r * Math.cos(d + prev_angle);
		let y = r * Math.sin(d + prev_angle);
		prev_angle += d;
		line(cX, cY, x, y)
	});
}

function setup() {
	createCanvas(windowWidth , windowHeight );
	background("#b2bec3");

	// Move Origin to the center
	strokeWeight(2);	
	translate(width/2, height/2);
	drawCircle(0, 0, 200);
	piechart([80, 50, 30, 10], 0, 0, 200);

	// Grid
	textSize(10)
	strokeWeight(0.15);
	fill(50);
	for (let index = -650 ; index < width; index += 50) {
		// Vertical
		text(-index, 0, index)
		line(index, -height, index, height);

		// Horizontal
		text(index, index, 10);
		line(-width, index, width, index);	
	}	
}