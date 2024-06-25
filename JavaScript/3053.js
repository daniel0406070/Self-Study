const rl = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function (line) {
    const input = line.split(' ').map(Number);

    if(input[0]*2>=input[1]){
        console.log('E');
    }
    else{
        console.log('H');
    }
    rl.close();
}).on("close", function () {
    process.exit();
});
