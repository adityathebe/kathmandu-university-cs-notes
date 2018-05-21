function lcm (x,y) {
    var temp = x>y ? x : y;
    var lcm = 1;
    while(1) {
        if(temp % x === 0 && temp % y === 0) {
            lcm = temp;
            break;
        } else {
            temp++;
        }
    }
    return lcm;
}