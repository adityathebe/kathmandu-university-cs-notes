class Pendulum {
    constructor(m, l) {
        this.m = m;
        this.l = l;
        this.a = PI / 2
        this.v = 0
        this.g = 0.163;
        this.init();
    }

    init() {
        this.x = this.l * sin(this.a);
        this.y = this.l * cos(this.a);
    }

    update() {
        let acc = (-this.g * sin(this.a)) / this.l;
        this.x = this.l * sin(this.a);
        this.y = this.l * cos(this.a);
        
        this.v += acc;
        this.a += this.v;
        // console.log(acc, this.x, this.y, this.v, this.a)
    }

    display() {
        let mag = 10;
        stroke(255);
        line(0, 0, this.x * mag, this.y * mag);
    }
}