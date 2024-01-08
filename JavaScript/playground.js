console.log(eval("3+4*2"));

(function () {
    function a(name){
        console.log(`Hello ${name}!`);
    }

    a('World');
})();


console.log("가나다" + a);
var a; // undefined
// let a; // ReferenceError: Cannot access 'a' before initialization

const b = 1;
// b = 2; // TypeError: Assignment to constant variable.

const c = {name: 'John'};
c.name = 'Jane'; // const로 선언한 객체는 변경 가능

const d= [1, 2, 3];
d.push(4); // const로 선언한 배열도 변경 가능

console.log("37"-7); // 30
console.log("37"+7); // 377 tlqkf
console.log(+"37"+7); // 44
