class Generator {

    val = 0;

    constructor() {

    }

    *next() {
        if(this.val >= 4) {
          return;
        }

        this.val++;
        yield this.val;
        this.val++;
        this.val++;
        yield this.val;
    }

}

let gen = new Generator();

let n = gen.next();
console.log(n.next());
console.log(n.next());
n = gen.next();
console.log(n.next());
n = gen.next();
console.log(n.next());