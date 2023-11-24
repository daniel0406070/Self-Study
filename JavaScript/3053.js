const rl = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function (line) {
    const a = parseInt(line);
    
    let uc = a*a*Math.PI;
    let tc = a*a*2;

    console.log(uc.toFixed(6));
    console.log(tc.toFixed(6));

    rl.close();
}).on("close", function () {
    process.exit();
});
