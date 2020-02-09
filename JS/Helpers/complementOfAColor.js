
    getComplementColor = function (percentage) {
      var color = _sc.green2Red(percentage);
      var colorHex = "0x" + color.slice(1);
      var complement = (0xffffff ^ colorHex).toString(16);

      while (complement.length < 6)
        complement = "0" + complement;
      return "#" + complement;
    }
