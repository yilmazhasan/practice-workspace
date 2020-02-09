(function (deps, factory) {
    if (typeof module === 'object' && typeof module.exports === 'object') {
        var v = factory(require, exports); if (v !== undefined) module.exports = v;
    }
    else if (typeof define === 'function' && define.amd) {
        define(deps, factory);
    }
})(["require", "exports", "./Point"], function (require, exports) {
    var Point_1 = require("./Point");
    var p = new Point_1.Point(1);
    p.z = -2;
    p.draw();
    var p2 = new Point_1.Point2(1);
    p2.z = -2;
    p2.draw();
});
