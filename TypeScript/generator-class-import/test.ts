import GeneratorClass from './GeneratorClass';

let test = new GeneratorClass();
let gen = test.generator(2);
console.log(gen.next())
console.log(gen.next())
console.log(gen.next())