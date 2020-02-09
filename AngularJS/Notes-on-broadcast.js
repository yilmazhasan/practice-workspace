//AngularJs Notes:

//$emit dispatches an event upwards ... $broadcast dispatches an event downwards



_sc.$on('myEvent', function (event, args) {
  console.log('myEvent catched - Data: ' + args);
});
_sc.$emit("secondready");  


_sc.broadcast = function () {
  console.log('broadcasting: ' + { "a": 1, "b": 2 });
  _root.$broadcast('myEvent', 123);
};

_root.$on("secondready", function () {
  _sc.broadcast();
});
