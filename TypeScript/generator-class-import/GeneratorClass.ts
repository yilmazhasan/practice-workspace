export default class GeneratorClass {
    constructor() {
        const iterator = this.generator(10);
        iterator.next();
    }
    *generator(count:number): IterableIterator<number> {
        while(true)
            yield count++;
    }
}
