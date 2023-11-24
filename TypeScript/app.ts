const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
});

let input = [];
readline.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    console.log(solution(input));
    process.exit();
});