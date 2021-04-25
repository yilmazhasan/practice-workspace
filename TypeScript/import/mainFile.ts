// Importing the class from the location of the file
import { exportedFile } from "./exportedFile";

// Creating an object of the class which is imported
let user = new exportedFile();

// Calling the imported class function
console.log(user.sayHello("Geek"));