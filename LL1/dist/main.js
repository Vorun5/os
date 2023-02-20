"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const ll1_1 = require("./ll1");
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
    4. (3
    5. a)
    6. +a*b
    7. 3**a
    8. *-8+b
    9. a3
*/
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
    '(3',
    'a)',
    '+a*b',
    '+a*b',
    '3**a	',
    '*-8+b',
    'a3',
];
console.log('\n\n\nVALID TESTS');
for (let i = 0; i < validTest.length; i++) {
    const test = validTest[i];
    const result = (0, ll1_1.ll1)(test);
    console.log(`${i + 1}. ${test}\t\t${result ? 'successful' : 'crash'}`);
}
console.log('\n\n\nINVALID TESTS');
for (let i = 0; i < invalidTest.length; i++) {
    const test = invalidTest[i];
    const result = (0, ll1_1.ll1)(test);
    console.log(`${i + 1}. ${test}\t\t${!result ? 'successful' : 'crash'}`);
}
//# sourceMappingURL=main.js.map