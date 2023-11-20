const getInfoText: (name:string, age:number) => string = (name, age) => {
    const nameText = name.substr(0, 10);
    const ageText = age >= 35? 'senior' : 'junior';
    return `name : ${nameText} age: ${ageText}`
}

const v1: string = getInfoText('mike', 23);
console.log(v1);