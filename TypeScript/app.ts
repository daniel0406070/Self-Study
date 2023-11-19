// 타입 공부

/*
function add(a: number, b: number): Number { // 함수
  return a + b;
}

let result:number = add(1, 4); //함수>숫자
console.log(result);


let a:string = "hello" // 문자열

let text1:symbol = Symbol(a); // 심볼
let text2:symbol = Symbol(a);
console.log(text1==text2); // false


let obj = { // 객체
  name: "John",
  age: 30,
  city: "New York"
};

let myJSON = JSON.stringify(obj);
console.log(myJSON);
*/

interface Person { // 인터페이스 >> 객체의 타입을 정의
  name: string;
  age: number;
}

let person: Person = { // 객체
  name: "John",
  age: 30
}

console.log(person.name);

