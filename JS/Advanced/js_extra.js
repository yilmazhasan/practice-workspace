
  getUIDPromise() {
    return new Promise((resolve, reject) => {
      setInterval(() => {
        if (this.user) {
          resolve(this.user.uid);
        }
      }, 500);

      setTimeout(() => {
        reject();
      }, 5000);
    }
    );
  }
    loadStringExtension() {
    // MakeFirst Letter Is Upper
    Object.defineProperty(String.prototype, 'toSentenceCase', {
      value: function toSentenceCase() {
        const splittedBySpace = this.split(' ');

        splittedBySpace.forEach((word, i) => {
          splittedBySpace[i] = word.slice(0, 1).toUpperCase() + word.slice(1).toLowerCase();
        });

        return splittedBySpace.join(' ');
      },
      writable: true,
      configurable: true
    });
  }