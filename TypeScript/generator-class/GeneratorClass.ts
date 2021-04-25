class GeneratorClass {
    constructor() {
        const iterator = this.generator(10);
        iterator.next();
    }
    *generator(count:number): IterableIterator<number> {
        while(true)
            yield count++;
    }
}

let test = new GeneratorClass();
let gen = test.generator(5);
let countdown = 15;

while(countdown--) {
    console.log(gen.next())
}
