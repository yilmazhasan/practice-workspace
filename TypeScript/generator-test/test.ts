import {Generator} from './Generator';

let gen = new Generator();

let n = gen.next();
console.log(n.next());
console.log(n.next());
gen.next();
console.log(n.next());
let n2 = gen.next();
console.log('n :',  n.next());
console.log('n2 :', n2.next());
console.log('n :',  n.next());
