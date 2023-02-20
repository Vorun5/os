"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const Table = [
    // 0
    {
        name: 'EXP',
        symbols: ['-', '(', 'a', 'b', '8', '3'],
        shift: false,
        error: true,
        ref: 1,
        onStack: false,
        end: false,
    },
    // 1
    {
        name: 'T',
        symbols: ['-', '(', 'a', 'b', '8', '3'],
        shift: false,
        error: true,
        ref: 13,
        onStack: true,
        end: false,
    },
    // 2
    {
        name: 'EXPR',
        symbols: ['+', '\n', '*', ')'],
        shift: false,
        error: true,
        ref: 3,
        onStack: false,
        end: false,
    },
    // 3
    {
        name: 'EXPR',
        symbols: ['*'],
        shift: false,
        error: false,
        ref: 7,
        onStack: false,
        end: false,
    },
    // 4
    {
        name: 'EXPR',
        symbols: [')'],
        shift: false,
        error: false,
        ref: 8,
        onStack: false,
        end: false,
    },
    // 5
    {
        name: 'EXPR',
        symbols: ['+'],
        shift: false,
        error: false,
        ref: 9,
        onStack: false,
        end: false,
    },
    // 6
    {
        name: 'EXPR',
        symbols: ['\n'],
        shift: false,
        error: true,
        ref: 12,
        onStack: false,
        end: false,
    },
    // 7
    {
        name: '*',
        symbols: ['*'],
        shift: false,
        error: true,
        ref: -1,
        onStack: false,
        end: false,
    },
    // 8
    {
        name: ')',
        symbols: [')'],
        shift: false,
        error: true,
        ref: -1,
        onStack: false,
        end: false,
    },
    // 9
    {
        name: '+',
        symbols: [')'],
        shift: true,
        error: true,
        ref: 10,
        onStack: false,
        end: false,
    },
    // 10
    {
        name: 'T',
        symbols: ['-', '(', 'a', 'b', '8', '3'],
        shift: false,
        error: true,
        ref: 13,
        onStack: true,
        end: false,
    },
    // 11
    {
        name: 'EXPR',
        symbols: ['+', '\n', '*', ')'],
        shift: false,
        error: true,
        ref: 3,
        onStack: false,
        end: false,
    },
    // 12
    {
        name: '\n',
        symbols: ['\n'],
        shift: true,
        error: false,
        ref: -1,
        onStack: false,
        end: true,
    },
    // 13
    {
        name: 'T',
        symbols: ['-', '(', 'a', 'b', '8', '3'],
        shift: false,
        error: true,
        ref: 14,
        onStack: false,
        end: false,
    },
    // 14
    {
        name: 'F',
        symbols: ['-', '(', 'a', 'b', '8', '3'],
        shift: false,
        error: true,
        ref: 26,
        onStack: true,
        end: false,
    },
    // 15
    {
        name: 'TR',
        symbols: ['*', '\n', '+', ')'],
        shift: false,
        error: true,
        ref: 16,
        onStack: false,
        end: false,
    },
    // 16
    {
        name: 'TR',
        symbols: ['*'],
        shift: false,
        error: false,
        ref: 20,
        onStack: false,
        end: false,
    },
    // 17
    {
        name: 'TR',
        symbols: ['+'],
        shift: false,
        error: false,
        ref: 21,
        onStack: false,
        end: false,
    },
    // 18
    {
        name: 'TR',
        symbols: [')'],
        shift: false,
        error: false,
        ref: 22,
        onStack: false,
        end: false,
    },
    // 19
    {
        name: 'TR',
        symbols: ['\n'],
        shift: false,
        error: true,
        ref: 25,
        onStack: false,
        end: false,
    },
    // 20
    {
        name: '*',
        symbols: ['*'],
        shift: true,
        error: true,
        ref: 23,
        onStack: false,
        end: false,
    },
    // 21
    {
        name: '+',
        symbols: ['+'],
        shift: false,
        error: true,
        ref: -1,
        onStack: false,
        end: false,
    },
    // 22
    {
        name: ')',
        symbols: [')'],
        shift: false,
        error: true,
        ref: -1,
        onStack: false,
        end: false,
    },
    // 23
    {
        name: 'F',
        symbols: ['-', '(', 'a', 'b', '8', '3'],
        shift: false,
        error: true,
        ref: 26,
        onStack: true,
        end: false,
    },
    // 24
    {
        name: 'TR',
        symbols: ['*', '\n', '+', ')'],
        shift: false,
        error: true,
        ref: 16,
        onStack: false,
        end: false,
    },
    // 25
    {
        name: '\n',
        symbols: ['\n'],
        shift: true,
        error: false,
        ref: -1,
        onStack: false,
        end: true,
    },
    // 26
    {
        name: 'F',
        symbols: ['-'],
        shift: false,
        error: false,
        ref: 32,
        onStack: false,
        end: false,
    },
    // 27
    {
        name: 'F',
        symbols: ['('],
        shift: false,
        error: false,
        ref: 34,
        onStack: false,
        end: false,
    },
    // 28
    {
        name: 'F',
        symbols: ['a'],
        shift: false,
        error: false,
        ref: 37,
        onStack: false,
        end: false,
    },
    // 29
    {
        name: 'F',
        symbols: ['b'],
        shift: false,
        error: false,
        ref: 38,
        onStack: false,
        end: false,
    },
    // 30
    {
        name: 'F',
        symbols: ['8'],
        shift: false,
        error: false,
        ref: 39,
        onStack: false,
        end: false,
    },
    // 31
    {
        name: 'F',
        symbols: ['3'],
        shift: false,
        error: true,
        ref: 40,
        onStack: false,
        end: false,
    },
    // 32
    {
        name: '-',
        symbols: ['-'],
        shift: true,
        error: true,
        ref: 33,
        onStack: false,
        end: false,
    },
    // 33
    {
        name: 'F',
        symbols: ['-', '(', 'a', 'b', '8', '3'],
        shift: false,
        error: true,
        ref: 26,
        onStack: false,
        end: false,
    },
    // 34
    {
        name: '(',
        symbols: ['('],
        shift: true,
        error: true,
        ref: 35,
        onStack: false,
        end: false,
    },
    // 35
    {
        name: 'EXP',
        symbols: ['-', '(', 'a', 'b', '8', '3'],
        shift: false,
        error: true,
        ref: 0,
        onStack: true,
        end: false,
    },
    // 36
    {
        name: ')',
        symbols: [')'],
        shift: true,
        error: true,
        ref: -1,
        onStack: false,
        end: false,
    },
    // 37
    {
        name: 'a',
        symbols: ['a'],
        shift: true,
        error: true,
        ref: -1,
        onStack: false,
        end: false,
    },
    // 38
    {
        name: 'b',
        symbols: ['b'],
        shift: true,
        error: true,
        ref: -1,
        onStack: false,
        end: false,
    },
    // 39
    {
        name: '8',
        symbols: ['8'],
        shift: true,
        error: true,
        ref: -1,
        onStack: false,
        end: false,
    },
    // 40
    {
        name: '8',
        symbols: ['3'],
        shift: true,
        error: true,
        ref: -1,
        onStack: false,
        end: false,
    },
];
exports.default = Table;
//# sourceMappingURL=table.js.map