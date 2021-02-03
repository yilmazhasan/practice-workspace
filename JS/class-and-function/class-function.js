function MyClassFn() {
    let val = 'let';
    this.val = 'this';
    function MyClassFn() {
        console.log('This is ctor')
    }

    this.getVal = () => {
        return val;
    }

    this.getThisVal = () => {
        return this.val;
    }

    console.log('This is body')

    return 0;
}


let fn = new MyClassFn();
console.log("--")
console.log(fn)
console.log('val: ', fn.getVal())
console.log('this.val: ', fn.getThisVal())
console.log(typeof(fn))
console.log(fn.getVal)
console.log("--")

let fnRet = MyClassFn()
console.log('This fn returns: ', fnRet)
