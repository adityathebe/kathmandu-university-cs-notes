class Pendulum {
    constructor(m1, m2, l1, l2) {
        this.l1 = l1;
        this.l2 = l2;
        this.m1 = m1;
        this.m2 = m2;
        this.a1 = PI / 2;
        this.a2 = PI / 2;
        this.v1 = 0
        this.v2 = 0;
        this.ac1 = 0
        this.ac2 = 0;
        this.g = 9.8 / (60 * 60);
        this.init();
    }

    init() {
        this.x1 = this.l1 * sin(this.a1);
        this.y1 = this.l1 * cos(this.a1);

        this.x2 = this.x1 + this.l2 * sin(this.a2);
        this.y2 = this.y1 + this.l2 * cos(this.a2);
    }

    update() {

        let num1 = this.g * ( (2*this.m1) + this.m2) * sin(this.a1);
        let num2 = this.m2 * this.g * sin(this.a1 - (2*this.a2) );
        let num3 = 2 * sin(this.a1 - this.a2) * this.m2;
        let num4 = (this.v2 * this.v2 * this.l2 ) + ( this.v1 * this.v1 * this.l1 * cos(this.a1 - this.a2) );
        let den = this.l1 * ( (2*this.m1) + this.m2 - (this.m2 * cos( (2*this.a1) - (2*this.a2) ) ) );
        this.ac1 = (-num1 - num2 - ( num3 * num4) ) / den;

        // console.log(`${this.ac1.toFixed(2)} = ${num1.toFixed(2)} - ${num2.toFixed(2)} + ${num3.toFixed(2)} * ${num4.toFixed(2)} / ${den.toFixed(2)}`);
        
        num1 = 2 * sin(this.a1 - this.a2);
        num2 = (this.v1 * this.v1 * this.l1 * (this.m1 + this.m2));
        num3 = this.g * (this.m1 + this.m2) * cos(this.a1);
        num4 = this.v2 * this.v2 * this.l2 * this.m2 * cos(this.a1 - this.a2);
        den = this.l2 * (2 * this.m1 + this.m2 - this.m2 * cos(2 * this.a1 - 2 * this.a2));
        this.ac2 = (num1 * (num2 + num3 + num4)) / den;

        // console.log(`${this.ac2.toFixed(2)} = ${num1.toFixed(2)} * ( ${num2.toFixed(2)} + ${num3.toFixed(2)} * ${num4.toFixed(2)} ) / ${den.toFixed(2)}`);

        this.x1 = this.l1 * sin(this.a1);
        this.y1 = this.l1 * cos(this.a1);

        this.x2 = this.x1 + this.l2 * sin(this.a2);
        this.y2 = this.y1 + this.l2 * cos(this.a2);

        this.v1 += this.ac1;
        this.v2 += this.ac2;
        this.a1 += this.v1;
        this.a2 += this.v2;

    }

    display() {
        let mag = 180;
        let mag2 = 20
        stroke(255);
        line(0, 0, this.x1 * mag, this.y1 * mag);
        line(this.x1 * mag, this.y1 * mag, this.x2 * mag, this.y2 * mag);

        stroke(0);
        ellipse(this.x1 * mag, this.y1 * mag, this.m1 * mag2, this.m1 * mag2);
        ellipse(this.x2 * mag, this.y2 * mag, this.m2 * mag2, this.m2 * mag2);
    }
}