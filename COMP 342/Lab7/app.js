const getRegionCode = (p, c_window) => {
    let code_arr = [
        p.y > c_window.ymax ? 1 : 0,
        p.y < c_window.ymin ? 1 : 0,
        p.x > c_window.xmax ? 1 : 0,
        p.x < c_window.xmin ? 1 : 0,
    ]
    return code_arr.join('')
}

const cohenSutherland = (point1, point2, clipping_window) => {
    strokeWeight(3);
    stroke("#f1c40f");
    line(point1.x, point1.y, point2.x, point2.y);
    let slope = (point2.y - point1.y) / (point2.x - point1.x);

    let accept = false;
    while (1) {
        let r1 = getRegionCode(point1, clipping_window);
        let r2 = getRegionCode(point2, clipping_window);

        // Lies completely inside
        if (parseInt(r1, 2) === 0 && parseInt(r2, 2) === 0) {
            accept = true;            
            break;
        }

        // Lies completely outside
        else if ((parseInt(r1, 2) & parseInt(r2, 2)) !== 0) {
            break;
        }

        // Lies partially inside
        else {
            let out_code, x, y;
            if (parseInt(r1, 2) !== 0) {
                out_code = r1;
                x = point1.x;
                y = point1.y;
            } else {
                out_code = r2;
                x = point2.x;
                y = point2.y;
            }

            // Top clipper
            if ((parseInt(out_code, 2) & parseInt("1000", 2)) !== 0) {
                y = clipping_window.ymax;
                x = point1.x + ((y - point1.y) / slope);
            }

            // Bottom Clipper
            else if ((parseInt(out_code, 2) & parseInt("0100", 2)) !== 0) {
                y = clipping_window.ymin;
                x = point1.x + ((y - point1.y) / slope)
            }

            // Right Clipper
            else if ((parseInt(out_code, 2) & parseInt("0010", 2)) !== 0) {
                x = clipping_window.xmax;
                y = slope * (x - point1.x) + point1.y;
            }

            // Left Clipper
            else if ((parseInt(out_code, 2) & parseInt("0001", 2)) !== 0) {
                x = clipping_window.xmin;
                y = slope * (x - point1.x) + point1.y;
            }

            // Replace outside point with x and y
            if (out_code === r1) {
                point1.x = x
                point1.y = y
            } else {
                point2.x = x
                point2.y = y
            }
        }
    }

    if (accept) {    
        strokeWeight(5);
        stroke("#e74c3c");
        line(point1.x, point1.y, point2.x, point2.y);
    }
}

function setup() {
    createCanvas(windowWidth, windowHeight);
    background("#3498db");

    // Clipping Window (100, 100, 400, 400)
    let clipping_window = { xmin: 100, xmax: 400, ymin: 100, ymax: 400 };
    rect(clipping_window.xmin, clipping_window.ymin, clipping_window.xmax - clipping_window.xmin, clipping_window.ymax - clipping_window.ymin);

    // Draw and clip points
    cohenSutherland({ x: 25, y: 175 }, { x: 200, y: 450 }, clipping_window);
    cohenSutherland({ x: 150, y: 220 }, { x: 300, y: 370 }, clipping_window);
    cohenSutherland({ x: 500, y: 110 }, { x: 200, y: 370 }, clipping_window);
    cohenSutherland({ x: 450, y: 110 }, { x: 600, y: 370 }, clipping_window);
}