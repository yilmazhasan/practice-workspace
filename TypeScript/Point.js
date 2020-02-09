(function (deps, factory) {
    if (typeof module === 'object' && typeof module.exports === 'object') {
        var v = factory(require, exports); if (v !== undefined) module.exports = v;
    }
    else if (typeof define === 'function' && define.amd) {
        define(deps, factory);
    }
})(["require", "exports"], function (require, exports) {
    var Point = (function () {
        function Point(x, y, z) {
            this.x = x;
            this.y = y || -1;
            this.z = z;
        }
        Point.prototype.draw = function () {
            console.log("X: " + this.x + " Y: " + this.y + " Z: " + this.z);
        };
        return Point;
    })();
    exports.Point = Point;
    var Point2 = (function () {
        //access modifires are public by default	
        function Point2(x, y, z) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.y = y || -1;
        }
        Point2.prototype.draw = function () {
            console.log("X: " + this.x + " Y: " + this.y + " Z: " + this.z);
        };
        return Point2;
    })();
    exports.Point2 = Point2;
});
