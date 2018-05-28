function SIN(degree) {
    let radian = degree * (Math.PI / 180);
    return Math.sin(degree);
}

function COS(degree) {
    let radian = degree * (Math.PI / 180);
    return Math.cos(degree);
}

class Pendulum {
    constructor(nodes, masses, arm_length) {
        this.nodes = nodes;
        this.arm_length = arm_length;
        this.m = masses;
        this.a = [PI/2, PI/2];
        this.v = [0, 0];
        this.acc = [0, 0];
        this.g = 0.163;
        this.init();
    }

    init() {
        this.x1 = this.arm_length * SIN(this.a[0]);
        this.y1 = this.arm_length * COS(this.a[0]);

        this.x2 = this.x1 + this.arm_length * SIN(this.a[1]);
        this.y2 = this.y1 + this.arm_length * COS(this.a[1]);
    }

    update() {
       
        let num1 = -this.g * ((2 * this.m[0]) + this.m[1]) * SIN(this.a[0]);
        let num2 = -this.m[1] * this.g * SIN(this.a[0] - (2 * this.a[1]));
        let num3 = -2 * SIN(this.a[0] - this.a[1]) * this.m[1];
        let num4 = Math.pow(this.v[1], 2) * this.arm_length + Math.pow(this.v[0], 2) * this.arm_length * COS(this.a[0] - this.a[1]);
        let den = this.arm_length * ( (2 * this.m[0]) + this.m[1] - (this.m[1] * COS(2 * this.a[0] - 2 * this.a[1])))
        this.acc[0] = (num1 + num2 + num3 * num4) / den;

        let num21 = 2 * SIN(this.a[0] - this.a[1]);
        let num22 = Math.pow(this.v[0], 2) * this.arm_length * (this.m[0] + this.m[1]);
        let num23 = this.g * (this.m[0] + this.m[1]) * COS(this.a[0]);
        let num24 = Math.pow(this.v[1], 2) * this.arm_length * this.m[1] * COS(this.a[0] - this.a[1]);
        this.acc[1] = (num21 * (num22 + num23 + num24)) / den;
        
        for (let i = 0; i < this.v.length; i++) {
            this.v[i] += this.acc[i];
        }
        
        for (let i = 0; i < this.a.length; i++) {
            this.a[i] += this.v[i];
        }

        this.init();        
    }

    display() {
        let mag = 1;
        stroke(255);
        line(0, 0, this.x1 * mag, this.y1 * mag);
        line(this.x1 * mag, this.y1 * mag, this.x2 * mag, this.y2 * mag);

        stroke(0);
        ellipse(this.x1 * mag, this.y1 * mag, this.m[0] * 200, this.m[0] * 200);
        ellipse(this.x2 * mag, this.y2 * mag, this.m[1] * 200, this.m[1] * 200);
    }
}