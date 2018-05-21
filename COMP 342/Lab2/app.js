function drawLine(x1, y1, x2, y2) {
	let dx = x2 - x1;
	let dy = y2 - y1;

	let steps = Math.abs(dy) > Math.abs(dx) ? Math.abs(dy) : Math.abs(dx);
	let x_inc = dx / steps;
	let y_inc = dy / steps;

	let x = x1, y = y1;
	for (let i = 0; i < steps; i++) {
		point(x, y);
		x += x_inc;
		y += y_inc;
	}
}

function setup() {
	let canvas = createCanvas(800, 650);
	background('#ebebeb');

	// Axes
	strokeWeight(3)
	drawLine(50, 50, 50, 550);
	drawLine(50, 550, 750, 550);

	let y_val = [480, 500, 400, 430, 350, 330, 250, 200, 250, 240, 270, 340]
	let month = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'June', 'July', 'Aug', 'Sept', 'Oct', 'Nov', 'Dec'];

	// Lines
	for (let i = 0; i < 12; i++) {
		strokeWeight(2);
		stroke(0);
		let x1 = 100 + (55 * i);
		let x2 = x1 + 55;
		let y1 = y_val[i];
		let y2 = y_val[i + 1];

		if (i < 11) drawLine(x1, y1, x2, y2);

		// X Labels
		strokeWeight(1);
		text(month[i], x1 - 10, 570)

		// Y Labels
		let y_label = i * 50;
		text(550 - y_label, 25, y_label)

		// Grid Lines
		stroke(255, 204, 0);
		drawLine(x1, 50, x1, 550);
	}
}