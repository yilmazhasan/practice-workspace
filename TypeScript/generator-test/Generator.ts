export class Generator {
    val = 0;

    *next() {
      while(true) {
        this.val++;
        yield this.val;
      }
    }
}
