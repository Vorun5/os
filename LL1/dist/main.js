"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
const ll1_1 = require("./ll1");
const fs = __importStar(require("fs"));
/*
Valid tests:
    1. --b
    2. a+b
    3. -(a+b)
    4. (-8)
    5. b+-a
    6. a+(-3)
    7. -(8*b*-((b*-3)*-8+(-3)))
    8. (a+-b*(-a+3)+((a+b)+((a*-b)))+((((a+8)+(a*8)))))
    
Invalid tests:
    1. empty
    2. )
    3. (
    4. +a*b
    5. 3**a
    6. *-8+b
    7. a3
*/
function testing(table, log = false) {
    const validTest = [
        '--b',
        'a+b',
        'a*b',
        '-(a+b)',
        '(-8)',
        'b+-a',
        'a+(-3)',
        '-(8*b*-((b*-3)*-8+(-3)))',
        '(a+-b*(-a+3)+((a+b)+((a*-b)))+((((a+8)+(a*8)))))',
    ];
    const invalidTest = [
        'empty',
        ')',
        '(',
        '+a*b',
        '+a*b',
        '3**a	',
        '*-8+b',
        'a3',
    ];
    console.log('\n\n\nVALID TESTS');
    for (let i = 0; i < validTest.length; i++) {
        const test = validTest[i];
        const result = (0, ll1_1.ll1)(test, table, log);
        console.log(`${i + 1}. ${test}\t\t${result ? 'success' : 'crash'}`);
    }
    console.log('\n\n\nINVALID TESTS');
    for (let i = 0; i < invalidTest.length; i++) {
        const test = invalidTest[i];
        const result = (0, ll1_1.ll1)(test, table, log);
        console.log(`${i + 1}. ${test}\t\t${!result ? 'success' : 'crash'}`);
    }
}
function readTableFromFile(fileName) {
    const text = fs.readFileSync(fileName, 'utf-8');
    const lines = text.split('\n');
    const table = [];
    for (let line of lines) {
        line = line.replace('\r', '');
        const words = line.split(' ');
        const name = words[0];
        const countSym = Number.parseInt(words[1]);
        const symbols = words
            .slice(2, 2 + countSym)
            .map((el) => (el === 'n' ? '\n' : el));
        const shift = words[countSym + 2] === 't';
        const error = words[countSym + 3] === 't';
        const onStack = words[countSym + 4] === 't';
        const end = words[countSym + 5] === 't';
        const ref = Number.parseInt(words[countSym + 6]);
        table.push({
            name,
            end,
            symbols,
            shift,
            error,
            onStack,
            ref,
        });
    }
    return table;
}
const table = readTableFromFile('files/table.txt');
console.log(table);
console.log(table.length);
testing(table);
//# sourceMappingURL=main.js.map