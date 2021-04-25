export default class Generator {

    val = 0;

    constructor() {
      console.log('Generator created');
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
