interface IInput {
    (): string[];
}

const input = ((): IInput => {
    const line=require("readline").createInterface({input:process.stdin});
    const lines:string[]=[];
    line.on("line", (line:string) => lines.push(line));
    return () => lines;
});

