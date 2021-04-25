export class MyClass {

    val = 0;

    constructor() {
      console.log('My Class created');
    }

    next() {
      this.val++;
      return this.val;
    }

}
