function greet(name, lastName = '') {
    console.log("Hello " + name + ' ' + lastName);
}

let inputName = 'John';
greet(inputName);