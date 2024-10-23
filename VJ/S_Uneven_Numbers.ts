import { createInterface } from "readline";
import * as fs from "fs";
import { log } from "console";
import { exit } from "process";

function getd(n : number) : number {
    let ans = 0;
    while (n >= 1)
    {
        ans++;
        n /= 10;
    }
    return ans;
}

function main() {
    const N = nextNum()
    let n = 1, rest = N, cnt = 0;
    while (n <= N)
    {
        if (getd(n) % 2 == 1)
        {
            cnt += Math.min(9 * n, rest);
        }
        rest -= 9 * n;
        n *= 10;
    }
    console.log(cnt);
}

let inputs = "";
let inputArray: string[];
let currentIndex = 0;

function next() {
    return inputArray[currentIndex++];
}
function nextNum() {
    return +next();
}
function nextBigInt() {
    return BigInt(next());
}
function nexts(length: number) {
    const arr = [];
    for (let i = 0; i < length; ++i) arr[i] = next();
    return arr;
}
function nextNums(length: number) {
    const arr = [];
    for (let i = 0; i < length; ++i) arr[i] = nextNum();
    return arr;
}
function nextBigInts(length: number) {
    const arr = [];
    for (let i = 0; i < length; ++i) arr[i] = nextBigInt();
    return arr;
}

if (process.env.OS == "Windows_NT") {
    const stream = createInterface({
        input: process.stdin,
        output: process.stdout,
    });
    stream.on("line", (line) => {
        inputs += line;
        inputs += "\n";
    });
    stream.on("close", () => {
        inputArray = inputs.split(/\s/);
        main();
    });
} else {
    inputs = fs.readFileSync("/dev/stdin", "utf8");
    inputArray = inputs.split(/\s/);
    main();
}